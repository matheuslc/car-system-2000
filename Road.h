#include "array_list.h";

class Road
{
    protected:
        double size;
        double max_velocity;
        double state;

        double probLeft;
        double probRight;

        std::queue<Car*> cars;

    public:
        Road(Semaphore& semaphore, double size, double max_velocity, double probLeft, double probRight);
        ~Roead();

        void addCar(Car car);
        Car popCar();
        bool empty();
        bool full();

        bool blocked;
}