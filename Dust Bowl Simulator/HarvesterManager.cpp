#include "HarvesterManager.h"

HarvesterManager::HarvesterManager(std::vector<Land>* land, int startingAmount, int rate, int fuelCapacity) :
	Vehicle(land, startingAmount, rate, fuelCapacity)
{

}

int HarvesterManager::Harvest()
{
	int seedsYielded = 0;

	for (int i = 0; i < (amountActive * operatingRate); i++)
	{
		int index = i + lastLandOperated;
		int seeds = (*land)[index].GetSeedCount();
		int daysUntilMaturity = (*land)[index].GetDaysUntilMaturity();

		if (seeds > 0 && daysUntilMaturity == 0)
		{
			if (totalFuel > 0)
			{
				seedsYielded += seeds;
				(*land)[index].SetSeedCount(0);
				totalFuel -= seeds;
				lastLandOperated++;
			}
			else

			{
				return seedsYielded;
			}
		}
	}
	operatingDaysLeft = (land->size() / amountActive) * lastLandOperated;
	return seedsYielded;
}