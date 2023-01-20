#include <stdio.h>
#include <algorithm>
int dp[185], sum[190], n, a[185], k;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = n - 1; i >= 0; i--)
        sum[i] = sum[i+1] + a[i];
    for(int i = 0; i < n; i++){
        printf("a[%d] : %d || sum[%d] : %d\n",i,a[i],i,sum[i]);
    }
    puts("");
    scanf("%d",&k);
    for(int i = 1; i <= k; i++){
        printf("------i = %d-----\n", i);
        for(int j = n - i; j >= 0; j--){
            printf("j = %d\n",j);
            printf("sum[%d] = %d\n",j,sum[j]);
            printf("dp[%d] = %d\n",j+i, dp[j+i]);
            printf("sum - dp = %d\n",sum[j]-dp[j+i]);
            printf("dp[%d] = %d\n",j,dp[j]);
            dp[j] = std::max(sum[j] - dp[j + i], dp[j]);
            printf("dp[%d] sekarang = %d\n",j,dp[j]);
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}
