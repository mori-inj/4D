#include "24cell.h"


CELL24::CELL24(Point4D origin, LD r) : Drawee4D(origin)
{
	dots.push_back(new Point4D(origin.X + r, 0, 0, 0)); //0
	dots.push_back(new Point4D(origin.X - r, 0, 0, 0)); //1

	dots.push_back(new Point4D(0, origin.Y + r, 0, 0)); //2
	dots.push_back(new Point4D(0, origin.Y - r, 0, 0)); //3

	dots.push_back(new Point4D(0, 0, origin.Z + r, 0)); //4
	dots.push_back(new Point4D(0, 0, origin.Z - r, 0)); //5

	dots.push_back(new Point4D(0, 0, 0, origin.W + r)); //6
	dots.push_back(new Point4D(0, 0, 0, origin.W - r)); //7
    

    
	/*edges.push_back(new Edge4D(dots[0], dots[2]));
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
	edges.push_back(new Edge4D(dots[5], dots[7]));*/




	//-------------------------------------------------


	r = r/2.0;

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


	edges.push_back(new Edge4D(dots[0+8+8], dots[1+8+8]));
    edges.push_back(new Edge4D(dots[1+8+8], dots[2+8+8]));
    edges.push_back(new Edge4D(dots[2+8+8], dots[3+8+8]));
    edges.push_back(new Edge4D(dots[3+8+8], dots[0+8+8]));

    edges.push_back(new Edge4D(dots[4+8+8], dots[5+8+8]));
    edges.push_back(new Edge4D(dots[5+8+8], dots[6+8+8]));
    edges.push_back(new Edge4D(dots[6+8+8], dots[7+8+8]));
    edges.push_back(new Edge4D(dots[7+8+8], dots[4+8+8]));

    edges.push_back(new Edge4D(dots[0+8+8], dots[4+8+8]));
    edges.push_back(new Edge4D(dots[1+8+8], dots[5+8+8]));
    edges.push_back(new Edge4D(dots[2+8+8], dots[6+8+8]));
    edges.push_back(new Edge4D(dots[3+8+8], dots[7+8+8]));


	edges.push_back(new Edge4D(dots[0+8], dots[0+8+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[1+8+8]));
	edges.push_back(new Edge4D(dots[2+8], dots[2+8+8]));
	edges.push_back(new Edge4D(dots[3+8], dots[3+8+8]));
	edges.push_back(new Edge4D(dots[4+8], dots[4+8+8]));
	edges.push_back(new Edge4D(dots[5+8], dots[5+8+8]));
	edges.push_back(new Edge4D(dots[6+8], dots[6+8+8]));
	edges.push_back(new Edge4D(dots[7+8], dots[7+8+8]));



//--------------------------------------------------------------------


	edges.push_back(new Edge4D(dots[0], dots[8]));
	edges.push_back(new Edge4D(dots[3], dots[8]));
	edges.push_back(new Edge4D(dots[5], dots[8]));
	edges.push_back(new Edge4D(dots[6], dots[8]));

	edges.push_back(new Edge4D(dots[0], dots[9]));
	edges.push_back(new Edge4D(dots[2], dots[9]));
	edges.push_back(new Edge4D(dots[5], dots[9]));
	edges.push_back(new Edge4D(dots[6], dots[9]));

	edges.push_back(new Edge4D(dots[1], dots[10]));
	edges.push_back(new Edge4D(dots[2], dots[10]));
	edges.push_back(new Edge4D(dots[5], dots[10]));
	edges.push_back(new Edge4D(dots[6], dots[10]));

	edges.push_back(new Edge4D(dots[1], dots[11]));
	edges.push_back(new Edge4D(dots[3], dots[11]));
	edges.push_back(new Edge4D(dots[5], dots[11]));
	edges.push_back(new Edge4D(dots[6], dots[11]));

	edges.push_back(new Edge4D(dots[0], dots[12]));
	edges.push_back(new Edge4D(dots[3], dots[12]));
	edges.push_back(new Edge4D(dots[4], dots[12]));
	edges.push_back(new Edge4D(dots[6], dots[12]));

	edges.push_back(new Edge4D(dots[0], dots[13]));
	edges.push_back(new Edge4D(dots[2], dots[13]));
	edges.push_back(new Edge4D(dots[4], dots[13]));
	edges.push_back(new Edge4D(dots[6], dots[13]));

	edges.push_back(new Edge4D(dots[1], dots[14]));
	edges.push_back(new Edge4D(dots[2], dots[14]));
	edges.push_back(new Edge4D(dots[4], dots[14]));
	edges.push_back(new Edge4D(dots[6], dots[14]));
	
	edges.push_back(new Edge4D(dots[1], dots[15]));
	edges.push_back(new Edge4D(dots[3], dots[15]));
	edges.push_back(new Edge4D(dots[4], dots[15]));
	edges.push_back(new Edge4D(dots[6], dots[15]));



//---------------------------------------------------

	edges.push_back(new Edge4D(dots[0], dots[8+8]));
	edges.push_back(new Edge4D(dots[3], dots[8+8]));
	edges.push_back(new Edge4D(dots[5], dots[8+8]));
	edges.push_back(new Edge4D(dots[7], dots[8+8]));

	edges.push_back(new Edge4D(dots[0], dots[9+8]));
	edges.push_back(new Edge4D(dots[2], dots[9+8]));
	edges.push_back(new Edge4D(dots[5], dots[9+8]));
	edges.push_back(new Edge4D(dots[7], dots[9+8]));

	edges.push_back(new Edge4D(dots[1], dots[10+8]));
	edges.push_back(new Edge4D(dots[2], dots[10+8]));
	edges.push_back(new Edge4D(dots[5], dots[10+8]));
	edges.push_back(new Edge4D(dots[7], dots[10+8]));

	edges.push_back(new Edge4D(dots[1], dots[11+8]));
	edges.push_back(new Edge4D(dots[3], dots[11+8]));
	edges.push_back(new Edge4D(dots[5], dots[11+8]));
	edges.push_back(new Edge4D(dots[7], dots[11+8]));

	edges.push_back(new Edge4D(dots[0], dots[12+8]));
	edges.push_back(new Edge4D(dots[3], dots[12+8]));
	edges.push_back(new Edge4D(dots[4], dots[12+8]));
	edges.push_back(new Edge4D(dots[7], dots[12+8]));

	edges.push_back(new Edge4D(dots[0], dots[13+8]));
	edges.push_back(new Edge4D(dots[2], dots[13+8]));
	edges.push_back(new Edge4D(dots[4], dots[13+8]));
	edges.push_back(new Edge4D(dots[7], dots[13+8]));

	edges.push_back(new Edge4D(dots[1], dots[14+8]));
	edges.push_back(new Edge4D(dots[2], dots[14+8]));
	edges.push_back(new Edge4D(dots[4], dots[14+8]));
	edges.push_back(new Edge4D(dots[7], dots[14+8]));

	edges.push_back(new Edge4D(dots[1], dots[15+8]));
	edges.push_back(new Edge4D(dots[3], dots[15+8]));
	edges.push_back(new Edge4D(dots[4], dots[15+8]));
	edges.push_back(new Edge4D(dots[7], dots[15+8]));

	



	/*
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));

	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	edges.push_back(new Edge4D(dots[6], ));
	*/











    /*dots.push_back(new Point4D(origin.X + r, origin.Y + r, 0, 0));
	dots.push_back(new Point4D(origin.X - r, origin.Y - r, 0, 0));

	dots.push_back(new Point4D(origin.X - r, origin.Y + r, 0, 0));
	dots.push_back(new Point4D(origin.X + r, origin.Y - r, 0, 0));

	dots.push_back(new Point4D(0, 0, origin.Z + r, origin.W + r));
	dots.push_back(new Point4D(0, 0, origin.Z - r, origin.W - r));

	dots.push_back(new Point4D(0, 0, origin.Z - r, origin.W + r));
	dots.push_back(new Point4D(0, 0, origin.Z + r, origin.W - r));
    

    
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



//-------------------------------------------------------------------------------------


	dots.push_back(new Point4D(origin.X + r, 0, origin.Z + r, 0));
	dots.push_back(new Point4D(origin.X - r, 0, origin.Z - r, 0));

	dots.push_back(new Point4D(origin.X - r, 0, origin.Z + r, 0));
	dots.push_back(new Point4D(origin.X + r, 0, origin.Z - r, 0));

	dots.push_back(new Point4D(0, origin.Y + r, 0, origin.W + r));
	dots.push_back(new Point4D(0, origin.Y - r, 0, origin.W - r));

	dots.push_back(new Point4D(0, origin.Y - r, 0, origin.W + r));
	dots.push_back(new Point4D(0, origin.Y + r, 0, origin.W - r));
    

    
	edges.push_back(new Edge4D(dots[0+8], dots[2+8]));
	edges.push_back(new Edge4D(dots[0+8], dots[3+8]));
	edges.push_back(new Edge4D(dots[0+8], dots[4+8]));
	edges.push_back(new Edge4D(dots[0+8], dots[5+8]));
	edges.push_back(new Edge4D(dots[0+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[0+8], dots[7+8]));
	
	edges.push_back(new Edge4D(dots[1+8], dots[2+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[3+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[4+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[5+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[1+8], dots[7+8]));

	
	edges.push_back(new Edge4D(dots[2+8], dots[4+8]));
	edges.push_back(new Edge4D(dots[2+8], dots[5+8]));
	edges.push_back(new Edge4D(dots[2+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[2+8], dots[7+8]));

	edges.push_back(new Edge4D(dots[3+8], dots[4+8]));
	edges.push_back(new Edge4D(dots[3+8], dots[5+8]));
	edges.push_back(new Edge4D(dots[3+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[3+8], dots[7+8]));


	edges.push_back(new Edge4D(dots[4+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[4+8], dots[7+8]));

	edges.push_back(new Edge4D(dots[5+8], dots[6+8]));
	edges.push_back(new Edge4D(dots[5+8], dots[7+8]));





//------------------------------------------------------------------------



	dots.push_back(new Point4D(origin.X + r, 0, 0, origin.W + r));
	dots.push_back(new Point4D(origin.X - r, 0, 0, origin.W - r));

	dots.push_back(new Point4D(origin.X - r, 0, 0, origin.W + r));
	dots.push_back(new Point4D(origin.X + r, 0, 0, origin.W - r));

	dots.push_back(new Point4D(0, origin.Y + r, origin.Z + r, 0));
	dots.push_back(new Point4D(0, origin.Y - r, origin.Z - r, 0));

	dots.push_back(new Point4D(0, origin.Y - r, origin.Z + r, 0));
	dots.push_back(new Point4D(0, origin.Y + r, origin.Z - r, 0));
    

    
	edges.push_back(new Edge4D(dots[0+16], dots[2+16]));
	edges.push_back(new Edge4D(dots[0+16], dots[3+16]));
	edges.push_back(new Edge4D(dots[0+16], dots[4+16]));
	edges.push_back(new Edge4D(dots[0+16], dots[5+16]));
	edges.push_back(new Edge4D(dots[0+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[0+16], dots[7+16]));
	
	edges.push_back(new Edge4D(dots[1+16], dots[2+16]));
	edges.push_back(new Edge4D(dots[1+16], dots[3+16]));
	edges.push_back(new Edge4D(dots[1+16], dots[4+16]));
	edges.push_back(new Edge4D(dots[1+16], dots[5+16]));
	edges.push_back(new Edge4D(dots[1+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[1+16], dots[7+16]));

	
	edges.push_back(new Edge4D(dots[2+16], dots[4+16]));
	edges.push_back(new Edge4D(dots[2+16], dots[5+16]));
	edges.push_back(new Edge4D(dots[2+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[2+16], dots[7+16]));

	edges.push_back(new Edge4D(dots[3+16], dots[4+16]));
	edges.push_back(new Edge4D(dots[3+16], dots[5+16]));
	edges.push_back(new Edge4D(dots[3+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[3+16], dots[7+16]));


	edges.push_back(new Edge4D(dots[4+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[4+16], dots[7+16]));

	edges.push_back(new Edge4D(dots[5+16], dots[6+16]));
	edges.push_back(new Edge4D(dots[5+16], dots[7+16]));*/


//-----------------------------------------------------------------





	//edges.push_back(new Edge4D(dots[18], dots[10]));
	//edges.push_back(new Edge4D(dots[19], dots[11]));

	/*edges.push_back(new Edge4D(dots[4], dots[20]));
	edges.push_back(new Edge4D(dots[5], dots[21]));
	edges.push_back(new Edge4D(dots[6], dots[22]));
	edges.push_back(new Edge4D(dots[7], dots[23]));*/
    
}
