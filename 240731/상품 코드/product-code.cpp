#include <iostream>
#include <string>
using namespace std;

class Code{
    public:
        string name;
        int num;
    Code(string name = "codetree",int num = 50){
        this->name = name;
        this->num = num;
    }
};


int main() {
    string s;
    int n;
    cin >> s >> n;
    Code code1 = Code();
    Code code2 = Code(s,n);
    cout << "product " << code1.num << " is " <<code1.name << "\n"; 
    cout << "product " << code2.num << " is " <<code2.name;
    return 0;
}