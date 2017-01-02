#include "drawee4D.h"


Drawee4D::Drawee4D(Point4D origin)
{
    this->origin = origin;
	maxX = maxY = -1e9;
	minX = minY = 1e9;
	dots = vector<Point4D*>();
	edges = vector<Edge4D*>();
}

void Drawee4D::Update(HDC MemDC)
{
	HPEN hPen, oldPen;

	for (int i = 0; i < (int)edges.size(); i++)
    {
		try
		{
			Point3D dotS3D = *Observer::HyperProjection(*(edges[i]->S));
			Point3D dotE3D = *Observer::HyperProjection(*(edges[i]->E));

			Point2D dotS = * Observer::Projection(dotS3D);
			Point2D dotE = * Observer::Projection(dotE3D);

			LD m1 = (double)dotS.X;
			LD n1 = (double)dotS.Y;

			LD m2 = (double)dotE.X;
			LD n2 = (double)dotE.Y;

			/*if(0 <= i && i < 32)
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
				oldPen = (HPEN)SelectObject(MemDC, hPen);
			}
			else if(32 <= i && i < 64)
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
				oldPen = (HPEN)SelectObject(MemDC, hPen);
			}
			else if(64 <= i && i < 96)
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
				oldPen = (HPEN)SelectObject(MemDC, hPen);
			}
			else
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
				oldPen = (HPEN)SelectObject(MemDC, hPen);
			}*/
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			oldPen = (HPEN)SelectObject(MemDC, hPen);
			MoveToEx(MemDC, (int)m1, (int)n1, NULL);
			LineTo(MemDC, (int)m2, (int)n2);
			DeleteObject(hPen);
		}
		catch(int e)
		{
            continue;
		}

    }
}

void Drawee4D::Rotate(WPARAM wParam)
{
	int flag;
	int sign = 1;
	LD dtheta = 5.0 * (LD)PI / 180.0;

	if(GetKeyState(VK_SHIFT) & 0x8000)
		sign = -1;
	
	switch (wParam)
    {
		case 'U':
			flag = 0;
			break;
		case 'I':
			flag = 1;
			break;
		case 'O':
			flag = 2;
			break;
		case 'J':
			flag = 3;
			break;
		case 'K':
			flag = 4;
			break;
		case 'L':
			flag = 5;
			break;

		default:
			return;
	}

	dtheta *= sign;
	for(int i=0; i<(int)dots.size(); i++)
	{
		LD X = dots[i]->X - origin.X, Y = dots[i]->Y - origin.Y, Z = dots[i]->Z - origin.Z, W = dots[i]->W - origin.W;

		LD x[6] = {cos(dtheta)*X - sin(dtheta)*Y, cos(dtheta)*X - sin(dtheta)*Z, X,							    cos(dtheta)*X - sin(dtheta)*W, X,							  X};
		LD y[6] = {sin(dtheta)*X + cos(dtheta)*Y, Y,							 cos(dtheta)*Y - sin(dtheta)*Z, Y,							   cos(dtheta)*Y - sin(dtheta)*W, Y};
		LD z[6] = {Z,							  sin(dtheta)*X + cos(dtheta)*Z, sin(dtheta)*Y + cos(dtheta)*Z, Z,							   Z,							  cos(dtheta)*Z - sin(dtheta)*W};
		LD w[6] = {W,							  W,							 W,								sin(dtheta)*X + cos(dtheta)*W, sin(dtheta)*Y + cos(dtheta)*W, sin(dtheta)*Z + cos(dtheta)*W};

		dots[i]->X = x[flag] + origin.X;
		dots[i]->Y = y[flag] + origin.Y;
		dots[i]->Z = z[flag] + origin.Z;
		dots[i]->W = w[flag] + origin.W;
	}
}