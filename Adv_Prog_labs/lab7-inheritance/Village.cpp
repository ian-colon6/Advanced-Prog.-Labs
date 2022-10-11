/**
 * REQUIRED INFO
 * 
 *  Full Name: Ián G. Colón
 * 	GitHub Repo Link: https://github.com/UPRM-CIIC4010-S21/s21-lab07-inheritance-ian-colon6
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*-----------------------------------------------------------------------------------------------------------------------------
	  													This is the abstract class Player
------------------------------------------------------------------------------------------------------------------------------*/
class Player
{
private:
    string name;
    int height;
    int weight;

public:
    Player(string name, int height, int weight)
    {
        this->name = name;
        this->height = height;
        this->weight = weight;
    }
    string getName() { return name; }
    int getHeight() { return height; }
    int getWeight() { return weight; }

    void setName(string name) { this->name = name; }
    void setHeight(int height) { this->height = height; }
    void setWeight(int weight) { this->weight = weight; }

    virtual string toString() = 0;
    virtual bool canDisableAlarm() { return false; }
    virtual bool equals(Player *) = 0;
    virtual string greet() = 0;
    virtual bool canEnterEvent(string event) { return false; }
};
/*--------------------------------------------------------------------------------------------------------------------------------
	 														This is the Villager Class
	 	This is the first class of the four classes. In this class you must to complete part of the given code, read instructions.													

----------------------------------------------------------------------------------------------------------------------------------*/
class Villager : public Player
{

private:
    string job;

public:
    Villager(string name, int height, int weight, string job) : Player(name, height, weight)
    {
        this->job = job;
    }

    string getJob() { return job; }
    void setJob(string job) { this->job = job; }

    virtual string toString();
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};
/*--------------------------------------------------------------------------------------------------------------------------------
													   This is the Police Class
        This is the second class of the four classes. In this class you must to complete part of the given code, read instructions.													

----------------------------------------------------------------------------------------------------------------------------------*/
class Police : public Player
{

private:
    const int SALARY = 50000;
    string rank;

public:
    Police(string name, int height, int weight, string rank) : Player(name, height, weight)
    {
        this->rank = rank;
    }

    string getRank() { return rank; }
    void setRank(string rank) { this->rank = rank; }

    virtual int getSalary() { return SALARY; }

    virtual string toString();
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};
/*---------------------------------------------------------------------------------------------------------------------------------
	   													This is the Chief Class
		This is the third class of the four classes. In this class you must to complete part of the given code, read instructions.													
-----------------------------------------------------------------------------------------------------------------------------------*/
class Chief : public Police
{

private:
    int yearsInService;

public:
    Chief(string name, int height, int weight, int yearsInService);

    int getYearsInService() { return yearsInService; }
    void setYearInService(int yearsInService) { this->yearsInService = yearsInService; }

    virtual int getSalary();

    virtual string toString();
    virtual bool canDisableAlarm();
    virtual string greet();
    virtual bool equals(Player *p);
};

/*----------------------------------------------------------------------------------------------------------------------------------
		                                              This is the Mayor Class
         This is the fourth class of the four classes. In this class you must to complete part of the given code, read instructions.													
------------------------------------------------------------------------------------------------------------------------------------*/
class Mayor : public Player
{

private:
    int term;

public:
    Mayor(string name, int height, int weight, int term) : Player(name, height, weight)
    {
        this->term = term;
    }

    int getTerm() { return term; }
    void setTerm(int term) { this->term = term; }

    virtual string toString();
    virtual bool canEnterEvent(string event);
    virtual string greet();
    virtual bool equals(Player *p);
};

string Villager::toString()
{
    string result = "{Villager: ";
    result += "Name=" + this->getName() + " ";
    result += "Height=" + std::to_string(this->getHeight()) + " ";
    result += "Weight=" + std::to_string(this->getWeight()) + " ";
    result += "Job=" + this->getJob();
    result += "}";
    return result;
}

string Police::toString()
{
    string result = "{Police: ";
    result += "Name=" + this->getName() + " ";
    result += "Height=" + std::to_string(this->getHeight()) + " ";
    result += "Weight=" + std::to_string(this->getWeight()) + " ";
    result += "Rank=" + this->getRank() + " ";
    result += "}";
    return result;
}

string Chief::toString()
{
    string result = "{Chief: ";
    result += "Name=" + this->getName() + " ";
    result += "Height=" + std::to_string(this->getHeight()) + " ";
    result += "Weight=" + std::to_string(this->getWeight()) + " ";
    result += "Rank=" + this->getRank() + " ";
    result += "Years=" + std::to_string(this->getYearsInService()) + " ";
    result += "}";
    return result;
}

string Mayor::toString()
{
    string result = "{Mayor: ";
    result += "Name=" + this->getName() + " ";
    result += "Height=" + std::to_string(this->getHeight()) + " ";
    result += "Weight=" + std::to_string(this->getWeight()) + " ";
    result += "Term=" + std::to_string(this->getTerm()) + " ";
    result += "}";
    return result;
}

/*-----------------------------------------------------------------------------------------------------------------------------
	   												    EXERCISES												
-------------------------------------------------------------------------------------------------------------------------------*/

/*
 * EXERCISE A
 * 
 * Implement the Chief Class constructor by calling its super class constructor
 * and passing the appropriate parameters.
 * HINT: You use the Police class as a guide. And remember a Chief is a rank
*/

Chief::Chief(string name, int height, int weight, int yearsInService) : Police(name, height, weight, "Chief") //Dummy super constructor
{
    this->yearsInService = yearsInService;
    
}

/*
 * EXERCISE B
 * 
 * Override the getSalary method in the Chief class by calling the super
 * getSalary method and adding the bonus times yearInService.
 * If chief has more than 3 years and less than 5 years of service his salary will be raised 25%
 * If chief has 5 years or more and less that 10 years of service his salary will be raised 50%
 * If chief has 10 years or more of service his salary will be raised 75%
 * Else the salary will not be raised.
 */

int Chief::getSalary()
{
    int bonus = 0;
    if(this->getYearsInService() > 3 && this->getYearsInService() < 5){
        bonus = Police::getSalary() * 0.25;
    }
    else if(this->getYearsInService() >= 5 && this->getYearsInService() < 10){
        bonus = Police::getSalary() * 0.5;
    }
    else if(this->getYearsInService() >= 10){
        bonus = Police::getSalary() *0.75;
    }
    else{
        bonus = 0;
    }

    return Police::getSalary() + bonus; //Dummy Return
}

/*
 * EXERCISE C PART 1-a
 * 
 * Override object's method (canEnterEvent) considering
 * the parameter's type string
 * Villager's can only enter the "Party" event
 */

bool Villager::canEnterEvent(string event)
{
    if(event == "Party"){
        return true;
    }
    else{
        return false;
    }

}

/*
 * EXERCISE C PART 1-b
 * 
 * Override object's method canEnterEvent considering
 * the parameter event string
 * Police can only enter the "Party" and "PDMeeting" events
 */

bool Police::canEnterEvent(string event)
{
    if(event == "Party" || event == "PDMeeting"){
        return true;
    }
    else{
        return false;
    }
}

/*
 * EXERCISE C PART 1-c
 * 
 * Override object's method canEnterEvent considering
 * the parameter event string.
 * Mayor can enter the Party, PDMeeting and Presidential Reunion events.
 */

bool Mayor::canEnterEvent(string event)
{
    if(event == "Party" || event == "PDMeeting" || event == "Presidential Reunion"){
        return true;
    }
    else{
        return false;
    }
}

/*
 * EXERCISE C PART 2
 * 
 * Create and Override the canDisableAlarm method in the Chief class to
 * return true. Remember that only a Chief can disable alarms.
 */

bool Chief::canDisableAlarm()
{
    //--->>> Implement here! <<<---
    return true; // Dummy return
}

/*
 * EXERCISE D PART 1
 * 
 * Modify each class to greet as follows: (greet() method).
 * Villager: "Hello, I am [name] and I work at [work place]."
 */

string Villager::greet()
{

    return "Hello, I am " + this->getName() + " and I work at " + this->getJob() + ".";
}

/*
 * EXERCISE D PART 2
 * 
 * Modify the greet method to return the following string:
 * "I am Police [name] at your service."
 */

string Police::greet()
{

    return "I am Police " + this->getName() + " at your service."; //Dummy Return
}

/*
 * EXERCISE D PART 3
 * 
 * Modify each class to greet as follows: (greet() method).
 * Chief: "I am Chief [name]."
 */

string Chief::greet()
{

    return "I am Chief " + this->getName() + "."; //Dummy Return
}

/*
 * EXERCISE D PART 4 
 * 
 * Modify the Mayor's greet method to return the string:
 * "Greetings, I am [name], the Mayor of this city."
 */

string Mayor::greet()
{

    return "Greetings, I am "  + this->getName() + ", the Mayor of this city.";
}

/* 
 * EXERCISE E PART 1
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Villager::equals(Player *p)
{
    Player *player_vill = new Villager(this->getName(), this->getHeight(), this->getWeight(), job);

    Villager* village_dude = dynamic_cast<Villager*>(player_vill);

    if(village_dude->getName() == p->getName() && village_dude->getHeight() == p->getHeight() && village_dude->getWeight() == p->getWeight()){
        return true;
    }
    else{
        return false;
    }
}

/* 
 * EXERCISE E PART 2
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Police::equals(Player *p)
{
    Player *player_cop = new Police(this->getName(), this->getHeight(), this->getWeight(), rank);

    Police* village_cop = dynamic_cast<Police*>(player_cop);

    if(village_cop->getName() == p->getName() && village_cop->getHeight() == p->getHeight() && village_cop->getWeight() == p->getWeight()){
        return true;
    }
    else{
        return false;
    }
}

/* 
 * EXERCISE E PART 3
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Chief::equals(Player *p)
{
    Player *player_chief = new Chief(this->getName(), this->getHeight(), this->getWeight(), yearsInService);

    Chief* village_chief = dynamic_cast<Chief*>(player_chief);

    if(village_chief->getName() == p->getName() && village_chief->getHeight() == p->getHeight() && village_chief->getWeight() == p->getWeight()){
        return true;
    }
    else{
        return false;
    }
}

/* 
 * EXERCISE E PART 4
 * 
 * Override Player's equals method considering
 * the parameter's type and the object's variables.
 * Two players are equal if all their properties are equal.
 */

bool Mayor::equals(Player *p)
{
    Player *player_mayor = new Mayor(this->getName(), this->getHeight(), this->getWeight(), term);

    Mayor* village_mayor = dynamic_cast<Mayor*>(player_mayor);

    if(village_mayor->getName() == p->getName() && village_mayor->getHeight() == p->getHeight() && village_mayor->getWeight() == p->getWeight()){
        return true;
    }
    else{
        return false;
    }
}

/*
 * BONUS:
 * 
 * Implement the method to count the difference types of Players.
 * Return a new string array with 3 numbers as a string.
 * First one would be the number of Villagers.
 * Second would be number of Polices.
 * Third would be number of Mayors.
 * (Hint: Use the method to_string(...) to change from a int to a string)
 */

static vector<string> countTypesOfPlayersIn(vector<Player*> &list)
{
    //Implement here!
    

    return vector<string>{}; //Dummy Return
}

/*
 * 
 * TESTING AREA
 * 
 */

void testChiefConstructor();
void testChiefGetSalary();
void testCanEnterEvent();
void testDisableAlarm();
void testGreet();
void testEquals();
void testCountTypeOfPlayers();

int main()
{
    cout << boolalpha;

    testChiefConstructor();     // A
    testChiefGetSalary();       // B
    testCanEnterEvent();        // C Part 1
    testDisableAlarm();         // C Part 2
    testGreet();                // D
    testEquals();               // E
    testCountTypeOfPlayers();   // BONUS
}

// EXERCISE A
void testChiefConstructor()
{
    cout << "Beginning testChiefConstructor" << endl;
    Chief *c = new Chief("Felipe", 60, 100, 20);
    cout << c->toString() << endl;
}

// EXERCISE B
void testChiefGetSalary()
{
    cout << "Beginning testChiefGetSalary" << endl;

    Chief *chief1 = new Chief("Felipe", 60, 100, 0);
    Chief *chief2 = new Chief("Mario", 65, 120, 1);
    Chief *chief3 = new Chief("Pepe", 65, 120, 3);


    cout << chief1->getSalary() << endl; // Expected 50000
    cout << chief2->getSalary() << endl; // Expected 50000
    cout << chief3->getSalary() << endl; // Expected 50000

}

// EXERCISE C PART 1
void testCanEnterEvent()
{
    cout << "Beginning testCanEnterEvent" << endl;

    Villager *v = new Villager("Alberto", 72, 100, "BlackSmithShop");
    Police *p = new Police("Elvin", 60, 100, "ClerkPlace");
    Chief *c = new Chief("Harry", 61, 100, 5);
    Mayor *m = new Mayor("Bienve", 70, 100, 10);

    cout << v->canEnterEvent("Party") << endl;
    cout << p->canEnterEvent("Party") << endl;
    cout << c->canEnterEvent("Party") << endl;
    cout << m->canEnterEvent("Party") << endl;

    cout << v->canEnterEvent("PDMeeting") << endl;
    cout << p->canEnterEvent("PDMeeting") << endl;
    cout << c->canEnterEvent("PDMeeting") << endl;
    cout << m->canEnterEvent("PDMeeting") << endl;

    cout << v->canEnterEvent("Presidential Reunion") << endl;
    cout << p->canEnterEvent("Presidential Reunion") << endl;
    cout << c->canEnterEvent("Presidential Reunion") << endl;
    cout << m->canEnterEvent("Presidential Reunion") << endl;
}

// EXERCISE C PART 2
void testDisableAlarm()
{
    cout << "Beginning testDisableAlarm" << endl;

    Villager *v = new Villager("Tato", 60, 100, "PizzaPlace");
    Police p1 = Police("Felipe", 64, 100, "Clerk");
    Police p2 = Chief("Juan", 67, 100, 5);
    Mayor *m = new Mayor("Pedro", 68, 100, 10);

    cout << (v->canDisableAlarm()) << endl;
    cout << (p1.canDisableAlarm()) << endl;
    cout << (p2.canDisableAlarm()) << endl;
    cout << (m->canDisableAlarm()) << endl;
}

// EXERCISE D
void testGreet()
{
    cout << "Beginning test greet method" << endl;

    Villager *v = new Villager("Alberto", 72, 100, "BlackSmithShop");
    Police *p = new Police("Elvin", 60, 100, "ClerkPlace");
    Chief *c = new Chief("Harry", 61, 100, 5);
    Mayor *m = new Mayor("Bienve", 70, 100, 10);

    cout << v->greet() << endl; // EXPECTED: "Hello, I am Alberto and I work at BlackSmithShop."
    cout << p->greet() << endl; // EXPECTED: "I am Police Elvin at your service."
    cout << c->greet() << endl; // EXPECTED: "I am Chief Harry.""
    cout << m->greet() << endl; // EXPECTED: "Greetings, I am Bienve, the Mayor of this city."
}

// EXERCISE E
void testEquals()
{
    cout << "Beginning test equals method" << endl;

    Villager *v = new Villager("Alberto", 72, 100, "BlackSmithShop");
    Police *p = new Police("Elvin", 60, 100, "ClerkPlace");
    Chief *c = new Chief("Harry", 61, 100, 5);
    Mayor *m = new Mayor("Bienve", 70, 100, 10);


    cout << v->equals(m) << endl;
    cout << p->equals(c) << endl;
    cout << c->equals(p) << endl;
    cout << m->equals(v) << endl;
    cout << v->equals(v) << endl;
    cout << p->equals(p) << endl;
    cout << c->equals(c) << endl;
    cout << m->equals(m) << endl;

}

// BONUS EXERCISE
void testCountTypeOfPlayers()
{
    cout << "Beginning testCountTypeOfPlayers" << endl;

    const int villagerIndex = 0;
    const int policeIndex = 1;
    const int mayorIndex = 2;

    Player *c = new Chief("Harry", 61, 100, 5);
    Player *m = new Mayor("Bienve", 70, 100, 10);
    Player *p = new Police("Elvin", 60, 100, "ClerkPlace");
    Player *v = new Villager("Alberto", 72, 100, "BlackSmithShop");

    vector<Player*> list = {c, m, p, v};

    vector<string> playersCount = countTypesOfPlayersIn(list);

    cout << (playersCount.at(villagerIndex)) << endl; // EXPECTED 1
    cout << (playersCount.at(policeIndex)) << endl; // EXPECTED 2
    cout << (playersCount.at(mayorIndex)) << endl; // EXPECTED 1

}