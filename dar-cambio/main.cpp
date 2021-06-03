#include <iostream>
#include<vector>
using namespace std;

vector<int> darcambio(int n){
    vector<int> den = {10,5,2,1};
    vector<int> solucion = vector<int>(4,0);
    for (int i = 0; i < 4; ++i) {
        solucion[i] = n/den[i];
        n -= solucion[i]*den[i];
    }
    return solucion;
}

int main() {
    for (auto c: darcambio(123))
        cout << c << ",";
}
