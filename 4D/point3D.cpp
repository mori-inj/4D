#include "point2D.h"
#include "point3D.h"

Point3D::Point3D(LD x, LD y, LD z)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
}

Point3D::Point3D(const Point3D& that)
{
    this->X = that.X;
    this->Y = that.Y;
    this->Z = that.Z;
}

Point3D::Point3D(Point2D that, LD z)
{
    this->X = that.X;
    this->Y = that.Y;
    this->Z = z;
}

Point3D Point3D::operator -()
{
    return Point3D(-X, -Y, -Z);
}
Point3D Point3D::operator +(Point3D point3d)
{
	return Point3D(X+point3d.X, Y+point3d.Y, Z+point3d.Z);
}

Point3D Point3D::operator -(Point3D point3d)
{
    return *this + -point3d;
}

Point3D operator *(LD k, Point3D point3d)
{
    return Point3D(k * point3d.X, k * point3d.Y, k * point3d.Z);
}

Point3D operator *(Point3D point3d, LD k)
{
    return Point3D(k * point3d.X, k * point3d.Y, k * point3d.Z);
}

LD operator *(Point3D point3d1, Point3D point3d2)
{
	LD ret = (point3d1.X * point3d2.X + point3d1.Y * point3d2.Y + point3d1.Z * point3d2.Z);
    return ret;
}
Point3D Point3D::operator ^(Point3D point3d)
{
    LD x1 = X;
    LD y1 = Y;
    LD z1 = Z;

    LD x2 = point3d.X;
    LD y2 = point3d.Y;
    LD z2 = point3d.Z;

    return Point3D(y1*z2 - z1*y2, z1*x2 - x1*z2, x1*y2 - y1*x2);
}

void Point3D::norm()
{
    LD size = (LD)sqrt( (*this)*(*this) );
    X = X / size;
    Y = Y / size;
    Z = Z / size;
}
