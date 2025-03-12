#ifndef FARMLAND_H
#define FARMLAND_H

#include <vector>

/**
 * Manages the crops of all owned land
 * Keeps track of how much each land's crops have grown
 * and how much water each land has
*/

class FarmLand {
public:

    /**
     * Create land with given number of acres
     * Default values set for the best possible conditions
     * 
     * Number of crops = 0
     * Growth percentage = 0%
     * Water saturation = 100%
     * Soil richness = 100%
     * Crop yield = 100%
     * Fertilizer concentration = 100%
     * Pest concentration = 0%
     * Weed concentration = 0%
    */
    FarmLand();

    /**
     * Create land with given number of acres
     * and given conditions
    */
    FarmLand(int num_crops, float growth, float water, float soil,
        float yield, float fert, float pest, float weed);

    /**
     * Get number of crops
    */
    int GetNumCrops();

    /**
     * Get water saturation
    */
    float GetWaterSaturation();

    /**
     * Get soil richness
    */
    float GetSoilRichness();

    /**
     * Get crop growth as a percentage of fully matured
    */
    float GetGrowthPercentage();

    /**
     * Get yield percentage
    */
    float GetYieldPercentage();

    /**
     * Get fertilizer concentration
    */
    float GetFertilizerConcentration(); 

    /**
     * Get pest concentration
    */
    float GetPestConcentration();

    /**
     * Get weed concentration
    */
    float GetWeedConcentration();

    /**
     * Set number of crops
    */
    void SetNumCrops(int num);

    /**
     * Set water saturation
    */
    void SetWaterSaturation(float sat);

    /**
     * Set soil richness
    */
    void SetSoilRichness(float richness);

    /**
     * Set crop growth as a percentage of fully matured
    */
    void SetGrowthPercentage(float percent);

    /**
     * Set yield percentage
    */
    void SetYieldPercentage(float percent);

    /**
     * Set fertilizer concentration
    */
    void SetFertilizerConcentration(float con); 

    /**
     * Set pest concentration
    */
    void SetPestConcentration(float con);

    /**
     * Set weed concentration
    */
    void SetWeedConcentration(float con);

    /**
     * NextDayUpdates all FarmLand
     * The following is updated:
     *      Crop growth percentage 
     *      Water saturation 
     *      Soil Richness 
     *      Pest concentration
     *      Weed concentration
    */
    void NextDayUpdate();

private:
    // Number of crops growing on land
    int m_num_crops;

    /**
     * The higher the fertilizer concentration, the higher the rate
     * of increase for soil richness.
     * 
     * Formula: soil_rich = 0.05 / (1 + exp(-10 * (fert_con - 0.5))) <- Sigmoid function
     * 
     * Value is changed at 0% and 100%
     * At 0%, soil richness +0% per day
     * At 50%, soil richness +2.5% per day
     * At 100%, soil richness +5% per day
    */
    float m_fert_concen;

    /**
     * The lesser than 100%, the faster the number of crops will decrease
     * per day. At 0%, half of the crops dies out per day.
     *
     * Formula for percentage of crops that will die per day: 50% - 50% * water_sat
     * The value is from 0% to 100%
    */
    float m_water_sat;

    /**
     * Higher soil richness increases crop yield per day and vice versa
     * At 0%, 5% decrease of yield percent per day
     * At 50%, no change in yield percent per day
     * At 100%, 5% increase of yield percent per day
     * The value is from 0% to 100%
    */
    float m_soil_rich;

    /**
     * 0% is seed, 100% is fully matured
     * +0.5% per day
    */
    float m_growth_percent;

    /**
     * How much crop can be harvested as a percentage of current number of crops 
     * Example: 50% yield = 50% of crops will become fully grown crops
     * Unlike changing the number of crops, the yield percent can go back up.
     * But once you lose crops, that's it, they're gone.
     * You gotta replant them again after the next harvest.
    */
    float m_yield_percent;
    
    /**
     * Concentration of pests from 0% to 100%
     * Pests will decrease the number of crops
     * 
     * Formula: 0.25 / (1 + exp(-10 * (pest_con - 0.5))) <- Sigmoid function
     * 
     * 0% pest concentration = no decrease in crops per day
     * 50% pest concentratoin = 12.5% decrease in crops per day
     * 100% pest concentration = 25% decrease in crops per day
    */
    float m_pest_concen;

    /**
     * Concentration of weeds from 0% to 100%
     * Weeds will decrease soil richness
     * 
     * Formula: = 0.1 / (1 + exp(-10 * (weed_con - 0.5))) <- Sigmoid function
     * 
     * 0% weed concentration = no decrease in crops per day
     * 50% weed concentration = 5% decrease in soil richness per day
     * 100% weed concentration = 10% decrease in soil richness per day
    */
    float m_weed_concen;

    float Sigmoid(float highest_value, float x);
};

class FarmLandManager {
public:
    FarmLand GetFarmLand(int x, int y);
    void SetFarmLand(FarmLand land, int x, int y);

private:
    std::vector<std::vector<FarmLand>> m_grid;
};

#endif