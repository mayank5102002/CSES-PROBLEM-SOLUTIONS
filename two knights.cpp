#include <iostream>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;
    
    for(int i = 1; i<=n; i++){
        
        ll a = i*i, a2 = a*(a-1)/2;
        
        cout<<a2-4*(i-1)*(i-2)<<endl;
        
    }
    
    return 0;
}