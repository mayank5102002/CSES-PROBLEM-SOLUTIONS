#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    set<pair<ll, ll>> left, right;
    ll leftSum = 0, rightSum = 0;
    
    for(ll i = 0; i<k; i++){
        right.insert({arr[i], i});
        rightSum += arr[i];
        
        while(right.size() > left.size()){
            auto itr = right.begin();
            // cout<<(*itr).first<<" "<<(*itr).second<<endl;
            rightSum -= (*itr).first;
            leftSum += (*itr).first;
            left.insert(*itr);
            right.erase(*itr);
        }
        while((*left.rbegin()).first > (*right.begin()).first && right.size() > 0){
            auto f = *left.rbegin(), s = *right.begin();
            // cout<<f.first<<" "<<s.first<<endl;
            leftSum -= f.first, leftSum += s.first;
            rightSum -= s.first, rightSum += f.first;
            left.erase(f), right.erase(s);
            left.insert(s), right.insert(f);
        }
    }
    cout<<left.size()*(*left.rbegin()).first-leftSum + rightSum - right.size()*(*left.rbegin()).first<<" ";
    
    for(ll i = k; i<n; i++){
        pair<ll, ll> toRem = {arr[i-k], i-k};
        if(left.find(toRem) != left.end()){
            left.erase(toRem);
            leftSum -= arr[i-k];
            if(left.size() < right.size()){
                auto itr = right.begin();
                rightSum -= (*itr).first;
                leftSum += (*itr).first;
                left.insert(*itr);
                right.erase(*itr);
            }
        }
        if(right.find(toRem) != right.end()){
            right.erase(toRem);
            rightSum -= arr[i-k];
            if(left.size()-right.size() == 2){
                auto itr = left.rbegin();
                leftSum -= (*itr).first;
                rightSum += (*itr).first;
                right.insert(*itr);
                left.erase(*itr);
            }
        }
        
        right.insert({arr[i], i});
        rightSum += arr[i];
        
        while(right.size() > left.size()){
            auto itr = right.begin();
            rightSum -= (*itr).first;
            leftSum += (*itr).first;
            left.insert(*itr);
            right.erase(*itr);
        }
        while((*left.rbegin()).first > (*right.begin()).first && right.size() > 0){
            auto f = *left.rbegin(), s = *right.begin();
            leftSum -= f.first, leftSum += s.first;
            rightSum -= s.first, rightSum += f.first;
            left.erase(f), right.erase(s);
            left.insert(s), right.insert(f);
        }
        cout<<left.size()*(*left.rbegin()).first-leftSum + rightSum - right.size()*(*left.rbegin()).first<<" ";
    }
    return 0;
}