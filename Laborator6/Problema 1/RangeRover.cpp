#include "RangeRover.h"

RangeRover::RangeRover() : fuelCapacity(45.0),
fuelConsumption(2.5),
speedSunny(65.0),
speedRainy(55.0),
speedSnowy(45.0) ,
brand("RangeRover"){};

double RangeRover::getFuelCapacity() {
	return this->fuelCapacity;
}

double RangeRover::getFuelConsumption() {
	return this->fuelConsumption;
}

double RangeRover::getAverageSpeed(Weather weather) {
	switch (weather) {
	case Sunny: return this->speedSunny;
	case Rainy: return this->speedRainy;
	case Snowy: return this->speedSunny;
	}
}

double RangeRover::calculateTime(double distance, Weather weather) {
	return distance / this->getAverageSpeed(weather);
}

const char* RangeRover::getBrand() {
	return this->brand;
}