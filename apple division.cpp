#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll sol = INT_MAX;

void solve(vector<ll>& a, int i, ll diff, unordered_map<int, unordered_map<ll, int>>& dp){
    
    if(i == a.size()){
        sol = min(sol, abs(diff));
        return;
    }
    
    if(dp.find(i) != dp.end() && dp[i].find(diff) != dp[i].end()){
        return;
    }
    
    //Include current in first
    solve(a, i+1, diff+a[i], dp);
    
    //Include current in second
    solve(a, i+1, diff-a[i], dp);
    
    dp[i][diff] = 1;
    return;
}

int main() {
    int n;
    cin>>n;
    
    vector<ll> a;
    for(int i = 0; i<n; i++){
        ll temp;
        cin>>temp;
        a.push_back(temp);
    }
    
    unordered_map<int, unordered_map<ll, int>> dp;
    
    solve(a, 0, 0, dp);
    
    cout<<sol;
    
    return 0;
}