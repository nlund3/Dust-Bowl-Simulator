#include "PlanterManager.h"
#include "Land.h"
#include "Vehicle.h"

PlanterManager::PlanterManager(std::vector<Land>* land, int startingVehicleCount, int rate, int fuelCapacity)
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

int PlanterManager::Plant()
{
	int seedsPlanted = 0;

	for (int i = 0; i < (amountActive * operatingRate); i++)
	{
		int index = i + lastLandOperated;
		int landCapacity = (*land)[i].GetSeedCapacity();

		if ((*land)[i].GetSeedCount() == 0)
		{
			if (totalFuel > 0)
			{
				seedsPlanted += landCapacity;
				(*land)[index].SetSeedCount(0);
				totalFuel -= landCapacity;
				lastLandOperated++;
			}
			else

			{
				return seedsPlanted;
			}
		}
	}
	operatingDaysLeft = (land->size() / amountActive) * lastLandOperated;
	return seedsPlanted;
}