#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main() {
    int n, k;
    cin>>n>>k;
    
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    ordered_set<pair<int, int>> s;
    for(int i = 0; i<k; i++){
        s.insert({arr[i], i});
    }
    
    if(s.size()%2 == 0)
    cout<<(*s.find_by_order(s.size()/2-1)).first<<" ";
    else
    cout<<(*s.find_by_order(s.size()/2)).first<<" ";
    
    for(int i = k; i<n; i++){
        s.insert({arr[i], i});
        s.erase({arr[i-k], i-k});
        if(s.size()%2 == 0)
        cout<<(*s.find_by_order(s.size()/2-1)).first<<" ";
        else
        cout<<(*s.find_by_order(s.size()/2)).first<<" ";
    }
    
}