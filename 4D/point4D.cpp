#include "point2D.h"
#include "point3D.h"
#include "point4D.h"

Point4D::Point4D(LD x, LD y, LD z, LD w)
{
    this->X = x;
    this->Y = y;
    this->Z = z;
	this->W = w;
}

Point4D::Point4D(const Point4D& that)
{
    this->X = that.X;
    this->Y = that.Y;
    this->Z = that.Z;
	this->W = that.W;
}

Point4D::Point4D(Point3D that, LD w)
{
    this->X = that.X;
    this->Y = that.Y;
	this->Z = that.Z;
    this->W = w;
}

Point4D Point4D::operator -()
{
    return Point4D(-X, -Y, -Z, -W);
}
Point4D Point4D::operator +(Point4D point4d)
{
	return Point4D(X+point4d.X, Y+point4d.Y, Z+point4d.Z, W+point4d.W);
}

Point4D Point4D::operator -(Point4D point4d)
{
    return *this + -point4d;
}

Point4D operator *(LD k, Point4D point4d)
{
    return Point4D(k * point4d.X, k * point4d.Y, k * point4d.Z, k * point4d.W);
}

Point4D operator *(Point4D point4d, LD k)
{
    return Point4D(k * point4d.X, k * point4d.Y, k * point4d.Z, k * point4d.W);
}

LD operator *(Point4D point4d1, Point4D point4d2)
{
	LD ret = (point4d1.X * point4d2.X + point4d1.Y * point4d2.Y + point4d1.Z * point4d2.Z + point4d1.W * point4d2.W);
    return ret;
}

void Point4D::norm()
{
    LD size = (LD)sqrt( (*this)*(*this) );
    X = X / size;
    Y = Y / size;
    Z = Z / size;
	W = W / size;
}
