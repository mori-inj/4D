#include "drawee.h"


Drawee::Drawee(Point3D origin)
{
    this->origin = origin;
	maxX = maxY = -1e9;
	minX = minY = 1e9;
	dots = vector<Point3D*>();
	edges = vector<Edge*>();
}

void Drawee::Update(HDC MemDC)
{
	for (int i = 0; i < (int)edges.size(); i++)
    {
		try
		{
			Point2D dotS = *Observer::Projection(*(edges[i]->S));
			Point2D dotE = *Observer::Projection(*(edges[i]->E));

			LD m1 = (double)dotS.X;
			LD n1 = (double)dotS.Y;

			LD m2 = (double)dotE.X;
			LD n2 = (double)dotE.Y;

			MoveToEx(MemDC, (int)m1, (int)n1, NULL);
			LineTo(MemDC, (int)m2, (int)n2);
		}
		catch(int e)
		{
            continue;
		}

    }
}

void Drawee::Rotate(WPARAM wParam)
{
	int flag;
	int sign;
	LD dtheta = 0.8 * (LD)PI / 180.0;
	
	switch (wParam)
    {
        case 'I':
            flag = 1;
			sign = 1;
            break;
        case 'K':
            flag = 1;
			sign = -1;
            break;
        case 'J':
            flag = 0;
			sign = 1;
            break;
        case 'L':
            flag = 0;
			sign = -1;
            break;
        case 'U':
            flag = 2;
			sign = 1;
            break;
        case 'O':
            flag = 2;
			sign = -1;
            break;
		default:
			return;
	}

	dtheta *= sign;
	for(int i=0; i<(int)dots.size(); i++)
	{
		LD X = dots[i]->X - origin.X, Y = dots[i]->Y - origin.Y, Z = dots[i]->Z - origin.Z;
		LD x[3] = {cos(dtheta)*X - sin(dtheta)*Y, cos(dtheta)*X + sin(dtheta)*Z, X};
		LD y[3] = {sin(dtheta)*X + cos(dtheta)*Y, Y, cos(dtheta)*Y - sin(dtheta)*Z};
		LD z[3] = {Z, cos(dtheta)*Z - sin(dtheta)*X, sin(dtheta)*Y + cos(dtheta)*Z};
		dots[i]->X = x[flag] + origin.X;
		dots[i]->Y = y[flag] + origin.Y;
		dots[i]->Z = z[flag] + origin.Z;
	}
}