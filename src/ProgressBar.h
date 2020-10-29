#ifndef PROGRESS_BAR
#define PROGRESS_BAR

#include "Console.h"
#include <string>
#include <iostream>
#include <math.h>

class ProgressBar
{
public:
    ProgressBar(int first_num, int second_num /*const char* color*/);

    void AddProgress(int x);
    void RemoveProgress(int x);
    std::string GetBar();
    
private:
    float first_num;
    float second_num;
    //const char* color;
    std::string bar;
    int progress;
    float percentage;
};
#endif