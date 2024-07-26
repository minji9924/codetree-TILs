#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int i=1;
    while(1){
        if(i%n==0 && i%m ==0)  
            break;
        i++;
    }
    cout << i;
    return 0;
}