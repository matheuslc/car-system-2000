// Copyright Matheus Lucca do Carmo

#ifndef ROAD_H
#define ROAD_H

#include "linked_queue.h"
#include "Semaphore.h"
#include "Car.h"

class Road
{
    protected:
        double size;
        double max_velocity;
        double state;

        double probLeft;
        double probRight;

        LinkedQueue<Car> cars;

    public:
        Road(Semaphore& semaphore, double size, double max_velocity, double probLeft, double probRight);
        ~Road();

        void addCar(Car car);
        Car popCar();
        bool empty();
        bool full();

        bool blocked;
};

#endif