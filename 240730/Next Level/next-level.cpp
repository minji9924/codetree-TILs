#include <iostream>
#include <string>
using namespace std;

class Pie{
    public:
        string id;
        int lv;
    Pie(string id1 ="codetree", int lv1 = 10){
        this->id=id1;
        this->lv=lv1;
    }
};



int main() {
    string id3;
    int lv3;
    cin >> id3 >> lv3;

    Pie P1 = Pie(id3,lv3);
    Pie P2 = Pie();
    
    cout << "user " << P2.id << " lv " << P2.lv << "\n";     
    cout << "user " << P1.id << " lv " << P1.lv;

    return 0;
}