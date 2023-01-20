#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,h,max=0,sum=0;
    vector <int> v;
    cin >> n;
    while(n--){
        cin >> h;
        v.push_back(h);
    }
    while(v.size() > 1){
        int minim = *min_element(v.begin(),v.end());
        auto it1 = min_element(v.begin(),v.end());
        int mindex = distance(v.begin(),it1);
        int maxim = *max_element(it1, v.end());
        auto it2 = max_element(it1, v.end());
        int maxdex = distance(v.begin(),it2);
        sum = sum + (maxim-minim);
        v.erase(v.begin(),it2);
    }
    cout << sum;
    return 0;
}