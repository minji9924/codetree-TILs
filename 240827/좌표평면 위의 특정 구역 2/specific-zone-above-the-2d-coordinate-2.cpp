#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n,x[101],y[101],mn=INT_MAX;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];

    }
    for(int i=0;i<n;i++){
        int mnx=INT_MAX,mxx=INT_MIN,mny=INT_MAX,mxy=INT_MIN,ext=INT_MAX;
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            mnx=min(mnx,x[j]);
            mxx=max(mxx,x[j]);
            mny=min(mny,y[j]);
            mxy=max(mxy,y[j]);
        }
        ext=(mxx-mnx)*(mxy-mny);
        mn=min(ext,mn);
    }
    cout << mn;
    return 0;
}