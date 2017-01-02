#ifndef __HYPERCUBE__
#define __HYPERCUBE__

#include "drawee4D.h"

class HyperCube : public Drawee4D
{
public:
	HyperCube() {};
	HyperCube(Point4D origin, LD r);
};

#endif