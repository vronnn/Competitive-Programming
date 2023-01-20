#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1000000007; // modulo
map<ll,ll> F;

ll f(ll n) {
	if (F.count(n)) return F[n];
	ll k = n/2;
	if (n%2 == 0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

int main()
{
	ll n;
	F[0]=F[1]=1;
    cin >> n;
    n++;
    ll res = (n==0 ? 0 : f(n-1));
	cout << (res*res)%M << endl;
	return 0;
}