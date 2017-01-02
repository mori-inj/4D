#ifndef __EDGE__
#define __EDGE__

#include "point3D.h"

class Edge
{
public:
    Point3D* S;
    Point3D* E;

    Edge(Point3D* start, Point3D* end);
 
};

#endif