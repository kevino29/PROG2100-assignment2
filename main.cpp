#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string *courseList;
    int numCourses;
public:
    Student()= default; //default constructor

    Student(string& name){
        this->name = name;
    }

    Student(string& name, int& numCourses, string* courseList) {
        this->name = name;
        this->numCourses = numCourses;
        this->courseList = courseList;
    }

    Student(Student& other) {
        this->name = other.getName();
        this->numCourses = other.getNumCourses();

        // Deep copy of the course list
        if (other.getCourseList()) {
            this->courseList = new string[other.getNumCourses()];

            for (int i = 0; i < other.getNumCourses(); i++) {
                this->courseList[i] = other.getCourseList()[i];
            }
        }
        else {
            this->courseList = nullptr;
        }
    }

    ~Student() { //destructor
        if (courseList) {
            courseList = nullptr;
            delete[] courseList;
        }
        numCourses = 0;
    }

    string getName() {return this->name;}
    void setName(string name) {this->name = name;}

    int getNumCourses() const {return this->numCourses;}

    string* getCourseList() {return this->courseList;}

    string toString() {
        string output = "Student Name: " + this->name + "\n" +
                "Number of Course(s): " + to_string(this->numCourses) + "\n" +
                "Course List:\n";

        for (int i = 0; i < this->numCourses; i++) {
            output += this->courseList[i] + "\n";
        }

        return output;
    }

    Student& operator=(Student& other) {
        if (&other != this) {
            this->name = other.getName();
            this->numCourses = other.getNumCourses();
            this->courseList = other.getCourseList(); // Shallow copy
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, Student& student); // needs work, only returns the address
};

ostream& operator<<(ostream& os, Student& student) {
    os << student.toString() << endl;
    return os;
}

void program() {
    // Gets student one information
    string name;
    cout << "Enter student one name: ";
    cin >> name;

    int max = 1;
    int courseNum = 0;
    string input;
    string *courses = new string[max];
    do { //Loops until the user enters 'quit'
        cout << "Enter the course (or enter 'quit' to quit): ";
        cin >> input;

        if (input == "quit") continue;
        courses[courseNum++] = input;

        if (courseNum >= max) { //Resizes the array for more storage if full.
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
    cout << endl;

    // Creates student one and output information using the overloaded << operator
    Student studentOne(name, courseNum, courses);
    cout << studentOne;

    // Gets student two name
    cout << "Enter student two name: ";
    cin >> name;
    cout << endl;

    // Copies the information from student one to student two
    Student studentTwo(studentOne);
    cout << "Copy constructor activated" << endl;
    studentTwo.setName(name); //set a new name for student two

    studentOne.~Student();
    cout << "Destructor activated." << endl;
    cout << studentOne;
    cout << studentTwo;

    Student studentThree;
    studentThree = studentTwo;
    cout << "Custom assignment operator activated." << endl;
    cout << studentThree;
}

int main() {
    cout << "Welcome to the Student Course Program.\n" << endl;

    while (true) {
        program();

        string input;
        cout << "Try again? (y or n)" << endl;
        cin >> input;

        if (input == "n")
            break;
    }
    return 0;
}
