#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(ll d[], int n, ll r)
{
    int left = 0;
    int right = n-1;
    int cnt = 0;
    while(left <= right){
        int mid = (left+right)/2;
        if(d[mid] <= r){
            cnt = mid+1;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return cnt;
}

int main()
{
    ll xb,yb,n,xm,ym,q,r;
    cin >> xb >> yb >> n;
    ll dis[n+1];
    for(int i = 0; i < n; i++){
        cin >> xm >> ym;
        dis[i] = ((xm-xb)*(xm-xb)) + ((ym-yb)*(ym-yb));
    }
    sort(dis,dis+n);
    cin >> q;
    while(q--){
        cin >> r;
        cout << count(dis,n,r*r) << '\n';
    }
    return 0;
}