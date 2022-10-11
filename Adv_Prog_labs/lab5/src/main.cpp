#include "Planet.h"
#include "Mario.h"

int main() {

    //----------------------PART 1-------------------------------

    cout << "--------- PART #1 ---------" << endl;
    Planet p0("CIIC", 67211, true, 34.66, true, "AZGARD", "MILKYWAY");
	Planet p1("EXON", 2323, true, 3.42, false, "Tatooine", "ANDROMEDA"); //using normal constructor
    Planet p2(p1); //using copy constructor
    Planet p3; //using default constructor
    
    cout << "\n------ EX1 Default constructor ------" << endl;
	cout << p3.toString() << endl;

    cout << "\n------ EX2 Compare Area ------" << endl;
    cout << p0.compareArea(p1) << endl;

    cout << "\n------ EX3 Volume ------" << endl;
    cout << p1.volumePlanet() << endl;

    cout << "\n------ EX4 Same Galaxy ------" << endl;
    cout << (p2.sameGalaxy(p1)?"TRUE":"FALSE") << endl;
    
    //----------------------PART 2-------------------------------

    cout << "\n--------- PART #2 ---------" << endl;
    Mario m0(12,33,444,2,1);
    Mario m1(13,44,100,56,3);
    Mario m2(m1);

    cout <<"\n-------- EX5A Constructor --------" << endl;
    cout << m0.toString() << endl;

    cout << "\n------ EX5B Copy Constructor ------" << endl;
    cout << m2.toString() << endl;

    cout << "\n------ EX6 Decision Player ------" << endl;
    cout << m0.decisionPlayer(m1).toString() << endl;

    cout << "\n------ EX7 # Levels Passed ------" << endl;
    cout << "Levels passed before: " << to_string(m1.getLevelsCleared()) << endl;
    m1.passedLevel();
    cout << "Levels passed after: " << to_string(m1.getLevelsCleared()) << endl;

    cout << "\n------ EX8 New World ------" << endl;
    cout << (m0.readyForNewWorld()?"TRUE":"FALSE") << endl;

    cout << "\n------ Ex9 Enough Coins ------" << endl;
    cout << (m1.buyStar()?"TRUE":"FALSE") << endl;

    cout << "\n------ EX10 Survive Bowser ------" << endl;
    cout << to_string(m2.surviveBowser()) << endl;

	return 0;
}