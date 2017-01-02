#ifndef __EDGE4D__
#define __EDGE4D__

#include "point4D.h"

class Edge4D
{
public:
    Point4D* S;
    Point4D* E;

    Edge4D(Point4D* start, Point4D* end);
 
};

#endif