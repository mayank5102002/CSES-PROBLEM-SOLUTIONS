#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, a, b;
    cin>>n>>a>>b;
    
    vector<ll> arr(n);
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(ll i = 1; i<n; i++){
        prefix[i] = arr[i]+prefix[i-1];
    }
    
    set<pair<ll, ll>> s;
    for(ll i = a-1; i<b; i++){
        s.insert({prefix[i], i});
    }
    ll sol = -1e18;
    sol = max(sol, (*s.rbegin()).first);
    
    for(ll i = 1; i<n; i++){
        if(i+a-1 == n)
        break;
        
        auto itr = s.find({prefix[i+a-2], i+a-2});
        s.erase(itr);
        
        if(i+b-1 < n){
            s.insert({prefix[i+b-1], i+b-1});
        }
        sol = max(sol, (*s.rbegin()).first-prefix[i-1]);
    }
    
    cout<<sol;
}