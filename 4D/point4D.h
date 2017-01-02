#ifndef __POINT4D__
#define __POINT4D__

#include <math.h>

#define LD long double

class Point2D;
class Point3D;

class Point4D
{
public:
    LD X,Y,Z,W;

	Point4D() {};
    Point4D(LD x, LD y, LD z, LD w);
	Point4D(const Point4D& that);
	Point4D(Point3D that, LD w);

	Point4D operator -();
	Point4D operator +(Point4D point4d);
	Point4D operator -(Point4D point4d);
	friend Point4D operator *(LD k, Point4D point4d);
	friend Point4D operator *(Point4D point4d, LD k);
	friend LD operator *(Point4D point4d1, Point4D point4d2);

    void norm();
};

#endif