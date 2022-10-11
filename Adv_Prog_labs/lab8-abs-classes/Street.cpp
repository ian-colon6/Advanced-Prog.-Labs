#include <iostream>
#include <cassert>
#include <string>

using namespace std;



/*
    Create an interface class Nameable with the methods string getName() and int getDistance()
    Make Street inherit from Nameable and implement the methods getDistance() and getName()
*/
class Nameable{
    string name;
    public:
        Nameable(){
            this->name = "El jurutungo";
        }

        Nameable(string name){
            this->name = name;
        }

        virtual string getName() = 0;
};


class Street : public Nameable{
    private:
        string name;
        int distance;
    
    public:
        Street(const string& name, int distance) : Nameable(name) {
            this->name = name;
            this->distance = distance;
        }

        string getName() {return name;};
        int getDistance() {return distance;};
};


/*--------------------------------------------------------------------------------------------------------------------------------												
                                                        TESTING AREA
----------------------------------------------------------------------------------------------------------------------------------*/

Street street1("Rodeo Drive", 3200);
Street street2("Mulholland Drive", 34000);
Street street3("Hollywood Boulevard", 7400);
Street street4("Sunset Boulevard", 35000);
Street street5("Melrose Avenue", 3500);

void testNameableInterface();
void testGetName();
void testGetDistance();


int main() {
    testNameableInterface();
    testGetName();
    testGetDistance();

    cout << "\nSUCCESS: ALL TEST PASSED!";
    return 0;
}


void testNameableInterface() {
    cout << "Beginning movieImplementsInterfaceTest" << endl;
    Nameable* n = dynamic_cast<Nameable*>(&street1);
    assert(n != NULL);
    cout << "PASSED movieImplementsInterfaceTest" << endl;
}


void testGetName() {
    cout << "Beginning testGetName" << endl;
    assert("Rodeo Drive" == street1.getName());
    assert("Mulholland Drive" == street2.getName());
    assert("Hollywood Boulevard" == street3.getName());
    assert("Sunset Boulevard" == street4.getName());
    assert("Melrose Avenue" == street5.getName());
    cout << "PASSED testGetName" << endl;
}


void testGetDistance(){
    cout << "Beginning testGetDistance" << endl;
    assert(3200 == street1.getDistance());
    assert(34000 == street2.getDistance());
    assert(7400 == street3.getDistance());
    assert(35000 == street4.getDistance());
    assert(3500 == street5.getDistance());
    cout << "PASSED testGetDistance" << endl;
}
