#include "Fiat.h"

Fiat::Fiat() : fuelCapacity(40.0),
fuelConsumption(5.0),
speedSunny(100.0),
speedRainy(80.0),
speedSnowy(65.0),
brand("Fiat") {};

double Fiat::getFuelCapacity() {
	return this->fuelCapacity;
}

double Fiat::getFuelConsumption() {
	return this->fuelConsumption;
}

double Fiat::getAverageSpeed(Weather weather) {
	switch (weather) {
	case Sunny: return this->speedSunny;
	case Rainy: return this->speedRainy;
	case Snowy: return this->speedSunny;
	}
}

double Fiat::calculateTime(double distance, Weather weather) {
	return distance / this->getAverageSpeed(weather);
}
const char* Fiat::getBrand() {
	return this->brand;
}