#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;

    while(n--){
        ll a, b;
        cin>>a>>b;
        
        if(a>b)swap(a, b);
        
        if(2*a < b){
            cout<<"NO"<<endl;
        } else {
            a %=3, b%=3;
            
            if((a==0 and b==0) or (a==1 and b==2) or (a == 2 and b == 1)){
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    
    return 0;
}