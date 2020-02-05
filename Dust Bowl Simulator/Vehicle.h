#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include "Land.h"
class Vehicle
{
protected:
	std::vector<Land>* land;
	int amountOfVehicles;
	int totalFuel;
	int lastLandOperated;
	int operatingDaysLeft;
	int amountActive;
	int maxFuelCapacity;
	int operatingRate;

public:
	Vehicle(std::vector<Land>* land, int startingAmount, int rate, int fuelCapacity);
	int GetVehicles();
	int GetFuel();
	int GetOperatingDaysLeft();
	int GetLastLandOperated();
	int GetVehiclesActive();

	int AddFuel(int addFuel); //returns spill over
	int AddFuelMax(); //returns how much fuel it took to fill it up
	void AddVehicles(int num);
	void RemoveVehicles(int num);
};
#endif
