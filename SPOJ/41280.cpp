#include <stdio.h>
#include <algorithm>
#define llu long long unsigned

void solve()
{
    int n,k,dif,a;
    llu num,sum;
    scanf("%d %d", &n, &k);
    dif = std::__gcd(n,k);
    num = n / dif;
    (dif == 1)? a = 0 : a = 1;
    sum = (num*(2*a+(num-1)*dif))/2;
    printf("%llu", sum);
}

int main()
{
    solve();
    return 0;
}

