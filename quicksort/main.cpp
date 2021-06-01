#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &vec, int a, int b){
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}

int partition(vector<int> &vec,int p, int r){
    int x = vec[r];
    int i = p-1;
    for (int j = p; j < r; ++j) {
        if(vec[j] <= x){
            i++;
            swap(vec,i,j);
        }
    }
    swap(vec, i+1 , r);

    return i+1;
}

void quicksort(vector<int> &vec, int p, int r){
    if(p < r){
        int pvt = partition(vec, p,r);
        quicksort(vec, p, pvt-1);
        quicksort(vec, pvt+1, r);
    }
}

int main() {
    vector<int> test = {3,9,9,5,2,8,7,4,1,2,6,1};
    quicksort(test,0,11);
    for (auto c: test) {
        cout << c;
    }
}
