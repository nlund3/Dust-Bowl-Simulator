#ifndef LAND_H
#define LAND_H

struct Land
{
private:
	int seedCount = 0;
	int daysUntilMaturity;
	int CAPACITY = 100;
public:
	Land(int days);
	int GetSeedCount();
	int GetSeedCapacity();
	int GetDaysUntilMaturity();
	void SetSeedCount(int seeds);
	void TimeTravel(int days);
};

#endif