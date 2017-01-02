#ifndef __24CELL__
#define __24CELL__

#include "drawee4D.h"

class CELL24 : public Drawee4D
{
public:
	CELL24() {};
	CELL24(Point4D origin, LD r);
};

#endif