#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal;
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

/** EXERCISE #3 -- DEFINE A NEW Flying Abstract Class
 * 
 * An interface that represents a potentially flying object.
 * It should contain one pure virtual method named canFly() 
 * that returns true if the target object can fly.
 * 
 */
class Flying
{
public:
    /**
	 *  Add canFly() pure virtual method
	 */
    // ADD YOUR CODE HERE
    public:
        virtual bool canFly() = 0;

};

/**
 * 
 * EXERCISE #4 (Part A) -- IMPLEMENT NEW Flying interface in Insect class.
 *  Insects can fly if they have either Foldable or Unfoldable wings.
 *  
 */

class Insect : public Flying
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

    // Exercise 4A: Add canFly method declaration
    bool canFly();

    Insect(string commonName, Type type, Feed feed, float maxWeight, WingType wingType)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->wingType = wingType;
    }

}; // End of Insect class

// Exercise 4A: Add canFly method definition to Insect class
bool Insect::canFly()
{
    // ADD YOUR CODE HERE
    return (wingType == Foldable || wingType == Unfoldable) ? true : false;

}

/**
 * EXERCISE #4 (Part B) -- IMPLEMENT NEW Flying interface in the Cat class.
 *
 * No Cats can fly.
 * 
 */
class Cat : public Flying
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

    // Ex 4B: Add canFly() method declaration
    bool canFly();

    Cat(string commonName, Type type, Feed feed, float maxWeight, Subtype subtype)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->subtype = subtype;
    }

}; // End of Cat class

// Exercise 4B: Add canFly method definition to Cat class
bool Cat::canFly()
{
    return false;

}