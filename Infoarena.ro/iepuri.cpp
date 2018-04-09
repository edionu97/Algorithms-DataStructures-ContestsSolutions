#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <initializer_list>
#define MOD 666013
 
using namespace std;
 
template <typename T >class matrix {
 
private:
 
    vector < vector < T > > m;
 
    int line = -1;
 
public:
 
    matrix(int __rowCount, int __columnCount) {
        m.resize(__rowCount);
        for_each(m.begin(), m.end(), [=](vector < T >& line) {
            line.resize(__columnCount);
        });
    }
 
    matrix(const matrix& other) {
        m = other.m;
    }
 
    matrix & operator << (const initializer_list <T> & list) {
 
        ++line;
 
        for (auto it = list.begin(); it != list.end(); ++it) m[line][(it - list.begin() )] = *it;
             
        return *this;
    }
 
 
    matrix& operator =(const matrix& other) {
 
        m = other.m;
 
        return *this;
    }
 
    matrix operator *(const matrix & other) const {
 
        matrix <T> B{ static_cast <int> (m.size()),static_cast <int>(other.m[0].size()) };
 
        for (int i = 0; i < B.m.size(); ++i)
            for (int j = 0; j < B.m[i].size(); ++j)
                for (int k = 0; k < B.m.size(); ++k)B.m[i][j] = ((m[i][k] * other.m[k][j]) % MOD + B.m[i][j]) % MOD;
 
        return B;
    }
 
    inline void clear() {
        line = -1;
    }
 
    const T& getFirst() const {
        return m[0][0];
    }
 
};
 
 
matrix <long long > expl(const matrix < long long >& m, int exp) {
 
    if (!exp) return (matrix<long long> { 3,3 } << initializer_list<long long>{1, 0, 0} << initializer_list<long long>{0, 1, 0} << initializer_list <long long>{0, 0, 1});
 
    if (exp % 2 == 0)return expl(m * m, exp / 2);
 
    return m * expl(m * m, exp / 2);
}
 
void readAndAnswer() {
 
    ifstream f{ "iepuri.in" };
    ofstream g{ "iepuri.out" };
 
    long long N;
 
    int T,X,Y,Z,A,B,C;
 
    f >> T;
 
    matrix < long long > m{ 3,3 };
 
    while (T--) {
         
        m.clear();
 
        f >> X >> Y >> Z >> A >> B >> C >> N;
 
        m << initializer_list <long long > {A, B, C} << initializer_list<long long >{1, 0, 0} << initializer_list <long long >{0, 1, 0};
 
        ----N;
 
        g << (expl(m, N) * (matrix<long long >(3, 1) << initializer_list<long long >{Z} << initializer_list <long long >{Y} << initializer_list<long long >{X})).getFirst() << '\n';
 
    }
}
 
 
int main() {
    readAndAnswer();
}