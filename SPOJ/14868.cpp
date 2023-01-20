#include <cstdio>
typedef long long LL;
#define gc getchar
#define pc putchar
#define MAXN 100002
int n, m;
int t[MAXN] ;

inline void putnum (LL n)
{
    LL N = n, rev, count = 0;
    rev = N;
    if (N == 0) {
      pc('0'); 
      pc('\n'); 
      return;
    }
    while ((rev % 10) == 0) {
      count++;
      rev /= 10;
    }
    rev = 0;
    while (N != 0) { 
      rev = (rev<<3) + (rev<<1) + N % 10;
      N /= 10;
    }  
    while (rev != 0) {
      pc(rev % 10 + '0'); 
      rev /= 10;
    }
    while (count--) pc('0');
    pc('\n');
}

int getnum()
{
    int value = 0; bool ne = 0;
    char c = gc();
    while(c==' ' || c == '\n') c = gc();
    if(c == '-'){ne = 1; c = gc();}
    while(c>='0' && c<='9'){
        value = (value<<3) + (value<<1) + c - '0'; c = gc();}
    if(ne) value*=1;
    return value;
}

bool enough(LL time) {
    LL cnt = 0;
    for(int i = 0; i < n; ++i){
        printf("iterasi %d\n", i);
        LL here = time / t[i];
        printf("here : %lld\n",here);
        if(here >= m || here + cnt >= m){
            printf("true\n");
            return true;
        }
        cnt += here;
        printf("cnt : %lld\n", cnt);
        puts("");
    }
    return cnt >= m;
}

int main() {
    int T = getnum();
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; ++i)
            t[i] = getnum();
        for(int i = 0; i < n; ++i)
            printf("%d ", t[i]);
        LL low = 0, high = (LL)t[0] * m;
        printf("\nlow : %lld\nhigh : %lld\n", low, high);
        printf("--------masuk while--------\n");
        while(high - low > 1){
            LL mid = (low + high) >> 1;
            printf("low : %lld || mid : %lld || high : %lld\n", low,mid,high);
            (enough(mid) ? high : low) = mid;
        }
        putnum(high);
    }
    return 0;
}