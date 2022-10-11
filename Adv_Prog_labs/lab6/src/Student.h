#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum Gender{
    MALE,
    FEMALE
};


class Student{

private:
    long id; // Unique ID
    string name; // Name of student
    Gender gender; // Gender of student
    string courseCode; // Course code (CIIC or ICOM)
    double gpa; // GPA of student

public:
    Student(long id, const string &name, Gender gender, double gpa){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->courseCode = "";
        this->gpa = gpa;
    }

    Student(long id, const string &name, Gender gender, string courseCode, double gpa){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->courseCode = courseCode;
        this->gpa = gpa;
    }

    Student(){}

    static string toString(Student& s){
        string genderLetter = (s.gender  == MALE ? "M" : "F");
        return string("{" + to_string(s.id) + "," + s.name + "," + genderLetter + "," + to_string(s.gpa) + "}");
    }

    static string toString(vector<Student>& v){
        string result = "{";
        for (Student s : v) {
            result += toString(s) + ",";
        }
        result += "}";
        return result;
    }

    static string toString(vector<long>& v){
        string result = "{";
        for (long id : v) {
            result += to_string(id) + ",";
        }
        result += "}";
        return result;
    }

    // Getters
    long getID(){return id;}
    string getName(){return name;}
    Gender getGender(){return gender;}
    double getGPA(){return gpa;}
    string getCourseCode(){return courseCode;}

    //Setters
    void setName(string name){this->name = name;}
    void setGender(Gender gender){this->gender = gender;}
    void setGPA(double gpa){this->gpa = gpa;}
    void setCourseCode(string code){this->courseCode = code;}

    // EXERCISES
    static double maxStudentGPA(vector<Student>& v);
    static double minStudentGPA(vector<Student>& v);
    static double averageGPA(vector<Student> &v, int N);
    static vector<long> countStudents(vector<Student>& v, string code);
    static void removeByID(vector<Student> &v, long ID);
    static void updateStudent(vector<Student> &v, Student s);
    static vector<Student> findStudents(vector<Student>& v, float gpa);
    static vector<Student> repeatedStudentNames(vector<Student>& v); //BONUS
   
};