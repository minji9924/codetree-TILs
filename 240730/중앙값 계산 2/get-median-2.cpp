#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[101];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        // sum+= arr[i];
        // if(i%2!=0)
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        sum+= arr[i];
        if(i%2!=0)
            cout << sum/i << ' ';
    }


    return 0;
}