#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

namespace ForegroundColors
{
    constexpr char BLACK[] = "\x1b[30m";
    constexpr char RED[] = "\x1b[31m";
    constexpr char GREEN[] = "\x1b[32m";
    constexpr char YELLOW[] = "\x1b[33m";
    constexpr char BLUE[] = "\x1b[34m";
    constexpr char MAGENTA[] = "\x1b[35m";
    constexpr char CYAN[] = "\x1b[36m";
    constexpr char WHITE[] = "\x1b[37m";
    constexpr char GRAY[] = "\x1b[90m";
    constexpr char BRIGHT_RED[] = "\x1b[91m";
    constexpr char BRIGHT_GREEN[] = "\x1b[92m";
    constexpr char BRIGHT_YELLOW[] = "\x1b[93m";
    constexpr char BRIGHT_BLUE[] = "\x1b[94m";
    constexpr char BRIGHT_MAGENTA[] = "\x1b[95m";
    constexpr char BRIGHT_CYAN[] = "\x1b[96m";
    constexpr char BRIGHT_WHITE[] = "\x1b[97m";
}

namespace BackgroundColors
{
    constexpr char BLACK[] = "\x1b[40m";
    constexpr char RED[] = "\x1b[41m";
    constexpr char GREEN[] = "\x1b[42m";
    constexpr char YELLOW[] = "\x1b[43m";
    constexpr char BLUE[] = "\x1b[44m";
    constexpr char MAGENTA[] = "\x1b[45m";
    constexpr char CYAN[] = "\x1b[46m";
    constexpr char WHITE[] = "\x1b[47m";
    constexpr char GRAY[] = "\x1b[100m";
    constexpr char BRIGHT_RED[] = "\x1b[101m";
    constexpr char BRIGHT_GREEN[] = "\x1b[102m";
    constexpr char BRIGHT_YELLOW[] = "\x1b[103m";
    constexpr char BRIGHT_BLUE[] = "\x1b[104m";
    constexpr char BRIGHT_MAGENTA[] = "\x1b[105m";
    constexpr char BRIGHT_CYAN[] = "\x1b[106m";
    constexpr char BRIGHT_WHITE[] = "\x1b[107m";
}

std::string InputString();
int Input();

void PrintColor(const std::string& x, const char* foreground, const char* background);

void MoveCursorUp(int val);
void MoveCursorDown(int val);
void MoveCursorRight(int val);
void MoveCursorLeft(int val);

void MoveCursorToPosition(int x, int y);

void FillScreen(const char* background_color);
void FillLine(const char* background_color);
void ClearScreen();
#endif