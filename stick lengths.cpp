#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int1 long long

int main() {
    int n;
    cin>>n;
    
    vector<int1> arr;
    for(int i = 0; i<n; i++){
        int1 temp;
        cin>>temp;
        
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    
    int1 mid = arr[n/2];
    
    int1 sol = 0;
    for(int i = 0; i<n; i++){
        sol += abs(mid-arr[i]);
    }
    
    if(n%2 == 0){
        int1 sol2 = 0;
        mid = arr[n/2]-1;
        for(int i = 0; i<n; i++){
            sol2 += abs(mid-arr[i]);
        }
        sol = min(sol, sol2);
    }
    
    cout<<sol;
}