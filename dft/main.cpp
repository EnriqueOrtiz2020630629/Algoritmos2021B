#include <iostream>
#include <complex>
#include <vector>

using namespace std;

vector<vector<double>> dft(vector<double> arr){
    int N = arr.size();
    vector<vector<double>> out(2, vector<double>(N, 0));
    for (int k=0; k < N; ++k) {
        for (int n=0; n < N; ++n) {
            out[0][k] += arr[n]*cos(((2*M_PI)/N)*k*n);
            out[1][k] += -arr[n]*sin(((2*M_PI)/N)*k*n);
        }
    }
    return out;
}

int main() {
    vector<double> arr = {1,2,3,4};
    vector<vector<double>> os = dft(arr);

    for (int i = 0; i < os[0].size(); ++i) {
        cout << os[0][i] << " +i" << os[1][i] << endl;
    }
}
