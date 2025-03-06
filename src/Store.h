#ifndef STORE_H
#define STORE_H

#include <map>

/**
 * Items found in the store
*/
enum StoreItem {
    MONEY, SEED, FUEL, LAND, PLANTER, HARVESTER
};


/**
 * A class for managing store items.
 * Provides buying and selling functionality
*/
class Store {
public:
    Store();

    /**
     * Sets the customer's shopping basket
     * Their current money and inventory is passed as an argument
    */
    void Enter(std::map<StoreItem, int> customer_inventory);

    /**
     * Returns the customer's new money and inventory
    */
    std::map<StoreItem, int> Exit();

    /**
     * Buys a type of item from the store
     * The number of items bought = num_items
    */
    bool Buy(StoreItem item, int num_items);

    /**
     * Sell a type of item to the store
     * The number of items sold = num_items
    */
    bool Sell(StoreItem item, int num_items);

    /**
     * The total cost for a type of item
     * Negative number means the money is going back to the user
    */
    int TotalCostOfItem(StoreItem item);

   /**
    * The total cost of all pending purchases/sells 
    * Negative number means the money is going back to the user
   */
    int TotalCost();

private:
    // The price of each item
    std::map<StoreItem, int> m_prices; 

    // The pending changes to the customer's money and inventory
    std::map<StoreItem, int> m_basket;

    // The customer's previous inventory before they exit the store
    std::map<StoreItem, int> m_prev_inventory;
};
#endif