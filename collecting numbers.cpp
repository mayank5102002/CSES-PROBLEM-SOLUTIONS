#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    map<int, int> arr;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        
        arr[temp] = i;
    }
    
    int temp = -1;
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i+1] < temp){
            count++;
        }
        temp = arr[i+1];
    }
    
    cout<<count+1;
}