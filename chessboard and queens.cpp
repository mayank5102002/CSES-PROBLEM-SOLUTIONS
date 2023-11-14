#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& grid, int n, int r, int c){
    int x = r-1, y = c-1;
    
    while(x>=0 && y>=0){
        if(grid[x][y] == '0'){
            return true;
        }
        x--;
        y--;
    }
    
    x = r+1, y = c-1;
    while(x<n && y>=0){
        if(grid[x][y] == '0'){
            return true;
        }
        x++;
        y--;
    }
    
    return false;
}

int rec(vector<vector<char>>& grid, int n, int col, vector<bool>& rowise){
    if(col >= n){
        return 1;
    }
    
    int sol = 0;
    
    for(int i = 0; i<n; i++){
        if(grid[i][col] == '*'){
            continue;
        }
        if(rowise[i] == true){
            continue;
        }
        
        if(check(grid, n, i, col)){
            continue;
        }
        
        rowise[i] = true;
        grid[i][col] = '0';
        sol += rec(grid, n, col+1, rowise);
        grid[i][col] = '.';
        rowise[i] = false;
    }
    
    return sol;
}

int main() {
    int n = 8;
    
    vector<vector<char>> grid(n, vector<char>(n));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char temp;
            cin>>temp;
            
            grid[i][j] = temp;
        }
    }
    
    vector<bool> queenPresentInRow(n, false);
    
    cout<<rec(grid, n, 0, queenPresentInRow);
}