#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    map<int, int> tickets;
    
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        
        tickets[temp]++;
    }
    
    vector<int> people(m);
    for(int i = 0; i<m; i++){
        int temp;
        cin>>temp;
        
        if(tickets.size() == 0){
            cout<<-1<<endl;
            continue;
        }
        
        auto it = tickets.lower_bound(temp);
        if((*it).first == temp){
            cout<<(*it).first<<endl;
            if(tickets[(*it).first] == 1){
                tickets.erase((*it).first);
            } else {
                tickets[(*it).first]--;
            }
        } else if(it == tickets.begin()){
            cout<<-1<<endl;
        } else {
            if((*it).first != temp)
                it--;
            cout<<(*it).first<<endl;
            if(tickets[(*it).first] == 1){
                tickets.erase((*it).first);
            } else {
                tickets[(*it).first]--;
            }
        }
    }
    
    
}