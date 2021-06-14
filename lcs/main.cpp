#include <iostream>
#include <vector>
using namespace std;

int naive(vector<char>& a, vector<char> &b, int i, int j){
    if (i == 0 or  j == 0)
        return 0;
    else if(a[i-1] == b[j-1]){
        return 1 + naive(a,b, i-1, j-1);
    } else
        return max(naive(a,b,i-1,j), naive(a,b,i,j-1));
}

int bottom(vector<char>& a, vector<char> &b, int i, int j){
    vector<vector<int>> dp = vector<vector<int>>(i+1,vector<int>(j+1, -1));

    for (int k = 0; k <= i; ++k) {
        for (int l = 0; l <= j; ++l) {
            if(k == 0 or l == 0)
                dp[k][l] = 0;
            else if(a[k-1] == b[l-1])
                dp[k][l] = dp[k-1][l-1] + 1;
            else
                dp[k][l] = max(dp[k-1][l], dp[k][l-1]);
        }
    }

    return dp[i][j];
}

int top(vector<char>& a, vector<char> &b, vector<vector<int>> &dp, int i, int j){
    if (i == 0 or j == 0)
        dp[i][j] = 0;
    else if(a[i-1] == b[j-1]){
        dp[i][j] = 1 + top(a,b,dp,i-1,j-1);
    } else
        dp[i][j] = max(top(a,b,dp,i-1,j), top(a,b,dp,i,j-1));

    return dp[i][j];
}

int topmemo(vector<char>& a, vector<char> &b, int i, int j){
    vector<vector<int>> dp = vector<vector<int>>(i+1,vector<int>(j+1, -1));
    return top(a,b,dp,i,j);
}


int main() {
    vector<char> x = {'e','s','t','e','r','n','o','c','l','e','i','d','o','m','a','s','t','o','i','d','e','o'};
    vector<char> y = {'e','u','c','l','i','d','i','a','n','o'};

    cout << topmemo(x,y,x.size(),y.size());
}
