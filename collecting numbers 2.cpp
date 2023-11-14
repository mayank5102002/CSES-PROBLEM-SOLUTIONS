#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    vector<int> arr(n+2, 0), ind(n+1);
    arr[n+1] = n+1;
    for(int i = 1; i<=n; i++){
        int temp;
        cin>>temp;
        
        arr[temp] = i;
        ind[i] = temp;
    }
    
    int temp = 1;
    int count = 1;
    for(int i= 1; i<=n; i++){
        if(temp > arr[i]){
            count++;
        }
        temp = arr[i];
    }
    
    for(int i = 0; i<m; i++){
        int s, e;
        cin>>s>>e;
        
        int fir = ind[s], sec = ind[e];
        swap(ind[s], ind[e]);
        
        if(arr[fir-1] > arr[fir] && arr[fir-1] <= e){
            count--;
        }
        if(arr[fir-1] <= arr[fir] && arr[fir-1] > e){
            count++;
        }
        if(arr[fir+1] >= arr[fir] && arr[fir+1] < e){
            count++;
        }
        if(arr[fir+1] < arr[fir] && arr[fir+1] >= e){
            count--;
        }
        
        arr[fir] = e;
        
        if(arr[sec-1] > arr[sec] && arr[sec-1] <= s){
            count--;
        }
        if(arr[sec-1] <= arr[sec] && arr[sec-1] > s){
            count++;
        }
        if(arr[sec+1] >= arr[sec] && arr[sec+1] < s){
            count++;
        }
        if(arr[sec+1] < arr[sec] && arr[sec+1] >= s){
            count--;
        }
        
        arr[sec] = s;
        
        cout<<count<<endl;
    }
    
}