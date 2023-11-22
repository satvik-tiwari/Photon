#include "Triangle.h"

Triangle::Triangle()
{
    shared_material = nullptr;
}


float Triangle::intersect(Ray r)
{
    //return the calculated t for a given intersection
    //based on line and origin from ray r and the current triangle
    //Homogeneous4 verts[3];

    Cartesian3 vertices[3];

    //converting homogenous coordinates to points
    for(int i = 0; i < 3; i++)
        vertices[i] = verts[i].Point(); //.vector or .point????

    //vectors u and v

    Cartesian3 u = vertices[1] - vertices[0];
    Cartesian3 v = vertices[2] - vertices[0];

    //normalizing u
    u = u.unit();

    //compute n and normailze
    Cartesian3 n = u.cross(v);
    n = n.unit();

    //compute w and normalise
    Cartesian3 w = n.cross(u);
    w = w.unit();

    Cartesian3 p = vertices[0];

    //origin is vertices[0] so that will be p and we have vecotors u,w,n as orthonormal bases
    //plane |-| = {p, vect.u, vect.w, vect.n}
    // p is origion of planar coordinate system
    //s is the origin of r
    //l is the direction of r

    Cartesian3 s = r.origin;
    Cartesian3 l = r.direction; //is l right?? how do u reperesent line using r.direction??

    //orthonormal rotation matirx
    Matrix4 pcs;
    pcs.SetZero();

    for(int j = 0; j < 3; j++)
    {
       pcs[0][j] = u[j];
       pcs[1][j] = w[j];
       pcs[2][j] = n[j];
    }

    pcs[3][3] = 1;

    //convert the origin of ray and direction of ray which is a line
    // to planr coordinate system

    Cartesian3 s_prime = pcs * (p - s);

    Cartesian3 l_prime = pcs * l;

    //calculate t

    float Sn = (p - s_prime).dot(n);
    float ln = l_prime.dot(n);

    float t = Sn/ln;

    //Cartesian3 o = s + l * t;

    return  t;
}
