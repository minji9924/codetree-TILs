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

bool compare(Person person1,Person person2){
    if(person1.name > person2.name)
        return true;
    return false;
}

Person persons[10];

int main() {
    int n;
    cin >> n;
    string a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        persons[i]=Person(a,b,c);
    }
    sort(persons,persons+n,compare);
    cout << "name " << persons[0].name << "\n";
    cout << "addr " << persons[0].address << "\n";
    cout << "city " << persons[0].location << "\n";
    return 0;
}