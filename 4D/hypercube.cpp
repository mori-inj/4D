#include "hypercube.h"

HyperCube::HyperCube(Point4D origin, LD r) : Drawee4D(origin)
{
    dots.push_back(new Point4D(origin.X + r, origin.Y - r, origin.Z - r, origin.W + r));
    dots.push_back(new Point4D(origin.X + r, origin.Y + r, origin.Z - r, origin.W + r));
    dots.push_back(new Point4D(origin.X - r, origin.Y + r, origin.Z - r, origin.W + r));
    dots.push_back(new Point4D(origin.X - r, origin.Y - r, origin.Z - r, origin.W + r));

    dots.push_back(new Point4D(origin.X + r, origin.Y - r, origin.Z + r, origin.W + r));
    dots.push_back(new Point4D(origin.X + r, origin.Y + r, origin.Z + r, origin.W + r));
    dots.push_back(new Point4D(origin.X - r, origin.Y + r, origin.Z + r, origin.W + r));
    dots.push_back(new Point4D(origin.X - r, origin.Y - r, origin.Z + r, origin.W + r));

	dots.push_back(new Point4D(origin.X + r, origin.Y - r, origin.Z - r, origin.W - r));
    dots.push_back(new Point4D(origin.X + r, origin.Y + r, origin.Z - r, origin.W - r));
    dots.push_back(new Point4D(origin.X - r, origin.Y + r, origin.Z - r, origin.W - r));
    dots.push_back(new Point4D(origin.X - r, origin.Y - r, origin.Z - r, origin.W - r));

    dots.push_back(new Point4D(origin.X + r, origin.Y - r, origin.Z + r, origin.W - r));
    dots.push_back(new Point4D(origin.X + r, origin.Y + r, origin.Z + r, origin.W - r));
    dots.push_back(new Point4D(origin.X - r, origin.Y + r, origin.Z + r, origin.W - r));
    dots.push_back(new Point4D(origin.X - r, origin.Y - r, origin.Z + r, origin.W - r));

    
	edges.push_back(new Edge4D(dots[0], dots[1]));
    edges.push_back(new Edge4D(dots[1], dots[2]));
    edges.push_back(new Edge4D(dots[2], dots[3]));
    edges.push_back(new Edge4D(dots[3], dots[0]));

    edges.push_back(new Edge4D(dots[4], dots[5]));
    edges.push_back(new Edge4D(dots[5], dots[6]));
    edges.push_back(new Edge4D(dots[6], dots[7]));
    edges.push_back(new Edge4D(dots[7], dots[4]));

    edges.push_back(new Edge4D(dots[0], dots[4]));
    edges.push_back(new Edge4D(dots[1], dots[5]));
    edges.push_back(new Edge4D(dots[2], dots[6]));
    edges.push_back(new Edge4D(dots[3], dots[7]));


	edges.push_back(new Edge4D(dots[0+8], dots[1+8]));
    edges.push_back(new Edge4D(dots[1+8], dots[2+8]));
    edges.push_back(new Edge4D(dots[2+8], dots[3+8]));
    edges.push_back(new Edge4D(dots[3+8], dots[0+8]));

    edges.push_back(new Edge4D(dots[4+8], dots[5+8]));
    edges.push_back(new Edge4D(dots[5+8], dots[6+8]));
    edges.push_back(new Edge4D(dots[6+8], dots[7+8]));
    edges.push_back(new Edge4D(dots[7+8], dots[4+8]));

    edges.push_back(new Edge4D(dots[0+8], dots[4+8]));
    edges.push_back(new Edge4D(dots[1+8], dots[5+8]));
    edges.push_back(new Edge4D(dots[2+8], dots[6+8]));
    edges.push_back(new Edge4D(dots[3+8], dots[7+8]));


	edges.push_back(new Edge4D(dots[0], dots[0+8]));
	edges.push_back(new Edge4D(dots[1], dots[1+8]));
	edges.push_back(new Edge4D(dots[2], dots[2+8]));
	edges.push_back(new Edge4D(dots[3], dots[3+8]));
	edges.push_back(new Edge4D(dots[4], dots[4+8]));
	edges.push_back(new Edge4D(dots[5], dots[5+8]));
	edges.push_back(new Edge4D(dots[6], dots[6+8]));
	edges.push_back(new Edge4D(dots[7], dots[7+8]));
}
