#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    int sum=0;
    cin >> A;
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i]=='('){
                if(A[j]==')')
                    sum++;
            }
        }
    }
    cout << sum;
    return 0;
}