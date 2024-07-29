#include <iostream>
using namespace std;

int n;
int arr[11];

int lcm(int a,int b){
    int gcd = 1;
    for(int i=1;i<=min(a,b);i++){
            if(a%i ==0 && b%i==0)
                gcd = i;
    }
    return a*b/gcd;
}

int GetLCMALL(int index){
    if(index == 1)
        return arr[1];
    
    return lcm(GetLCMALL(index - 1), arr[index]);
}


int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cout<<GetLCMALL(n);
    return 0;
}