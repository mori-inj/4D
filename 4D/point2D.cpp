#include "point2D.h"
#include "point3D.h"

Point2D::Point2D(LD x, LD y)
{
    this->X = x;
    this->Y = y;
}

Point2D::Point2D(const Point2D& that)
{
    this->X = that.X;
    this->Y = that.Y;
}

Point2D Point2D::operator -()
{
	return Point2D(-X, -Y);
}

Point2D Point2D::operator +(Point2D point2d)
{
	return Point2D(X+point2d.X, Y+point2d.Y);
}

Point2D Point2D::operator -(Point2D point2d)
{
    return (*this) + -point2d;
}

Point2D Point2D::operator *(LD k)
{
	return Point2D(X*k, Y*k);
}

LD Point2D::operator *(Point2D point2d)
{
	LD ret = X * point2d.X + Y * point2d.Y;
    return ret;
}

Point3D Point2D::operator ^(Point2D point2d)
{
    Point3D point3d1 = Point3D(*this, (LD)0.0);
    Point3D point3d2 = Point3D(point2d, (LD)0.0);
    return point3d1 ^ point3d2;
}



