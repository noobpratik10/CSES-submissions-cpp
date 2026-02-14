#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr.begin(),arr.end());

    // ll sum1=0,sum2=0;
    // for(int i=0;i<n;i++){
    //     if(sum1<=sum2){
    //         sum1+=arr[i];
    //     }else{
    //         sum2+=arr[i];
    //     }
    // }
    // cout<<2*max(sum1,sum2)<<endl;
    ll sum = accumulate(arr.begin(), arr.end(), 0ll);
    int maxi = *max_element(arr.begin(), arr.end());
    cout << max(sum, 2ll * maxi) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
