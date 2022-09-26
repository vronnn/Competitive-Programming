#include <stdio.h>
#include <algorithm>
#define llu long long unsigned

int main()
{
    int t,n,k;
    llu x;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        llu sum = 0, arr[n];
        std::fill_n(arr, n, 0);
        for(int i = 0; i < n; i++){
            scanf("%llu", &x);
            arr[i%k] = std::max(arr[i%k], x);
        }
        for(int i = 0; i < k; i++)
            sum += arr[i];
        printf("%llu\n", sum);
    }
    return 0;
}
