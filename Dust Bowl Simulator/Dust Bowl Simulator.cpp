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
	} while (!(std::cin >> input));
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
	PlanterManager p = PlanterManager(land, 0, 1, 2);
	HarvesterManager h = HarvesterManager(land, 0, 1, 2);

	Vehicle* planters = &p;
	Vehicle* harvesters = &h;
	
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
		Log("Peasant (Enter 1)");
		Log("Industrial Farmer (Enter 2)");
		Log("Experimental Farmer (Enter 3)");
		Log("YEE HAW (Enter 4)");
		Log("Info (Enter 5)");

		difficulty = Input();
		if (difficulty < 5)
		{
			switch (difficulty)
			{
			case 1:
				monies = 1000;
				land->resize(10, Land(daysToMature));
				gameType = "Peasant";
				break;
			case 2:
				monies = 5000;
				land->resize(50, Land(daysToMature));
				harvesterDiscount = true;
				gameType = "Industrial Farmer";
				break;
			case 3:
				monies = 5000;
				daysToMature = 50;
				land->resize(5, Land(daysToMature));

				gameType = "Experimental Farmer";
			case 4:
				monies = 1000000;
				daysToMature = 5;
				land->resize(1000, Land(daysToMature));
				harvesterDiscount = true;
				smolDustBowlChance = 0.15;
				dustBowlChance = 0.03;
				gameType = "YEE HAW";
			}
		}
		else
		{
			Log("Here is a table of what each mode will give you");
			Log("               _____________________________________________________________________________________________________________");
			Log("              | Monies|Land|Harvesting Discount|Days To Mature (Per 100)|Chance Of Small Dust Bowl|Chance of Large Dust Bowl|");
			Log("Peasant:      |   1000|  10|                 No|                     200|                       5%|                       1%|");
			Log("Industrial:   |   5000|  50|                Yes|                     200|                       5%|                       1%|");
			Log("Experimental: |   5000|   5|                 No|                      50|                       5%|                       1%|");
			Log("YEE HAW:      |1000000|1000|                Yes|                       5|                      15%|                       3%|");

			Log("\nEach land holds up to 100 seeds and produce up to 100 crops + 110 seeds");
			Log("The amount of days it takes for seeds in a land to become ready to harvest is depends on how many there are. days = seeds * 2");
			Log("Small dust bowls wipe out half the crops per land");
			Log("Large dust bowls wipe EVERYTHING\n");

			Log("Enter Any Number To Continue");
			int input = Input();
		}
	} while (difficulty == 5);

	//What would you like to do?
	while (monies > 0 || land->size() > 0 || seedSupply > 0 || fuelSupply > 0 || harvesters->GetVehicles() > 0 || cropSupply > 0)
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
		Log("\nWhat Would You Like To Do?");
		Log("Buy Supplies (Enter 1)");
		Log("Plant Seeds (Enter 2)");
		Log("Refuel Harvesters (Enter 3)");
		Log("Harvest (Enter 4)");
		Log("Expand Farm (Enter 5)");
		Log("Sell (Enter 6)\n");

		Log("Monies: " + ToString(monies));
		Log("Seeds: " + ToString(seedSupply));
		Log("Fuel: " + ToString(fuelSupply));
		Log("Harvesters: " + ToString(harvesters->GetVehicles()));
			Log("    Fuel: " + ToString(harvesters->GetFuel()));
			Log("    Harvesting Days Left: " + ToString(harvesters->GetOperatingDaysLeft()));
			Log("    Land Pointer: " + ToString(harvesters->GetLastLandOperated()));
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

				Shop farmerShop = Shop(shoppingCash, seedsInBasket, fuelInBasket, harvestersInBasket, plantersInBasket, harvesterDiscount);

				*seedsInBasket = 0;
				*fuelInBasket = 0;
				*harvestersInBasket = 0;

				int seedPrice = farmerShop.GetSeedPrice();
				int fuelPrice = farmerShop.GetFuelPrice();
				int harvesterPrice = farmerShop.GetHarvesterPrice();
				int planterPrice = farmerShop.GetPlanterPrice();

				int seedsCost;
				int fuelCost;
				int harvesterCost;
				int planterCost;
				int totalCost;

				bool inStore = true;
				while (inStore)
				{
					seedsCost = *seedsInBasket * seedPrice;
					fuelCost = *fuelInBasket * fuelPrice;
					harvesterCost = *harvestersInBasket * harvesterPrice;
					planterCost = *plantersInBasket * planterPrice;
					totalCost = seedsCost + fuelCost + harvesterCost;

					Log("Farm Shop. Buy Something!");
					Log("$" + ToString(seedPrice) + " Seeds (Enter 1)");
					Log("$" + ToString(fuelPrice) + " Harvester Fuel (Enter 2)");
					Log("$" + ToString(harvesterPrice) + " Harvesters (Enter 3)");
					Log("Leave Store (Enter 4) \n");

					Log("Seeds: " + ToString(*seedsInBasket) + " | $" + ToString(seedsCost));
					Log("Fuel: " + ToString(*fuelInBasket) + " | $" + ToString(fuelCost)); 
					Log("Harvesters: " + ToString(*harvestersInBasket) + " | $" + ToString(harvesterCost));
					Log("Total: $" + ToString(totalCost));
					

					int shoppingChoice = Input();

					switch (shoppingChoice)
					{
						int amount;
					case 1:
						Log("How Many?");
						Log("Monies: " + ToString(*shoppingCash));
						amount = Input();

						farmerShop.BuySeeds(amount);
						break;
					case 2:
						Log("How Many?");
						Log("Monies: " + ToString(*shoppingCash));
						amount = Input();

						farmerShop.BuyFuel(amount);
						break;
					case 3:
						Log("How Many?");
						Log("Monies: " + std::to_string(*shoppingCash));
						amount = Input();

						farmerShop.BuyHarvesters(amount);
						break;
					case 4:
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
				harvesters->AddVehicles(*harvestersInBasket);
				planters->AddVehicles(*plantersInBasket);

				delete seedsInBasket, fuelInBasket, harvestersInBasket, plantersInBasket;
			}
				break;
			case 2:
			{
				if (land->size() > 0)
				{
					Log("Which Land Do You Want To Plants Seeds In?");
					Log("You have land 0 to " + ToString(land->size() - 1));

					int index;
					do
					{
						index = Input();
					} while (index > land->size() - 1);

					Log("Enter amount of seeds you want to plant. Up to 100");
					int seedsPlanted = Input();
					while (seedsPlanted > (100 - (*land)[index].GetSeedCount()))
					{
						Log("Too Many Seeds");
						Log("Enter amount of seeds you want to plant. Up to 100");
						seedsPlanted = Input();
					}
					OkScreen("Planted");
					(*land)[index].SetSeedCount((*land)[index].GetSeedCount() + seedsPlanted);
					seedSupply -= seedsPlanted;
				}
				else
				{
					OkScreen("You Have No Land");
				}
				break;
			}
			case 3:
			{
				Log("Enter amount of fuel you want to use to refuel");
				int fuel = Input();
				if (fuel > fuelSupply)
				{
					OkScreen("Not enough fuel in fuel supply");
				}
				else
				{
					int overFill = harvesters->AddFuel(fuel);
					fuelSupply -= fuel + overFill;
					break;
				}
			}
			case 4:
			{
				if (land->size() > 0)
				{
					OkScreen("Harvesting Land");
					cropSupply += h.Harvest();
				}
				else
				{
					OkScreen("How Can You Harvest Land If You Don't Have Any?");
				}
			}
		}
	}

	Log("Oops you ran out of money. Better luck next time!");
}