#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin>>n>>x;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    map<long long int, long long int> freq;
    freq[0] = 1;
    
    long long int sum = 0;
    long long int sol = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        sol += freq[sum-x];
        freq[sum]++;
    }
    
    cout<<sol;
}