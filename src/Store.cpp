#include "Store.h"
#include <stdio.h>

Store::Store() {
    m_prices = {
        {SEED, 5},
        {FUEL, 5},
        {LAND, 10000},
        {PLANTER, 100000},
        {HARVESTER, 100000}
    };

    m_basket = {
        {MONEY, 0}, 
        {SEED, 0}, 
        {FUEL, 0}, 
        {LAND, 0}, 
        {PLANTER, 0}, 
        {HARVESTER, 0}, 
    };
}

void Store::Enter(std::map<StoreItem, int> customer_inventory) {
    m_prev_inventory = customer_inventory;
}

std::map<StoreItem, int> Store::Exit() {
    for (int i = 0; i < 6; i++) {
        m_prev_inventory[(StoreItem) i] += m_basket[(StoreItem) i];
    }
    return m_basket;
}

bool Store::Buy(StoreItem item, int num_items) {
    int cost = m_prices[item] * num_items;
    if (m_prev_inventory[MONEY] + m_basket[MONEY] >= cost) {
        m_basket[item] += num_items;
        m_basket[MONEY] -= cost;
        return true;
    }
    return false;
}

bool Store::Sell(StoreItem item, int num_items) {
    int cost = m_prices[item] * num_items;
    if (m_prev_inventory[item] + m_basket[item] >= num_items) {
        m_basket[item] -= num_items;
        m_basket[MONEY] += cost;
        return true;
    }
    return false;
}

int Store::TotalCostOfItem(StoreItem item) {
    return m_basket[item] * m_prices[item];
}

int Store::TotalCost() {
    return m_basket[SEED] * m_prices[SEED] + 
        m_basket[FUEL] * m_prices[FUEL] + 
        m_basket[LAND] * m_prices[LAND] + 
        m_basket[PLANTER] * m_prices[PLANTER] + 
        m_basket[HARVESTER] * m_prices[HARVESTER];
}
