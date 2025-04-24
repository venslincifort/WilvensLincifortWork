#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Student Class Definition
// Represents a student with attributes: Name, Grade, Age, and ID.
class Student {
public:
    string Name;
    int Grade;
    int Age;
    int ID;

    // Default constructor
    Student() : Name("Unknown"), Grade(0), Age(0), ID(0) {}

    // Parameterized constructor
    Student(string x, int y, int z, int j) : Name(x), Grade(y), Age(z), ID(j) {}

    // Display student information
    void displayInfo() const {
        cout << "ID: " << ID << " | Name: " << Name << " | Grade: " << Grade << " | Age: " << Age << endl;
    }

    // Accessor and mutator methods
    int getID() const { return ID; }
    string getName() const { return Name; }
    int getGrade() const { return Grade; }
    int getAge() const { return Age; }

    void setID(int a) { ID = a; }
    void setName(string a) { Name = a; }
    void setGrade(int a) { Grade = a; }
    void setAge(int a) { Age = a; }
};


void addStudent(vector<Student>& students) {
    int age, id, grade;
    string name;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Grade: ";
    cin >> grade;
    cout << "Enter Age: ";
    cin >> age;

    students.push_back(Student(name, grade, age, id));
    cout << "Student added successfully!" << endl;
}


void insertAtPosition(vector<Student>& students, const Student& newStudent, int position) {
    if (position >= 0 && position <= students.size()) {
        students.insert(students.begin() + position, newStudent);
        cout << "Student inserted at position " << position + 1 << "." << endl;
    } else {
        cout << "Invalid position!" << endl;
    }
}


void removeStudent(vector<Student>& students, int id) {
    auto it = remove_if(students.begin(), students.end(), [id](const Student& student) {
        return student.getID() == id;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student removed successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}


void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display." << endl;
    } else {
        for (const auto& student : students) {
            student.displayInfo();
        }
    }
}


void sortByCondition(vector<Student>& students, const string& condition) {
    if (condition == "Name") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getName() < b.getName();
        });
        cout << "Students sorted by Name." << endl;
    } else if (condition == "Age") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getAge() < b.getAge();
        });
        cout << "Students sorted by Age." << endl;
    } else {
        cout << "Invalid sorting condition!" << endl;
    }
}


void reverseStudents(vector<Student>& students) {
    reverse(students.begin(), students.end());
    cout << "Students reversed successfully!" << endl;
}


void getMinMax(const vector<Student>& students, const string& condition) {
    if (students.empty()) {
        cout << "No students in the list." << endl;
        return;
    }

    if (condition == "MinAge") {
        auto minAgeStudent = *min_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getAge() < b.getAge();
        });
        cout << "Student with minimum age: ";
        minAgeStudent.displayInfo();
    } else if (condition == "MaxAge") {
        auto maxAgeStudent = *max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getAge() > b.getAge();
        });
        cout << "Student with maximum age: ";
        maxAgeStudent.displayInfo();
    } else {
        cout << "Invalid condition!" << endl;
    }
}


void filterByCondition(const vector<Student>& students, const string& condition, int value) {
    vector<Student> filtered;
    if (condition == "AgeAbove") {
        for (const auto& student : students) {
            if (student.getAge() > value) {
                filtered.push_back(student);
            }
        }
    } else if (condition == "GradeBelow") {
        for (const auto& student : students) {
            if (student.getGrade() < value) {
                filtered.push_back(student);
            }
        }
    }

    if (filtered.empty()) {
        cout << "No students match the filter condition." << endl;
    } else {
        for (const auto& student : filtered) {
            student.displayInfo();
        }
    }
}


void updateStudent(vector<Student>& students, int id) {
    auto it = find_if(students.begin(), students.end(), [id](const Student& student) {
        return student.getID() == id;
    });

    if (it != students.end()) {
        cout << "Updating information for Student with ID " << id << ":" << endl;

       
       
        string input;
        cout<<"which would you like to update?"<<"Name,Age,Grade?"<<endl;
        cin>>input;
        if(input=="Name"){
        string newName;
        cout << "Enter New Name: ";
        cin >> newName;
        it->setName(newName);
        }
        else if( input== "Age"){
        int newGrade;
        cout << "Enter New Grade: ";
        cin >> newGrade;
        it->setGrade(newGrade);
        }
        else if(input== "Grade"){
        int newAge;
        cout << "Enter New Age: ";
        cin >> newAge;
        it->setAge(newAge);
       
}

     
        cout << "Student updated successfully!" << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}


void searchStudent(const vector<Student>& students, const string& condition, const string& value) {
    bool found = false; // Flag to track if any student is found
    for (int i = 0; i < students.size(); ++i) {
    const Student& student = students.at(i);
        if ((condition == "Name" && student.getName() == value) ||
            (condition == "ID" && to_string(student.getID()) == value)) {
            student.displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No student matches the search criteria." << endl;
    }
}


int main() {
    vector<Student> students;

    cout << "Welcome to the Student Management Program!" << endl;

    while (true) {
        int userChoice = 0;
        cout << endl << "Menu" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Insert Student at Specific Position" << endl;
        cout << "3. Remove a Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Sort Students" << endl;
        cout << "6. Reverse Students" << endl;
        cout << "7. Get Min/Max Value" << endl;
        cout << "8. Filter Students" << endl;
        cout << "9. Update a Student" << endl;
        cout << "10. Search Student" << endl;
        cout << "11. Quit" << endl;
        cout << "Choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            addStudent(students);
        } else if (userChoice == 2) {
            int pos, age, id, grade;
            string name;

            cout << "Enter Position to Insert: ";
            cin >> pos;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Grade: ";
            cin >> grade;
            cout << "Enter Age: ";
            cin >> age;

            insertAtPosition(students, Student(name, grade, age, id), pos - 1);
        } else if (userChoice == 3) {
            int id;
            cout << "Enter ID of Student to Remove: ";
            cin >> id;
            removeStudent(students, id);
        } else if (userChoice == 4) {
            displayStudents(students);
        } else if (userChoice == 5) {
            string condition;
            cout << "Sort by (Name/Age): ";
            cin >> condition;
            sortByCondition(students, condition);
        } else if (userChoice == 6) {
            reverseStudents(students);
        } else if (userChoice == 7) {
            string condition;
            cout << "Get (MinAge/MaxAge): ";
            cin >> condition;
            getMinMax(students, condition);
        } else if (userChoice == 8) {
            string condition;
            int value;
            cout << "Filter by (AgeAbove/GradeBelow): ";
            cin >> condition;
            cout << "Enter Value: ";
            cin >> value;
            filterByCondition(students, condition, value);
        } else if (userChoice == 9) {
            int id;
            cout << "Enter ID of the student to update: ";
            cin >> id;
            updateStudent(students, id);
        } else if (userChoice == 10) {
            string condition, value;
            cout << "Search by (Name/ID): ";
            cin >> condition;
            cout << "Enter the value to search for: ";
            cin >> value;
            searchStudent(students, condition, value);
        } else if (userChoice == 11) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}