#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    
    string s;
    cin>>s;
    
    int ans = 1;
    char c = 'A';
    int count = 0;
    
    for(auto d : s){
        if(d == c){
            count++;
            ans = max(ans, count);
        } else {
            c = d;
            count = 1;
        }
    }
    
    cout<<ans;
    
}