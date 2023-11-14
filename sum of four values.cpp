#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin>>n>>x;
    
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i = 0; i<n; i++){
        cin>>arr[i][0];
        arr[i][1] = i+1;
    }
    
    sort(arr.begin(), arr.end());
    
    map<int, vector<int>> sums;
    
    bool ans = false;
    
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int sum = x-arr[j][0]-arr[i][0];
            if(sums.find(sum) != sums.end()){
                ans = true;
                cout<<sums[sum][0]<<" "<<sums[sum][1]<<" "<<arr[i][1]<<" "<<arr[j][1];
                break;
            }
        }
        if(ans){
            break;
        }
        for(int j = 0; j<i; j++){
            sums[arr[i][0]+arr[j][0]] = {arr[i][1], arr[j][1]};
        }
    }
    
    if(!ans){
        cout<<"IMPOSSIBLE";
    }
}