#include "RenderParameters.h"

void RenderParameters::findLights(std::vector<ThreeDModel> objects)
{
    for(ThreeDModel obj: objects)
    {
        //find objects that have a "light" material
        if(obj.material->isLight())
        {
            //if the object has exactly 2 triangles, its a rectangular area light.
            if(obj.faceVertices.size()== 2)
            {
                for(unsigned int i = 0; i < 3; i++)
                {
                    unsigned int vid = obj.faceVertices[0][i]; //vertices instead of facevertices, why was
                                                               //this causing the error
                    bool found = false;
                    for(unsigned int j = 0; j < 3; j++)
                    {
                        if(vid == obj.faceVertices[1][j])
                        {

                            found = true;
                            break;
                        }
                    }

                    if(!found)
                    {
                        unsigned int id1 = obj.faceVertices[0][i];
                        unsigned int id2 = obj.faceVertices[0][(i + 1) % 3];
                        unsigned int id3 = obj.faceVertices[0][(i + 2) % 3];

                        Cartesian3 v1 = obj.vertices[id1];
                        Cartesian3 v2 = obj.vertices[id2];
                        Cartesian3 v3 = obj.vertices[id3];

                        Cartesian3 vecA = v2 - v1;
                        Cartesian3 vecB = v3 - v1;

                        Homogeneous4 color = obj.material->emissive;
                        Homogeneous4 pos = v1 + (vecA/2) + (vecB/2);
                        Homogeneous4 normal = obj.normals[obj.faceNormals[0][0]];

                        Light *l = new Light(Light::Area, color, pos, normal, vecA, vecB);
                        l->enabled = true;
                        lights.push_back(l);
                    }


                }


                //std::cout << "Exercise #3, replace this with the code!" << std::endl;
            }
            else
            {
                Cartesian3 center = Cartesian3(0, 0, 0);
                for(unsigned int i = 0; i < obj.vertices.size(); i++)
                {
                    center = center + obj.vertices[i];
                }
                center = center / obj.vertices.size();
                Light *l = new Light(Light::Point, obj.material->emissive,
                                      center, Homogeneous4(),
                                     Homogeneous4(), Homogeneous4());
                l->enabled = true;
                lights.push_back(l);


                //std::cout << "Exercise #3, replace this with the code!" << std::endl;
            }
        }
    }
}


