#include "Land.h"

Land::Land(int days)
{
	daysUntilMaturity = days;
}

short Land::GetSeedCount()
{
	return seedCount;
}

short Land::GetSeedCapacity()
{
	return CAPACITY;
}

int Land::GetDaysUntilMaturity()
{
	return daysUntilMaturity;
}

void Land::SetSeedCount(short seeds)
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