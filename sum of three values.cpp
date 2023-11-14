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
    
    bool ans = false;
    
    for(int i = 0; i<n; i++){
        int j = i+1, k = n-1;
        while(j<k){
            int sum = arr[i][0]+arr[j][0]+arr[k][0];
            if(sum == x){
                ans = true;
                cout<<arr[i][1]<<" "<<arr[j][1]<<" "<<arr[k][1];
                break;
            } else if(sum < x){
                j++;
            } else {
                k--;
            }
        }
        if(ans){
            break;
        }
    }
    
    if(!ans){
        cout<<"IMPOSSIBLE";
    }
}