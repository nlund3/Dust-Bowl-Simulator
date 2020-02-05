#ifndef PLANTERMANAGER_H
#define PLANTERMANAGER_H

#include <vector>
#include "Vehicle.h"

class PlanterManager : public Vehicle
{
public:
	PlanterManager(std::vector<Land>* land, int startingAmount, int rate, int fuelCapacity);
	int Plant();
};
#endif
