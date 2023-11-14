#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    set<int> freq;
    
    for(int i = 0; i<n; i++){
        int c;
        cin>>c;
        
        freq.insert(c);
    }
    
    cout<<freq.size();
}