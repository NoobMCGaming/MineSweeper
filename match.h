#ifndef MATCH_H
#define MATCH_H

#include <bits/stdc++.h>
#include "menu.h"

using namespace std;

const long long r[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const long long c[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
bool check[101][101];
long long a[101][101], b[101][101];
string match[101][101];
bool isFirstPlay = true;
long long mine = countMine;
long long flag = countFlag;

void spawnSpace(long long sl){
    for(long long i = 1; i <= sl; i++) cout<<" ";
}

bool isMine(long long x, long long y){
    if(a[x][y] == 1) return true;
    return false;
}

void checkMap(long long sizeMap){
    memset(b, 0, sizeof(b));
    for(long long i = 1; i <= sizeMap; i++){
        for(long j = 1; j <= sizeMap; j++){
            if(isMine(i, j) == false){
                for(long long k = 0; k < 8; k++){
                    if(check[i+r[k]][j+c[k]] == true and a[i+r[k]][j+c[k]] == 1){
                        b[i][j]++;
                    }
                }
            }
        }
    }
}

void setMatch(long long sizeMap){
    for(long long i = 1; i <= sizeMap; i++){
        for(long long j = 1; j <= sizeMap; j++){
            match[i][j] = "#";
        }
    }
}

void setMapMine(long long sizeMap, long long mine){
    srand(time(0));
    memset(a, 0, sizeof(a));
    memset(check, false, sizeof(check));
    for(long long i = 1; i <= mine; i++){
        long long x = 1 + rand()%sizeMap;
        long long y = 1 + rand()%sizeMap;
        a[x][y] = 1;
    }
    for(long long i = 1; i <= sizeMap; i++){
        for(long long j = 1; j <= sizeMap; j++){
            check[i][j] = true;
        }
    }
    checkMap(sizeMap);
    setMatch(sizeMap);
}

void outputMatch(){
    resetColor();
    cout<<"Flags: "<<countFlag<<endl;
    for(long long i = 1; i <= sizeMap; i++){
        spawnSpace(40);
        for(long long j = 1; j <= sizeMap; j++){
            if(check[i][j] == true){
                if(match[i][j] == "#") setColor(2);
                if(match[i][j] == "L") setColor(4);
                cout<<match[i][j]<<" ";
            }
            else{
                resetColor();
                cout<<b[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void loang(long long x, long long y, long long sizeBreak, long long countBreak){
    if(countBreak == sizeBreak){
        return;
    }
    check[x][y] = false;
    for(long long i = 0; i < 1 + rand()%8; i++){
        if(check[x+r[i]][y+c[i]] == true and a[x+r[i]][y+c[i]] != 1){
            loang(x+r[i], y+c[i], sizeBreak, countBreak+1);
        }
    }
}

void console(){
    long long x, y, m;
    while(true){
        outputMatch();
        setColor(9);
        cin>>x>>y>>m;
        if(m == 0){
            if(check[x][y] == true){
                if(isFirstPlay == true){
                    b[x][y] = 0;
                    loang(x, y, sizeLoang, 0);
                    isFirstPlay = false;
                }
                else{
                    if(isMine(x, y) == true){
                        outputMatch();
                        setColor(4);
                        cout<<"BAN DA THUA !!!!"<<endl;
                        break;
                    }
                    else{
                        long long lucky = 1 + rand()%5;
                        if(lucky == 3) loang(x, y, 3, 0);
                        check[x][y] = false;
                    }
                }
            }
        }
        if(m == 1){
            if(check[x][y] == true){
                if(match[x][y] == "L"){
                    countFlag++;
                    match[x][y] = "#";
                    if(isMine(x, y) == true) mine++;
                }
                else{
                    if(isMine(x, y) == true){
                        match[x][y] = "L";
                        mine--;
                        countFlag--;
                        if(mine == 0){
                            setColor(6);
                            cout<<"BAN DA CHIEN THANG !!!!"<<endl;
                        }
                    }
                    else{
                        match[x][y] = "L";
                        countFlag--;
                    }
                }
            }
        }
    }
}


#endif // MATCH_H
