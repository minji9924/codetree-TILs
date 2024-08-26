#include <iostream>
#include <climits>
using namespace std;
#define MAX_P 6
int main() {
    int ab[6],sum=0,mn=INT_MAX,mxs=0,mns=INT_MAX;
    for(int i=0;i<MAX_P;i++){
        cin >> ab[i];
        sum+=ab[i];
    }

    for(int i=0;i<MAX_P-1;i++){
        for(int j=i+1;j<MAX_P;j++){
            int sum1=ab[i]+ab[j];
            for(int p=0;p<MAX_P;p++){
                if(p!=i && p!=j){
                    for(int q=0;q<MAX_P;q++){
                        if(q!=i && q!=j && q!=p){
                            int sum2=ab[p]+ab[q];
                            int sum3=sum-sum1-sum2;
                            
                            mxs=max(sum1,sum2);
                            mxs=max(mxs,sum3);
                            
                            mns=min(sum1,sum2);
                            mns=min(mns,sum3);

                            mn=min(mn,mxs-mns);
                        }

                    }
                }
            }
        }
    }
    cout << mn;
    return 0;
}