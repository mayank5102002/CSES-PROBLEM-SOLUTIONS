#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<long long> arr(n);
    for(int i = 0; i<n; i++){
        long long temp;
        cin>>temp;
        
        arr[i] = temp;
    }
    
    long long ans = INT_MIN;
    long long sum = 0;
    
    for(int i = 0; i<n; i++){
        sum += arr[i];
        ans = max(ans, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    
    cout<<ans;
}