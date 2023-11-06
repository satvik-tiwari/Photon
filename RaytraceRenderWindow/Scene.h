#ifndef SCENE_H
#define SCENE_H

#include "ThreeDModel.h"
#include "RenderParameters.h"
#include "Triangle.h"
#include "Material.h"

class Scene
{
public:

    std::vector<ThreeDModel>* objects;
    RenderParameters* rp;
    std::vector<Triangle> triangles;
    Scene(std::vector<ThreeDModel> *texobs, RenderParameters *renderp);
    Material *default_mat;

    void updateScene();

    Scene();
};

#endif // SCENE_H
