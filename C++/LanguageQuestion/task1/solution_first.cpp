#include<iostream> 
#include<string>
using namespace std;

class Person {
    public:
        Person(const string& personName, int personAge);
        void display()const;
    private:
        string name;
        int age;
};
Person :: Person(const string& personName, int personAge){
    name = personName;
    age = personAge;
}
void Person :: display()const{
    cout << name <<" " << age << endl;
    }

int main() {
    Person person1("ZhangSan",10),person2("LiSi",11);
    person1.display();
    person2.display();
    return 0;
}