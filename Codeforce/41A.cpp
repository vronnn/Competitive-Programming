#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    if(s.length() != t.length()) cout << "NO";
    else{
        int f = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != t[t.length()-i-1]){
                f = 1;
                break;
            }
        }
        f == 1? cout << "NO" : cout << "YES";
    }
    return 0;
}
