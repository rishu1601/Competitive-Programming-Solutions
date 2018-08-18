#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modExp(ll x,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=((res%10)*(x%10))%10;
		x=((x%10)*(x%10))%10;
		b>>=1;
	}
	return res;
}
int main() 
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<modExp(a,b)<<endl;
	}
	return 0;
}