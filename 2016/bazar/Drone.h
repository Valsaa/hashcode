#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>


using namespace std;


class Drone
{
    public:
        Drone();
        virtual ~Drone();

        int _positionX;
        int _positionY;
        bool dispo;

    private:
};

#endif // DRONE_H
