#include<bits/stdc++.h>
using namespace std;
 
long long n,ans,dp[2][200005],a[200005];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<=1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            dp[0][i]=dp[0][i-1]+1;
            dp[1][i]=dp[1][i-1]+1;
        }
        if(a[i]>a[i-2])
        {
            dp[1][i]=max(dp[0][i-2]+1,dp[1][i]);
        }
        ans=max(ans,max(dp[0][i],dp[1][i]));
    }
    cout<<ans<<'\n';
    return 0;
}