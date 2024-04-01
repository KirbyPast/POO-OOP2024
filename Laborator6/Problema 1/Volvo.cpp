#include "Volvo.h"

Volvo::Volvo() : fuelCapacity(40.0),
fuelConsumption(3.0),
speedSunny(70.0),
speedRainy(50.0),
speedSnowy(35.0),
brand("Volvo"){};

double Volvo::getFuelCapacity() {
	return this->fuelCapacity;
}

double Volvo::getFuelConsumption() {
	return this->fuelConsumption;
}

double Volvo::getAverageSpeed(Weather weather) {
	switch (weather) {
	case Sunny: return this->speedSunny;
	case Rainy: return this->speedRainy;
	case Snowy: return this->speedSunny;
	}
}

double Volvo::calculateTime(double distance, Weather weather) {
	return distance / this->getAverageSpeed(weather);
}

const char* Volvo::getBrand() {
	return this->brand;
}