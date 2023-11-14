#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int1 long long

struct custom_sort
{
    inline bool operator() (const vector<int1>& arr1, const vector<int1>& arr2)
    {
        if (arr1[1] != arr2[1]){
            return arr1[1]<arr2[1];
        } else {
            return arr1[0]>arr2[0];
        }
    }
};

int main() {
    int n;
    cin>>n;
    
    vector<vector<int1>> arr;
    map<int1, map<int1, int>> indexes;
    for(int i = 0; i<n; i++){
        int1 x,y;
        cin>>x>>y;
        
        vector<int1> temp = {x,y};
        indexes[x][y] = i;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end(), custom_sort());
    
    vector<int> contains(n, 0), contained(n, 0);
    
    int1 maxi = arr[0][0];
    for(int i = 1; i<n; i++){
        if(arr[i][0] <= maxi){
            contains[indexes[arr[i][0]][arr[i][1]]] = 1;
        }
        maxi = max(maxi, arr[i][0]);
    }
    
    int1 mini = INT_MAX;
    for(int i = n-1; i>=0; i--){
        if(arr[i][0] >= mini){
            contained[indexes[arr[i][0]][arr[i][1]]] = 1;
        }
        mini = min(mini, arr[i][0]);
    }
    
    for(int i = 0; i<n; i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<contained[i]<<" ";
    }
}