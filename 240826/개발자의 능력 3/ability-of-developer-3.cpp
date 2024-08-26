#include <iostream>
#include <climits>
using namespace std;

int main() {
    int p[6],sum=0,mn=INT_MAX,n=6;
    for(int i=0;i<6;i++){
        cin >> p[i];
        sum+=p[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int sum2=p[i]+p[j]+p[k];
                int diff=sum-sum2;
                mn=min(mn,abs(diff-sum2));
            }
        }
    }
    cout << mn;
    return 0;
}