#ifndef HARVESTERMANAGER_H
#define HARVESTERMANAGER_H

#include <vector>
#include "Land.h"
#include "Vehicle.h"

class HarvesterManager : public Vehicle
{
public:
	HarvesterManager(std::vector<Land>* land, int startingAmount, int rate, int fuelCapacity);
	int Harvest();
};
#endif