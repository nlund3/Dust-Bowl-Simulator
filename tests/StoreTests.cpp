#include <catch2/catch_test_macros.hpp>
#include "Store.h"

TEST_CASE("Buying And Selling Without Anything") {
    Store store;
    std::map<StoreItem, int> inventory = {
        {MONEY, 0}, 
        {SEED, 0}, 
        {FUEL, 0}, 
        {LAND, 0}, 
        {PLANTER, 0}, 
        {HARVESTER, 0}, 
    };
    store.Enter(inventory);

    SECTION("Buying Without Money") {
        REQUIRE(!store.Buy(SEED, 100));
        REQUIRE(store.TotalCost() == 0);
        REQUIRE(store.Exit()[MONEY] == 0);
    }
}

TEST_CASE("Buying") {
    Store store;
    int previous_money = 100000000;
    std::map<StoreItem, int> inventory = {
        {MONEY, previous_money}, 
        {SEED, 0}, 
        {FUEL, 0}, 
        {LAND, 0}, 
        {PLANTER, 0}, 
        {HARVESTER, 0}, 
    };
    store.Enter(inventory);

    SECTION("Buying Seeds") {
        REQUIRE(store.Buy(SEED, 100));
        REQUIRE(store.TotalCostOfItem(SEED) > 0);
        REQUIRE(store.TotalCost() > 0);
        
        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] < previous_money);
        REQUIRE(new_inventory[SEED] > 0);
    }
    
    SECTION("Buying Fuel") {
        REQUIRE(store.Buy(FUEL, 100));
        REQUIRE(store.TotalCostOfItem(FUEL) > 0);
        REQUIRE(store.TotalCost() > 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] < previous_money);
        REQUIRE(new_inventory[FUEL] > 0);
    }

    SECTION("Buying Land") {
        REQUIRE(store.Buy(LAND, 100));
        REQUIRE(store.TotalCostOfItem(LAND) > 0);
        REQUIRE(store.TotalCost() > 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] < previous_money);
        REQUIRE(new_inventory[LAND] > 0);
    }
    
    SECTION("Buying Planters") {
        REQUIRE(store.Buy(PLANTER, 100));
        REQUIRE(store.TotalCostOfItem(PLANTER) > 0);
        REQUIRE(store.TotalCost() > 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] < previous_money);
        REQUIRE(new_inventory[PLANTER] > 0);
    }
    
    SECTION("Buying Harvesters") {
        REQUIRE(store.Buy(HARVESTER, 100));
        REQUIRE(store.TotalCostOfItem(HARVESTER) > 0);
        REQUIRE(store.TotalCost() > 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] < previous_money);
        REQUIRE(new_inventory[HARVESTER] > 0);
    }
}

TEST_CASE("Selling") {
    Store store;
    int prev_amount = 1000;
    std::map<StoreItem, int> inventory = {
        {MONEY, 0}, 
        {SEED, prev_amount},
        {FUEL, prev_amount},
        {LAND, prev_amount},
        {PLANTER, prev_amount},
        {HARVESTER, prev_amount},
    };
    store.Enter(inventory);

    SECTION("Selling Seeds") {
        REQUIRE(store.Sell(SEED, 100));
        REQUIRE(store.TotalCostOfItem(SEED) < 0);
        REQUIRE(store.TotalCost() < 0);
        
        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] > 0);
        REQUIRE(new_inventory[SEED] < prev_amount);
    }
    
    SECTION("Selling Fuel") {
        REQUIRE(store.Sell(FUEL, 100));
        REQUIRE(store.TotalCostOfItem(FUEL) < 0);
        REQUIRE(store.TotalCost() < 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] > 0);
        REQUIRE(new_inventory[FUEL] < prev_amount);
    }

    SECTION("Selling Land") {
        REQUIRE(store.Sell(LAND, 100));
        REQUIRE(store.TotalCostOfItem(LAND) < 0);
        REQUIRE(store.TotalCost() < 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] > 0);
        REQUIRE(new_inventory[LAND] < prev_amount);
    }
    
    SECTION("Selling Planters") {
        REQUIRE(store.Sell(PLANTER, 100));
        REQUIRE(store.TotalCostOfItem(PLANTER) < 0);
        REQUIRE(store.TotalCost() < 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] > 0);
        REQUIRE(new_inventory[PLANTER] < prev_amount);
    }
     
    SECTION("Selling Harvesters") {
        REQUIRE(store.Sell(HARVESTER, 100));
        REQUIRE(store.TotalCostOfItem(HARVESTER) < 0);
        REQUIRE(store.TotalCost() < 0);

        std::map<StoreItem, int> new_inventory = store.Exit();
        REQUIRE(new_inventory[MONEY] > 0);
        REQUIRE(new_inventory[HARVESTER] < prev_amount);
    }
}