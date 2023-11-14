#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mov{
    ll s, e;
    bool operator < (const mov &other) const {
        return e<other.e;
    }
};
 
int main() {
    ll n, k;
    cin>>n>>k;
    
    vector<mov> movies(n);
    for(ll i = 0; i<n; i++){
        cin>>movies[i].s;
        cin>>movies[i].e;
    }
    
    sort(movies.begin(), movies.end());
    
    multiset<ll> pq;
    ll total = 0;
    for(ll i = 0; i<n; i++){
        if(pq.size() == 0 || (pq.size() < k && movies[i].s < *pq.begin())){
            ll top = movies[i].e;
            pq.insert(top);
            total++;
        } else if(movies[i].s >= *pq.begin()){
            auto itr = pq.lower_bound(movies[i].s);
            if(*itr != movies[i].s)
            itr--;
            pq.erase(itr);
            pq.insert(movies[i].e);
            total++;
        }
    }
    
    cout<<total<<endl;
    
}