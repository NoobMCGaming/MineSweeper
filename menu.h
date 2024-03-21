#ifndef MENU_H
#define MENU_H

long long sizeMap = 0;
long long countMine = 0;
long long sizeLoang = 0;
long long countFlag = 0;

#include "compiler.h"
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

const long long sizeList[3] = {10, 20, 30};
const long long mineList[3] = {10, 30, 50};
const long long loangList[3] = {3, 4, 5};
const long long flagList[3] = {10, 30, 50};

long long mt_rand(long long from, long long to){
    srand(time(0));
    return from + rand()%to;
}

void selectLevel(){
    long long level = 0;
    while(level != 1 and level != 2 and level  != 3){
        cout<<"1. "; setColor(6); cout<<"Map 10x10"<<endl;
        resetColor();
        cout<<"2. "; setColor(6); cout<<"Map 20x20"<<endl;
        resetColor();
        cout<<"3. "; setColor(6); cout<<"Map 30x30"<<endl;
        setColor(9);
        cout<<"Select Your Level: ";
        resetColor();
        cin>>level;
    }
    sizeMap = sizeList[level-1];
    countMine = mineList[level-1];
    sizeLoang = loangList[level-1];
    countFlag = flagList[level-1];
}

#endif // MENU_H
