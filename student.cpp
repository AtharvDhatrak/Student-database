#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    double marks;
};

vector<Student> studentRecords;

void addRecord() {
    Student student;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter marks: ";
    cin >> student.marks;
    studentRecords.push_back(student);
    cout << "Student record added successfully!\n";
}

void displayRecords() {
    if (studentRecords.empty()) {
        cout << "No student records to display.\n";
        return;
    }

    cout << "Student Records:\n";
    for (const auto& student : studentRecords) {
        cout << "Name: " << student.name << "\n";
        cout << "Roll Number: " << student.rollNumber << "\n";
        cout << "Marks: " << student.marks << "\n";
        cout << "-----------------------\n";
    }
}

void searchRecord() {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    for (const auto& student : studentRecords) {
        if (student.rollNumber == rollNumber) {
            cout << "Student found:\n";
            cout << "Name: " << student.name << "\n";
            cout << "Roll Number: " << student.rollNumber << "\n";
            cout << "Marks: " << student.marks << "\n";
            return;
        }
    }

    cout << "Student with roll number " << rollNumber << " not found.\n";
}

void deleteRecord() {
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    for (auto it = studentRecords.begin(); it != studentRecords.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            it = studentRecords.erase(it);
            cout << "Student record deleted successfully!\n";
            return;
        }
    }

    cout << "Student with roll number " << rollNumber << " not found.\n";
}

int main() {
    while (true) {
        cout << "\nStudent Record System\n";
        cout << "1. Add student record\n";
        cout << "2. Display student records\n";
        cout << "3. Search student record\n";
        cout << "4. Delete student record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

