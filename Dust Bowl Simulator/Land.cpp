#include "Land.h"

Land::Land(int days)
{
	daysUntilMaturity = days;
}

int Land::GetSeedCount()
{
	return seedCount;
}

int Land::GetSeedCapacity()
{
	return CAPACITY;
}

int Land::GetDaysUntilMaturity()
{
	return daysUntilMaturity;
}

void Land::SetSeedCount(int seeds)
{
	seedCount = seeds;
}

void Land::TimeTravel(int days)
{
	if (seedCount > 0 && daysUntilMaturity > 0)
	{
		daysUntilMaturity -= days;
	}
}