#include "matrix2by2.h"

const LD Matrix2by2::Epsilon = 1e-9;

Matrix2by2::Matrix2by2(LD a, LD b, LD c, LD d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    DET = a*d - b*c;
}

Matrix2by2 Matrix2by2::operator *(LD k)
{
	return Matrix2by2(a*k, b*k, c*k, d*k);
}

Matrix2by2 Matrix2by2::operator *(Matrix2by2 mat)
{
	return Matrix2by2(
				a * mat.a + b * mat.c,
				a * mat.b + b * mat.d,
				c * mat.a + d * mat.c,
				c * mat.b + d * mat.d
			);   
}

Point2D Matrix2by2::operator *(Point2D& p)
{
	LD x, y;
	x = p.X;
	y = p.Y;

	return Point2D(a * x + b * y, c * x + d * y);
}

bool Matrix2by2::isInversible()
{
    if (abs(DET) < Epsilon)
        return false;
    else
        return true;
}

Matrix2by2* Matrix2by2::Inverse()
{
	LD det = DET;
    if(abs(DET) > Epsilon)
    {
        return new Matrix2by2(d/det, -c/det, -b/det, a/det);
    }
    else
    {
		throw 0;
    }
}
