#include "16cell.h"


CELL16::CELL16(Point4D origin, LD r) : Drawee4D(origin)
{
    dots.push_back(new Point4D(origin.X + r, 0, 0, 0));
	dots.push_back(new Point4D(origin.X - r, 0, 0, 0));

	dots.push_back(new Point4D(0, origin.Y + r, 0, 0));
	dots.push_back(new Point4D(0, origin.Y - r, 0, 0));

	dots.push_back(new Point4D(0, 0, origin.Z + r, 0));
	dots.push_back(new Point4D(0, 0, origin.Z - r, 0));

	dots.push_back(new Point4D(0, 0, 0, origin.W + r));
	dots.push_back(new Point4D(0, 0, 0, origin.W - r));
    

    
	edges.push_back(new Edge4D(dots[0], dots[2]));
	edges.push_back(new Edge4D(dots[0], dots[3]));
	edges.push_back(new Edge4D(dots[0], dots[4]));
	edges.push_back(new Edge4D(dots[0], dots[5]));
	edges.push_back(new Edge4D(dots[0], dots[6]));
	edges.push_back(new Edge4D(dots[0], dots[7]));
	
	edges.push_back(new Edge4D(dots[1], dots[2]));
	edges.push_back(new Edge4D(dots[1], dots[3]));
	edges.push_back(new Edge4D(dots[1], dots[4]));
	edges.push_back(new Edge4D(dots[1], dots[5]));
	edges.push_back(new Edge4D(dots[1], dots[6]));
	edges.push_back(new Edge4D(dots[1], dots[7]));

	
	edges.push_back(new Edge4D(dots[2], dots[4]));
	edges.push_back(new Edge4D(dots[2], dots[5]));
	edges.push_back(new Edge4D(dots[2], dots[6]));
	edges.push_back(new Edge4D(dots[2], dots[7]));

	edges.push_back(new Edge4D(dots[3], dots[4]));
	edges.push_back(new Edge4D(dots[3], dots[5]));
	edges.push_back(new Edge4D(dots[3], dots[6]));
	edges.push_back(new Edge4D(dots[3], dots[7]));


	edges.push_back(new Edge4D(dots[4], dots[6]));
	edges.push_back(new Edge4D(dots[4], dots[7]));

	edges.push_back(new Edge4D(dots[5], dots[6]));
	edges.push_back(new Edge4D(dots[5], dots[7]));
    
}
