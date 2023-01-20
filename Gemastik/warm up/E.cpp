#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,q,m;
    cin >> n;
    while(n--){
        cin >> p >> q >> m;
        while(m--){
            if(p >= 0 || q >= 0){
                if(p >= q){
                    p = p/2;
                }
                else if(p < q){
                    q = q/2;
                }
            }
        }
        cout << max(p,q) << ' ' << min(p,q) << '\n';
    }
    return 0;
}