#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
};

vector<Student> students;
void loadStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.id >> s.name) {
        students.push_back(s);
    }
    file.close();
}

void addStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    students.push_back(s);

    ofstream file("students.txt", ios::app);
    file << s.id << " " << s.name << endl;
    file.close();

    cout << "Student added successfully!\n";
}
void displayStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (auto s : students) {
        cout << s.id << " - " << s.name << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << endl;
            return;
        }
    }

    cout << "Student not found\n";
}
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            found = true;
            break;
        }
    }

    if (found) {
        ofstream file("students.txt");
        for (auto s : students) {
            file << s.id << " " << s.name << endl;
        }
        file.close();

        cout << "Student deleted successfully!\n";
    } else {
        cout << "Student not found\n";
    }
}

int main() {
    int choice;

    loadStudents();

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}