#include <iostream>
#include <string>
#include <array>
using namespace std;

class Student {
private:
    string name;
    string *courseList;
    int numCourses;
public:
    Student(){} //default constructor
    Student(string name){
        this->name = name;
    }
    ~Student(){} //destructor
    string getName() {return this->name;}
    void setName(string name) { this->name = name;}
};

int main() {
    auto *student = new Student("Kevin");
    cout << student->getName() << endl;
    student->setName("Orenday");
    cout << student->getName() << endl;
    return 0;
}
