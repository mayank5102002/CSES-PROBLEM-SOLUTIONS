#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& arr, long long mid, int groups){
    long long g = 0;
    long long sum = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > mid){
            return false;
        }
        sum += arr[i];
        if(sum > mid){
            g++;
            sum = arr[i];
        }
    }
    
    if(g+1 <= groups){
        return true;
    }
    return false;
}

int main() {
    int n, x;
    cin>>n>>x;
    
    vector<long long> arr(n);
    long long e = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        e += arr[i];
    }
    
    long long s = 0;
    long long sol = e;
    while(s<=e){
        long long mid = (s+e)/2;
        
        if(check(arr, mid, x)){
            sol = min(sol, mid);
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    
    cout<<sol;
    
}