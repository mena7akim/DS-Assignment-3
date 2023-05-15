#ifndef DS_ASSIGNMENT_3_STUDENT_H
#define DS_ASSIGNMENT_3_STUDENT_H

#include <iostream>
#include <iomanip>
using namespace std;


class Student {
    int ID;
    string name;
    string department;
    float gpa;
public:
    Student() {
        ID = 0;
        name = "";
        department = "";
        gpa = 0.0;
    }

    Student(int ID, string name, string department, float gpa) {
        this->ID = ID;
        this->name = name;
        this->department = department;
        this->gpa = gpa;
    }

    int getId() const {
        return ID;
    }

    void setId(int id) {
        ID = id;
    }

    string getName() const {
        return name;
    }

    void setName(string &Name) {
        name = Name;
    }

    string getDepartment() const {
        return department;
    }

    void setDepartment(string &dep) {
        department = dep;
    }

    float getGpa() const {
        return gpa;
    }

    void setGpa(float GPA) {
        gpa = GPA;
    }

    bool operator<(const Student &stud) const {
        return this->ID < stud.ID;
    }

    bool operator<=(const Student &stud) const {
        return this->ID <= stud.ID;
    }

    bool operator>(const Student &stud) const {
        return this->ID > stud.ID;
    }

    bool operator>=(const Student &stud) const {
        return this->ID >= stud.ID;
    }

    bool operator==(const Student &stud) const {
        return this->ID == stud.ID;
    }

    void printStudent() const {
        cout << string(31, '-') << '\n';
        cout << "| Name: " << name << setw(24 - name.size()) << "|\n";
        cout << "| ID: " << ID << setw(26 - to_string(ID).size()) << "|\n";
        cout << "| Department: " << department << setw(18 - department.size()) << "|\n";
        cout << "| GPA: " << (float) gpa << setw(30 - to_string((float) gpa).size()) << "|\n";
        cout << string(31, '-') << '\n';
    }
    friend istream& operator>>(istream& in, Student& stud) {
        int id;
        string Name, Department;
        float GPA;
        cout << "Enter student ID:\n";
        in >> id;
        cout << "Enter student name:\n";
        in >> Name;
        cout << "Enter student gpa:\n";
        in >> GPA;
        cout << "Enter student department:\n";
        in >> Department;
        stud.setId(id);
        stud.setName(Name);
        stud.setDepartment(Department);
        stud.setGpa(GPA);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& stud) {
        out << stud.ID << ' ' << stud.name << ' ' << stud.department << ' ' << stud.gpa << '\n';
        return out;
    }
};


#endif
