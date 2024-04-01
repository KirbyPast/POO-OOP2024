#include "Seat.h"

Seat::Seat() : fuelCapacity(35.0),
fuelConsumption(4.0),
speedSunny(90.0),
speedRainy(70.0),
speedSnowy(45.0),
brand("Seat"){};

double Seat::getFuelCapacity() {
	return this->fuelCapacity;
}

double Seat::getFuelConsumption() {
	return this->fuelConsumption;
}

double Seat::getAverageSpeed(Weather weather) {
	switch (weather) {
	case Sunny: return this->speedSunny;
	case Rainy: return this->speedRainy;
	case Snowy: return this->speedSunny;
	}
}

double Seat::calculateTime(double distance, Weather weather) {
	return distance / this->getAverageSpeed(weather);
}

const char* Seat::getBrand() {
	return this->brand;
}