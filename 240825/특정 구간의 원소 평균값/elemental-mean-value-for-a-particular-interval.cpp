#include <iostream>
using namespace std;

int main() {
    int n,a[101]={0},tmp=0,mx=0,cnt=0;
    double sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                sum+=a[k];
            }
            sum=sum/(double)(j-i);
            for(int k=i;k<j;k++){
                if(a[k]==sum){
                    cnt++;
                    break;
                }
            }
            sum=0;
        }
    }
    cout << cnt;
    return 0;
}