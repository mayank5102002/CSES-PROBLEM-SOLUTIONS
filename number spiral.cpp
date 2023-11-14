#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;
    
    for(ll i = 0; i<n; i++){
        ll r, c;
        cin>>r;
        cin>>c;
        
        ll z = max(r, c);
        ll z2 = (z-1)*(z-1);
        
        ll ans = z2;
        
        if(z&1){
            if(r == z){
                ans += c;
            } else {
                ans += z + (z-r);
            }
        } else {
            if(c == z){
                ans += r;
            } else {
                ans += z + (z-c);
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}