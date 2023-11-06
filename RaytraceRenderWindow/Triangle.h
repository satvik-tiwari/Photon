#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Homogeneous4.h"
#include "Cartesian3.h"
#include "Material.h"

class Triangle
{
public:
    Homogeneous4 verts[3];
    Homogeneous4 norms[3];
    Homogeneous4 colors[3];
    Cartesian3 uvs[3];

    Material *shared_material;
    Triangle();
};

#endif // TRIANGLE_H
