#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,y;
    cin >> n;
    while(n--){
        x = 0; y = 0;
        cin >> m;
        if(m <= 15){
            if(m == 0){
                x = x;
                y = y;
            }
            else if(m == 1){
                x = x+1;
                y = y;
            }
            else if(m <= 3){
                x = x+1;
                y = y+(m-1);
            }
            else if(m <= 6){
                x = (x+1)-(m-3);
                y = y+2;
            }
            else if(m <= 10){
                x = x-2;
                y = (y+2)-(m-6);
            }
            else if(m <= 15){
                x = (x-2)+(m-10);
                y = y-2;
            }
        }
        else {
            x = (x+3)*(m/15);
            y = (y-2)*(m/15);
            m = m%15;
            if(m == 0){
                x = x;
                y = y;
            }
            else if(m == 1){
                x = x+1;
                y = y;
            }
            else if(m <= 3){
                x = x+1;
                y = y+(m-1);
            }
            else if(m <= 6){
                x = (x+1)-(m-3);
                y = y+2;
            }
            else if(m <= 10){
                x = x-2;
                y = (y+2)-(m-6);
            }
            else if(m <= 15){
                x = (x-2)+(m-10);
                y = y-2;
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}