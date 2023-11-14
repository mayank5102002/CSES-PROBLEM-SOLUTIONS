#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin>>n;
    
    ll sum = n*(n+1)/2;
    
    if(sum%2 == 1){
        cout<<"NO";
        return 0;
    } else {
        vector<int> a, b;
        if(n%4 == 0){
            for(int i = 1; i<=n/4; i++){
                a.push_back(i);
            }
            for(int i = 0; i<n/4; i++){
                a.push_back(n-i);
            }
            for(int i = 1; i<=a.size(); i++){
                b.push_back(i+n/4);
            }
        } else if(n%4 == 3){
            for(int i = 0; i<n/4; i++){
                a.push_back(4+i);
            }
            for(int i = 0; i<n/4; i++){
                a.push_back(n-i);
            }
            for(int i = 0; i<a.size(); i++){
                b.push_back(i+4+n/4);
            }
            a.push_back(1), a.push_back(2);
            b.push_back(3);
        } else {
            cout<<"NO";
            return 0;
        }
        
        cout<<"YES"<<endl;
    
        cout<<a.size()<<endl;
        for(int i = 0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl<<b.size()<<endl;
        for(int i = 0; i<b.size(); i++){
            cout<<b[i]<<" ";
        }
    
        
    }
    return 0;
}