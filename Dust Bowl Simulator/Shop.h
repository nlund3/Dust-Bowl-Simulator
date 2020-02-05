#ifndef SHOP_H
#define SHOP_H

class Shop
{
private:
	const int SEED_PRICE = 3;
	const int FUEL_PRICE = 1;
	const int CROP_PRICE = 6;
	int harvesterPrice;
	int planterPrice;

	int* cash;
	int* seeds;
	int* fuel;
	int* harvesters;
	int* planters;

public:
	Shop(int* shopCash, int* shopSeeds, int* shopFuel, int* shopHarvesters, int* shopPlanters, bool discount);

	int GetSeedPrice();
	int GetFuelPrice();
	int GetHarvesterPrice();
	int GetPlanterPrice();

	void BuySeeds(int amount);
	void BuyFuel(int amount);
	void BuyHarvesters(int amount);
	void BuyPlanters(int amount);

	void CheckOut();
};
#endif