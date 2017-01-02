#ifndef __POINT2D__
#define __POINT2D_

#define LD long double

class Point3D;

class Point2D
{
public:
    LD X, Y;
    
	Point2D() {};
    Point2D(LD x, LD y);
    Point2D(const Point2D& that);
    Point2D operator -();
    Point2D operator +(Point2D point2d);
    Point2D operator -(Point2D point2d);
    Point2D operator *(LD k);
    LD operator *(Point2D point2d);
    Point3D operator ^(Point2D point2d);
};

#endif