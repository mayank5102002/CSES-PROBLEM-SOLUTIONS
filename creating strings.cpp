#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<string> sol;

void solve(unordered_map<char, int>& freq, string s, int n){
    
    if(s.length() == n){
        sol.push_back(s);
        return;
    }
    
    for(int i = 0; i<26; i++){
        char c = 'a'+i;
        
        if(freq[c] > 0){
            freq[c]--;
            solve(freq, s+c, n);
            freq[c]++;
        }
    }
    
    return;
}

int main() {
    string s;
    cin>>s;
    
    unordered_map<char, int> freq;
    for(auto c : s){
        freq[c]++;
    }
    string temp = "";
    solve(freq, temp, s.length());
    
    cout<<sol.size()<<endl;
    for(int i = 0; i<sol.size(); i++){
        cout<<sol[i]<<endl;
    }
    
    return 0;
}