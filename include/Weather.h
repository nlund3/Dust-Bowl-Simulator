#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <string>

enum class WeatherTypes
{
    CLEAR,
    SHOWER,
    STORM,
    MONSOON,
    TIMID,
    MILD,
    SEVERE,
    CATASTROPHIC
};

WeatherTypes Weather();
void WeatherPrint(WeatherTypes weather);
#endif