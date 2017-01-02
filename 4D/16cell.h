#ifndef __16CELL__
#define __16CELL__

#include "drawee4D.h"

class CELL16 : public Drawee4D
{
public:
	CELL16() {};
	CELL16(Point4D origin, LD r);
};

#endif