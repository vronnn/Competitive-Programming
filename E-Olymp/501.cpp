#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,f1=0,f2=0;
    char c,fn,fm;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        cin >> c;
        char cn[n][2];
        char cm[m][2];
        for(int i=0; i<n; i++){
            scanf("%s", &cn[i]);
            getchar();
        }
        for(int i=0; i<m; i++){
            scanf("%s", &cm[i]);
        }
        printf("%s ", cn[0]);
    }
    //printf("%d %d %c", n,m,c);
    return 0;
}