#include <iostream>
using namespace std;
int arr[10];
int index=1;
int f(int a,int b){
    if(arr[index]==0)
        return a;
    int max=1;
    for(int i=2;i<=a;i++)
        if(a%i==0 && b%i==0)
            max=i;
    index++;

    return f(a*b/max,arr[index]);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<f(arr[0],arr[1]);
    return 0;
}