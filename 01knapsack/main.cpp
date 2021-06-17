#include <iostream>
#include <vector>
using namespace std;

int recursivo(vector<int> &weight, vector<int> &value, int i, int W){//O(2^n)
    if(i == 0 or W == 0)
        return 0;
    if(weight[i-1]  > W)
        return recursivo(weight,value, i-1, W);
    else
        return max(recursivo(weight,value, i-1, W), value[i-1] + recursivo(weight,value,i-1, W-weight[i-1]));
}

int bottom(vector<int> &weight, vector<int> &value, int i, int W){
    vector<vector<int>> dp = vector<vector<int>>(i+1, vector<int>(W+1,-1));

    for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= W; ++k) {
            if(j == 0 or k == 0)
                dp[j][k] = 0;
            else if(k >= weight[j-1])
                dp[j][k] = max(dp[j-1][k], value[j-1] + dp[j-1][k-weight[j-1]]);
            else {
                dp[j][k] = dp[j-1][k];
            }
        }
    }

    return dp[i][W];
}


int top(vector<int> &weight, vector<int> &value, int i, int W, vector<vector<int>>& dp){
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if(weight[i-1]  > W){
        dp[i][W] =  top(weight,value, i-1, W,dp);
        return dp[i][W];
    }
    else{
        dp[i][W] = max(top(weight,value, i-1, W,dp), value[i] + top(weight,value,i-1, W-weight[i],dp));
        return dp[i][W];
    }
}

int memo(vector<int> &weight, vector<int> &value, int i, int W){
    vector<vector<int>> dp = vector<vector<int>>(i+1, vector<int>(W+1,-1));
    return top(weight,value,i,W,dp);
};

int main() {
    vector<int> v = {60,100,120};
    vector<int> w = {10,20,30};

    cout << memo(w,v,3,50);
}
