#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin>>n>>x;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    map<int, int> freq;
    int s = 0;
    long long int sol = 0;
    for(int i = 0; i<n; i++){
        freq[arr[i]]++;
        
        while(freq.size() > x){
            freq[arr[s]]--;
            if(freq[arr[s]] == 0){
                freq.erase(arr[s]);
            }
            s++;
        }
        
        sol += i-s+1;
    }
    
    cout<<sol;
}