#include "Student.h"

using namespace std;

/*
* EXERCISE: #2A
*
* IMPLEMENT USING AN ENHANCED FOR LOOP (ForEach).
*
* Returns the value of the Student's GPA
* that has the maximum GPA on the list
*  
*/
double Student::maxStudentGPA(vector<Student>& v)
{
    double maxGPA = 0.0;
    for(Student stu : v){
        if(stu.getGPA() > maxGPA){
            maxGPA = stu.getGPA();
        }
    }

    return maxGPA; //DUMMY RETURN
}

/*
* EXERCISE: #2B
*
* IMPLEMENT USING A REGULAR FOR LOOP.
*
* Returns the value of the Student's GPA
* that has the minimum GPA of the list
*
*/
double Student::minStudentGPA(vector<Student>& v)
{
    double minGPA = 4.0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].getGPA() < minGPA){
            minGPA = v[i].getGPA();
        }
    }
    
    return minGPA; //DUMMY RETURN
}

/* 
* Exercise #2C
*
* IMPLEMENT USING A WHILE LOOP
*
* For the first N students, calculate the average gpa
* 
* Formula: average = sum / N
*    Assume N is greater than 0
*/
double Student::averageGPA(vector<Student> &v, int N){
    
    int counter = 0;
    double sum = 0;
    while(counter < N){

        sum += v[counter].getGPA();
        counter++;

    }
    
    return sum/N; //DUMMY RETURN
}

/*
* EXERCISE #3
* 
* IMPLEMENT IT USING AN ENHANCED FOR LOOP (ForEach)
*
* Given the course code (CIIC or ICOM), you must return a vector
* that contains ONLY the unique ID of the Students that have on record
* a that course code.
*/
vector<long> Student::countStudents(vector<Student>& v, string code){
    vector<long> result;

    for(Student fulano : v){
        if(fulano.getCourseCode() == code){
            result.push_back(fulano.getID());
        }
    }

    return result;
}

/*
* EXERCISE #4
* 
* IMPLEMENT USING A DO...WHILE LOOP
* 
* Return a vector that contains all the Students that have a GPA greater
* or equal to the GPA passed as the parameter
* 
* Assume the list contains at least one element
*/
vector<Student> Student::findStudents(vector<Student>& v, float gpa){
    int counter = 0;
    vector<Student> high_gpa;
    do{
        if(v[counter].getGPA() >= gpa){
           high_gpa.push_back(v[counter]);
        }
        counter++;
    }
    while ((counter < v.size()));
    

    return high_gpa;
}

/*
* EXERCISE: #5
*
* IMPLEMENT WITH ANY LOOP
*
* Removes the first occurrence of the specified Student ID,
* if it is present. If not present, then list is unchanged.
*
* HINT: Verify the methods erase() and begin() of the vector
*/
void Student::removeByID(vector<Student> &v, long ID){

    for(int i = 0; i < v.size(); i++){
        if(v[i].getID() == ID){
            v.erase(v.begin() + i);
        }
    }
}

/*
* EXERCISE #6
* 
* DO NOT USE WHILE LOOPS
*
* Find the Student record that matches the given Student
* and update its data. If the Student is not present, add it to the list.
* 
* Remember that each Student has an unique identifier
*/
void Student::updateStudent(vector<Student> &v, Student s){
    int max_cap = v.size() - 1;
    for(int i = 0; i < v.size(); i++){
        if(v[i].getID() == s.getID()){

            v[i].setName(s.getName());
            v[i].setGPA(s.getGPA());
            v[i].setGender(s.getGender());

        }

        else{
            v.push_back(s);
        }

    }

}

/*
* BONUS
*
* IMPLEMENT WITH NESTED LOOPS USING ANY LOOP.
*
* Returns a vector cointaining two Students that has the same name.
* If there is no repeated names, the vector stays empty.
* 
* HINT: Use the compare method of the string library
*/
vector<Student> Student::repeatedStudentNames(vector<Student>& v){

    //YOUR CODE HERE

    return v;
}
