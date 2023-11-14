#include <bits/stdc++.h>
using namespace std;

struct cus{
    int s, e, index;
    bool operator < (const cus &other) const {
        return s<other.s;
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<cus> customers(n);
    for(int i = 0; i<n; i++){
        cin>>customers[i].s;
        cin>>customers[i].e;
        customers[i].index = i;
    }
    
    sort(customers.begin(), customers.end());
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> rooms(n);
    int total = 0;
    for(int i = 0; i<n; i++){
        if(pq.size() == 0 || customers[i].s <= pq.top()[0]){
            total++;
            pq.push({customers[i].e, total});
            rooms[customers[i].index] = total;
        } else {
            vector<int> top = pq.top();
            pq.pop();
            rooms[customers[i].index] = top[1];
            top[0] = customers[i].e;
            pq.push(top);
        }
    }
    
    cout<<total<<endl;
    for(int i = 0; i<n; i++){
        cout<<rooms[i]<<" ";
    }
    
}