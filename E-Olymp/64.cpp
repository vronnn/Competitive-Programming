#include <stdio.h>
#define gc getchar
#define pc putchar
int n,k,u[51],c[51],t[51],tm[51];

inline void putnum (int n)
{
    int N = n, rev, count = 0;
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

bool enough(int mid){
    int lsn = 0;
    for(int i=0; i<n; i++){
        printf("mtc : %d\n", (mid/tm[i]) * c[i]);
        printf("mtc : %d\n", (mid%tm[i]) / u[i]);
        int now = (mid/tm[i]) * c[i] + (mid%tm[i]) / u[i];
        printf("now : %d\n", now);
        if(lsn >= k || lsn+now >= k){
            printf("true\n");
            return true;
        }
        lsn += now;
        printf("lsn : %d\n", lsn);
        puts("");
    }
    return (lsn >= k);
}

int main(){
    n = getnum(), k = getnum();

    for(int i = 0 ; i < n ; i++) {
        u[i] = getnum(), c[i] = getnum(), t[i] = getnum();
        tm[i] = u[i] * c[i] + t[i];
    }
    int low = 1, high = (k/c[0])*tm[0]+(k%c[0])*u[0];

    while(high - low > 1){
        int mid = (low + high) >> 1;
        printf("low : %d || mid : %d || high : %d\n", low, mid, high);
        (enough(mid) ? high : low) = mid;
    }
    putnum(high);

    return 0;
}