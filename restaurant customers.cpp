#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    map<int, int> freq;
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        
        freq[s]++;
        freq[e+1]--;
    }
    
    int count = 0;
    int sum = 0;
    
    for(auto [key, value] : freq){
        sum += value;
        count = max(count, sum);
    }
    
    cout<<count;
    
}