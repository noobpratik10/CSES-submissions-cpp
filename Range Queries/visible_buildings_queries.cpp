/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int>arr;
stack<int>st;
vector<int>nextGreater;
vector<int>nextGCnt;
vector<vector<int>>segTree; //cnt min max

void buildSegTree(int index,int low,int high){
    if(low==high){
        segTree[index]={1,low,low};
        return;
    }
    
    int mid=low+(high-low)/2;
    buildSegTree(2*index+1,low,mid);
    buildSegTree(2*index+2,mid+1,high);
    
    
    //case1:max tower of first child is less thatn min tower of second child
    if(arr[segTree[2*index+1][2]]<arr[segTree[2*index+2][1]]){
        segTree[index][0]=segTree[2*index+1][0]+segTree[2*index+2][0];
        segTree[index][1]=segTree[2*index+1][1];
        segTree[index][2]=segTree[2*index+2][2];
    }
    //case2:max tower of first child is greater than eql to max tower of second child
    else if(arr[segTree[2*index+1][2]]>=arr[segTree[2*index+2][2]]){
        segTree[index][0]=segTree[2*index+1][0];
        segTree[index][1]=segTree[2*index+1][1];
        segTree[index][2]=segTree[2*index+1][2];        
    }
    //case3:-max tower of left child is somewhere btw range of min and max tower 
    //of right child
    else{
        int rightCnt=0;
        int nextGOfMaxLeft=nextGreater[segTree[2*index+1][2]];
        if(nextGOfMaxLeft<=segTree[2*index+2][2]){
            rightCnt+=(1+nextGCnt[nextGOfMaxLeft]);
            rightCnt-=nextGCnt[segTree[2*index+2][2]];
        }
        segTree[index][0]=segTree[2*index+1][0]+rightCnt;
        segTree[index][1]=segTree[2*index+1][1];
        segTree[index][2]=segTree[2*index+2][2];
    }
}

vector<int>querySegTree(int index,int low,int high,int lRange,int hRange){
    if(hRange<low || high<lRange){
        return {0, -1, -1};
    }
    if(lRange<=low && high<=hRange){
        return segTree[index];
    }
    
    int mid=low+(high-low)/2;
    vector<int>lAns=querySegTree(2*index+1,low,mid,lRange,hRange);
    vector<int>rAns=querySegTree(2*index+2,mid+1,high,lRange,hRange);
    
    if(lAns[0]==0){
        return rAns;
    }
    else if(rAns[0]==0){
        return lAns;
    }
    else{
        vector<int>curAns={0,-1,-1};
        //case1:max tower of first child is less thatn min tower of second child
        if(arr[lAns[2]]<arr[rAns[1]]){
            curAns[0]=lAns[0]+rAns[0];
            curAns[1]=lAns[1];
            curAns[2]=rAns[2];
        }
        //case2:max tower of first child is greater than eql to max tower of second child
        else if(arr[lAns[2]]>=arr[rAns[2]]){
            curAns[0]=lAns[0];
            curAns[1]=lAns[1];
            curAns[2]=lAns[2];        
        }
        //case3:-max tower of left child is somewhere btw range of min and max tower 
        //of right child
        else{
            int rightCnt=0;
            int nextGOfMaxLeft=nextGreater[lAns[2]];
            if(nextGOfMaxLeft<=rAns[2]){
                rightCnt+=(1+nextGCnt[nextGOfMaxLeft]);
                rightCnt-=nextGCnt[rAns[2]];
            }
            curAns[0]=lAns[0]+rightCnt;
            curAns[1]=lAns[1];
            curAns[2]=rAns[2];
        } 
        return curAns;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    nextGreater.resize(n,n);
    nextGCnt.resize(n,0);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nextGreater[i]=st.top();
            nextGCnt[i]=st.size();
        }
        st.push(i);
    }
    
    segTree.resize(4*n,{0,-1,-1});
    buildSegTree(0,0,n-1);
    
    vector<int>ans;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        
        vector<int>curAns=querySegTree(0,0,n-1,a,b);
        ans.push_back(curAns[0]);
    }
    
    for(auto &i:ans){
        cout<<i<<endl;
    }

    return 0;
}