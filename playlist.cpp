#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<int> arr(n+1);
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        
        arr[i+1] = temp;
    }
    
    map<int, int> freq;
    int temp = -1;
    int sol = 0;
    
    for(int i = 1; i<=n; i++){
        temp = max(temp, freq[arr[i]]+1);
        // cout<<arr[i]<<" "<<temp<<endl;
        sol = max(sol, i-temp+1);
        freq[arr[i]] = i;
    }
    
    cout<<sol;
}