#include "Circuit.h"
#include "stdlib.h"
#include "algorithm"

Circuit::Circuit() : length(100.0), weather(Sunny), numberOfCars(0), cars(nullptr), capacity(0) {
};

void Circuit::AddCar(Car* car) {
	if (numberOfCars >= capacity) {
		capacity += 5; 
		Car** temp = new Car * [capacity];
		for (int i = 0; i < numberOfCars; ++i) {
			temp[i] = cars[i];
		}
		delete[] cars;
		cars = temp;
	}
	cars[numberOfCars++] = car;
}

void Circuit::SetLength(double length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}

void Circuit::Race() {
	for (int i = 0; i < numberOfCars - 1; i++) {
		for (int j = i + 1; j < numberOfCars; j++) {
			double time1 = cars[i]->calculateTime(this->length, this->weather);
			double time2 = cars[j]->calculateTime(this->length, this->weather);
			if (time2 < time1) {
				std::swap(cars[i], cars[j]);
			}
		}
	}
}

void Circuit::ShowFinalRanks() {
	int placement = 0;
		for (int i = 0; i < numberOfCars; i++) {
			if (cars[i]->calculateTime(this->length, this->weather) <= cars[i]->getFuelCapacity() / cars[i]->getFuelConsumption()) {
				printf("Car %d who finished: %s in %lf\n", ++placement, cars[i]->getBrand(), cars[i]->calculateTime(this->length, this->weather));
			}
		}
}

void Circuit::ShowWhoDidNotFinish() {
	int placement = 0;
	for (int i = 0; i < numberOfCars; i++) {
		if (cars[i]->calculateTime(this->length, this->weather) > cars[i]->getFuelCapacity() / cars[i]->getFuelConsumption())
			printf("Car %d who DNF: %s in %lf\n", ++placement, cars[i]->getBrand(), cars[i]->calculateTime(this->length, this->weather));
	}
}


Circuit::~Circuit() {
	for (int i = 0; i < capacity; ++i) {
		delete cars[i];
	}
	delete[] cars;
}