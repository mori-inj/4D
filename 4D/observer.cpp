#include "observer.h"

Point3D Observer::O;
Point3D Observer::N;
Point3D Observer::U;
Point3D Observer::R;
LD Observer::D;
LD Observer::dtheta;

Point4D Observer::HO;
Point4D Observer::HN;
LD Observer::HD;

const LD Observer::step = 7.0;

LD Observer::Width;
LD Observer::Height;

Matrix2by2 Observer::XY;
Matrix2by2 Observer::YZ;
Matrix2by2 Observer::XZ;

Matrix2by2 Observer::XYi;
Matrix2by2 Observer::YZi;
Matrix2by2 Observer::XZi;
Observer::InversibleFlag Observer::flag;

Point3D* Observer::RotateVec(Point3D A, Point3D B, LD dtheta)
{
	LD x = A.X * (LD)cos((double)dtheta) + B.X * (LD)sin((double)dtheta);
    LD y = A.Y * (LD)cos((double)dtheta) + B.Y * (LD)sin((double)dtheta);
    LD z = A.Z * (LD)cos((double)dtheta) + B.Z * (LD)sin((double)dtheta);

	return new Point3D(x, y, z);
}

LD Observer::max3(LD a, LD b, LD c)
{
	return max(max(a,b),c);
}


Observer::Observer()
{
	O = Point3D(-120.0, 0.0, 0.0);
	N = Point3D(1.0, 0.0, 0.0);
	U = Point3D(0.0, 0.0, 1.0);
	R = N^U;
	D = 750;
	dtheta = 10.0 * (LD)PI / 180.0;

	HO = Point4D(0.0, 0.0, 0.0, -100.0);
	HN = Point4D(0.0 ,0.0 ,0.0, 1.0);
	HD = 200.0;

	Width = 800;
	Height = 600;

	Matrix2by2 XY = Matrix2by2(R.X, U.X, R.Y, U.Y);
	Matrix2by2 YZ = Matrix2by2(R.Y, U.Y, R.Z, U.Z);
	Matrix2by2 XZ = Matrix2by2(R.X, U.X, R.Z, U.Z);

    XY = Matrix2by2(R.X, U.X, R.Y, U.Y);
    YZ = Matrix2by2(R.Y, U.Y, R.Z, U.Z);
    XZ = Matrix2by2(R.X, U.X, R.Z, U.Z);

            

    if (XY.isInversible())
    {
		flag = XYf;
        XYi = *XY.Inverse();
    }
    else if (YZ.isInversible())
    {
        flag = YZf;
        YZi = *YZ.Inverse();
    }
    else if (XZ.isInversible())
    {
        flag = ZXf;
        XZi = *XZ.Inverse();
    }
}

void Observer::Axis(HDC MemDC)
{
	Point2D trans;
	LD m1,m2,n1,n2;
	LD INF = 1e2;

	try
	{
		trans = *ProjectionAxis(Point3D(-INF, 0, 0));
        m1 = (double)trans.X;
        n1 = (double)trans.Y;
			
		trans = *ProjectionAxis(Point3D(INF, 0, 0));
        m2 = (double)trans.X;
        n2 = (double)trans.Y;

		MoveToEx(MemDC, (int)m1, (int)n1, NULL);
		LineTo(MemDC, (int)m2, (int)n2);
    }
	catch (int e) {}
		
    try 
	{
		trans = *ProjectionAxis(Point3D(0, -INF, 0));
        m1 = (double)trans.X;
        n1 = (double)trans.Y;
			
		trans = *ProjectionAxis(Point3D(0, INF, 0));
        m2 = (double)trans.X;
        n2 = (double)trans.Y;

		MoveToEx(MemDC, (int)m1, (int)n1, NULL);
		LineTo(MemDC, (int)m2, (int)n2);
    }
	catch (int e) {}
        
    try 
	{
		trans = *ProjectionAxis(Point3D(0, 0, -INF));
        m1 = (double)trans.X;
        n1 = (double)trans.Y;
			
		trans = *ProjectionAxis(Point3D(0, 0, INF));
        m2 = (double)trans.X;
        n2 = (double)trans.Y;

		MoveToEx(MemDC, (int)m1, (int)n1, NULL);
		LineTo(MemDC, (int)m2, (int)n2);
    }
	catch (int e) {}
}

/*void Observer::Update(HDC MemDC)
{
	Axis(MemDC);   
}*/

void Observer::Scroll(int delta)
{
    O = O + (0.3*(LD)delta) * N;

    XY = Matrix2by2(R.X, U.X, R.Y, U.Y);
    YZ = Matrix2by2(R.Y, U.Y, R.Z, U.Z);
    XZ = Matrix2by2(R.X, U.X, R.Z, U.Z);

    if (XY.isInversible())
    {
        flag = XYf;
        XYi = *XY.Inverse();
    }
    else if (YZ.isInversible())
    {
        flag = YZf;
        YZi = *YZ.Inverse();
    }
    else if (XZ.isInversible())
    {
        flag = ZXf;
        XZi = *XZ.Inverse();
    }
}

void Observer::Transform(WPARAM wParam)
{
    switch (wParam)
    {
		case VK_PRIOR:
            O = O + step*N;
            break;
        case VK_NEXT:
            O = O - step*N;
            break;
        case VK_LEFT:
            O = O - step*R;
            break;
        case VK_RIGHT:
            O = O + step*R;
            break;
        case VK_UP:
            O = O + step * U;
            break;
        case VK_DOWN:
            O = O - step * U;
            break;

        case 'W':
            N = *RotateVec(N, U, dtheta);
            U = R^N;
            break;
        case 'S':
            N = *RotateVec(N, U, -dtheta);
            U = R^N;
            break;
        case 'A':
            R = *RotateVec(R, N, dtheta);
            N = U ^ R;
            break;
        case 'D':
            R = *RotateVec(R, N, -dtheta);
            N = U ^ R;
            break;
        case 'Q':
            R = *RotateVec(R, U, -dtheta);
            U = R ^ N;
            break;
        case 'E':
            R = *RotateVec(R, U, dtheta);
            U = R ^ N;                  
            break;
    }

    XY = Matrix2by2(R.X, U.X, R.Y, U.Y);
    YZ = Matrix2by2(R.Y, U.Y, R.Z, U.Z);
    XZ = Matrix2by2(R.X, U.X, R.Z, U.Z);

    LD detXY = XY.DET, detYZ = YZ.DET, detZX = XZ.DET;
    LD detMax = max3(abs(detXY), abs(detYZ), abs(detZX));

    if (abs(detXY) == detMax)
    {
        flag = XYf;
        XYi = *XY.Inverse();
    }
    else if (abs(detYZ) == detMax)
    {
        flag = YZf;
        YZi = *YZ.Inverse();
    }
    else if (abs(detZX) == detMax)
    {
		flag = ZXf;
        XZi = *XZ.Inverse();
    }
}

Point2D* Observer::ProjectionAxis(Point3D P)
{
    if(abs(N * (P - O)) < 1e-9)
        throw -1;
    LD K = (D*(N*N)) / ( N*(P-O) );

    /*Point3D dist = K * (P - O);
    if (dist*dist < D*D)
        return null;*/

    Point2D ans;        

    if (flag == XYf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        Point2D xy = Point2D(tx, ty);
        ans = XYi * xy;
    }

    else if (flag == YZf)
    {
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D yz = Point2D(ty, tz);       
        ans = YZi * yz;
    }

    else if (flag == ZXf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D xz = Point2D(tx, tz);
        ans = XZi * xz;
    }
    return new Point2D(ans.X + Width / 2, -ans.Y + Height / 2);
}

Point2D* Observer::Projection(Point3D P)
{
    if(abs(N * (P - O)) < 1e-9)
        throw -1;
	if((P-O)*N < D/100)
		throw -1;
    LD K = (D*(N*N)) / ( N*(P-O) );

    /*Point3D dist = K * (P - O);
    if (dist*dist < D*D)
        return null;*/

    Point2D ans;        

    if (flag == XYf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        Point2D xy = Point2D(tx, ty);
        ans = XYi * xy;
    }

    else if (flag == YZf)
    {
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D yz = Point2D(ty, tz);       
        ans = YZi * yz;
    }

    else if (flag == ZXf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D xz = Point2D(tx, tz);
        ans = XZi * xz;
    }
    return new Point2D(ans.X + Width / 2, -ans.Y + Height / 2);
}

Point3D* Observer::HyperProjection(Point4D P)
{
    //if(abs(HN * (P - HO)) < 1e-9)
      //  throw -1;
	//if((P-HO)*HN < HD/100)
		//throw -1;
    LD K = (HD*(HN*HN)) / ( HN*(P-HO) );

	Point4D Q = HO + K * (P - HO);
	return new Point3D(Q.X, Q.Y, Q.Z);

    /*Point3D dist = K * (P - O);
    if (dist*dist < D*D)
        return null;*/

    /*Point2D ans;        

    if (flag == XYf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        Point2D xy = Point2D(tx, ty);
        ans = XYi * xy;
    }

    else if (flag == YZf)
    {
        LD ty = K * (P.Y - O.Y) - D * N.Y;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D yz = Point2D(ty, tz);       
        ans = YZi * yz;
    }

    else if (flag == ZXf)
    {
        LD tx = K * (P.X - O.X) - D * N.X;
        LD tz = K * (P.Z - O.Z) - D * N.Z;
        Point2D xz = Point2D(tx, tz);
        ans = XZi * xz;
    }
    return new Point2D(ans.X + Width / 2, -ans.Y + Height / 2);*/
}

Point3D* Observer::InverseProjection(Point2D P)
{
	return new Point3D(O + D*N + P.X*R + P.Y*U);
}

Point3D* Observer::InverseProjectionVector(Point2D P)
{
	Point3D* ret = new Point3D(D*N + P.X*R + P.Y*U);
	ret->norm();
	return ret;
}