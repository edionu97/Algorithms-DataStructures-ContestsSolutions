// Fractii.cpp : Defines the entry point for the console application.
//
 
#include "stdafx.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
 
using std::ifstream;
int N;
 
inline void readData() {
    ifstream f{ "fractii.in" };
    f >> N;
}
 
using std::vector;
using std::for_each;
 
long long getNumberOfFrac() {
 
    vector <int> primeWith( N + 1 );
 
    for_each(primeWith.begin() + 1, primeWith.end(), [](int &value) {
        static int  i = -1;
        value = ++i;
    });
 
    long long result = 0;
 
    for (int i = 2; i <= N; ++i) {
        for (int j = 2 * i; j <= N; j += i)primeWith[j] -= primeWith[i];
        result += primeWith[i] * 2;
    }
     
    return 1 + result;
}
 
using std::ofstream;
 
 
int main(){
 
    readData();
 
    ofstream g{ "fractii.out" };
 
    g << getNumberOfFrac();
     
    return 0;
}