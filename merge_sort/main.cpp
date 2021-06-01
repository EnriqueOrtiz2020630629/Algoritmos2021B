#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

vector<int> merge(vector<int> vec, vector<int> b, vector<int> c){
    int i = 0, j=0,k=0;
    while (i<b.size() and j<c.size()){
        if(b[i] <= c[j]){
            vec[k] = b[i];
            i++;
        } else{
            vec[k] = c[j];
            j++;
        }
        k++;
    }

    if(i==b.size()){
        for (int l = j; l < c.size(); ++l) {
            vec[k] = c[l];
            k++;
        }
    } else{
        for (int l = i; l < b.size(); ++l) {
            vec[k] = b[l];
            k++;
        }
    }

    return vec;
}

vector<int> mergesort(vector<int> vec){
    int n = vec.size();
    int p = floor(n/2);
    if(n>1) {
        vector<int> b(vec.begin(), vec.begin() + p);
        vector<int> c(vec.begin() + p, vec.end());
        b= mergesort(b);
        c= mergesort(c);
        vec = merge(vec, b, c);
    }
    return vec;
}

int main() {
    vector<int> test = {8,3,2,9,7,1,5,4};
    vector<int> ans = mergesort(test);
    for(auto c : ans)
        cout << c;
}
