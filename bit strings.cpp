#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;
    
    ll mod = 1e9+7;
    
    ll ans = 1;
    
    for(int i = 0; i<n; i++){
        ans = (ans<<1)%mod;
    }
    
    cout<<ans;
    
    return 0;
}