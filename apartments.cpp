#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<int> req(n);
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        
        req[i] = temp;
    }
    
    vector<int> ap(m);
    for(int i = 0; i<m; i++){
        int temp;
        cin>>temp;
        
        ap[i] = temp;
    }
    
    sort(req.begin(), req.end());
    sort(ap.begin(), ap.end());
    
    int count = 0;
    
    int i = 0, j = 0;
    
    while(i<n && j<m){
        while(j<m && i<n && req[i]-k > ap[j]){
            j++;
        }
        while(i<n && j<m && req[i]+k < ap[j]){
            i++;
        }
        if(i<n && j<m && ap[j]>=req[i]-k && ap[j]<=req[i]+k){
            i++;
            j++;
            count++;
        }
    }
    
    cout<<count;
}