#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool comparador(pair<int, int> i1, pair<int, int> i2){
    return i1.first/i1.second > i2.first/i2.second;
}

vector<double> knapsacksolucion(vector<pair<int,int>> arr, int w){
    vector<double> solucion = vector<double>(arr.size(),0);
    sort(arr.begin(), arr.end(), comparador);

    int index = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if(w-arr[i].second >= 0){
            w -= arr[i].second;
            solucion[i] = 1;
            index = i+1;
        } else
            break;
    }

    if(w>0){
        solucion[index] = (float)w/arr[index].second;
    }

    return solucion;
}

double knapsackvalor(vector<pair<int,int>> arr, int w){
    double solucion = 0;
    sort(arr.begin(), arr.end(), comparador);

    int index = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if(w-arr[i].second >= 0){
            w -= arr[i].second;
            solucion += arr[i].first;
            index = i+1;
        } else
            break;
    }

    if(w>0){
        solucion += arr[index].first*((double)w/arr[index].second);
    }

    return solucion;
}


int main() {
    vector<pair<int,int>> test = {make_pair(60,10), make_pair(100,20), make_pair(120,30)};

    vector<double> ans = knapsacksolucion(test, 50);

    for (auto c: ans) {
        cout << c << '|';
    }

    cout << knapsackvalor(test, 50);
    return 0;
}
