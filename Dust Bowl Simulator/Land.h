#ifndef LAND_H
#define LAND_H

struct Land
{
private:
	short seedCount = 0;
	int daysUntilMaturity;
	short CAPACITY = 100;
public:
	Land(int days);
	short GetSeedCount();
	short GetSeedCapacity();
	int GetDaysUntilMaturity();
	void SetSeedCount(short seeds);
	void TimeTravel(int days);
};

#endif