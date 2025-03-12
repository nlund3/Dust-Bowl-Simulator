#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "FarmLand.h"

using namespace Catch::Matchers;

TEST_CASE("Default FarmLand") {
    FarmLand land;
    
    SECTION("Crop amount == 0") {
        REQUIRE(land.GetNumCrops() == 0);
    }
    
    SECTION("Water saturation == 1.0f%") {
        REQUIRE(land.GetWaterSaturation() == 1.0f);
    }

    SECTION("Crop yield == 1.0f%") {
        REQUIRE(land.GetYieldPercentage() == 1.0f);
    }
    
    SECTION("Soil richness == 1.0f%") {
        REQUIRE(land.GetSoilRichness() == 1.0f);
    }

    SECTION("Fertilizer concentration == 1.0f%") {
        REQUIRE(land.GetFertilizerConcentration() == 1.0f);
    }
    
    SECTION("Pest concentration == 0%") {
        REQUIRE(land.GetPestConcentration() == 0.0f);
    }

    SECTION("Weed concentration == 0%") {
        REQUIRE(land.GetWeedConcentration() == 0.0f);
    }
    
    SECTION("Growth percentage == 0%") {
        REQUIRE(land.GetGrowthPercentage() == 0.0f);
    }
}

TEST_CASE("Custom FarmLand") {
    FarmLand land(12345, 0.1, 0.2, 0.3, 0.4, 0.5f, 0.6, 0.7);
    
    REQUIRE(land.GetNumCrops() == 12345);
    REQUIRE(land.GetGrowthPercentage() == 0.1f);
    REQUIRE(land.GetWaterSaturation() == 0.2f);
    REQUIRE(land.GetSoilRichness() == 0.3f);
    REQUIRE(land.GetYieldPercentage() == 0.4f);
    REQUIRE(land.GetFertilizerConcentration() == 0.5f);
    REQUIRE(land.GetPestConcentration() == 0.6f);
    REQUIRE(land.GetWeedConcentration() == 0.7f);
}

TEST_CASE("Changing FarmLand properties") {
    FarmLand land;
    
    SECTION("Changing crop amount") {
        land.SetNumCrops(10.0f);
        REQUIRE(land.GetNumCrops() == 10.0f);
    }
    
    SECTION("Changing water saturation") {
        land.SetWaterSaturation(0.5f);
        REQUIRE(land.GetWaterSaturation() == 0.5f);
    }

    SECTION("Changing crop yield") {
        land.SetYieldPercentage(0.5f);
        REQUIRE(land.GetYieldPercentage() == 0.5f);
    }
    
    SECTION("Changing soil richness") {
        land.SetSoilRichness(0.5f);
        REQUIRE(land.GetSoilRichness() == 0.5f);
    }

    SECTION("Changing fertilizer concentration") {
        land.SetFertilizerConcentration(0.5f);
        REQUIRE(land.GetFertilizerConcentration() == 0.5f);
    }
    
    SECTION("Changing pest concentration") {
        land.SetPestConcentration(0.5f);
        REQUIRE(land.GetPestConcentration() == 0.5f);
    }

    SECTION("Changing weed concentration") {
        land.SetWeedConcentration(0.5f);
        REQUIRE(land.GetWeedConcentration() == 0.5f);
    }
    
    SECTION("Changing growth percentage") {
        land.SetGrowthPercentage(0.5f);
        REQUIRE(land.GetGrowthPercentage() == 0.5f);
    }
}


TEST_CASE("Fertilizer changes soil richness per day") {
    FarmLand land;
    land.SetSoilRichness(0.5f);

    SECTION("0% fertilizer -> +0% soil richness per day") {
        land.SetFertilizerConcentration(0.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetSoilRichness() == 0.5f);
    }

    SECTION("50% fertilizer -> +2.5% soil richness per day") {
        land.SetFertilizerConcentration(0.5f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.525f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.55f, 1e-6));
    }

    SECTION("100% fertilizer -> +5% soil richness per day") {
        land.SetFertilizerConcentration(1.0f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.55f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.6f, 1e-6));
    }
}

TEST_CASE("Water saturation changes number of crops per day") {
    FarmLand land;
    land.SetNumCrops(1000);

    SECTION("0% water saturation -> -50% number of crops per day") {
        land.SetWaterSaturation(0.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 500);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 250);
    }

    SECTION("50% water saturation -> -25% number of crops per day") {
        land.SetWaterSaturation(0.5f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 750);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 562);
    }

    SECTION("100% water saturation -> -0% number of crops per day") {
        land.SetWaterSaturation(1.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 1000);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 1000);
    }
}

TEST_CASE("Soil richness changes yield percent per day") {
    FarmLand land;
    land.SetFertilizerConcentration(0.0f);
    land.SetYieldPercentage(0.5f);

    SECTION("0% soil richness -> -5% yield percent per day") {
        land.SetSoilRichness(0.0f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetYieldPercentage(), WithinAbs(0.45f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetYieldPercentage(), WithinAbs(0.4f, 1e-6));
    }

    SECTION("50% soil richness -> +0% yield percent per day") {
        land.SetSoilRichness(0.5f);

        land.NextDayUpdate();
        REQUIRE(land.GetYieldPercentage() == 0.5f);
    }

    SECTION("100% soil richness -> +5% yield percent per day") {
        land.SetSoilRichness(1.0f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetYieldPercentage(), WithinAbs(0.55f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetYieldPercentage(), WithinAbs(0.6f, 1e-6));
    }
}

TEST_CASE("Growing percent +0.5% per day") {
    FarmLand land(1000, 0.0f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f);

    land.NextDayUpdate();
    REQUIRE_THAT(land.GetGrowthPercentage(), WithinAbs(0.005f, 1e-6));

    land.NextDayUpdate();
    REQUIRE_THAT(land.GetGrowthPercentage(), WithinAbs(0.01f, 1e-6));
}

TEST_CASE("Pest concentration changes number of crops per day") {
    FarmLand land;
    land.SetNumCrops(1000);

    SECTION("0% pest concentration -> -0% number of crops per day") {
        land.SetPestConcentration(0.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 1000);
    }

    SECTION("50% pest concentration -> -5% number of crops per day") {
        land.SetPestConcentration(0.5f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 875);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 765);
    }

    SECTION("100% pest concentration -> -10% number of crops per day") {
        land.SetPestConcentration(1.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 750);

        land.NextDayUpdate();
        REQUIRE(land.GetNumCrops() == 562);
    }
}

TEST_CASE("Weed concentration changes soil richness per day") {
    FarmLand land;
    land.SetSoilRichness(0.5f);
    land.SetFertilizerConcentration(0.0f);

    SECTION("0% weed concentration -> -0% soil richness per day") {
        land.SetWeedConcentration(0.0f);

        land.NextDayUpdate();
        REQUIRE(land.GetSoilRichness() == 0.5f);
    }

    SECTION("50% weed concentration -> -5% soil richness per day") {
        land.SetWeedConcentration(0.5f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.45f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.4f, 1e-6));
    }
    
    SECTION("100% weed concentration -> -10% soil richness per day") {
        land.SetWeedConcentration(1.0f);

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.4f, 1e-6));

        land.NextDayUpdate();
        REQUIRE_THAT(land.GetSoilRichness(), WithinAbs(0.3f, 1e-6));
    }
}