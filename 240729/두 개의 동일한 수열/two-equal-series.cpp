#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[100];
    int B[100];
    int ck=1;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A,A+n);
    for(int i=0;i<n;i++){
        cin >> B[i];
    }
    sort(B,B+n);
    while(n--){
        if(A[n] != B[n]){
            ck=0;
            break;
        }
    }

    if(ck)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}