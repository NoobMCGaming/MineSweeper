#ifndef COMPILER_H
#define COMPILER_H

#include <bits/stdc++.h>
#include <windows.h>

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(long long id){
    SetConsoleTextAttribute(Console, id);
}

void resetColor(){
    SetConsoleTextAttribute(Console, RESETDEV);
}

#endif
