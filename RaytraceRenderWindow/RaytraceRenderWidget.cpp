//////////////////////////////////////////////////////////////////////
//
//  University of Leeds
//  COMP 5812M Foundations of Modelling & Rendering
//  User Interface for Coursework
////////////////////////////////////////////////////////////////////////


#include <math.h>
#include <random>
#include <QTimer>
// include the header file
#include "RaytraceRenderWidget.h"
#include <QTimer>

#define N_THREADS 16
#define N_LOOPS 100
#define N_BOUNCES 5
#define TERMINATION_FACTOR 0.35f

// constructor
RaytraceRenderWidget::RaytraceRenderWidget
        (   
        // the geometric object to show
        std::vector<ThreeDModel>      *newTexturedObject,
        // the render parameters to use
        RenderParameters    *newRenderParameters,
        // parent widget in visual hierarchy
        QWidget             *parent
        )
    // the : indicates variable instantiation rather than arbitrary code
    // it is considered good style to use it where possible
    : 
    // start by calling inherited constructor with parent widget's pointer
    QOpenGLWidget(parent),
    // then store the pointers that were passed in
    texturedObjects(newTexturedObject),
    renderParameters(newRenderParameters)
    { // constructor

        scene = new Scene(newTexturedObject, renderParameters);

        QTimer *timer =  new QTimer(this);


        connect(timer, &QTimer::timeout, this, &RaytraceRenderWidget::forceRepaint);
        timer->start(30);
    } // constructor


// destructor
RaytraceRenderWidget::~RaytraceRenderWidget()
    { // destructor
    // empty (for now)
    // all of our pointers are to data owned by another class
    // so we have no responsibility for destruction
    // and OpenGL cleanup is taken care of by Qt
    } // destructor                                                                 

// mouse-handling
void RaytraceRenderWidget::mousePressEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mousePressEvent()
    // store the button for future reference
    int whichButton = int(event->button());
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;

    
    // and we want to force mouse buttons to allow shift-click to be the same as right-click
    unsigned int modifiers = event->modifiers();
    
    // shift-click (any) counts as right click
    if (modifiers & Qt::ShiftModifier)
        whichButton = Qt::RightButton;
    
    // send signal to the controller for detailed processing
    emit BeginScaledDrag(whichButton, x,y);
    } // RaytraceRenderWidget::mousePressEvent()
    
void RaytraceRenderWidget::mouseMoveEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mouseMoveEvent()
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;
    
    // send signal to the controller for detailed processing
    emit ContinueScaledDrag(x,y);
    } // RaytraceRenderWidget::mouseMoveEvent()
    
void RaytraceRenderWidget::mouseReleaseEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mouseReleaseEvent()
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;
    
    // send signal to the controller for detailed processing
    emit EndScaledDrag(x,y);
    } // RaytraceRenderWidget::mouseReleaseEvent()

// called when OpenGL context is set up
void RaytraceRenderWidget::initializeGL()
    { // RaytraceRenderWidget::initializeGL()
	// this should remain empty
    } // RaytraceRenderWidget::initializeGL()

// called every time the widget is resized
void RaytraceRenderWidget::resizeGL(int w, int h)
    { // RaytraceRenderWidget::resizeGL()
    // resize the render image
    frameBuffer.Resize(w, h);
    } // RaytraceRenderWidget::resizeGL()
    
// called every time the widget needs painting
void RaytraceRenderWidget::paintGL()
    { // RaytraceRenderWidget::paintGL()
    // set background colour to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // and display the image
    glDrawPixels(frameBuffer.width, frameBuffer.height, GL_RGBA, GL_UNSIGNED_BYTE, frameBuffer.block);
    } // RaytraceRenderWidget::paintGL()

void RaytraceRenderWidget::Raytrace()
{
   scene->updateScene();
   raytracingThread = std::thread(&RaytraceRenderWidget::RaytraceThread, this);
   raytracingThread.detach();

}

void RaytraceRenderWidget::RaytraceThread()
{
    frameBuffer.clear(RGBAValue(0.0f, 0.0f, 0.0f, 1.0f));

    #pragma omp parallel for schedule(dynamic)

    for(int j = 0; j < frameBuffer.height; j++)
    {
        for(int i = 0; i < frameBuffer.width; i++)
        {
            Homogeneous4 color(i/float(frameBuffer.height), j/float(frameBuffer.width), 0);
            //Homogeneous4 color(j/float(frameBuffer.width), i/float(frameBuffer.height), 0);

            /*int k = 100000;
            while(k-- > 0);*/

            //casting ray
            Ray ray = calculateRay(i, j, !renderParameters->orthoProjection);

            //Gamma correction...

            float gamma = 2.2f;

            //We already calculate everything in float, so we just do gamma correction before putting it in integer format.

            color.x = pow(color.x, 1 / gamma);
            color.y = pow(color.y, 1 / gamma);
            color.z = pow(color.z, 1 / gamma);
            frameBuffer[j][i] = RGBAValue(color.x * 255.0f,
                                          color.y * 255.0f, color.z * 255.0f, 255.0f);

            //if( j < 2)
            //std::cout << "REd : " << color.x << " , " << "Green : " << color.y << std::endl;
        }
    }

    std::cout << "Done!" <<std::endl;
}

void RaytraceRenderWidget::forceRepaint()
{
    update();
}

Ray RaytraceRenderWidget::calculateRay(int pixelx, int pixely, bool perspective)
{
    //given a pixel positon, cast a ray towards the scene

    float x, y, z;
     z = -1; //since camera is facing -z

    Cartesian3 direction;
    Cartesian3 position; //camera postion



    //pixels are in device coordinate system
    int i_DCS = pixelx;
    int j_DCS = pixely;

    //converting pixels from device coordinate system to
    //normailze device coordinate system
    float i_NDCS = (i_DCS/width() - 0.5f) * 2;
    float j_NDCS = (j_DCS/height() - 0.5f) * 2;

    float aspectRatio = width()/height();

    if(aspectRatio > 1)
    {
        x = i_NDCS * aspectRatio;
        y = j_NDCS;
    }

    else {
        x = i_NDCS;
        y = j_NDCS / aspectRatio;
    }

    if(perspective)
    {
      direction = Cartesian3(x, y, z); //since cam is at 0 direction is (direction - 0,0,0) = direction
      direction.unit();
      position = Cartesian3(0,0,0);
    }

    else
    {
      direction = Cartesian3(0, 0, z);
      direction.unit();
      position = Cartesian3(x, y, 0);
     // position = Cartesian3(x, y, 0);
    }

    Ray ray(position, direction);
    return ray;
}
