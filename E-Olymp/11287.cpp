#include <stdio.h>
#define gc getchar

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

int main()
{
    int n = getnum();
    int a,b,c;
    for(int i=0; i<=n; i++){
        c = getnum();
        if(i == 0) a = b = c;
        else if(c < b){
            printf("%d\n",i-1);
            break;
        }
        else{
            a = b;
            b = c;
        }
    }
    return 0;
}