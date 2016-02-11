#include "Grp.h"

Grp::Grp()
{
    //ctor
}

int Grp::calcul_distance_W(Warehouse* WH)
{
	int X_bar = 0, Y_bar = 0;
	
	for(int a=0 ; a<=cmd.size() ; a++)
	{
		X_bar += cmd.at(a)._positionX;
		Y_bar += cmd.at(a)._positionY;
	}
	X_bar = X_bar/cmd.size();
	Y_bar = Y_bar/cmd.size();
	
	return ceil( sqrt( (abs(X_bar-WH->_positionX))*(abs(X_bar-WH->_positionX)) + abs(Y_bar-WH->_positionY))*(abs(Y_bar-WH->_positionY)) ) );
}

Grp::~Grp()
{
    //dtor
}
