/*
	Problem-https://www.spoj.com/problems/MIXTURES/
	Author - Rishabh Kumar
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename t>
t Min(t a,t b)
{
	return a<b?a:b;
}
ll dp[1000][1000];
ll a[1000];
ll sum(ll s,ll e)
{
	ll ans=0;
	for(ll i=s;i<=e;i++)
	{
		ans=((ans%100)+(a[i]%100))%100;
	}
	return ans;
}
//Top down DP
ll getAns(ll i,ll j)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=INT_MAX;
	for(ll k=i;k<=j;k++)
	{
		dp[i][j]=Min(dp[i][j],getAns(i,k)+getAns(k+1,j)+(sum(i,k)*sum(k+1,j)));
	}
	return dp[i][j];
}
int main()
{
	ll n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i][j]=-1;
			}
		}
		cout<<getAns(0,n-1)<<endl;
	}
	return 0;
}