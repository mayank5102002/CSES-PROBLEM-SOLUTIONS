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
    
    stack<pair<int, int>> s;
    s.push({-1, 0});
    
    for(int i = 0; i<n; i++){
        while(s.size() > 1 && s.top().first >= arr[i]){
            s.pop();
        }
        
        cout<<s.top().second<<" ";
        s.push({arr[i], i+1});
    }
}