#include <iostream>
#include <time.h>

#include "ProgressBar.h"
#include "Console.h"
#include "Weather.h"

/*
#ifdef _WIN32
#include <windows.h>
void clear() 
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
};
#else
void clear() 
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
};
#endif*/


int main()
{
    srand(time(NULL));

    PrintColor("Dust Bowl Simulator\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
    PrintColor("By Hervert Hoover\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
    Input();
    ClearScreen();

    bool planting = false;
    bool harvesting = false;

    int land = 10;
    int seeds = 0;
    int fuel = 0;
    int harvesters = 0;
    int planters = 0;
    int money = 500000;
    int crops = 0;

    int day = 1;

    int seeds_planted = 0;
    int seed_capacity = land * 100;
    int seeds_matured = 0;
    int seeds_harvested = 0;

    int planting_speed = planters * 50;
    int harvesting_speed = harvesters * 50;

    float growth_rate;
    WeatherTypes weather = Weather();

    while(true)
    {

        //Print Stuff
        //--------------------------------------------------------------------------------------------------------------
        ClearScreen();
        PrintColor("Day: " + std::to_string(day) + "\n", ForegroundColors::RED, BackgroundColors::BLACK);
        PrintColor("Weather: ", ForegroundColors::RED, BackgroundColors::BLACK);
        WeatherPrint(weather);
        PrintColor("\n\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

        PrintColor("Progress:\n==================================\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
        ProgressBar growing_progress = ProgressBar(seeds_matured, seeds_planted);
        PrintColor("Plant Growth " + growing_progress.GetBar(), ForegroundColors::YELLOW, BackgroundColors::BLACK);
        ProgressBar planting_progress = ProgressBar(seeds_planted, seed_capacity);
        PrintColor("Planting (" + (planting) ? "Active" : "Inactive" + ") " + planting_progress.GetBar(), ForegroundColors::YELLOW, BackgroundColors::BLACK);
        ProgressBar harvesting_progress = ProgressBar(seeds_harvested, seeds_matured);
        PrintColor("Harvesting (" + (harvesting) ? "Active" : "Inactive" + ") " + harvesting_progress.GetBar(), ForegroundColors::YELLOW, BackgroundColors::BLACK);

        PrintColor("\nSupply:\n======================================\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("Seeds: " + std::to_string(seeds), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\n$: " + std::to_string(money), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\nCrops: " + std::to_string(crops), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\nLand: " + std::to_string(land), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\nFuel: " + std::to_string(fuel), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\nPlanters: " + std::to_string(planters), ForegroundColors::WHITE, BackgroundColors::BLACK);
        PrintColor("\nHarvesters: " + std::to_string(planters) + "\n\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

        PrintColor("Actions:\n=====================================\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

        PrintColor("Next, Store, Plant, Harvest\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
        //-------------------------------------------------------------------------------------------------------------------

        //Input
        std::string input = InputString();
        
        if(input == "next")
        {
            day++;
        }
        else if(input == "store")
        {
            ClearScreen();
            PrintColor("Welcome. How Can I Help?\n\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
            PrintColor("Buy : Sell : Leave\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
            
            std::string input = InputString();
            int amount_input;

            if(input == "buy")
            {
                ClearScreen();
                PrintColor("Here's What I Got\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("Fuel ($1) : Seeds ($3) : Land ($10K) : Planter ($100K) : Harvester ($100K)\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("If You Don't Want Anything, Say Nothing\n\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                
                PrintColor("Seeds: " + std::to_string(seeds), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\n$: " + std::to_string(money), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nCrops: " + std::to_string(crops), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nLand: " + std::to_string(land), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nFuel: " + std::to_string(fuel), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nPlanters: " + std::to_string(planters), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nHarvesters: " + std::to_string(planters) + "\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

                input = InputString();
                if(input == "fuel")
                {
                    ClearScreen();
                    PrintColor("How Much Fuel?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
            
                    amount_input = Input();
                    if(money - amount_input >= 0)
                    {
                        fuel += amount_input;
                        money -= amount_input;
                    }
                }
                else if(input == "seeds")
                {
                    ClearScreen();
                    PrintColor("How Many Seeds?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(money - amount_input * 3>= 0)
                    {
                        seeds += amount_input;
                        money -= amount_input * 3;
                    }
                }
                else if(input == "land")
                {
                    ClearScreen();
                    PrintColor("How Much Land?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(money - amount_input * 10000>= 0)
                    {
                        land += amount_input;
                        money -= amount_input * 10000;
                    }
                }
                else if(input == "planter")
                {
                    ClearScreen();
                    PrintColor("How Many Planters?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(money - amount_input * 100000>= 0)
                    {
                        
                        planters += amount_input;
                        money -= amount_input * 100000;
                    }
                }
                else if(input == "harvesters")
                {
                    ClearScreen();
                    PrintColor("How Many Harvesters?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(money - amount_input * 100000 >= 0)
                    {
                        
                        harvesters += amount_input;
                        money -= amount_input * 100000;
                    }
                }       
            }
            else if(input == "sell")
            {
                ClearScreen();
                PrintColor("Here's What I'm Offeringt\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("Fuel ($1) : Seeds ($2) : Land ($8K) : Planter ($80K) : Harvester ($80K)\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("If You Don't Like My Offers, Say Nothing\n\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

                PrintColor("Seeds: " + std::to_string(seeds), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\n$: " + std::to_string(money), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nCrops: " + std::to_string(crops), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nLand: " + std::to_string(land), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nFuel: " + std::to_string(fuel), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nPlanters: " + std::to_string(planters), ForegroundColors::WHITE, BackgroundColors::BLACK);
                PrintColor("\nHarvesters: " + std::to_string(planters) + "\n", ForegroundColors::WHITE, BackgroundColors::BLACK);

                input = InputString();
                if(input == "fuel")
                {
                    ClearScreen();
                    PrintColor("How Much Fuel?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
            
                    amount_input = Input();
                    if(fuel - amount_input >= 0)
                    {
                        fuel -= amount_input;
                        money += amount_input;
                    }
                }
                else if(input == "seeds")
                {
                    ClearScreen();
                    PrintColor("How Many Seeds?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(seeds - amount_input >= 0)
                    {
                        seeds -= amount_input;
                        money += amount_input * 2;
                    }
                }
                else if(input == "land")
                {
                    ClearScreen();
                    PrintColor("How Much Land?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(land - amount_input >= 0)
                    {
                        land -= amount_input;
                        money += amount_input * 8000;
                    }
                }
                else if(input == "planter")
                {
                    ClearScreen();
                    PrintColor("How Many Planters?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(planters - amount_input >= 0)
                    {
                        
                        planters -= amount_input;
                        money += amount_input * 80000;
                    }
                }
                else if(input == "harvesters")
                {
                    ClearScreen();
                    PrintColor("How Many Harvesters?\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                    
                    amount_input = Input();
                    if(harvesters - amount_input >= 0)
                    {
                        
                        harvesters -= amount_input;
                        money += amount_input * 80000;
                    }
                }
            }
            else
            {
                ClearScreen();
                PrintColor("Bye Come Again!\n", ForegroundColors::WHITE, BackgroundColors::BLACK);
                Input();
            }
        }
        else if(input == "plant")
        {
            !planting;
        }
        else if(input == "harvest")
        {
            !harvesting;
        }
        else
        {
            return 0;
        }

        //Processes
        //---------------------------------------------------------
        if(planting)
        {
            if(fuel - 20 * planters >= 0)
            {
                fuel -= planters * 20;

                if(seeds_planted + planting_speed > seed_capacity)
                {
                    seeds_planted = seed_capacity;
                }
                else
                {
                    seeds_planted += planting_speed;
                }
            }
        }
        
        if(harvesting)
        {
            if(fuel - 20 * harvesters >= 0)
            {
                fuel -= harvesters * 20;

                if(seeds_harvested + harvesting_speed > seeds_matured)
                {
                    seeds_harvested = seeds_matured;
                }
                else
                {
                    seeds_harvested += harvesting_speed;
                }
            }
        }
        //---------------------------------------------------------

        //Weather
        weather = Weather();
        switch(weather)
        {
            case WeatherTypes::SHOWER:
                growth_rate = 1.5;
                break;
            case WeatherTypes::STORM:
                growth_rate = 2;
                break;
            case WeatherTypes::MONSOON:
                growth_rate = 5;
                break;
            case WeatherTypes::TIMID:
                seeds_planted -= 0.1 * seeds_planted;
                break;
            case WeatherTypes::MILD:
                seeds_planted -= 0.25 * seeds_planted;
                break;
            case WeatherTypes::SEVERE:
                seeds_planted -= 0.5 * seeds_planted;
                break;
            case WeatherTypes::CATASTROPHIC:
                seeds_planted -= seeds_planted;
                break;
        }

        if(seeds_planted < seeds_matured)
        {
            seeds_matured = seeds_planted;
        }
        else
        {
            seeds_matured += (rand() % 10) * growth_rate;
        }

        int planting_speed = planters * 50;
        int harvesting_speed = harvesters * 50;
    }
    
    //Game Loop
    //Farm

    //Go To Store
    //Store
    //Buy
    //Sell

    //Plant

    //Harvest

    //Play

    //Pause
}
