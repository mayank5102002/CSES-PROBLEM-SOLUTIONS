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
    
    int1 sum = 0;
    
    for(int i = 0; i<n; i++){
        if(arr[i] > sum){
            if(arr[i]-sum > 1){
                break;
            }
        }
        sum += arr[i];
    }
    
    cout<<sum+1;
}