// Copyright Matheus Lucca do Carmo

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