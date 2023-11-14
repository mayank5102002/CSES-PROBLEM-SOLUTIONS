#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> solve(int n){
    
    vector<string> res;
    
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    
    vector<string> temp = solve(n-1);
    for(int i = 0; i<temp.size(); i++){
        res.push_back('0'+temp[i]);
    }
    for(int i = temp.size()-1; i>=0; i--){
        res.push_back('1'+temp[i]);
    }
    
    return res;
}

int main() {
    int n;
    cin>>n;
    
    vector<string> res = solve(n);
    for(int i = 0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
}