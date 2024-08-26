#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n,h,t,ht[101]={0},mn=INT_MAX;
    cin >> n >> h >> t;
    for(int i=0;i<n;i++){
        cin >> ht[i];
    }
    for(int i=0;i<n-t+1;i++){
        int sum=0;
        for(int j=i;j<t+i;j++){
            sum+=abs(h-ht[j]);
        }
        mn=min(mn,sum);
    }
    cout << mn;
    return 0;
}