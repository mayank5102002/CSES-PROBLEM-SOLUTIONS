#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    map<int, long long int> freq;
    freq[0] = 1;
    
    long long int sum = 0;
    long long int sol = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        int mod = sum%n;
        if(mod < 0){
            mod += n;
        }
        sol += freq[mod];
        freq[mod]++;
    }
    
    cout<<sol;
}