#include "Vehicle.h"
#include "Land.h"

Vehicle::Vehicle(std::vector<Land>* land, int startingVehicleCount, int rate, int fuelCapacity)
{
	this->land = land;
	amountOfVehicles = startingVehicleCount;
	totalFuel = 0;
	operatingDaysLeft = 0;
	lastLandOperated = 0;
	amountActive = 0;
	operatingRate = rate;
	maxFuelCapacity = fuelCapacity;
}

int Vehicle::GetVehicles()
{
	return amountOfVehicles;
}

int Vehicle::GetFuel()
{
	return totalFuel;
}

int Vehicle::GetLastLandOperated()
{
	return lastLandOperated;
}

int Vehicle::GetOperatingDaysLeft()
{
	return operatingDaysLeft;
}

int Vehicle::GetVehiclesActive()
{
	return amountActive;
}

int Vehicle::AddFuel(int addFuel)
{
	if ((totalFuel + addFuel) >= (maxFuelCapacity * amountOfVehicles))
	{
		int overFill = (totalFuel + addFuel) - (maxFuelCapacity * amountOfVehicles);
		totalFuel += addFuel - overFill;
		return overFill;
	}
	else
	{
		totalFuel += addFuel;
		return 0;
	}
}

int Vehicle::AddFuelMax()
{
	int fuelRemaining = maxFuelCapacity - totalFuel;
	totalFuel += fuelRemaining;
	return fuelRemaining;
}

void Vehicle::AddVehicles(int num)
{
	amountOfVehicles += num;
}

void Vehicle::RemoveVehicles(int num)
{
	amountOfVehicles -= num;
}