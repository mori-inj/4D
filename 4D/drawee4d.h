#ifndef __DRAWEE4D__
#define __DRAWEE4D__

#include <math.h>
#include <vector>
#include <Windows.h>
#include "point4D.h"
#include "edge4d.h"
#include "observer.h"

using namespace std;

class Drawee4D
{
protected:
	Point4D origin;
    vector<Point4D*> dots;
    vector<Edge4D*> edges;

public:
	LD minX, minY, maxX, maxY;
	Drawee4D() {};
	Drawee4D(Point4D origin);
    void Update(HDC MemDC);
	void Rotate(WPARAM wParam);
};

#endif