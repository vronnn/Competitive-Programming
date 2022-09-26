#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,l;
    string s = "Timru",c;
    cin >> t;
    while(t--){
        cin >> l >> c;
        int f = 0;
        if(l != 5)
            f = 1;
        else{
            sort(c.begin(), c.end());
            if(c != s)
                f = 1;
        }
        if(f == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
