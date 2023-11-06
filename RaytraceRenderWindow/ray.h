#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "Cartesian3.h"

class Ray
{
public:

    Cartesian3 origin;
    Cartesian3 direction;

    Ray(Cartesian3 og, Cartesian3 dir);
};

#endif // RAY_H
