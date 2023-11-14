#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    vector<vector<int>> d;
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        
        vector<int> temp;
        temp.push_back(e);
        temp.push_back(s);
        
        d.push_back(temp);
    }
    
    sort(d.begin(), d.end());
    
    int end = 0;
    int count = 0;
    
    for(int i = 0; i<n; i++){
        if(end <= d[i][1]){
            count++;
            end = d[i][0];
        }
    }
    
    cout<<count;
}