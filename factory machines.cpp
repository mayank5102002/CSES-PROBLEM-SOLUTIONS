#include <bits/stdc++.h>
using namespace std;
#define ii long long int

bool check(vector<ii>& p, ii t, ii m){
    int prod = 0;
    
    for(int i = 0; i<p.size(); i++){
        if(m >= p[i])
        prod += m/p[i];
        
        if(prod >= t){
            return true;
        }
    }
    
    return false;
}

int main() {
    ii n, t;
    cin>>n>>t;
    
    vector<ii> products(n);
    ii mini = INT_MAX;
    for(ii i = 0; i<n; i++){
        cin>>products[i];
        mini = min(mini, products[i]);
    }
    
    ii s = 1, e = mini*t;
    while(s<=e){
        ii mid = (s+e)/2;
        if(check(products, t, mid)){
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    
    cout<<s;
    
    return 0;
}