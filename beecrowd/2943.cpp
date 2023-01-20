/* Dynamic Programming implementation of longest bitonic subsequence problem */
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

int solve( int arr[], int n )
{
    int i, j;
    int inc[n];
    for (i = 0; i < n; i++)
        inc[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && inc[i] < inc[j] + 1)
                inc[i] = inc[j] + 1;

    int dec[n];
    for (i = 0; i < n; i++)
        dec[i] = 1;

    for (i = n-2; i >= 0; i--)
        for (j = n-1; j > i; j--)
            if (arr[i] > arr[j] && dec[i] < dec[j] + 1)
                dec[i] = dec[j] + 1;

    int max = inc[0] + dec[0];
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] > max)
            max = inc[i] + dec[i];
    return max;
}

int main()
{
    int n,h; 
    n = getnum();
    int arr[n];
    for(int i=0; i<n; i++){
        h = getnum();
        arr[i] = h;
    }
    printf("%d\n",solve(arr,n));
    return 0;
}
