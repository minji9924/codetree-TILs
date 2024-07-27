#include <iostream>
using namespace std;

void PrintStar(int n){
    if(n==0)
        return;
    PrintStar(n-1);
    cout << "HelloWorld" << "\n";
    return;
}

int main() {
    int n;
    cin >> n;
    PrintStar(n);
    return 0;
}