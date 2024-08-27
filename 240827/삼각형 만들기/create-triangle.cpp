#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n,x[101],y[101],ext,mx_ext=INT_MIN;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n-1;i++){
        int dst_x=0;
        int dst_y=0;
        int dst_mxx=INT_MIN;
        int dst_mxy=INT_MIN;
        for(int j=0;j<n;j++){
            if(x[i]==x[j]){
                dst_y=abs(y[j]-y[i]);
                dst_mxy=max(dst_y,dst_mxy);
            }
            if(y[i]==y[j]){
                dst_x=abs(x[j]-x[i]);
                dst_mxx=max(dst_x,dst_mxx);
            }            
        }
        ext=dst_mxx*dst_mxy;
        mx_ext=max(mx_ext,ext);
    }
    cout << mx_ext;
    return 0;
}