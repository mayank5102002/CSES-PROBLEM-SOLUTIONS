#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin>>x>>n;
    
    set<int> ranges;
    multiset<int> sizes;
    ranges.insert(0);
    ranges.insert(x);
    sizes.insert(x-0);
    
    for(int i = 0; i<n; i++){
        int r;
        cin>>r;
        
        ranges.insert(r);
        auto curr = ranges.find(r);
        int prevVal = *prev(curr);
        int nextVal = *next(curr);
        
        sizes.erase(sizes.find(nextVal-prevVal));
        sizes.insert(r-prevVal);
        sizes.insert(nextVal-r);
        
        cout<<*sizes.rbegin()<<" ";
    }
    
    return 0;
}