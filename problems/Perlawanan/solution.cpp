#include<bits/stdc++.h>
using namespace std;

string s;
long long a;
stack<char>st;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(st.empty())
		{
			st.push(s[i]);
		}
		else
		{
			if(st.top()==s[i])
			{
				st.pop();
				a++;
			}
			else
			{
				st.push(s[i]);
			}
		}
	}
	if(a%2==0)
	{
		cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
	}
	return 0;
}