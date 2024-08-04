#include <iostream>
#include <string>
using namespace std;

int main() {
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int month_2011[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string day[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    int sum_2=0, sum_1=0;
    int i=1,j=1;
    while(i != m1){
        sum_1 += month_2011[i++];
    }
    sum_1 +=d1;
    while(j != m2){
        sum_2 += month_2011[j++];
    }
    sum_2 +=d2;
    int sum = sum_2 - sum_1;
    if(sum>=0){
        cout << day[sum%7];
    }
    else{
        while(1){
            sum += 7;
            if(sum>0){
                cout << day[sum];
                break; 
            }
        }
    }
    return 0;
}