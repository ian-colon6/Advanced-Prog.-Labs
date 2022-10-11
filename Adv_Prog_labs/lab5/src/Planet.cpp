#include "Planet.h"

/* EXERCISE #1
Finish the declaration of the default constructor

When a Planet is initially created it has the following default values:
Name: KNOWHERE
Population: 0
It is NOT habitable
Diameter: 8975
Closet Planet: XANDAR
It DOES HAVE water
Galaxy: GUARDIANS
*/
Planet::Planet() {
	this->name = "KNOWHERE";
	this->population = 0;
	this->isHabitable = false;
	this->diameter = 8975.0;
	this->hasWater = true;
	this->closestPlanet = "XANDAR";
	this->galaxy = "GUARDIANS";
}

/*
EXERCISE #2
Return the name of biggest planet (between the target and parameter) based on area
*/
string Planet::compareArea(Planet& p2){
	double planet1 = this->getDiameter();
	double planet2 = p2.getDiameter();

	if(planet1 > planet2){
		return this->getName();
	}else{
		return p2.getName();
	}
}

/*
EXERCISE #3
Return the volume of the target planet
Formula: (4*pi*r^3)/3
*/
double Planet::volumePlanet(){
	double volume = (2.0 * acos(0.0)) * 4 * pow((getDiameter()/2), 3) / 3; 
	return volume;
}

/*
EXERCISE #4
Return true if the target planet and the parameter planet are in the same galaxy
False otherwise.
HINT: use the compare method of string
*/
bool Planet::sameGalaxy(Planet &p2){
	
	return (this->getGalaxy() == p2.getGalaxy());
	
}