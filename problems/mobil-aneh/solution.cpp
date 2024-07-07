#include<bits/stdc++.h>
using namespace std;

long long n,m,x,y,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},dp[1005][1005][5];
bool visit[1005][1005],b;
char c[1005][1005];
void dfs(long long x,long long y,long long z,long long jum)
{
	if(jum==4)
	{
		return;
	}
	if(c[x][y]=='T')
	{
		b=true;
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(c[x+dx[i]][y+dy[i]]=='.'||c[x+dx[i]][y+dy[i]]=='T')
		{
			if(i!=z&&dp[x+dx[i]][y+dy[i]][i]>jum)
			{
				dp[x+dx[i]][y+dy[i]][i]=jum+1;
				dfs(x+dx[i],y+dy[i],i,jum+1);
			}
			else if(i==z&&dp[x+dx[i]][y+dy[i]][i]>jum)
			{
				dp[x+dx[i]][y+dy[i]][i]=jum;
				dfs(x+dx[i],y+dy[i],i,jum);
			}	
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=3;k++)
			{
				dp[i][j][k]=1e18;
			}
			cin>>c[i][j];
			if(c[i][j]=='S')
			{
				x=i;
				y=j;
			}
		}
	}
	dfs(x,y,-1,0);
	if(b)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}