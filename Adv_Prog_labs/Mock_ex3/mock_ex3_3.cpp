#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Insect;
class Cat;

enum Type
{
    WATER,
    REPTILE,
    BIRD,
    LAND,
    INSECT
};

enum Feed
{
    CARNIVORE,
    HERBIVORE,
    OMNIVORE
};

/**
 * Comparable abstract class
 * Include single pure virtual equals method returning
 * true if and only if both the target and parameter
 * objects are equal.  In order for two object to be
 * equal they MUST be instances of the same class.  In
 * addition one or more of their properties should be 
 * equal
 */
class Comparable {
    public:
    virtual bool equals(Comparable* c) = 0;

};

class Insect: public Comparable
{

public:
    enum WingType
    {
        None,
        Foldable,
        Unfoldable
    };

private:
    string commonName;
    Type type;
    Feed feed;
    float maxWeight;
    WingType wingType;

public:
    string getCommonName() { return commonName; }
    Type getType() { return type; }
    Feed getFeed() { return feed; }
    float getMaxWeight() { return maxWeight; }
    WingType getWingType() { return this->wingType; }

    void setCommonName(string commonName) { this->commonName = commonName; }
    void setType(Type type) { this->type = type; }
    void setFeed(Feed feed) { this->feed = feed; }
    void setMaxWeight(float weight) { this->maxWeight = weight; }
    void setWingType(WingType newWingType) { this->wingType = newWingType; }

    // Ex 5A: Add equals method declaration
    bool equals(Comparable* c2);

    Insect(string commonName, Type type, Feed feed, float maxWeight, WingType wingType)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->wingType = wingType;
    }

}; // End of Insect class

// Exercise 5 (Part A): Complete the definition of the equals method for the Insect class
// Two insects are considered equal if they are both insects and have the same common name.
// HINT: Consider using the compare method from the string class bool Insect::equals(Comparable* c2) 
bool Insect::equals(Comparable* c2) 
{
    if(dynamic_cast<Insect*>(c2) != nullptr){

        if(dynamic_cast<Insect*>(this)->getCommonName() == dynamic_cast<Insect*>(c2)->getCommonName()){

            return true;
        }
    }
    return false;
}

class Cat: public Comparable
{
public:
    enum Subtype
    {
        Domestic,
        Running,
        Roaring,
        Other
    };

private:
    string commonName;
    Type type;
    Feed feed;
    float maxWeight;
    Cat::Subtype subtype;

public:
    string getCommonName() { return commonName; }
    Type getType() { return type; }
    Feed getFeed() { return feed; }
    float getMaxWeight() { return maxWeight; }
    Cat::Subtype getSubtype() { return subtype; }

    void setCommonName(string commonName) { this->commonName = commonName; }
    void setType(Type type) { this->type = type; }
    void setFeed(Feed feed) { this->feed = feed; }
    void setMaxWeight(float weight) { this->maxWeight = weight; }
    void setSubtype(Cat::Subtype s) { subtype = s; }

    // Ex 5B: Add equals method declaration
    bool equals(Comparable* c2);

    Cat(string commonName, Type type, Feed feed, float maxWeight, Subtype subtype)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->subtype = subtype;
    }

}; // End of Cat class

// Exercise 5 (Part B): Complete the definition of the equals method for the Cat class
// Two cats are considered equal if they are both cats and have equal common names
// HINT: Consider using the compare method from the string class
bool Cat::equals(Comparable* c2) 
{
    if(dynamic_cast<Cat*>(c2) != nullptr){

        if(dynamic_cast<Cat*>(this)->getCommonName() == dynamic_cast<Cat*>(c2)->getCommonName()){

            return true;
        }
    }
    return false;
}