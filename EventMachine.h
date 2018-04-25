// Copyright Carmel

#include "linked_queue.h"

class EventMachine {
    private:
        int occurred = 0;

    public:
        explicit EventMachine(int whenOccurred);
        virtual ~EventMachine();
        virtual void log();

        virtual LinkedQueue<EventMachine*> runEvent();
};

