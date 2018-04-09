#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
 
using namespace std;
 
vector <long> numbers;
 
long S;
 
void readData() {
 
    ifstream f("loto.in");
 
    int N;
 
    long x;
 
    f >> N >> S;
 
    while (N--) f >> x,numbers.push_back(x);
 
}
 
struct reconstruct {
    int x, y, z;
 
    reconstruct() = default;
 
    reconstruct(int a, int b, int c) :x{ a }, y{ b }, z{ c } {}
};
 
unordered_map <long, reconstruct> partialSums;
 
void buildPartialSums() {
 
    ofstream g("loto.out");
 
    int N = numbers.size();
 
    for (int i = 0; i < N; ++i)
 
        for (int j = 0; j < N; ++j)
 
            for (int k = 0; k < N; ++k) {
 
                partialSums[numbers[i] + numbers[j] + numbers[k]] = reconstruct(i, j, k);
 
                auto it = partialSums.find(S - (numbers[i] + numbers[j] + numbers[k]));
 
                if (it == partialSums.end())continue;
 
                vector <long> v{ numbers[i], numbers[j], numbers[k], numbers[it->second.x], numbers[it->second.y], numbers[it->second.z] };
 
                sort(v.begin(), v.end());
 
                for (int el : v) g << el << ' ';
 
                return;
            }
 
    g << -1 << '\n';
 
}
 
int main() {
    readData();
    buildPartialSums();
    return 0;
}