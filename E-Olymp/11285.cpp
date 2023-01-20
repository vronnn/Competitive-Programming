#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> t;
        a[i] = a[i-1]^t;
    }
    int q,l,r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        int res = a[r] ^ a[l-1];
        cout << res << '\n';
    }
    return 0;
}