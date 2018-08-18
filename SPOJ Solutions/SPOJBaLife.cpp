//Problem - https://www.spoj.com/problems/BALIFE/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename t>
t Max(t a,t b)
{
	return (a>b)?a:b;
}
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
		{
			break;
		}
		vector<ll> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		ll su=accumulate(v.begin(),v.end(),(ll)0);
		if(su%n!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		vector<ll> pref(n);
		pref[0]=v[0];
		for(int i=1;i<n;i++)
		{
			pref[i]=pref[i-1]+v[i];
		}
		ll mx=-1;
		ll avg=su/n;
		ll curr=avg;
		for(int i=0;i<n;i++)
		{
			mx=Max(mx,abs(pref[i]-curr));
			curr+=avg;
		}
		cout<<mx<<endl;
	}
	return 0;
}
