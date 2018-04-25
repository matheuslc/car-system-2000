// Copyright Carmel

#include "Car.h"
#include <cstdlib>

Car::Car() {
    size = SIZE_ + SIZE_VAR + (double(rand()) / RAND_MAX);
}

int Car::getSize() {
    return size;
}