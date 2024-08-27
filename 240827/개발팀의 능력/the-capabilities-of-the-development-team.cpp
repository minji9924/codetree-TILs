#include <iostream>
#include <climits>
using namespace std;
#define MAX_P 5

int main() {
    int a[5],sum=0,mns=INT_MAX,mxs=INT_MIN,diff=0,mn=INT_MAX;
    for(int i=0;i<MAX_P;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<MAX_P-1;i++){
        for(int j=i+1;j<MAX_P;j++){
            int sum1=a[i]+a[j];
            for(int k=0;k<MAX_P;k++){
                if(k!=i && k!=j){
                    int tmp=sum;
                    int sum2=a[k];
                    int sum3=tmp-sum1-sum2;
                    if(sum1 != sum2 && sum1!=sum3 && sum2!=sum3){
                        mxs=max(sum1,sum2);
                        mxs=max(mxs,sum3);
                        mns=min(sum1,sum2);
                        mns=min(mns,sum3);
                        diff=mxs-mns;
                        mn=min(mn,diff);
                    }
                }
            }
        }
    }
    if(mn==INT_MAX)
        cout << -1;
    else
        cout << mn;
    return 0;
}