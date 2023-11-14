#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        
        arr[i] = x;
    }
    
    map<int, int> towers;
    for(int i = 0; i<n; i++){
        int curr = arr[i];
        
        auto it = towers.upper_bound(curr);
        
        if(it == towers.end()){
            towers[curr]++;
        } else {
            towers[curr]++;
            towers[(*it).first]--;
            if(towers[(*it).first] == 0){
                towers.erase((*it).first);
            }
        }
    }
    
    int count = 0;
    
    for(auto [key, value] : towers){
        count += value;
    }
    
    cout<<count;
    
}