#ifndef __POINT3D__
#define __POINT3D__

#include <math.h>

#define LD long double

class Point2D;

class Point3D
{
public:
    LD X,Y,Z;

	Point3D() {};
    Point3D(LD x, LD y, LD z);
	Point3D(const Point3D& that);
	Point3D(Point2D that, LD z);

	Point3D operator -();
	Point3D operator +(Point3D point3d);
	Point3D operator -(Point3D point3d);
	friend Point3D operator *(LD k, Point3D point3d);
	friend Point3D operator *(Point3D point3d, LD k);
	friend LD operator *(Point3D point3d1, Point3D point3d2);
	Point3D operator ^(Point3D point3d);

    void norm();
};

#endif