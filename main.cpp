#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string *courseList;
    int numCourses;
public:
    Student(){} //default constructor
    Student(string& name){
        this->name = name;
    }
    Student(string& name, int& numCourses, string* courseList) {
        this->name = name;
        this->numCourses = numCourses;
        this->courseList = courseList;
    }
    ~Student(){} //destructor

    string getName() {return this->name;}
    void setName(string name) { this->name = name;}
    string toString() {
        string output = "Name: " + this->name + "\n" +
                "Number of Course(s): " + to_string(this->numCourses) + "\n" +
                "Course List:\n";

        for (int i = 0; i < this->numCourses; i++) {
            output += courseList[i] + "\n";
        }

        return output;
    }
    friend ostream& operator<<(ostream os, Student& student); // needs work, only returns the address
};

ostream& operator<<(ostream& os, Student& student) {
    os << student.toString() << endl;
    return os;
}

int main() {
    string name;
//    auto *student = new Student(name);
//    cout << student->getName() << endl;
//    student->setName("Kevin Orenday");
//    cout << student->getName() << endl;

    cout << "Welcome to the Student Course Program.\n" << endl;
    cout << "Enter student name: ";
    cin >> name;

    int max = 1;
    int courseNum = 0;
    string input;
    string *courses = new string[max];
    do {
        cout << "Enter the course (or enter 'quit' to quit): ";
        cin >> input;

        if (input == "quit") continue;
        courses[courseNum++] = input;

        if (courseNum >= max) {
            max += 1;
            string *temp = new string[max];

            for (int i = 0; i < courseNum; i++) {
                temp[i] = courses[i];
            }
            delete []courses;
            courses = temp;
        }
    }
    while (input != "quit");

    auto *studentOne = new Student(name, courseNum, courses);

    cout << studentOne->toString() << endl;
    cout << studentOne << endl;

    return 0;
}
