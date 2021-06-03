#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp(100,-1);

long long fib(int n){
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    if(dp[n] == -1)
        dp[n] = fib(n-1) + fib(n-2);

    return dp[n];
}
int main() {
    cout << fib(15);
}
