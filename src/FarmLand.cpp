#include "FarmLand.h"
#include <cmath>

FarmLand::FarmLand() {
   m_num_crops = 0;
   m_growth_percent = 0.0;
   m_water_sat = 1.0;
   m_soil_rich = 1.0;
   m_yield_percent = 1.0;
   m_fert_concen = 1.0;
   m_pest_concen = 0.0;
   m_weed_concen = 0.0; 
}

FarmLand::FarmLand(int num_crops, float growth, float water, float soil,
    float yield, float fert, float pest, float weed) :
    m_num_crops(num_crops),
    m_growth_percent(growth),
    m_water_sat(water),
    m_soil_rich(soil),
    m_yield_percent(yield),
    m_fert_concen(fert),
    m_pest_concen(pest),
    m_weed_concen(weed)
{}

int FarmLand::GetNumCrops() {
    return m_num_crops;
}

float FarmLand::GetWaterSaturation() {
    return m_water_sat;
}

float FarmLand::GetSoilRichness() {
    return m_soil_rich;
}

float FarmLand::GetGrowthPercentage() {
    return m_growth_percent;
}

float FarmLand::GetYieldPercentage() {
    return m_yield_percent;
}

float FarmLand::GetFertilizerConcentration() { 
    return m_fert_concen;
}

float FarmLand::GetPestConcentration() {
    return m_pest_concen;
}

float FarmLand::GetWeedConcentration() {
    return m_weed_concen;
}

void FarmLand::SetNumCrops(int num) {
    m_num_crops = num;
}

void FarmLand::SetWaterSaturation(float sat) {
    m_water_sat = sat;
}

void FarmLand::SetSoilRichness(float richness) {
    m_soil_rich = richness;
}

void FarmLand::SetGrowthPercentage(float percent) {
    m_growth_percent = percent;
}

void FarmLand::SetYieldPercentage(float percent) {
    m_yield_percent = percent;
}

void FarmLand::SetFertilizerConcentration(float con) { 
    m_fert_concen = con;
}

void FarmLand::SetPestConcentration(float con) {
    m_pest_concen = con;
}

void FarmLand::SetWeedConcentration(float con) {
    m_weed_concen = con;
}

void FarmLand::NextDayUpdate() {
    m_growth_percent += 0.005;

    m_soil_rich += Sigmoid(0.05f, m_fert_concen); 
    m_num_crops *= 0.5 * (1 + m_water_sat);
    m_yield_percent += 0.1f * m_soil_rich - 0.05;

    m_num_crops *= 1 - Sigmoid(0.25f, m_pest_concen);
    m_soil_rich -= Sigmoid(0.1, m_weed_concen);
}

float FarmLand::Sigmoid(float highest_value, float x) {
    if (x == 0.0f) return 0.0f;
    if (x == 0.5f) return highest_value / 2;
    if (x == 1.0f) return highest_value;

    return highest_value / (1 + std::exp(-10 * (x - 0.5f)));
}
