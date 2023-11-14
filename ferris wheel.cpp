#include <iostream>
#include <bits/stdc++.h>
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
    
    sort(arr.begin(), arr.end());
    
    int i = 0, j = n-1;
    int count = 0;
    
    while(i<=j){
        if(i == j){
            count++;
            break;
        }
        int sum = arr[i]+arr[j];
        if(sum > x){
            count++;
            j--;
        } else {
            count++;
            i++;
            j--;
        }
    }
    
    cout<<count;
}