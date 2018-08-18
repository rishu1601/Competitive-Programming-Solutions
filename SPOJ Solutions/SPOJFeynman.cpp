/*
	Problem- https://www.spoj.com/problems/SAMER08F/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
	int n;
	vector<int> v;
	while(1)
	{
		cin>>n;
		if(n==0)break;
		else
		{
			ll ans=((n)*(n+1)*(2*n+1))/6;
			cout<<ans<<endl;
		}
	}
	return 0;
}
