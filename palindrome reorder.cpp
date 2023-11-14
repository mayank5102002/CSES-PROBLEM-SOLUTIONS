#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string s;
    cin>>s;
    
    unordered_map<char, int> freq;
    
    for(auto c : s){
        freq[c]++;
    }
    
    int count = 0;
    for(int i = 0; i<26; i++){
        char c = i+'A';
        if(freq[c]&1){
            count++;
        }
    }
    
    
    if(count > 1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    
    string ans1 = "", ans2 = "";
    
    char temp = '0';
    
    for(int i = 0; i<26; i++){
        char c = i+'A';
        if(freq[c]&1){
            temp = c;
        }
        
        
        for(int j = 0; j<freq[c]/2; j++){
            ans1 += c;
            ans2 += c;
        }
    }
    
    
    if(count == 1){
        ans1 += temp;
    }
    reverse(ans2.begin(), ans2.end());
    ans1 += ans2;
    
    cout<<ans1;
    
    return 0;
}