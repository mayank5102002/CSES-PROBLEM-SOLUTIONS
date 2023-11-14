#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main() {
    int n;
    cin>>n;
    
    vector<int> dp(n+100, 0);
    for(int i = 1; i<=6; i++){
        dp[i] = 1;
    }
    
    for(int sum = 1; sum<=n; sum++){
        for(int i = 1; i<=6; i++){
            if(sum>i)
            dp[sum] = (dp[sum]+dp[sum-i])%mod;
        }
    }
    
    cout<<dp[n]%mod;
}