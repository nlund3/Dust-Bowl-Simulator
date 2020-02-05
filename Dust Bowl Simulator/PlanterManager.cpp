#include "PlanterManager.h"
#include "Land.h"
#include "Vehicle.h"

PlanterManager::PlanterManager(std::vector<Land>* land, int startingVehicleCount, int rate, int fuelCapacity) :
	Vehicle(land, startingVehicleCount, rate, fuelCapacity)
{

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