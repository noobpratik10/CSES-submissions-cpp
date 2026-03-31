/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Approach1:-
//  --> Using merge sort seg tree + binary search
//  --> TC:- O(nlognlogn) SC:- O(nlogn)
//  --> Gives TLE on 2 test cases

// vector<int>arr;
// vector<vector<int>>mSegTree;

// void merge(int index,int low,int high){
//     int ind1=0;
//     int ind2=0;
//     int n=mSegTree[2*index+1].size();
//     int m=mSegTree[2*index+2].size();
//     while(ind1<n && ind2<m){
//         if(mSegTree[2*index+1][ind1]<=mSegTree[2*index+2][ind2]){
//             mSegTree[index].push_back(mSegTree[2*index+1][ind1]);
//             ind1++;
//         }
//         else{
//             mSegTree[index].push_back(mSegTree[2*index+2][ind2]);
//             ind2++;
//         }
//     }
//     while(ind1<n){
//         mSegTree[index].push_back(mSegTree[2*index+1][ind1]);
//         ind1++;
//     }
//     while(ind2<m){
//         mSegTree[index].push_back(mSegTree[2*index+2][ind2]);
//         ind2++;
//     }
// }

// void buildSegTree(int index,int low,int high){
//     if(low==high){
//         mSegTree[index]={arr[low]};
//         return;
//     }

//     int mid=low+(high-low)/2;
//     buildSegTree(2*index+1,low,mid);
//     buildSegTree(2*index+2,mid+1,high);
//     merge(index,low,high);
// }

// int querySegTree(int index,int low,int high,int lRange,int hRange,int c,int d){
//     if(hRange<low || high<lRange){
//         return 0;
//     }
//     if(lRange<=low && high<=hRange){
//         int lInd=lower_bound(mSegTree[index].begin(),mSegTree[index].end(),c)
//                     -mSegTree[index].begin();
//         int hInd=upper_bound(mSegTree[index].begin(),mSegTree[index].end(),d)
//                     -mSegTree[index].begin();
//         return (hInd-lInd);
//     }

//     int mid=low+(high-low)/2;
//     int lCnt=querySegTree(2*index+1,low,mid,lRange,hRange,c,d);
//     int rCnt=querySegTree(2*index+2,mid+1,high,lRange,hRange,c,d);
//     return lCnt+rCnt;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n,q;
//     cin>>n>>q;
//     arr.resize(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     mSegTree.resize(4*n);
//     buildSegTree(0,0,n-1);

//     vector<int>ans;
//     for(int i=0;i<q;i++){
//         int a,b,c,d;
//         cin>>a>>b>>c>>d;
//         a--;
//         b--;
//         int curCnt=querySegTree(0,0,n-1,a,b,c,d);
//         ans.push_back(curCnt);
//     }

//     for(auto &i:ans){
//         cout<<i<<endl;
//     }

//     return 0;
// }

// Approach2:-
//  --> Using persistent seg tree - or rather i call them prefix freq seg trees
//  --> add cordintate compression coz range is 1 to 1e9
//  --> Its like for each state of freq from ind 0 to ind i, we have a seg tree
//      to get freq cnt from c to d.
//  --> Its like having n diff seg tree for each state of freq, similar to
//      prefix sum but instead of storing each of them seperately which takes
//      huge amt of space, we store them to share some of the nodes with each
//      other
//  --> coz, each new addition at ind i, we just add one num , which just change
//      ine path from root to n, rest of the nodes, remains same, we can reuse them.
//  --> TC:- O(nlogn)  SC:-O(nlogn) -> Wayyy Coooler than App. 1

class Node
{
public:
    int left;
    int right;
    int cnt;

    Node()
    {
        left = -1;
        right = -1;
        cnt = 0;
    }
};

vector<int> arr;
vector<vector<int>> queries;
vector<int> cord;
int nodeCnt = 0;
vector<Node> pSegTree(6000000); // leftPtr, rightPtr, freqCnt
vector<int> pSegTreeRoots;

int compress(int x)
{
    return lower_bound(cord.begin(), cord.end(), x) - cord.begin();
}

int buildEmptyPSegTree(int low, int high)
{
    if (low == high)
    {
        return nodeCnt++;
    }

    int mid = low + (high - low) / 2;
    int lInd = buildEmptyPSegTree(low, mid);
    int rInd = buildEmptyPSegTree(mid + 1, high);
    pSegTree[nodeCnt].left = lInd;
    pSegTree[nodeCnt].right = rInd;
    return nodeCnt++;
}

int insertPSegTree(int prevInd, int low, int high, int curVal)
{
    if (low == high)
    {
        pSegTree[nodeCnt] = pSegTree[prevInd];
        pSegTree[nodeCnt].cnt++;
        return nodeCnt++;
    }

    int mid = low + (high - low) / 2;
    if (curVal <= mid)
    {
        int lInd = insertPSegTree(pSegTree[prevInd].left, low, mid, curVal);
        pSegTree[nodeCnt] = pSegTree[prevInd];
        pSegTree[nodeCnt].left = lInd;
        pSegTree[nodeCnt].cnt++;
        return nodeCnt++;
    }
    else
    {
        int rInd = insertPSegTree(pSegTree[prevInd].right, mid + 1, high, curVal);
        pSegTree[nodeCnt] = pSegTree[prevInd];
        pSegTree[nodeCnt].right = rInd;
        pSegTree[nodeCnt].cnt++;
        return nodeCnt++;
    }
}

int queryPSegTree(int hInd, int lInd, int low, int high, int lRange, int hRange)
{
    if (hRange < low || high < lRange)
    {
        return 0;
    }
    if (lRange <= low && high <= hRange)
    {
        return pSegTree[hInd].cnt - pSegTree[lInd].cnt;
    }

    int mid = low + (high - low) / 2;
    int lCnt = queryPSegTree(pSegTree[hInd].left, pSegTree[lInd].left, low, mid, lRange, hRange);
    int rCnt = queryPSegTree(pSegTree[hInd].right, pSegTree[lInd].right, mid + 1, high, lRange, hRange);
    return lCnt + rCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cord.push_back(arr[i]);
    }

    queries.resize(q);
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries[i] = {a, b, c, d};
        cord.push_back(c);
        cord.push_back(d);
    }

    sort(cord.begin(), cord.end());
    cord.erase(unique(cord.begin(), cord.end()), cord.end());

    int maxVal = cord.size() - 1;
    int pSegSize = 2 * (maxVal + 1) + (n + 1) * 25 + 100; // emptytree + insertion + buffer
    // pSegTree.resize(pSegSize); // no resize , it takes time instead predeclare
    pSegTreeRoots.resize(n + 1);
    pSegTreeRoots[0] = buildEmptyPSegTree(0, maxVal);

    for (int i = 0; i < n; i++)
    {
        int compVal = compress(arr[i]);
        pSegTreeRoots[i + 1] = insertPSegTree(pSegTreeRoots[i], 0, maxVal, compVal);
    }

    vector<int> ans;
    for (auto &q : queries)
    {
        int lRange = compress(q[2]);
        int hRange = compress(q[3]);
        int curAns = queryPSegTree(pSegTreeRoots[q[1]], pSegTreeRoots[q[0] - 1],
                                   0, maxVal, lRange, hRange);
        ans.push_back(curAns);
    }

    for (auto &i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}
