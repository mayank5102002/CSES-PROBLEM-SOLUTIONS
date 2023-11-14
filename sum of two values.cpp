#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin>>n>>x;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        
        arr[i] = temp;
    }
    
    map<int, int> freq;
    bool ans = false;
    for(int i = 0; i<n; i++){
        int temp = arr[i];
        
        if(temp >= x){
            continue;
        }
        
        int diff = x-temp;
        if(freq.find(diff) != freq.end()){
            cout<<freq[diff]<<" "<<i+1;
            ans = true;
            break;
        }
        freq[temp] = i+1;
    }
    
    if(ans == false){
        cout<<"IMPOSSIBLE";
    }
}