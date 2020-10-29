#include "ProgressBar.h"

ProgressBar::ProgressBar(int first_num, int second_num /*const char* color*/) : second_num(second_num)//, color(color)
{
    //bar = std::string(BackgroundColors::WHITE) + "                    ";
    progress = 0;
    percentage = 0;
    AddProgress(first_num);
}

void ProgressBar::AddProgress(int x)
{
    if(x + first_num > second_num)
    {
        first_num = second_num;
    }

    first_num += x;
    float fill_space = floor((first_num / second_num) * 100 / 5) - progress;

    for(int i = progress + 1; i < 20; i++)
    {
        bar[i] = ' ';
        fill_space--;
        if(fill_space <= 0)
        {
            progress = i;
            break;
        }
    }

    percentage = first_num / second_num;
}

void ProgressBar::RemoveProgress(int x)
{
    if(first_num - x < 0)
    {
        first_num = 0;
    }

    first_num -= x;
    float fill_space = progress - floor((first_num / second_num) * 100 / 5);

    for(int i = progress + 1; i >= 0; i--)
    {
        bar[i] = '-';
        fill_space--;
        if(fill_space <= 0)
        {
            progress = i;
            break;
        }
    }

    percentage = first_num / second_num;
}

std::string ProgressBar::GetBar()
{
    return bar + "(" + std::to_string(first_num) + " / " + std::to_string(second_num) + ")\n";
}