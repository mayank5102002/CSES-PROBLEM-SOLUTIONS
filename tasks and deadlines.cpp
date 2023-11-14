#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i = 0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    
    sort(arr.begin(), arr.end());
    
    long long int current = 0, sol = 0;
    
    for(int i = 0; i<n; i++){
        current += arr[i][0];
        
        sol += arr[i][1]-current;
    }
    
    cout<<sol;
    
    return 0;
}