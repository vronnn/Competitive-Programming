#include <stdio.h>
#include <math.h>
typedef long long ll;

ll n, k;
ll solve(ll x, ll y){
    ll ans;
    if(n & 1)
        ans = (ll)pow((double)(y-1), (double)x) - (y-1);
    else
        ans = (ll)pow((double)(y-1), (double)x) + (y-1);
    return ans;
}

int main(){
    scanf("%lld %lld", &n, &k);
    if(n == 1) printf("%lld\n",k);
    else if((k==1) || (n & 1 && k == 2)) printf("-1\n");
    else printf("%lld\n", solve(n,k));
    return 0;
}