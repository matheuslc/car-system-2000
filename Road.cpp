#include "Road.h"
#include <cstdlib>

Road::Road(Semaphore& semaphore, int size, int max_velocity,
		double probLeft, double probRight):
	semaphore(semaphore),
	size(size),
	max_velocity(max_velocity),
	probLeft(probLeft),
	probRight(probRight) {}

void Road::add(Vehicle v) {
	if (v.getSize() > size) {
		throw std::runtime_error("Road currently full");
	}

	size -= v.getSize();
	in++;
	totalIn_++;
	queue.enqueue(v);
}

Vehicle Road::pop() {
	auto v = queue.dequeue();
	size += v.getSize();
	out++;
	totalOut_++;
	return v;
}

bool Road::empty() {
	return queue.empty();
}

Road& Road::moveVehicle() {
	throw std::logic_error("Road::moveVehicle not implemented");
}

int Road::timeToTravel() const {
	return size / velocity / 3.6;
}

int Road::entered() const {
	return in;
}

int Road::left() const {
	return out;
}

int Road::areIn() const {
	return in-out;
}

int Road::totalIn() {
	return totalIn_;
}

int Road::totalOut() {
	return totalOut_;
}

CentralRoad::CentralRoad(Semaphore& semaphore, int size, int velocity,
		Road& rightExit, Road& straightExit, Road& leftExit,
		double probLeft, double probRight):
    Road(semaphore, size, velocity, probLeft, probRight),
	rightExit(rightExit),
	straightExit(straightExit),
	leftExit(leftExit) {}


Road& CentralRoad::moveVehicle() {
	if (!semaphore.getOpen())
		throw std::runtime_error("Red Semaphore");

	double r = rand()/RAND_MAX;
	auto v = pop();

	if (r > probRight) {
		rightExit.add(v);
		return rightExit;
	} else if (r < probLeft) {
		leftExit.add(v);
		return leftExit;
	}  else {
		straightExit.add(v);
		return straightExit;
	}
}

Source::Source(Semaphore& semaphore, int size, int velocity, int fixedFrequency,
		int variableFrequency, Road& rightExit, Road& straightExit,
		Road& leftExit, double probLeft, double probRight):
	Road(semaphore, size, velocity, probLeft, probRight),
	fixedFrequency(fixedFrequency - variableFrequency),
	variableFrequency(2*variableFrequency),
	rightExit(rightExit),
	straightExit(straightExit),
	leftExit(leftExit) {}

void Source::createVehicle() {
	Vehicle v;
	add(v);
}

Road& Source::moveVehicle() {
	if (!semaphore.getOpen())
		throw std::runtime_error("Red Semaphore");

	double r = (rand())/RAND_MAX;
	auto v = pop();

	if (r > probRight) {
		rightExit.add(v);
		return rightExit;
	} else if (r < probLeft) {
		leftExit.add(v);
		return leftExit;
	}  else {
		straightExit.add(v);
		return straightExit;
	}
}

int Source::nextEventsTime(int time) {
	return time + fixedFrequency + variableFrequency * float(rand())/RAND_MAX;
}

ExitRoad::ExitRoad(Semaphore& semaphore, int size, int velocity):
	Road(semaphore, size, velocity, 0, 0) {}