/ kaparitii.cpp : Defines the entry point for the console application.
//
 
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int aparitii[10][10];
 
int ordMax;
 
inline void openReadingWriting() {
    freopen("aparitii.in", "r", stdin);
    freopen("aparitii.out", "w", stdout);
}
 
void getFigures(int x) {
 
    int ordin = -1;
 
    while (x) aparitii[++ordin][x % 10]++, x /= 10;
 
    ordMax = max(ordin, ordMax);
}
 
int K;
 
void readData() {
 
    openReadingWriting();
 
    int  N;
 
    scanf("%d %d", &N, &K);
 
    while (N--) {
        int x; scanf("%d", &x);
        getFigures(x);
    }
 
}
 
void writeAnswer() {
 
    for (int i = ordMax; i >= 0; --i) 
        for (int j = 0; j < 10; ++j) {
            if (aparitii[i][j] % K == 0)continue;
            printf("%d", j);
        }
}
 
int main(){
    readData();
    writeAnswer();
    return 0;
}