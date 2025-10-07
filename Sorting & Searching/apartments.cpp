/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

// bool isPos(int mid,int &n,int &m,int &k,vector<int>&des,vector<int>&ava){
//     for(auto d:des){
//         int st=lower_bound(ava.begin(),ava.end(),d-k-1)-ava.begin();
//         int en=upper_bound(ava.begin(),ava.end(),d+k)-ava.begin();
//         if(st==m){
//             continue;
//         }

//     }
// }

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> des(n);
    for (int i = 0; i < n; i++)
    {
        cin >> des[i];
    }
    sort(des.begin(), des.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top() < des[i] - k)
        {
            pq.pop();
        }
        if (!pq.empty() && pq.top() <= des[i] + k)
        {
            cnt++;
            pq.pop();
        }
    }
    // sort(ava.begin(),ava.end());
    // int ans=0;
    // int start=0;
    // int end=m;
    // while(start<=end){
    //     int mid=start+(end-start)/2;
    //     if(isPos(mid,n,m,k,des,ava)){
    //         ans=max(ans,mid);
    //         start=mid+1;
    //     }else{
    //         end=mid-1;
    //     }
    // }

    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}