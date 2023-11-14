#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

typedef long long int1;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct range{
    int l, r, index;
    bool operator < (const range &other) const {
        if(l == other.l){
            return r>other.r;
        }
        return l<other.l;
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<range> arr(n);
    map<int1, map<int1, int>> indexes;
    for(int i = 0; i<n; i++){
        int1 x,y;
        cin>>x>>y;
        
        arr[i].l = x;
        arr[i].r = y;
        arr[i].index = i;
    }
    
    sort(arr.begin(), arr.end());
    
    vector<int> contains(n, 0), contained(n, 0);
    
    ordered_set<pair<int, int>> left;
    
    for(int i = 0; i<n; i++){
        left.insert({arr[i].r, -1*i});
        contains[arr[i].index] = left.size()-left.order_of_key({arr[i].r, -1*i})-1;
    }
    left.clear();
    for(int i = n-1; i>=0; i--){
        left.insert({arr[i].r, -1*i});
        contained[arr[i].index] = left.order_of_key({arr[i].r, -1*i});
    }
    
    for(int i = 0; i<n; i++){
        cout<<contained[i]<<" ";
    }
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<contains[i]<<" ";
    }
}