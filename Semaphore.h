// Copyright Matheus Lucca do Carmo

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

class Semaphore {
    private:
        Semaphore* nextSemaphore;
        bool isOpen;

    public:
        Semaphore();
        Semaphore(bool isOpen_);

        void turnSempahores();
        
        bool isOpenState() const;
        void setNext(Semaphore* semaphore_);
};

#endif 