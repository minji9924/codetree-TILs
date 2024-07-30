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
    }
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            sort(arr+1,arr+i+1);
            cout << arr[(i+1)/2] << ' ';    
        }
    }
    return 0;
}