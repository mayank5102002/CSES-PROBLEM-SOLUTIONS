#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    
    int n;
    cin>>n;
    
    ll ans = 0;
    
    ll mx = 0;
    
    for(int i = 0; i<n; i++){
        ll t;
        cin>>t;
        
        mx = max(mx, t);
        ans += mx-t;
    }
    
    cout<<ans;
    
}