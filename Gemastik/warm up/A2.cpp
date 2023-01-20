#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod (ll)(1e9 + 7)

int r, c, cR, cC, dR, dC;
map<pair<int, int>, int> checkerD;
map<pair<int, int>, int> checkerC;
vector<vector<char>> arena;

bool dFlag = false, cFlag = false;

void drecur(int n, int m)
{
    if (dFlag || arena[n][m] == '|' || arena[n][m] == '-' || arena[n][m] == 'x') return;

    pair<int, int> tmpP;

    tmpP.first = n;
    tmpP.second = m;

    if (checkerD[tmpP] == 1) return;
    
    checkerD[tmpP] = 1;
    if (n == cR && m == cC)
    {
        dFlag = true;
        return;
    }

    if (n > 0)
    {
        drecur(n - 1, m);
    }

    if (m > 0)
    {
        drecur(n, m - 1);
    }

    if (n < r - 1)
    {
        drecur(n + 1, m);
    }

    if (m < c - 1)
    {
        drecur(n, m + 1);
    }
}

void crecur(int n, int m)
{
    if (cFlag || arena[n][m] == '|' || arena[n][m] == '-' || arena[n][m] == 'x') return;

    pair<int, int> tmpP;

    tmpP.first = n;
    tmpP.second = m;

    if (checkerC[tmpP] == 1) return;
    
    checkerC[tmpP] = 1;
    if (arena[n][m] == ' ' && (n == 0 || m == 0 || n == r-1 || m == c-1))
    {
        cFlag = true;
        return;
    }

    if (n > 0)
    {
        crecur(n - 1, m);
    }

    if (m > 0)
    {
        crecur(n, m - 1);
    }

    if (n < r - 1)
    {
        crecur(n + 1, m);
    }

    if (m < c - 1)
    {
        crecur(n, m + 1);
    }
}

void solve()
{
    cin >> r >> c;

    bool cA = true;
    string bff;
    getline(cin, bff);
    for (int i = 0; i < r; i++)
    {
        vector<char> tmp;

        string str;
        getline(cin, str);

        for (int j = 0; j < c; j++)
        {
            if (cA && (i == 0 || j == 0 || i == r-1 || j == c-1))
            {
                if (str[j] == ' ')
                {
                    cA = false;
                }
            }

            if (str[j] == 'C')
            {
                cR = i, cC = j;
            }

            if (str[j] == 'D')
            {
                dR = i, dC = j;
            }

            tmp.push_back(str[j]);
        }

        arena.push_back(tmp);
    }

    drecur(dR, dC);

    if (dFlag) cout << "Dawala bertemu Cepot\n";
    else cout << "Dawala tidak bertemu Cepot\n";

    if (cA) cout << "tidak ada jalan Cepot lumpat";
    else
    {
        crecur(cR, cC);
        if (cFlag) cout << "ada jalan Cepot lumpat";
        else cout << "tidak ada jalan Cepot lumpat";
    }
}

int main()
{
    solve();
    return 0;
}