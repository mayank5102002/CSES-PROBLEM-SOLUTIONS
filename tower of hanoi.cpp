#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> sol;

void solve(int n, int from, int to, int aux){
    
    if(n == 1){
        vector<int> temp;
        temp.push_back(from);
        temp.push_back(to);
        sol.push_back(temp);
        return;
    }
    
    solve(n-1, from, aux, to);
    vector<int> temp;
    temp.push_back(from);
    temp.push_back(to);
    sol.push_back(temp);
    
    solve(n-1, aux, to, from);
    
    return;
    
}

int main() {
    int n;
    cin>>n;
    
    solve(n, 1, 3, 2);
    
    cout<<sol.size()<<endl;
    for(int i = 0; i<sol.size(); i++){
        cout<<sol[i][0]<<" "<<sol[i][1]<<endl;
    }
    
    return 0;
}