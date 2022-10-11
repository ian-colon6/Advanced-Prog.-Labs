#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Customer
{

private:
    long ID;
    string firstName;
    string lastName;
    float purchases;
    int yearsSinceLastPurchase;
    int yearsSinceFirstPurchase;

public:
    // Getters
    long getID() { return ID; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    float getPurchases() { return purchases; }
    int getYearsSinceLastPurchase() { return yearsSinceLastPurchase; }
    int getYearsSinceFirstPurchase() { return yearsSinceFirstPurchase; }

    // Setters
    void setID(long id) { ID = id; }
    void setFirstName(string fn) { firstName = fn; }
    void setLastName(string ln) { lastName = ln; }
    void setPurchases(float s) { purchases = s; }
    void setYearsSinceLastLastPurchase(int y) { yearsSinceLastPurchase = y; }
    void setYearsSinceFirstPurchase(int y) { yearsSinceFirstPurchase = y; }

    // Constructors

    Customer(long id, string fn, string ln, float sal, int yslp, int ysfp)
    {
        ID = id;
        firstName = fn;
        lastName = ln;
        purchases = sal;
        yearsSinceLastPurchase = yslp;
        yearsSinceFirstPurchase = ysfp;
    }

    // DO NOT EDIT OR CHANGE THIS METHOD
    void display() // Used to display tcst case results
    {
        cout << fixed;
        cout << setprecision(2);
        cout << "ID: " << this->getID();
        cout << " / First Name: " << this->getFirstName();
        cout << " / Last Name: " << this->getLastName();
        cout << " / Purchases: " << this->getPurchases();
        cout << " / Years Since Last Purchase: " << this->getYearsSinceLastPurchase();
        cout << " / Years Since First Purchase: " << this->getYearsSinceFirstPurchase() << endl;
    }

    // EXERCISE #1
    // Contructor creates new Customer with defaul initial Purchases of 0
    // and 0 years since last and first purchases
    Customer(long ID, string fn, string ln){
        this->ID = ID;
        this->firstName = fn;
        this->lastName = ln;
        this->purchases = 0.0;
        this->yearsSinceLastPurchase = 0;
        this->yearsSinceFirstPurchase = 0;

    }

    // Instance methods

    // EXERCISE #2
    // Register a new purchase by the target Customer of a fixed amount (parameter) .
    // Round to smallest dollar amount.
    // Reset years since last purchase.
    void purchase(float amount){
        this->purchases += floor(amount);
        this->yearsSinceLastPurchase = 0;
    }

    // EXERCISE #3
    // Returns true if target Customer has reached loyalty level and false otherwise.
    // A loyalty level is reached after purchases of at least 1 thousand dollars
    // and over 5 years since the first purchase.
    bool isLoyal(){
        if(this->purchases >= 1000 && this->yearsSinceFirstPurchase >= 5){
            return true;
        }
        else{
            return false;
        }
    }

    // EXERCISE #4
    // Returns true target Customer should get a coupon before parameter Customer,
    // and false if parameter Customer should get coupon first.
    // Customers with the longest time since last purchase should get a coupon first.
    //
    bool nextForCoupon(Customer e2){
        if(this->getYearsSinceLastPurchase() > e2.getYearsSinceLastPurchase()){
            return true;
        }
        else{
            return false;
        }
    }

    // EXERCISE #5
    // Returns an int > 1 if target Customer's last name goes before target Customer
    // alphabetically decreasing by last name, an int < 1 if parameter Customer should go first,
    // and zero otherwise.
    // HINT: Uses compariosn methods from the string class
    int compareLastNames(Customer e2){
        if(this->getLastName() > e2.getLastName()){
            return 1;
        }
        else if(e2.getLastName() > this->getLastName()){
            return -1;
        }
        else{
            return 0;
        }
    }
    
};

// EXERCISE #1
// Contructor creates new Customer with defaul initial Purchases of 0
// and 0 years since last and first purchases
Customer::Customer(long id, string fn, string ln)
{
	// YOUR CODE
}

// Instance methods

// EXERCISE #2
// Register a new purchase by the target Customer of a fixed amount (parameter) .
// Round to smallest dollar amount.
// Reset years since last purchase.
void Customer::purchase(float amount)
{
	// YOUR CODE
}

// EXERCISE #3
// Returns true if target Customer has reached loyalty level and false otherwise.
// A loyalty level is reached after purchases of at least 1 thousand dollars
// and over 5 years since the first purchase.
bool Customer::isLoyal()
{
	return false;
}

// EXERCISE #4
// Returns true target Customer should get a coupon before parameter Customer,
// and false if parameter Customer should get coupon first.
// Customers with the longest time since last purchase should get a coupon first.
//
bool Customer::nextForCoupon(Customer e2)
{
	return false;
}

// EXERCISE #5
// Returns an int > 1 if target Customer's last name goes before target Customer
// alphabetically decreasing by last name, an int < 1 if parameter Customer should go first,
// and zero otherwise.
// HINT: Uses compariosn methods from the string class
int Customer::compareLastNames(Customer e2)
{
	return 0;
}

int main()
{

    // test cases

    // EXERCISE #1
    Customer tc1(2, "Bienve", "Velez");
    tc1.display();

    // EXERCISE #2
    Customer tc2(1, "Juan", "del Pueblo", 50000, 0, 0);
    tc2.purchase(10000);
    tc2.display();

    // EXERCISE #3
    Customer tc3(2, "Bienve", "Velez");
    cout << (tc3.isLoyal() ? "TRUE" : "FALSE") << endl; // FALSE
    tc3.setPurchases(1000);
    tc3.setYearsSinceFirstPurchase(6);
    cout << (tc3.isLoyal() ? "TRUE" : "FALSE") << endl; // TRUE
    tc3.setPurchases(1000);
    tc3.setYearsSinceFirstPurchase(6);
    cout << (tc3.isLoyal() ? "TRUE" : "FALSE") << endl; // TRUE
    tc3.setPurchases(999);
    tc3.setYearsSinceFirstPurchase(6);
    cout << (tc3.isLoyal() ? "TRUE" : "FALSE") << endl; // FALSE

    // EXERCISE #4
    Customer tc4(1, "Juan", "del Pueblo", 50000, 10, 20);
    Customer tc5(1, "Maria", "del Pueblo", 60000, 15, 15);
    cout << (tc4.nextForCoupon(tc5) ? "TRUE" : "FALSE") << endl; // FALSE
    cout << (tc5.nextForCoupon(tc4) ? "TRUE" : "FALSE") << endl; // TRUE

    // EXERCISE #5
    Customer tc6(1, "Juan", "Rivera", 50000, 10, 20);
    Customer tc7(1, "Maria", "Velez", 60000, 15, 15);
    Customer tc8(1, "Maria", "Velazquez", 60000, 15, 15);

    cout << ((tc6.compareLastNames(tc7) < 0) ? "Passed" : "Failed") << endl;
    cout << ((tc7.compareLastNames(tc6) > 0) ? "Passed" : "Failed") << endl;
    cout << ((tc7.compareLastNames(tc8) > 0) ? "Passed" : "Failed") << endl;
    cout << ((tc8.compareLastNames(tc7) < 0) ? "Passed" : "Failed") << endl;
    cout << ((tc7.compareLastNames(tc7) == 0) ? "Passed" : "Failed") << endl;

}