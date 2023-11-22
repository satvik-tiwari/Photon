#ifndef SCENE_H
#define SCENE_H

#include "ThreeDModel.h"
#include "RenderParameters.h"
#include "Triangle.h"
#include "Material.h"
#include "ray.h"




class Scene
{
public:

    std::vector<ThreeDModel>* objects;
    RenderParameters* rp;
    std::vector<Triangle> triangles;
    Scene(std::vector<ThreeDModel> *texobs, RenderParameters *renderp);
    Material *default_mat;

    struct CollisionInfo
    {
        Triangle tri;
        float t;
    };

    void updateScene();

    Scene();

    Matrix4 getModelView();

    Scene::CollisionInfo closestTriangle(Ray r);
};






#endif // SCENE_H
