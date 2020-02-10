#ifndef SHOP_H
#define SHOP_H

#include<vector>
#include "Land.h"

class Shop
{
private:
	const int SEED_PRICE = 3;
	const int FUEL_PRICE = 1;
	const int CROP_PRICE = 6;
	const int LAND_PRICE = 1000;
	int harvesterPrice;
	int planterPrice;

	int* cash;
	int* seeds;
	int* fuel;
	int* harvesters;
	int* planters;
	std::vector<Land>* land;

public:
	Shop(int* shopCash, int* shopSeeds, int* shopFuel, int* shopHarvesters, int* shopPlanters, std::vector<Land>* shopLand, bool discount);
	 
	int GetSeedPrice();
	int GetFuelPrice();
	int GetHarvesterPrice();
	int GetPlanterPrice();
	int GetLandPrice();

	void BuySeeds(int amount);
	void BuyFuel(int amount);
	void BuyHarvesters(int amount);
	void BuyPlanters(int amount);
	void BuyLand(int amount, int daysUntilMaturity);

	void CheckOut();
};
#endif