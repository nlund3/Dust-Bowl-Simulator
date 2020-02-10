// Example program
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "Shop.h"
#include "Land.h"
#include "HarvesterManager.h"
#include "PlanterManager.h"

void Log(std::string text)
{
	std::cout << text << std::endl;
}

void Clear()
{
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif
}

std::string ToString(int x)
{
	return std::to_string(x);
}

int Input()
{
	int input;

	do
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> input;
	} while (!std::cin.good() || input < 0);

	Clear();
	return input;
}

void OkScreen(std::string message)
{
	Log(message);
	Log("Enter Any Number To Continue");
	int input = Input();
}

int main()
{
	int a = 5;
	int* b = &a;

	//Buy Seeds
	//Buy Resources
	//Plant Crops
	//Day
		//Chance of dustbowl
		//Crops grow
		//Resources get used
	//Harvest if no dustbowl
	//Repeat

	std::vector<Land>* land = new std::vector<Land>(); //Each land can hold 100 seeds

	int monies = 0;
	int seedSupply = 0;
	int fuelSupply = 0;

	PlanterManager planters = PlanterManager(land, 0, 1, 2);
	HarvesterManager harvesters = HarvesterManager(land, 0, 1, 2);
	
	//HarvesterManager harvesters = HarvesterManager(land, 0);
	int cropSupply = 0;
	int workers;
	
	
	int difficulty;
	std::string gameType;
	int daysToMature = 200;
	bool harvesterDiscount = false;
	
	double smolDustBowlChance = 0.05;
	double dustBowlChance = 0.01;

	Log("Dust Bowl Simulator");
	Log("Version: I lost count");
	Log("Developed By: CoolGuyPro1001\n");

	Log("ONLY ENTER IN NUMBERS OR IT WILL NOT WORK. EVEN IF IT SAYS TO PRESS ANY KEY");
	Log("Enter any NUMBER to start");
	Input();

	//Scam Warning Reference
	Log("THIS GAME MUST NOT BE SOLD,");
	Log("NEITHER ALONE NOR AS PART OF A BUNDLE\n");

	Log("IF YOU PAID FOR THIS GAME OR RECEIVED");
	Log("IT AS PART OF A BUNDLE FOLLOWING PAYMENT,");
	Log("YOU HAVE BEEN SCAMMED AND SHOULD");
	Log("DEMAND YOUR MONEY BACK IMMEDIATELY\n");

	Log("Enter Any Number To Continue");
	Input();
	do
	{
		Log("Choose Your Game Type");
		Log("Peasant (Enter 0)");
		Log("Industrial Farmer (Enter 1)");
		Log("Experimental Farmer (Enter 2)");
		Log("YEE HAW (Enter 3)");
		Log("Info (Enter 4)");

		difficulty = Input();
		switch (difficulty)
		{
		case 0:
			monies = 7500;
			land->resize(10, Land(daysToMature));
			gameType = "Peasant";
			break;
		case 1:
			monies = 20000;
			land->resize(50, Land(daysToMature));
			harvesterDiscount = true;
			gameType = "Industrial Farmer";
			break;
		case 2:
			monies = 20000;
			daysToMature = 50;
			land->resize(5, Land(daysToMature));

			gameType = "Experimental Farmer";
			break;
		case 3:
			monies = 1000000;
			daysToMature = 5;
			land->resize(1000, Land(daysToMature));
			harvesterDiscount = true;
			smolDustBowlChance = 0.15;
			dustBowlChance = 0.03;
			gameType = "YEE HAW";
			break;
		case 4:
			Log("Here is a table of what each mode will give you");
			Log("               __________________________________________________________________________________________________________");
			Log("              | Monies|Land|Vehicle Discount|Days To Mature (Per 100)|Chance Of Small Dust Bowl|Chance of Large Dust Bowl|");
			Log("Peasant:      |   7500|  10|              No|                     200|                       5%|                       1%|");
			Log("Industrial:   |  20000|  50|             Yes|                     200|                       5%|                       1%|");
			Log("Experimental: |  20000|   5|              No|                      50|                       5%|                       1%|");
			Log("YEE HAW:      |1000000|1000|             Yes|                       5|                      15%|                       3%|");

			Log("\nEach land holds up to 100 seeds and produce up to 100 crops + 110 seeds");
			Log("The amount of days it takes for seeds in a land to become ready to harvest is depends on how many there are. days = seeds * 2");
			Log("Small dust bowls wipe out half the crops per land");
			Log("Large dust bowls wipe EVERYTHING\n");

			Log("Enter Any Number To Continue");
			Input();
			break;
		}
	} while (difficulty >= 4 || difficulty < 0);

	//What would you like to do?
	while (monies > 0 || land->size() > 0 || seedSupply > 0 || fuelSupply > 0 || harvesters.GetVehicles() > 0 || cropSupply > 0)
	{
		
		
		Log("Land:");
		int i = 0;
		while(i < land->size())
		{
			std::string seeds = ToString((*land)[i].GetSeedCount());
			std::string days = ToString((*land)[i].GetDaysUntilMaturity());

			Log("Land " + ToString(i) + "(Seeds: " + seeds + ", Days Until Maturity: " + days + ")");
			i++;
		}
		Log("");
		
		Log("Game Type: " + gameType);
		Log("Skip Days (Enter 0)");
		Log("Buy Supplies (Enter 1)");
		Log("Planters (Enter 2)");
		Log("Harvesters (Enter 3)");
		Log("Expand Farm (Enter 4)");
		Log("Sell (Enter 5)\n");

		Log("Monies: " + ToString(monies));
		Log("Seeds: " + ToString(seedSupply));
		Log("Fuel: " + ToString(fuelSupply));
		Log("Planters: " + ToString(planters.GetVehicles()));
			Log("    Fuel: " + ToString(planters.GetFuel()));
			Log("    Amount Active" + ToString(planters.GetVehiclesActive()));
			Log("    Planting Days Left: " + ToString(planters.GetOperatingDaysLeft()));
			Log("    Current Planter Location: " + ToString(planters.GetLastLandOperated()));
		Log("Harvesters: " + ToString(harvesters.GetVehicles()));
			Log("    Fuel: " + ToString(harvesters.GetFuel()));
			Log("    Amount Active" + ToString(harvesters.GetVehiclesActive()));
			Log("    Harvesting Days Left: " + ToString(harvesters.GetOperatingDaysLeft()));
			Log("    Current Harvester Location: " + ToString(harvesters.GetLastLandOperated()));
		Log("Crops: " + ToString(cropSupply) + "\n");

		int choice = Input();
	    
		switch (choice)
		{
			//Time Travel
			case 0:
			{
				Log("Skip How Many Days?");
				int days = Input();
				
				for (int l = 0; l < land->size(); l++)
				{
					(*land)[l].TimeTravel(days);
				}
				break;
			}

			//Farmer Shop
			case 1:
			{
				int* shoppingCash = &monies;
				int* seedsInBasket = new int;
				int* fuelInBasket = new int;
				int* harvestersInBasket = new int;
				int* plantersInBasket = new int;
				std::vector<Land>* landInBasket = new std::vector<Land>();

				Shop farmerShop = Shop(shoppingCash, seedsInBasket, fuelInBasket, harvestersInBasket, plantersInBasket, landInBasket, harvesterDiscount);

				*seedsInBasket = 0;
				*fuelInBasket = 0;
				*harvestersInBasket = 0;
				*plantersInBasket = 0;

				int seedPrice = farmerShop.GetSeedPrice();
				int fuelPrice = farmerShop.GetFuelPrice();
				int harvesterPrice = farmerShop.GetHarvesterPrice();
				int planterPrice = farmerShop.GetPlanterPrice();
				int landPrice = farmerShop.GetLandPrice();

				int seedsCost;
				int fuelCost;
				int harvesterCost;
				int planterCost;
				int landCost;
				int totalCost;

				bool inStore = true;
				while (inStore)
				{
					seedsCost = *seedsInBasket * seedPrice;
					fuelCost = *fuelInBasket * fuelPrice;
					harvesterCost = *harvestersInBasket * harvesterPrice;
					planterCost = *plantersInBasket * planterPrice;
					landCost = landInBasket->size() *landPrice;
					totalCost = seedsCost + fuelCost + planterCost + harvesterCost + landCost;

					Log("Farm Shop. Buy Something!");
					Log("$" + ToString(seedPrice) + " Seeds (Enter 0)");
					Log("$" + ToString(fuelPrice) + " Harvester Fuel (Enter 1)");
					Log("$" + ToString(planterPrice) + " Planters (Enter 2)");
					Log("$" + ToString(harvesterPrice) + " Harvesters (Enter 3)");
					Log("$" + ToString(landPrice) + " Land (Enter 4)");
					Log("Leave Store (Enter 5) \n");

					Log("Seeds: " + ToString(*seedsInBasket) + " | $" + ToString(seedsCost));
					Log("Fuel: " + ToString(*fuelInBasket) + " | $" + ToString(fuelCost)); 
					Log("Planters: " + ToString(*plantersInBasket) + "| $" + ToString(planterCost));
					Log("Harvesters: " + ToString(*harvestersInBasket) + " | $" + ToString(harvesterCost));
					Log("Land: " + ToString(landInBasket->size()) + " | $" + ToString(landCost));
					Log("Total: $" + ToString(totalCost));
					

					int shoppingChoice = Input();

					switch (shoppingChoice)
					{
						int amount;
						case 0:
							Log("How Many?");
							Log("Monies: " + ToString(*shoppingCash));
							amount = Input();

							farmerShop.BuySeeds(amount);
							break;
						case 1:
							Log("How Many?");
							Log("Monies: " + ToString(*shoppingCash));
							amount = Input();

							farmerShop.BuyFuel(amount);
							break;
						case 2:
							Log("How Many?");
							Log("Monies: " + ToString(*shoppingCash));
							amount = Input();

							farmerShop.BuyPlanters(amount);
							break;
						case 3:
							Log("How Many?");
							Log("Monies: " + ToString(*shoppingCash));
							amount = Input();

							farmerShop.BuyHarvesters(amount);
							break;
						case 4:
							Log("How Many?");
							Log("Monies: " + ToString(*shoppingCash));
							amount = Input();

							farmerShop.BuyLand(amount, daysToMature);
							break;
						case 5:
							if (totalCost <= *shoppingCash)
							{
								farmerShop.CheckOut();
								OkScreen("Pleasure Doing Business With You");
								inStore = false;
							}
							else
							{
								OkScreen("Not Enough Monies");
							}
							break;
					}
				}

				monies = *shoppingCash;
				seedSupply += *seedsInBasket;
				fuelSupply += *fuelInBasket;
				harvesters.AddVehicles(*harvestersInBasket);
				planters.AddVehicles(*plantersInBasket);
				
				//if (landInBasket->size() > (land->capacity() - land->size())
				//{
				//	try
				//	{
				//		land.resize(landI)
				//	}
			//	}
			//	land->insert(land->end(), landInBasket->begin(), landInBasket->end());

				delete seedsInBasket, fuelInBasket, harvestersInBasket, plantersInBasket, landInBasket;
			}
				break;
			case 2:
			{
				Log("Refuel (Enter 1");
				Log("Plant (Enter 2)");

				int planterChoice = Input();
				switch (planterChoice)
				{
					case 1:
					{
						Log("Enter amount of fuel you want to use to refuel");
						int fuel = Input();
						if (fuel > fuelSupply)
						{
							OkScreen("Not enough fuel in fuel supply");
						}
						else
						{
							int overFill = planters.AddFuel(fuel);
							fuelSupply -= fuel + overFill;
						}
						break;
					}
					case 2:
					{
						if (land->size() > 0)
						{
							Log("How Many Planters Do You Want To Use");
							int amountToPlant = Input();

							while (amountToPlant > planters.GetVehicles())
							{
								OkScreen("Not Enough Planters");
								Log("How Many Planters Do You Want To Use");
								amountToPlant = Input();
							}

							planters.SetActive(amountToPlant);
							OkScreen("Planting Land");
							seedSupply -= planters.Plant();
						}
						else
						{
							OkScreen("How Can You Plant Seeds On Land If You Don't Have Any?");
						}
						break;
					}
				}
				break;
			}
			case 3:
			{
				Log("Refuel (Enter 1");
				Log("Harvest (Enter 2)");

				int planterChoice = Input();
				switch (planterChoice)
				{
				case 1:
				{
					Log("Enter amount of fuel you want to use to refuel");
					int fuel = Input();
					if (fuel > fuelSupply)
					{
						OkScreen("Not enough fuel in fuel supply");
					}
					else
					{
						int overFill = planters.AddFuel(fuel);
						fuelSupply -= fuel + overFill;
					}
					break;
				}
				case 2:
				{
					if (land->size() > 0)
					{
						Log("How Many Harvesters Do You Want To Use");
						int amountToPlant = Input();

						while (amountToPlant > planters.GetVehicles())
						{
							OkScreen("Not Enough Harvesters");
							Log("How Many Harvesters Do You Want To Use");
							amountToPlant = Input();
						}

						planters.SetActive(amountToPlant);
						OkScreen("Harvesting Land");
						seedSupply -= planters.Plant();
					}
					else
					{
						OkScreen("How Can You Harvest Land If You Don't Have Any?");
					}
					break;
				}
				}
				break;
			}
		}
	}

	Log("Oops you ran out of money. Better luck next time!");
}