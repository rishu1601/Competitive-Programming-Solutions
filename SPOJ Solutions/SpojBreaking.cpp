/*
	Problem-https://www.spoj.com/problems/BREAKING/
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename t>
t Min(t a,t b)
{
	return a<b?a:b;
}
const int mx=1e6+5;
vector<bool>pr(mx,true);
void pre()
{
	pr[0]=false;
	pr[1]=false;
	for(int i=2;i*i<mx;i++)
	{
		if(pr[i]==true)
		{
			for(int j=i*i;j<mx;j+=i)
			{
				pr[j]=false;
			}
		}
	}
}
set<int> getP(int n)
{
	set<int> s;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(pr[i])s.insert(i);
			if(pr[n/i])s.insert(n/i);
		}
	}
	return s;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	pre();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		set<int> ans=getP(n);
		for(auto it=ans.begin();it!=ans.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}