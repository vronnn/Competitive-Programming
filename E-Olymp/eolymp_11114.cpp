#include <stdio.h>
typedef long long ll;

ll modex(ll b, ll e, ll m){
    if(b == 0 || e == 0) return 0;
    ll r = 1;
    while(e>0){
        if(e&1) r = (r*b)%m;
        e>>=1;
        b = (b*b)%m;
    }
    return r;
}

int main()
{
    ll n,m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", modex(n*2+1,m,998244353));
    return 0;
}