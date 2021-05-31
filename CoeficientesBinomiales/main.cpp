#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> dp(100, vector<int>(100,0));

int bruta(int i, int n){ // T(n) <= 2T(n-1) + 1
    if(i == 0 or i == n) //O(2^n)
        return 1;
    else{
        return bruta(i-1,n-1) + bruta(i,n);
    }
}

int dinamic(int i, int n){
    if(i == 0 or i == n) //O(n^2)
        return 1;
    else{
        int s1, s2;
        if(dp[i-1][n-1] == 0){
            dp[i-1][n-1] = bruta(i-1, n-1);
        }
        if(dp[i][n-1] == 0){
            dp[i][n-1] = bruta(i, n-1);
        }
        return dp[i][n-1] + dp[i-1][n-1];
    }
}

int iterativo(int i, int n){
    for (int l=1; l<=n ; l++){
        dp[1][l] = 1;
        dp[l][l] = 1;
        for(int k = 1 ; k<l ; k++){
            dp[k][l] = dp[k-1][l-1] + dp[k][l-1];
        }
    }

    return dp[i][n];
}

int opti(int i, int n) {
    vector<int> prev(n+1, 0), next(n+1,0);
    prev[0] = 1;
    prev[1] = 1;

    for (int l= 2; l <= n; ++l) {
        next[0] = 1;
        next[l] = 1;
        for (int j = 1; j < n; ++j) {
            next[j] = prev[j-1] + prev[j];
        }
        prev = next;
    }

    return prev[i];
}

int main(void){
    cout << opti(2,3);
}