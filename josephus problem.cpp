#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int v){
        this->val = v;
    }
};

int main() {
    int n;
    cin>>n;
    
    Node* head = new Node(1);
    Node* curr = head;
    
    for(int i = 2; i<=n; i++){
        Node* temp = new Node(i);
        curr->next = temp;
        curr = temp;
    }
    curr->next = head;
    curr = head;
    
    while(curr->next != curr){
        cout<<curr->next->val<<" ";
        curr->next = curr->next->next;
        curr = curr->next;
    }
    cout<<curr->val;
    
    return 0;
}