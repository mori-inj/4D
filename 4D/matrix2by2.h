#ifndef __MATRIX2BY2__
#define __MATRIX2BY2__

#include <cstddef>
#include <math.h>
#include "point2D.h"

class Matrix2by2
{
private:
    static const LD Epsilon;
    LD a, b, c, d;
public:
    LD DET; 

	Matrix2by2() {};
    Matrix2by2(LD a, LD b, LD c, LD d);
    Matrix2by2 operator *(LD k);
    Matrix2by2 operator *(Matrix2by2 mat);
    Point2D operator *(Point2D& p);
    bool isInversible();
    Matrix2by2* Inverse();
};

#endif