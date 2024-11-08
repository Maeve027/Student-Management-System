/* Name- Methli Singh
   Elex. & Telecomm. - "A" (ETC-A)
   Roll No. 23T3037
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    int id;
    string name;
    int age;
    float grade;
  Student(int id, string name, int age, float grade) 
        : id(id), name(name), age(age), grade(grade) {}
};
void displayStudent(const Student& s) {
    cout << "ID: " << s.id << " | Name: " << s.name << " | Age: " << s.age << " | Grade: " << s.grade << endl;
}
void traverseQueue(queue<Student>& q) {
    if (q.empty()) {
        cout << "No students in the system yet!" << endl;
        return;
    }
    cout << "\nList of all students:\n";
    queue<Student> temp = q;
    while (!temp.empty()) {
        displayStudent(temp.front());
        temp.pop();
    }
    cout << endl;
}
void insertStudent(queue<Student>& q, int id, const string& name, int age, float grade) {
    Student newStudent(id, name, age, grade);
    q.push(newStudent);
    cout << "Student record inserted successfully!" << endl;
}
void searchStudentById(queue<Student>& q, int id) {
    queue<Student> temp = q;
    bool found = false;
    while (!temp.empty()) {
        if (temp.front().id == id) {
            cout << "Student found:\n";
            displayStudent(temp.front());
            found = true;
            break;
        }
        temp.pop();
    }
    if (!found) {
        cout << "Student with ID " << id << " not found!" << endl;
    }
}
void updateStudent(queue<Student>& q, int id, const string& newName, int newAge, float newGrade) {
    queue<Student> temp;
    bool updated = false;
    while (!q.empty()) {
        Student current = q.front();
        q.pop();
        if (current.id == id) {
            current.name = newName;
            current.age = newAge;
            current.grade = newGrade;
            updated = true;
            cout << "Student record updated successfully!" << endl;
        }
        temp.push(current);
    }
    if (!updated) {
        cout << "Student with ID " << id << " not found for update!" << endl;
    }
    q = temp;
}
void deleteStudent(queue<Student>& q, int id) {
    queue<Student> temp;
    bool deleted = false;
    while (!q.empty()) {
        Student current = q.front();
        q.pop();
        if (current.id == id) {
            deleted = true;
            cout << "Student with ID " << id << " has been deleted successfully!" << endl;
        } else {
            temp.push(current);
        }
    }
    if (!deleted) {
        cout << "Student with ID " << id << " not found for deletion!" << endl;
    }
    q = temp;
}
void sortStudents(queue<Student>& q) {
    vector<Student> studentList;
    while (!q.empty()) {
        studentList.push_back(q.front());
        q.pop();
    }
    sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade; // Sorting by grade
    });
    for (const auto& student : studentList) {
        q.push(student);
    }
    cout << "Students sorted by grade!" << endl;
}
int main() {
    queue<Student> studentQueue;
    int choice;
    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Insert a new student\n";
        cout << "2. Search for a student by ID\n";
        cout << "3. Traverse and display all students\n";
        cout << "4. Update student details\n";
        cout << "5. Delete a student\n";
        cout << "6. Sort students by grade\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id, age;
                string name;
                float grade;
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student grade: ";
                cin >> grade;
                insertStudent(studentQueue, id, name, age, grade);
                break;
            }
            case 2: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                searchStudentById(studentQueue, id);
                break;
            }
            case 3: {
                traverseQueue(studentQueue);
                break;
            }
            case 4: {
                int id, age;
                string name;
                float grade;
                cout << "Enter student ID to update: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter new student name: ";
                getline(cin, name);
                cout << "Enter new student age: ";
                cin >> age;
                cout << "Enter new student grade: ";
                cin >> grade;
                updateStudent(studentQueue, id, name, age, grade);
                break;
            }
            case 5: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                deleteStudent(studentQueue, id);
                break;
            }
            case 6: {
                sortStudents(studentQueue);
                break;
            }
            case 7: {
                cout << "Exiting the system. Have a nice day!" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }
    return 0;
}
