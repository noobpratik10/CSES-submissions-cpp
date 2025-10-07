/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    long long sum;
    vector<Node*>children;
    
    Node(){
        this->sum=0;
    }
};

void getSum(Node*&root){
    if(root==NULL){
        return;
    }
    
    // First recursively process all children
    for(auto &child:root->children){
        getSum(child);
    }
    
    // Then calculate subordinates: each child + all their subordinates
    for(auto &child:root->children){
        root->sum += 1 + child->sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<Node*>nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }

    for(int i=0;i<n-1;i++){
        int child=i+1;
        int par;
        cin>>par;
        par=par-1;
        nodes[par]->children.push_back(nodes[child]);
    }
    
    getSum(nodes[0]);
    
    for(int i=0;i<n;i++){
        cout<<nodes[i]->sum;
        if(i < n-1) cout<<" ";
    }
    cout<<endl;
    
    return 0;
}