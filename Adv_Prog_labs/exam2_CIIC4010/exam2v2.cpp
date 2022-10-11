/*
 * Candidate is a class that represents students who have
 * applied for admission. Each Candidate object includes
 * the student's GPA, SAT score, their high school and the
 * major they are applying to (see list of majors provided). 
 */
#include <iostream>
#include <vector>
#include <algorithm> // std::reverse
#include <string>

using namespace std;

enum Major
{
    CIIC,
    INSO,
    ICOM,
    COMP,
    SICI,
    OTHER
};

class Candidate
{

private:
    string name;
    string highSchool;
    double gpa;
    int sat;
    Major major;

public:
    Candidate(){};

    Candidate(string name, string highSchool, double gpa, int sat, Major major)
    {
        this->name = name;
        this->highSchool = highSchool;
        this->gpa = gpa;
        this->sat = sat;
        this->major = major;
    }

    string getName() { return name; }
    string getHighSchool() { return highSchool; }
    double getGpa() { return gpa; }
    int getSat() { return sat; }
    Major getMajor() { return major; }

    void setName(string name) { this->name = name; }
    void setHighSchool(string highSchool) { this->highSchool = highSchool; }
    void setGpa(double gpa) { this->gpa = gpa; }
    void setSat(int sat) { this->sat = sat; }
    void setMajor(Major major) { this->major = major; }

    // Returns true (1) if all the properties of target and the other Candidate are equal
    bool equals(Candidate otherCandidate)
    {
        return this->getName() == otherCandidate.getName() &&
               this->getHighSchool() == otherCandidate.getHighSchool() &&
               this->getGpa() == otherCandidate.getGpa() &&
               this->getSat() == otherCandidate.getSat() &&
               this->getMajor() == otherCandidate.getMajor();
    }

    // Return true (1) if both vectors are equal, uses above equals method
    static bool compareVectors(vector<Candidate> v1, vector<Candidate> v2)
    {
        if (v1.size() != v2.size())
            return false;

        for (int i = 0; i < v1.size(); i++)
        {
            if (!v1[i].equals(v2[i]))
                return false;
        }

        return true;
    }

    /**
     * EXERCISE #1: Returns the count of candidates from a given highschool.
     */
    static int highSchoolCount(string highSchool, vector<Candidate> candidates);
    /**
     * EXERCISE #2: Remove all unqualified candidates for admission.
     * Any candidate must be removed if it has less than the required GPA or SAT.
     */
    static void removeUnqualifiedCandidates(double reqGPA, double reqSAT, vector<Candidate> &candidates);
    /**
     * EXERCISE #3: Return true if the given vector doesn't have any duplicate candidate.
     * Otherwise return false (Hint: Use the given equals method).
     */
    static bool noDuplicates(vector<Candidate> candidates);
    /**
     * EXERCISE #4: Return the first occurrence of a candidate that fullfill the
     * GPA and SAT requirements. Assume that at least 1 candidate fullfill the 
     * requirements.
     */
    static Candidate firstOccurrenceOfACandidate(double reqGPA, double reqSAT, vector<Candidate> candidates);
    /**
     * EXERCISE #5: Return the the highest GPA of a candidate for a given requested
     * major. If there is no candidate for the given major return 0;
     */
    static double highestGPAperMajor(Major m, vector<Candidate> candidates);
    /**
     * EXERCISE #6: Return the position of the candidate with the highest score
     * The score is calculated by multiplying the GPA value with the SAT value.
     * If the vector is empty return -1;
     */
    static int highestScore(vector<Candidate> candidates);
    /**
     * EXERCISE #7: Return the average SAT score of a given requested mayor.
     * If there is no candidates for the given mayor return 0.
     */ 
    static double avgSatperMajor(Major m, vector<Candidate> candidates);
    /**
     * EXERCISE #8: Returns a new vector containing the DIFFERENCE of all the Candidates
     * from the two parameter vector (v1 - v2), that is the set of the candidates on parameter 
     * v1 that are NOT present on parameter v2.
     * Use the given equals method to determine if two candidates are the same.
     */    
    static vector<Candidate> difference(vector<Candidate> v1, vector<Candidate> v2);
};

/**
 * EXERCISE #1: Returns the count of candidates from a given highschool.
 */
int Candidate::highSchoolCount(string highSchool, vector<Candidate> candidates){
    
    int counter = 0;
    for(int i = 0; i < candidates.size(); i++){

        if(candidates[i].getHighSchool() == highSchool){
            counter++;
        }
    }
  	return counter; //Dummy Return
}

/**
 * EXERCISE #2: Remove all unqualified candidates for admission.
 * Any candidate must be removed if it has less than a required GPA and SAT.
 */
void Candidate::removeUnqualifiedCandidates(double reqGPA, double reqSAT, vector<Candidate> &candidates){
    
    for(int i = 0; i < candidates.size(); i++){

        for(int j = i + 1; j < candidates.size(); j++){

            if(candidates[i].getGpa() < reqGPA || candidates[i].getSat() < reqSAT){
                candidates.erase(candidates.begin() + i, candidates.begin() + j);
            }
        }
    }
    
}

/**
 * EXERCISE #3: Return true if the given vector doesn't have any duplicate candidate.
 * Otherwise return false (Hint: Use the given equals method).
 */
bool Candidate::noDuplicates(vector<Candidate> candidates){

    bool isEqual = false;
    
    for(int i = 0; i< candidates.size(); i++){

        for(int j = i + 1; j < candidates.size(); j++){

            if(candidates[i].equals(candidates[j])){
                
                isEqual = true;
            }
        }
    }
}

/**
 * EXERCISE #4: Return the first occurrence of a candidate that fullfill the
 * GPA and SAT requirements. Assume that at least 1 candidate fullfill the 
 * requirements.
 */
Candidate Candidate::firstOccurrenceOfACandidate(double reqGPA, double reqSAT, vector<Candidate> candidates){
    
    Candidate qualified;
    for(int i = 0; i < candidates.size(); i++){
        
        if(candidates[i].getGpa() >= reqGPA && candidates[i].getSat() >= reqSAT){
            qualified = candidates[i];
        }
    }
    return qualified; 
}

/**
 * EXERCISE #5: Return the the highest GPA of a candidate for a given requested
 * major. If there is no candidate for the given major return 0;
 */
double Candidate::highestGPAperMajor(Major m, vector<Candidate> candidates){
    
    int largest_gpa = -1;
    for(int i = 0; i < candidates.size(); i++){

        if(candidates[i].getMajor() == m && candidates[i].getGpa() > largest_gpa){
            largest_gpa = candidates[i].getGpa();
            return largest_gpa;
        }
    }
    return 0;
}
/**
 * EXERCISE #6: Return the position of the candidate with the highest score
 * The score is calculated by multiplying the GPA value with the SAT value.
 * If the vector is empty return -1;
 */
int Candidate::highestScore(vector<Candidate> candidates){

    int score = 0;
    for(int i = 0; i < candidates.size(); i++){

        int s = candidates[i].getSat() * candidates[i].getGpa();
        if(s > score){
            score = s;
        }
        
    }
    return score;
}

/**
 * EXERCISE #7: Return the average SAT score of a given requested mayor.
 * If there is no candidates for the given mayor return 0.
 */ 
double Candidate::avgSatperMajor(Major m, vector<Candidate> candidates){
    
    double sum = 0.0;
    int num_of_can = 0;
    double avg = sum/num_of_can;
    for(int i = 0; i < candidates.size(); i++){

        if(candidates[i].getMajor() == m){

            sum += candidates[i].getGpa();
            num_of_can++;
        }

    }
    return avg;
}

/**
 * EXERCISE #8: Returns a new vector containing the DIFFERENCE of all the Candidates
 * from the two parameter vector (v1 - v2), that is the set of the candidates on parameter 
 * v1 that are NOT present on parameter v2.
 * Use the given equals method to determine if two candidates are the same.
 */
vector<Candidate> Candidate::difference(vector<Candidate> v1, vector<Candidate> v2){

    vector<Candidate> different;
    
    for(int i = 0; i < v1.size(); i++){

        for(int j = 0; j < v2.size(); j++){

            if(!v2[j].equals(v1[i])){
                different.push_back(v1[i]);
            }
        }
    }
    return different;
}

int main()
{
    Candidate john("John", "JFK Isabela", 3.49, 1500, CIIC);
    Candidate dave("Dave", "PLT Pepino ", 3.50, 1550, COMP);
    Candidate sally("Sally", "ABC Mayaguez", 3.51, 1450, ICOM);
    Candidate tom("Tom", "DEF Ponce", 3.50, 1575, INSO);
    Candidate pete("Pete", "GHI Aguada", 3.00, 1400, OTHER);
    Candidate ana("Ana", "ABC Mayaguez", 3.75, 1400, CIIC);
    Candidate drew("Drew", "DEF Ponce", 3.75, 1565, CIIC);
    Candidate kate("Kate", "JKL SJ", 3.90, 1599, INSO);
    Candidate jane("Jane", "ABC Mayaguez", 3.95, 1555, SICI);

    vector<Candidate> zCollege{john, dave, sally, tom, pete, ana, drew, kate, jane};
    vector<Candidate> aCampus{john, dave, sally, tom, pete};
    vector<Candidate> bCampus{pete, ana, drew, kate, pete};
    vector<Candidate> cCampus{jane};
    vector<Candidate> ciicCandidates{john, ana, drew};
    vector<Candidate> insoCandidates{tom, kate};
    vector<Candidate> gCollege{ana, drew, kate, jane};
    vector<Candidate> hCollege{john, dave, sally, tom};
    vector<Candidate> iCollege{ana, drew, kate};
    vector<Candidate> empty;

    // SAMPLE TEST CASES -- MAY BE DIFFERENT FROM THOSE IN THE EXAM

    cout << "Ex 1 *************************************" << endl;
    cout << Candidate::highSchoolCount("ABC Mayaguez", zCollege) << endl;
    cout << Candidate::highSchoolCount("ABC Ponce", zCollege) << endl;
    cout << Candidate::highSchoolCount("JFK Moca", zCollege) << endl;

    cout << "Ex 2 *************************************" << endl;
    cout << zCollege[0].getName() << endl;
    Candidate::removeUnqualifiedCandidates(3.5,1500,zCollege);
    cout << zCollege[0].getName() << endl;

    cout << "Ex 3 *************************************" << endl;
    cout << Candidate::noDuplicates(aCampus) << endl;
    cout << Candidate::noDuplicates(bCampus) << endl;

    cout << "Ex 4 *************************************" << endl;
    cout << Candidate::firstOccurrenceOfACandidate(3.0,1500,aCampus).getName() << endl;
    cout << Candidate::firstOccurrenceOfACandidate(3.0,1500,bCampus).getName() << endl;

    cout << "Ex 5 *************************************" << endl;
    cout << Candidate::highestGPAperMajor(CIIC,zCollege) << endl;
    cout << Candidate::highestGPAperMajor(ICOM,aCampus) << endl;
    cout << Candidate::highestGPAperMajor(OTHER,bCampus) << endl;
    cout << Candidate::highestGPAperMajor(CIIC,empty) << endl;

    cout << "Ex 6 *************************************" << endl;
    cout << Candidate::highestScore(zCollege) << endl;
    cout << Candidate::highestScore(empty) << endl;
    cout << Candidate::highestScore(cCampus) << endl;

    cout << "Ex 7 *************************************" << endl;
    cout << Candidate::avgSatperMajor(CIIC, zCollege) <<endl;
    cout << Candidate::avgSatperMajor(INSO, zCollege) <<endl;
    cout << Candidate::avgSatperMajor(CIIC, empty) <<endl;

    cout << "Ex 8 *************************************" << endl;
    zCollege = {john, dave, sally, tom, pete, ana, drew, kate, jane};
    cout << Candidate::compareVectors(Candidate::difference(zCollege, aCampus), gCollege) << endl;
    cout << Candidate::compareVectors(Candidate::difference(aCampus, zCollege), empty) << endl;
    cout << Candidate::compareVectors(Candidate::difference(aCampus, bCampus), hCollege) << endl;
    cout << Candidate::compareVectors(Candidate::difference(bCampus, aCampus), iCollege) << endl;

    return 0;
}