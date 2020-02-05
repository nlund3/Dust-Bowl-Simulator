#include "Shop.h"
#include <iostream>

#define NOT_ENOUGH std::cout << "You Don't Have Enough Monies To Buy This\n\n";

#pragma region Constructor Definition
Shop::Shop(int* shopCash, int* shopSeeds, int* shopFuel, int* shopHarvesters, int* shopPlanters, bool discount)
{
	if (discount)
	{
		harvesterPrice = 500;
		planterPrice = 100;
	}
	else
	{
		harvesterPrice = 5000;
		planterPrice = 1000;
	}

	cash = shopCash;
	seeds = shopSeeds;
	fuel = shopFuel;
	harvesters = shopHarvesters;
	planters = shopPlanters;
}
#pragma endregion

#pragma region Member Function Definitions
#pragma region Getters
int Shop::GetSeedPrice()
{
	return SEED_PRICE;
}

int Shop::GetFuelPrice()
{
	return FUEL_PRICE;
}

int Shop::GetHarvesterPrice()
{
	return harvesterPrice;
}

int Shop::GetPlanterPrice()
{
	return planterPrice;
}
#pragma endregion

#pragma region Buying
void Shop::BuySeeds(int amount)
{
	if (*cash >= (amount * SEED_PRICE))
	{
		*seeds = amount;
	}
	else
	{
		NOT_ENOUGH
	}
}

void Shop::BuyFuel(int amount)
{
	if (*cash >= (amount * FUEL_PRICE))
	{
		*fuel = amount;
	}
	else
	{
		NOT_ENOUGH
	}
}

void Shop::BuyHarvesters(int amount)
{
	if (*cash >= (amount * harvesterPrice))
	{
		*harvesters = amount;
	}
	else
	{
		NOT_ENOUGH
	}
}

void Shop::BuyPlanters(int amount)
{
	if (*cash >= (amount * planterPrice))
	{
		*planters = amount;
	}
	else
	{
		NOT_ENOUGH
	}
}
#pragma endregion

#pragma region Other
void Shop::CheckOut()
{
	*cash -= (*seeds * SEED_PRICE) + (*fuel * FUEL_PRICE) + (*harvesters * harvesterPrice);
}

#pragma endregion
#pragma endregion