#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Planet{

private:
	string name;
	long population;
	bool isHabitable;
	double diameter;
	bool hasWater;
	string closestPlanet;
	string galaxy;

	/*
	Area of the Planet
	Furmula: area = 4 * pi * r^2
	*/
	double calculateArea(){
		return (2.0 * acos(0.0)) * 4 * pow((getDiameter()/2), 2);
	}

public:

	//Constructor
	Planet(string name, long population, bool isHabitable, double diameter, bool hasWater,
	 string closestPlanet, string galaxy){

	    this->name = name;
	    this->population = population;
	    this->isHabitable = isHabitable;
	    this->diameter = diameter;
	    this->hasWater = hasWater;
	    this->closestPlanet = closestPlanet;
	    this->galaxy = galaxy;

	}

	//Copy constructor
	Planet(Planet &p2){
	    this->name = p2.name;
	    this->population = p2.population;
	    this->isHabitable = p2.isHabitable;
		this->diameter = p2.diameter;
		this->closestPlanet = p2.closestPlanet;
	    this->hasWater = p2.hasWater;
	    this->galaxy = p2.galaxy;
	}

	//Default Constructor
	Planet();


	//Getters
	string getName(){return name;}
	long getPopulation(){ return population;}
	bool getIsHabitable(){return isHabitable;}
	double getDiameter(){return diameter;}
	double getArea(){return calculateArea();}
	bool getHasWater(){return hasWater;}
	string getClosestPlanet(){return closestPlanet;}
	string getGalaxy(){return galaxy;}

	//Setters
	void setName(string name){this->name = name;}
	void setPopulation(long population){this->population = population;}
	void setIsHabitable(bool isHabitable){this->isHabitable = isHabitable;}
	void setDiameter(double diameter){this->diameter = diameter;}
	void setHasWater(bool hasWater){this->hasWater = hasWater;}
	void setClosestPlanet(string closestPlanet){this->closestPlanet = closestPlanet;}
	void setGalaxy(string galaxy){this->galaxy = galaxy;}

	
	string toString(){
		return "{Name: " + getName() + "," 
				+ "Population: " + to_string(getPopulation()) + ", "
				+ (getIsHabitable()?"Habitable: True":"Habitable: False") + ", " 
				+ "Diameter: " + to_string(getDiameter()) + ", "
				+ (getHasWater()?"Water: True":"Water: False") + ", "
				+ "Closest Planet: " + getClosestPlanet() + ", "
				+ "Galaxy: " + getGalaxy() + "}";
	}

	//PART #1 EXERCISES
	string compareArea(Planet &p2);
	double volumePlanet();
	bool sameGalaxy(Planet &p2);

};

