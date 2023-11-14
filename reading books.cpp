#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<long long int> books(n);
    for(int i = 0; i<n; i++){
        cin>>books[i];
    }
    
    long long int s = 0, maxi = INT_MIN;
    
    for(int i = 0; i<n; i++){
        s += books[i];
        maxi = max(maxi, books[i]);
    }
    
    if(s <= 2*maxi){
        cout<< 2*maxi;
    } else {
        cout<<s;
    }
    
    return 0;
}