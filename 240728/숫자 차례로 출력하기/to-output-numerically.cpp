#include <iostream>
using namespace std;

void PrintStar(int n){
    if(n==0)    
        return;
    for(int i=1; i<=n; i++)
        cout << i << ' ';
    cout << "\n";
    for(int i=n; i>=1; i--)
        cout << i << ' ';
    
}

int main() {
    int n;
    cin >> n;
    PrintStar(n);
    return 0;
}