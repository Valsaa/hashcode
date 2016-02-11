#include "Warehouse.h"

Warehouse::Warehouse(int px, int py, vector<int*> *nbProduct)
{
    _positionX = px;
    _positionY = py;
    _nbProduct = nbProduct;
}

Warehouse::~Warehouse()
{
    //dtor
}
