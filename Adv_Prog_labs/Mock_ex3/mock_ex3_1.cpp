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

class Animal
{

/** EXERCISE #1 -- Complete ABSTRACT Animal CLASS
 *
 * Re-factor Insect and Cat classes.
 * An abstract class that holds the properties and implements the methods that are
 * common to existing Insect and Cat classes. All the moved properties must remain 
 * PRIVATE and the moved methods PUBLIC. A common method that behaves differently 
 * in each of the subclasses should be an abstract method in this abstract class and 
 * then overridden in the subclasses.
 * 
 * The abstract class should supply an appropriate constructor to be used by 
 * subclass constructors to initialize the private properties defined in the abstract class.
 * 
 */
 
 private:
    string commonName;
    Type type;
    Feed feed;
    float maxWeight;

public:
    virtual string getCommonName() = 0;
    virtual Type getType() = 0;
    virtual Feed getFeed() = 0;
    virtual float getMaxWeight() = 0;

    virtual void setCommonName(string commonName) { this->commonName = commonName; }
    virtual void setType(Type type) { this->type = type; }
    virtual void setFeed(Feed feed) { this->feed = feed; }
    virtual void setMaxWeight(float weight) { this->maxWeight = weight; }

    Animal(string Name, Type species, Feed diet, float weight){

        this->commonName = Name;
        this->type = species;
        this->feed = diet;
        this->maxWeight = weight;
    }

}; // End of abstract Animal class

/**
 * Exercise #2 (Part A)
 * Re-factor the Insect class to remove any property or method that was 
 * moved to the Abstract Animal class.  You should modify the
 * constructor to call the super constructor appropriately.
 * 
 * This class represents Insects
 */
class Insect : public Animal
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

    Insect(string commonName, Type type, Feed feed, float maxWeight, WingType wingType) : Animal(commonName, type, feed, maxWeight)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->wingType = wingType;
    }

}; // End of Insect class

/**
 * Exercise #2 (Part B)
 * Re-factor the Cat class to remove any property or method that was 
 * moved to the Abstract Animal class.  You should modify the
 * constructor to call the super constructor appropriately.
 * 
 * This class represents an Cat animal species
 * 
 */
class Cat : public Animal
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

    Cat(string commonName, Type type, Feed feed, float maxWeight, Subtype subtype) : Animal(commonName, type, feed, maxWeight)
    {
        this->commonName = commonName;
        this->type = type;
        this->feed = feed;
        this->maxWeight = maxWeight;
        this->subtype = subtype;
    }

}; // End of Cat class