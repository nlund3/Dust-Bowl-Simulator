#include "Weather.h"

WeatherTypes Weather()
{
    constexpr float clear_threshold = 999;
    constexpr float shower_threshold = 399;
    constexpr float storm_threshold = 174;
    constexpr float monsoon_threshold = 124;
    constexpr float timid_threshold = 109;
    constexpr float mild_threshold = 49;
    constexpr float severe_threshold = 19;
    constexpr float catas_threshold = 4;

    float weather = rand() % 1000;

    std::cout << weather << "|";

    WeatherTypes weather_type;
    if(weather <= catas_threshold)
        weather_type = WeatherTypes::CATASTROPHIC;
    else if(weather <= severe_threshold)
        weather_type = WeatherTypes::SEVERE;
    else if(weather <= mild_threshold)
        weather_type = WeatherTypes::MILD;
    else if(weather <= timid_threshold)
        weather_type = WeatherTypes::TIMID;
    else if(weather <= monsoon_threshold)
        weather_type = WeatherTypes::MONSOON;
    else if(weather <= storm_threshold)
        weather_type = WeatherTypes::STORM;
    else if(weather <= shower_threshold)
        weather_type = WeatherTypes::SHOWER;
    else if(weather <= clear_threshold)
        weather_type = WeatherTypes::CLEAR;

    return weather_type;
}

void WeatherPrint(WeatherTypes weather)
{
    switch(weather)
    {
        case WeatherTypes::CLEAR:
            std::cout << "Clear\n";
            break;
        case WeatherTypes::SHOWER:
            std::cout << "Raining (Shower) (Crops Grow 1.5x Faster!)\n";
            break;
        case WeatherTypes::STORM:
            std::cout << "Raining (Storm) (Crops Grow 2x Faster!)\n";
            break;
        case WeatherTypes::MONSOON:
            std::cout << "Raining (Monsoon) (Crops Grow 5x Faster!)\n";
            break;
        case WeatherTypes::TIMID:
            std::cout << "Dusty (Timid) (Destroyed 10% Of The Crops! Operations Halted For A Day!)\n";
            break;
        case WeatherTypes::MILD:
            std::cout << "Dusty (Mild) (Destroyed 25% Of The Crops! Operations Halted For 3 Days!)\n";
            break;
        case WeatherTypes::SEVERE:
            std::cout << "Dusty (Severe) (DESTROYED HALF OF EVERYTHING! Operations Halted For A Week!)\n";
            break;
        case WeatherTypes::CATASTROPHIC:
            std::cout << "Dusty (Catastrophic) (DESTROYED EVERYTHING!)\n";
            break;
    }
}