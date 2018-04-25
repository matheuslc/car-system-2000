// Copyright Carmel

#include "Semaphore.h"

Semaphore::Sempahore() {
    isOpen = false;
    nextSemaphore{nullptr}
}

// Override constructor
Semaphore::Semaphore(bool state) {
    isOpen = state;
    nextSemaphore{nullptr}
}

void Semaphore::turnSempahores {
    isOpen = !isOpen; // se é true é false se é false é true
    nextSemaphore->isOpen = !(nextSemaphore->open);
}

void Semaphore::setNext(Semaphore* semaphore) {
	nextSemaphore = semaphore;
}

bool Semaphore::isOpenState() {
    return isOpen;
}