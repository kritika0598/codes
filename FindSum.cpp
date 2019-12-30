#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD=1000000009;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll N,K;
	cin>>N>>K;

	priority_queue <ll> q;

	for(ll i=0;i<N;i++)
	{
		ll x;
		cin>>x;
		q.push(x);
	}
	ll sum=0;
	for(ll i=0;i<K;i++ )
	{
		sum=(sum%MOD+(q.top())%MOD)%MOD;
		ll x=q.top();
		q.pop();
		q.push(floor(x/2));
	}

	cout<<sum%MOD;
}