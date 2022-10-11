 
/*
 * Tool is a class that represents a tool or equipment 
 * that a hardware store rents.  Each Tool object includes
 * the product's description, type, price, size, weight,
 * the rental status and the name of the customer who is 
 * renting or rented it last.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum ToolType
{
	POWER,
	HAND,
	GENERATOR,
	YARD,
	PUMP,
	HEAVY,
	PAINT,
	MISC
};

class Tool
{

private:
	string description;
	ToolType type;
	double price;
	double size;
	double weight;
	bool rented;
	string customer;

public:
	Tool(){};

	Tool(string description, ToolType type, double price,
		 double size, double weight, bool rented, string customer)
	{
		this->description = description;
		this->type = type;
		this->price = price;
		this->size = size;
		this->weight = weight;
		this->rented = rented;
		this->customer = customer;
	}

	string getDescription() { return description; }
	ToolType getType() { return type; }
	double getPrice() { return price; }
	double getSize() { return size; }
	double getWeight() { return weight; }
	bool isRented() { return rented; }
	string getCustomer() { return customer; }

	void setDescription(string description) { this->description = description; }
	void setType(ToolType type) { this->type = type; }
	void setPrice(double price) { this->price = price; }
	void setSize(double size) { this->size = size; }
	void setWeight(double weight) { this->weight = weight; }
	void setRented(bool rented) { this->rented = rented; }
	void setCustomer(string customer) { this->customer = customer; }

	// Returns true (1) if all the properties of target and the other Tool are equal
	bool equals(Tool otherTool)
	{
		return this->getDescription() == otherTool.getDescription() &&
			   this->getType() == otherTool.getType() &&
			   this->getPrice() == otherTool.getPrice() &&
			   this->getSize() == otherTool.getSize() &&
			   this->getWeight() == otherTool.getWeight() &&
			   this->isRented() == otherTool.isRented() &&
			   this->getCustomer() == otherTool.getCustomer();
	}

	// Return true (1) if both vectors are equal, uses above equals method
	static bool compareVectors(vector<Tool> v1, vector<Tool> v2)
	{
		if (v1.size() != v2.size())
			return false;

		for (int i = 0; i < v1.size(); i++)
		{
			if (!v1[i].equals(v2[i]))
				return false;
		}

		return true;
	}

	static double percentRented(Tool store[], int size);
	static double priceRange(vector<Tool> &store);
	static void updateToolRentalPrice(vector<Tool> &store, ToolType type, double delta);
	static vector<Tool> filterByType(vector<Tool> &store, ToolType type);
	static string multiRental(Tool store[], int size);
};

/**
* EXERCISE #1 -- PERCENT RENTED
* Returns the percent of all tools that are rented out 
* at a particular store (array parameter).
*/
double Tool::percentRented(Tool store[], int size)
{
    double percent = 0;
	for(int i = 0; i < size; i++){
        if(store[i].isRented()){
            percent++;
        }
    }
    double result = (percent/size)*100;

	return result;; // dummy return
}

/**
 * EXERCISE #2 -- SEARCH MIN/MAX (USING VECTORS)
 * Return the range of rental prices at the particular store, 
 * the range is the difference between the lowest and highest values.
 * If the Vector is empty return -1.
 */
double Tool::priceRange(vector<Tool> &store)
{
    if(store.size() == 0){
        return -1;
    }
    double highest = 0;
    double smallest = 10000000; 
	for(Tool t : store){
        if(t.getPrice() > highest){
            highest = t.getPrice();
        }
        if (t.getPrice() < smallest){
            smallest = t.getPrice();
        }
        
    }

	return highest-smallest; // dummy return
}

/**
* EXERCISE #3 -- SEARCH & UPDATE VECTOR
* Update the rental price of the tools at a given store,
* identify tools which are of a particular type and change 
* the price to be the current price plus the given price delta.
*/
void Tool::updateToolRentalPrice(vector<Tool> &store, ToolType type, double delta)
{
	for(int i = 0; i < store.size(); i++){
	    if(store[i].getType() == type){
	        store[i].setPrice(store[i].getPrice() + delta);
	    }
        
    }
}

/**
* EXERCISE #4 -- RETURN NEW VECTOR
* Given a vector of Tools objects, return a new Vector
* containing only Tools that are of the parameter type.
* If the store vector is empty return the vector unchanged.
* 
* Study the tests!
*/
vector<Tool> Tool::filterByType(vector<Tool> &store, ToolType type)
{
    vector<Tool> toolbox;
    for(Tool objeto : store){
        if(objeto.getType() == type){
            toolbox.push_back(objeto);
        }
    }
	return toolbox; // dummy return
}


/**
* EXERCISE #5 -- FIND DUPLICATES (ARRAY)
* 
* Find customer who has more than one tool rented at a given store.
* The parameter store is an array of rented tools, the size is specified. 
* Stop as soon as you find the fist customer with more than one rental.
* Assume the renter's names are unique (similar to an id number).
* Return the name of the customer or return the following string:
*  "No customers with multi-rentals"
* 
*  HINT: USE A COPY OF THE ABOVE STRING
*  HINT: CONSIDER THE USE OF NESTED LOOPS
*  HINT: THE TOOLS INSTANCES MAY CHANGE FOR EACH TEST CASE
* 
* 
*/
string Tool::multiRental(Tool store[], int size)
{
	for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(store[i].getCustomer() == store[j].getCustomer() && i != j){
                return store[i].getCustomer();
            }
            else
            {
                return "No customers with multi-rentals";
            }
            
        }
    }
}

int main()
{
	// Tool Types {POWER, HAND, GENERATOR, YARD, PUMP, HEAVY, PAINT, MISC};
	// Tool id(description, type, price, size, weight, rented, customer);
	Tool bb("Hydraulic Hammer Drill", HEAVY, 15.25, 450, 125.0, true, "Bravo");
	Tool cc("M18 Hammer Drill", HAND, 5.25, 75, 5.3, false, "Charlie");
	Tool ii("Honda 2000", GENERATOR, 7.25, 225, 20.5, true, "India");
	Tool jj("HW Trimmer", YARD, 19.95, 375, 75, false, "Juliet");
	Tool ll("Mini-Excavator", HEAVY, 105.75, 1200, 1075, true, "Lima");
	Tool mm("Stump Grinder", HEAVY, 99.25, 2100, 1359, false, "Mike");
	Tool oo("Leaf Blower", YARD, 4.25, 125, 10, true, "Oscar");
	Tool rr("Ladder 50FT", MISC, 7.50, 325, 45, false, "Romeo");
	Tool tt("Spray Gun Pro", PAINT, 55.55, 295, 5, true, "Tango");
	Tool vv("Concrete Mixer", HEAVY, 115.00, 1100, 125, false, "Victor");
	Tool zz("Shallow 1.5HP", PUMP, 25.00, 205, 30, true, "Zulu");
	Tool ch1("Stump Grinder", HEAVY, 99.25, 2100, 1359, true, "Charlie");
	Tool ch2("HW Trimmer", YARD, 19.95, 375, 75, true, "Charlie");

	Tool store1[] = {bb, cc, ii, jj, ll, mm, oo, rr, tt, vv, zz};
	Tool store2[] = {bb, ii, ll, mm, oo, rr, tt, zz};
	Tool store3[] = {bb, cc, ii, ll, rr, tt, vv, zz};
	Tool store4[] = {bb, cc, ch1, ii, jj, ll, mm, oo, rr, tt, vv, ch2, zz};

	vector<Tool> storeX{bb, cc, ii, jj, ll, mm, oo, rr, tt, vv, zz};
	vector<Tool> storeY{};
	vector<Tool> storeZ{bb, cc, ch1, ii, jj, ll, mm, oo, rr, tt, vv, ch2, zz};
	vector<Tool> storeA{bb, ii, ll, mm, oo, rr, tt, zz};
	vector<Tool> storeB{bb, cc, ii, ll, rr, tt, vv, zz};
	vector<Tool> yard{jj, oo};
	vector<Tool> heavy{bb, ll, mm, vv};
	vector<Tool> empty{};

	// SAMPLE TEST CASES -- MAY BE DIFFERENT FROM THOSE IN THE EXAM

	// EX#1
	cout << "Ex 1 *************************************" << endl;
	cout << Tool::percentRented(store1, 11) << endl;
	cout << Tool::percentRented(store2, 8) << endl;
	cout << Tool::percentRented(store3, 8) << endl;


	// EX#2
	cout << "Ex 2 *************************************" << endl;
	cout << Tool::priceRange(storeX) << endl;
	cout << Tool::priceRange(storeY) << endl;
	cout << Tool::priceRange(storeA) << endl;
	cout << Tool::priceRange(storeB) << endl;


	cout << "Ex 4 *************************************" << endl;
	// Beware ... Done first beacuse EX#3 changes the vectors ******
	cout << Tool::compareVectors(Tool::filterByType(storeX, HEAVY), heavy) << endl;
	cout << Tool::compareVectors(Tool::filterByType(storeX, HEAVY), empty) << endl;
	cout << Tool::compareVectors(Tool::filterByType(storeX, YARD), yard) << endl;
	cout << Tool::compareVectors(Tool::filterByType(storeX, YARD), empty) << endl;
	
	
	// EX#3
	cout << "Ex 3 *************************************" << endl;
	cout << "Original Price" << endl;
	cout << storeX[0].getPrice() << endl;
	cout << storeX[1].getPrice() << endl;
	cout << storeX[9].getPrice() << endl;
	cout << storeX[10].getPrice() << endl;

	cout << "Updated Price" << endl;
	Tool::updateToolRentalPrice(storeX, HEAVY, -5.00);
	cout << storeX[0].getPrice() << endl;
	cout << storeX[1].getPrice() << endl;
	cout << storeX[9].getPrice() << endl;
	cout << storeX[10].getPrice() << endl;

	cout << "Updated Price" << endl;
	Tool::updateToolRentalPrice(storeX, HEAVY, 7.00);
	cout << storeX[0].getPrice() << endl;
	cout << storeX[1].getPrice() << endl;
	cout << storeX[9].getPrice() << endl;
	cout << storeX[10].getPrice() << endl;


	cout << "Ex 5 *************************************" << endl;
	cout << Tool::multiRental(store1, 11) << endl;
	cout << Tool::multiRental(store4, 13) << endl;

	return 0;
}
