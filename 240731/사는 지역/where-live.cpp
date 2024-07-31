#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        string address;
        string location;
    Person(string n,string a,string l){
        this->name = n;
        this->address = a;
        this->location = l;
    }
    Person(){}
};

Person persons[10];

int main() {
    int n;
    cin >> n;
    string a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        persons[i]=Person(a,b,c);
    }
    sort(persons[10].name.begin(),persons[10].name.end());
    cout << "name " << persons[n-1].name << "\n";
    cout << "addr " << persons[n-1].address << "\n";
    cout << "city " << persons[n-1].location << "\n";
    return 0;
}