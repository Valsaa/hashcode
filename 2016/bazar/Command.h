#ifndef COMMAND_H
#define COMMAND_H


#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;


class Command
{
    public:
        Command();
        virtual ~Command();

        int _positionX;
        int _positionY;
        vector<int> listProduct;
	int _groupid;

    private:
};

#endif // COMMAND_H
