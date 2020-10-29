#include "Console.h"

std::string InputString()
{
    std::string x;
    std::getline(std::cin, x);
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return x;
}

int Input()
{
    int x;
    std::cin >> x;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    return x;
}

void PrintColor(const std::string& x, const char* foreground, const char* background)
{
    std::cout << foreground << background << x;
}

void MoveCursorUp(int val)
{
    std::cout << "\x1b[" << val << "A";
}

void MoveCursorDown(int val)
{
    std::cout << "\x1b[" << val << "B";
}

void MoveCursorRight(int val)
{
    std::cout << "\x1b[" << val << "C";
}

void MoveCursorLeft(int val)
{
    std::cout << "\x1b[" << val << "D";
}

void MoveCursorToPosition(int x, int y)
{
    std::cout << "\x1b[" << x << ";" << y << "H";
}

void FillScreen(const char* background_color)
{
    std::cout << background_color;
    std::cout << "\x1b[2J";
}

void FillLine(const char* background_color)
{
    std::cout << background_color;
    std::cout << "\x1b[K";
}

void ClearScreen()
{
    FillScreen(BackgroundColors::BLACK);
    MoveCursorToPosition(0, 0);
}