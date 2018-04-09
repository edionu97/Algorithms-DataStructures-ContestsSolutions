#include "stdafx.h"
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_set>
#include <iostream>
 
using namespace std;
 
vector < int > v;
unordered_set < int > set;
 
int N;
 
void readData() {
    ifstream f{ "secv.in" };
 
    f >> N;
 
    while (N--) {
        int x; f >> x;
        v.push_back(x); set.insert(x);
    }
 
    f.close();
}
 
template <typename T>class cmp {
public:
    bool operator()(const T a, const T b) const {
        return a > b;
    }
};
 
priority_queue < int, vector < int >, cmp<int> > Q;
 
 
inline int answer() {
 
    vector < int > length(v.size(), 0), choice(v.size(), 0);
 
    for (int j = v.size() - 1; j >= 0; --j) {
        length[j] = 1, choice[j] = j;
 
        for (int i = j + 1; i < v.size(); ++i) {
 
            if (v[j] >= v[i] || length[j] > length[i] + 1)continue;
 
            if (length[j] == length[i] + 1) {
                choice[j] = min(choice[j], choice[i]); continue;
            }
 
            length[j] = length[i] + 1, choice[j] = choice[i];
        }
 
        if (length[j] == set.size())Q.push(choice[j] - j + 1);
    }
 
    return Q.empty() ? -1 : Q.top();
 
}
 
inline void writeAnswer(int a) {
    ofstream g{ "secv.out" };
    g << a << '\n';
    g.close();
}
 
 
int main() {
    readData();
    writeAnswer(answer());
    return 0;
}