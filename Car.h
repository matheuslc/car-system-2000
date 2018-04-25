// Copyright Matheus Lucca do Carmo

#ifndef CAR_H
#define CAR_H

class Car {
    private:
        int size;
        const int SIZE_ = 5, SIZE_VAR = 4;
    public:
        Car();
        int getSize();
};

#endif