#include <iostream>
#include <cmath>
#include <string>  // std::string, std::to_string, std::fixed
#include <iomanip> // std::setprecision

using namespace std;

class Car
{
private:
	float mileage;          // Total cumulative mileage traveled by the Car
	float gasInTank;        // Total gas in gallons held in the Car's tank
	float milesPerGallon;   // Car's gas mileage in miles per gallon (mpg)
	float tripMileage;      // Mileage traveled by Car on its last trip
	float tripGasConsumed;  // Gallons of gas consumed by Car during last trip

public:
	// Constructors
	/** 
	 * Car instance with an initial milesPerGallon (mpg).
	 * The other parameters are explicitly set to 0.0;
	 */
	Car(float mpg) {
		milesPerGallon = mpg;
		mileage = 0.0;
		gasInTank = 0.0;
		tripMileage = 0.0;
		tripGasConsumed = 0.0;
	}

	// Constructor declared
	Car(float mileage, float gasInTank, float milesPerGallon){
        this->tripMileage = 0.0;
        this->tripGasConsumed = 0.0;
        this->mileage = mileage;
        this->gasInTank = gasInTank;
        this->milesPerGallon = milesPerGallon;
    }

	// Getters
	float getMileage() {return mileage;}
	float getGasInTank() {return gasInTank;}
	float getMilesPerGallon() {return milesPerGallon;}
	float getTripMileage() {return tripMileage;}
	float getTripGasConsumed() {return tripGasConsumed;}

	// Setters
	void setMileage(double mileage){this->mileage = mileage;}
	void setGasInTank(double gasInTank){
        this->gasInTank = gasInTank;
    }
	void setMilesPerGallon(double milesPerGallon){
        this->milesPerGallon = milesPerGallon;
    }
	void setTripMileage(double tripMileage){
        this->tripMileage = tripMileage;
    }
	void setTripGasConsumed(double tripGasConsumed) {this->tripGasConsumed = tripGasConsumed;}

	// DO NOT EDIT OR CHANGE THIS METHOD
	void display() // Used to display test case results
	{
		cout << fixed;
		cout << setprecision(2);
		cout << "Mileage: " << this->getMileage();
		cout << " / Gas in tank: " << this->getGasInTank();
		cout << " / MPG: "  << this->getMilesPerGallon();
		cout << " / Trip Mileage: " << this->getTripMileage();
		cout << " / Trip Gas: " << this->getTripGasConsumed() << endl;
	}

	// Instance methods provided
	//Add the given gallons of gas to the target Car
	void pumpGas(float gallons) { gasInTank += gallons;}

	//Resets both the trip mileage and trip gas consumed
	//to 0 to start measuring the next (new) trip.
	void resetTrip() {
		tripMileage = 0;
		tripGasConsumed = 0;
	}

	// Methods declared
	Car mostFilled(Car &c2){
        if(this->getGasInTank() >= c2.getGasInTank()){
            return *this;
        }
        else{
            return c2;
        }
    }
	float fillToDistance(float miles, float gasCost)
        this->gasInTank = miles/milesPerGallon;
        return (this->gasInTank) * gasCost;
    }
	void fillPayment(float moneyPaid, float gasCost){
        this->getGasInTank() + moneyPaid*gasCost
    }
	float sellCar(){
        if(this->getMileage() < 1000){
            return 15000;
        }
        else if(this->getMileage() >= 1000 && this->getMileage() < 5000){
            return 10000;
        }
        else if(this->getMileage() >= 5000){
            return 5000;
        }
    }
};



int main(){
	cout << "HELLO FROM CAR CLASS" << endl;

	cout << "---TEST CASES BELOW---" << endl;
	

	//Example of Test Cases

	//Exercise #1
	Car Car11 = Car(12000, 2.5, 25);
	Car11.display();

	//Expected Result
	cout << "Mileage: 12000.00 / Gas in tank: 2.50 / MPG: 25.00 / Trip Mileage: 0.00 / Trip Gas: 0.00" << endl;
	cout << endl;

	//Exercise #2
	Car Car21 = Car(30);
	Car Car22 = Car(35);
	Car21.mostFilled(Car22).display();
	Car22.mostFilled(Car21).display();

	//Expected Result
	cout << "Mileage: 0.00 / Gas in tank: 5.00 / MPG: 30.00 / Trip Mileage: 0.00 / Trip Gas: 0.00\nMileage: 0.00 / Gas in tank: 5.00 / MPG: 35.00 / Trip Mileage: 0.00 / Trip Gas: 0.00" << endl;
	cout << endl;

	//Exercise #3
	Car Car31 = Car(30);
	cout << Car31.fillToDistance(200,2) << endl;

	//Expected Result
	cout << "13.33" << endl;
	cout << endl;

	//Exercise #4
	Car Car41 = Car(30);
	Car41.fillPayment(5,1.95);
	Car41.display();

	//Expected Result
	cout << "Mileage: 0.00 / Gas in tank: 2.56 / MPG: 30.00 / Trip Mileage: 0.00 / Trip Gas: 0.00" << endl;
	cout << endl;

	//Exercise #5
	Car Car51 = Car(30);
	Car51.setMileage(800);
	cout << Car51.sellCar() << endl;

	//Expected Result
	cout << "15000.00" << endl;

	return 0;
}
	/*********************************************************************
	 * EXERCISE #1
	 * 
	 * Create a constructor that can be used to create a Car object with
	 * a specified mileage, gas (in the tank) and miles-per-gallons (MPG).
	 * Useful if you need to create a "used" Car object with 12,000 miles,
	 * 2.5 gallons of gas in the tank and a rating of 25 MPG as follows:
	 * Car *usedCar = new Car(12000, 2.5, 25)
	 */
	Car::Car(float mileage, float gasInTank, float milesPerGallon) {
		// TODO -- YOUR CODE HERE
	}

	/*********************************************************************
	 * EXERCISE #2
	 * 
	 * Returns the car with the most amount of gas in the tank.
	 * If both cars have the same amount of gas return the target car.
	 */
	Car Car::mostFilled(Car &c2) {
		// TODO -- YOUR CODE HERE
		return 0; // Dummy return
	}

	/*********************************************************************
	 * EXERCISE #3
	 * 
	 * Fill the gas tank of the target car to reach a specific given distance
	 * and return the amount of payment. 
	 * The parameter gasCost is in dollars per gallon.
	 */
	float Car::fillToDistance(float miles, float gasCost){
		// TODO -- YOUR CODE HERE
		return 100; // Dummy return
	}

	/*********************************************************************
	 * EXERCISE #4
	 * 
	 * Fill the gas tank of the target car upto a given amount of money.
	 * The parameter gasCost is in dollars per gallon.
	 */
	void Car::fillPayment(float moneyPaid, float gasCost){
		// TODO -- YOUR CODE HERE
	}

	/*********************************************************************
	 * EXERCISE #5
	 * 
	 * Return the amount of selling price of the target car by mileage.
	 * If the mileage of the car is lower than 1000 miles it would sell at
	 * $15,000. If the mileage of the car is 1000 miles or greater and less
	 * than 5000 miles it would sell at $10,000. If the mileage of the car
	 * is 5000 miles or greater it would sell at $5,000.
	 */
	float Car::sellCar(){
		// TODO -- YOUR CODE HERE
		return 0; //Dummy Return
	}

	/*********************************************************************
	 * EXERCISE #6 BONUS!!
	 * 
	 * Define the setters for tripMileage, gasInTank, and milesPerGallon
	 */
	 // TODO -- YOUR CODE HERE
