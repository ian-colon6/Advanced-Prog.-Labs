#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class RGBColor
{
    private:
    short redLevel;
    short greenLevel;
    short blueLevel;

    public:
    RGBColor(short red, short green, short blue)
    {
        this->redLevel = red;
        this->greenLevel = green;
        this->blueLevel = blue;
    }

    short getRedLevel() { return redLevel; }
    short getGreenLevel() { return greenLevel; }
    short getBlueLevel() { return blueLevel; }
    string toString() { return "RGB(" + to_string(getRedLevel()) + ", " + to_string(getGreenLevel()) + ", " + to_string(getBlueLevel()) + ")"; }

};

class Colorable
{

public:
    virtual RGBColor getColor() = 0;
    virtual void setColor(RGBColor c) = 0;

};

class Component : public Colorable
{
    private:
        string label;
        RGBColor color;
    public:
        
        virtual double getPower() = 0;
        virtual double getCapacity() = 0;

        virtual RGBColor getColor(){return this->color;};
        virtual void setColor(RGBColor c){ this->color = c;};
        
        Component(string label, RGBColor col) : color(col){
            this->label = label;
            this->color = color;
        }
        
        
};

class Speaker : public Component
{
    private:
    string label;
    double volume;
    double dimension;
    RGBColor color;

    public:
    string getLabel() { return label; }
    double getVolume() { return volume; }
    double getDimension() { return dimension; }

    Speaker(string lbl, RGBColor col, double v, double c): Component(lbl, col){

        this->volume = v;
        this->dimension = c;
    }

    // Instance methods

    // TODO EX #1 (Part A) -- Implement getPower() in Speaker class
    virtual double getPower();

    // TODO EX #2 (Part A) -- Implement getCapacity() in Speaker class
    virtual double getCapacity();

};
class Buzzer : public Component
{
    private:
    string label;
    double frequency;
    string metal;

    public:
    string getLabel() { return label; }
    double getFrequency() { return frequency; }
    string getMetal() { return metal; }

    Buzzer(string lbl, double fr, string mt): Component(lbl) {
        this->frequency = fr;
        this->metal = mt;
    }

    // Instance methods

    // TODO EX #1 (Part B) -- Implement getPower() in Buzzer class
    virtual double getPower();

    // TODO EX #2 (Part B) -- Implement getCapacity() in Buzzer class
    virtual double getCapacity();
};

/**
 * EXERCISE #1 (Part A) -- IMPLEMENT getPower() in Speaker class.
 * Hint: Power is volume times dimension.
 */
double Speaker::getPower()
{

    return this->getVolume() * this->getDimension();
}

/**
 * EXERCISE #1 (Part B) -- IMPLEMENT getCapacity() in Speaker class.
 * Hint: Capacity is two times volume divided by dimension.
 */
double Speaker::getCapacity()
{

    return (2 * this->getVolume()) / this->getDimension();
}

/**
 * EXERCISE #2 (Part B) -- IMPLEMENT getPower() method in Buzzer class.
 * If metal is iron its factor is 50.
 * If metal is copper its factor is 200.
 * Every other metal its factor is 10.
 * Hint: Power is frequency times metal factor.
 */
double Buzzer::getPower()
{
    if(this->metal == "iron"){
        return this->getFrequency() * 50;
    }
    else if(this->metal == "copper"){
        return this->getFrequency() * 200;
    }
    else{
        return this->getFrequency() * 10;
    }
}

/**
 * EXERCISE #2 (Part B) -- IMPLEMENT getCapacity() method in Buzzer class.
 * If metal name starts with 'a' its factor is 30.
 * If metal name starts with 'r' its factor is 300.
 * If metal name starts with 'z' its factor is 10.
 * If metal name starts with 'o' its factor is 40.
 * Every other metal its factor is 20.
 * Hint: Capacity is frequency times metal factor divided by two.
 */
double Buzzer::getCapacity()
{
    
    if(this->metal[0] == 'a'){
        return this->getFrequency() * 30;
    }
    else if(this->metal[0] == 'r'){
        return this->getFrequency() * 300;
    }
    else if(this->metal[0] == 'z'){
        return this->getFrequency() * 10;
    }
    else if (this->metal[0] == 'o'){
        return this->getFrequency() * 40;
    }
    else{
        return this->getFrequency() * 20;
    }
}

//Uncomment main function to test in vscode
// int main() {
    
//     Speaker *c1 = new Speaker("C1", 10, 5);
//     Speaker *c2 = new Speaker("C2", 20, 10);

//     Buzzer *r1 = new Buzzer("R1", 1, "iron");
//     Buzzer *r2 = new Buzzer("R2", 2, "copper");

//     // Test Exercise #1
//     cout << "Speaker(\"C1\", 10, 5)) power = " << c1->getPower() << endl;
//     cout << "Speaker(\"C2\", 20, 10) power = " << c2->getPower() << endl;
//     cout << "Buzzer(\"R1\", 1, iron) power = " << r1->getPower() << endl;
//     cout << "Buzzer(\"R2\", 2, copper) power = " << r2->getPower() << endl;

//     // Test Exercise #2
//     cout << "Speaker(\"C1\", 10, 5) capacity = " << c1->getCapacity() << endl;
//     cout << "Speaker(\"C2\", 20, 10) capacity = " << c2->getCapacity() << endl;
//     cout << "Buzzer(\"R1\", 1, iron) capacity = " << r1->getCapacity() << endl;
//     cout << "Buzzer(\"R2\", 2, copper) capacity = " << r2->getCapacity() << endl;

// }