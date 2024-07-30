#include <iostream>
#include <string>

using namespace std;

class hodu{
    public:
            string v1;
            char v2;
            int v3;
    
    hodu(string c1,char c2,int c3){
        this->v1 = c1;
        this->v2 = c2;
        this->v3 = c3;
    }
};



int main() {
    string i1;
    char i2;
    int i3;

    cin >> i1 >> i2 >> i3;
    hodu z1 = hodu(i1,i2,i3);
    cout << "secret code : " << z1.v1 << "\n";
    cout << "meeting point : " << z1.v2 << "\n";
    cout << "time : " <<z1.v3 << "\n";
    return 0;
}