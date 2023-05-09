#ifndef DS_ASSIGNMENT_3_STUDENT_H
#define DS_ASSIGNMENT_3_STUDENT_H

#include <iostream>
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

    friend istream& operator>>(istream& in, Student& stud) {
        int id;
        string Name, Department;
        float GPA;
        in >> id >> Name >> GPA >> Department;
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
