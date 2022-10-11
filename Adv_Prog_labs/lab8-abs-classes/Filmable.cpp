#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;


class Actor {
    private:
        string name;
        int costOfContract;
        int fameScore; // This Score goes on a scale from 0 to 5
    
    public:
        Actor(const string& name, int costOfContract, int fameScore) {
            this->name = name;
            this->costOfContract = costOfContract;
            this->fameScore = fameScore;
        }

        string getName() {
            return name;
        }

        int getCostOfContract() {
            return costOfContract;
        }

        int getFameScore() {
            return fameScore;
        }

        void setName(const string& name) {
            this->name = name;
        }

        void setCostOfContract(int costOfContract) {
            this->costOfContract = costOfContract;
        }

        void setFameScore(int fameScore) {
            this->fameScore = fameScore;
        }
};


// Interface class
class Filmable {
    public:
		virtual int getBudget() = 0;
		virtual bool isClassic() = 0;
		virtual bool isSuccessful() = 0;
};


// Base class
class Production {
    private:
		string name;
		vector<Actor> cast;
		int productionCosts;
    
    public:
        Production(const string& name, vector<Actor>& cast, int productionCosts) {
			this->name = name;
			this->cast = cast;
			this->productionCosts = productionCosts;
		}

        string getName() { return name; }
    	vector<Actor> getCast() { return cast; }
        int getProductionCosts() { return productionCosts; }

        void setName(const string& name) { this->name = name; }
		void setCast(vector<Actor>& cast) { this->cast = cast; }
		void setProductionCosts(int productionCosts) { this->productionCosts = productionCosts; }
};


// Add the missing code to inherit from Production and Filmable
class Movie : public Production, public Filmable{
    private:
		int yearsSinceProduced;
		int rating; // This rating goes from 0 to 5

    public:
		Movie(const string& name, vector<Actor>& cast, int productionCosts, int yearsSinceProduced, int rating): Production(name, cast, productionCosts) {
			this->yearsSinceProduced = yearsSinceProduced;
			this->rating = rating;
		}

        int getYearsSinceProduced() { return yearsSinceProduced; }
        int getRating() { return rating; }

		void setYearsSinceProduced(int yearsSinceProduced) { this->yearsSinceProduced = yearsSinceProduced; }
		void setRating(int rating) { this->rating = rating; }

		/*
		 * This method should return the sum of the production cost + the cost
		 * of Contract of each of the actors
		 */
		int getBudget();

		/*
		 * This method should return true if the Movie's year
		 * of production was more than 10 years ago
		 */
		bool isClassic();

		/*
		 * This method should true true if at least ONE of the members of the cast has 
		 * a fameScore of 4 or 5 AND the rating is bigger than 4.
		 */
		bool isSuccessful();
};


// Add the missing code to inherit from Production and Filmable
class Series : public Production, public Filmable{
    private:
		int numberOfSeasons;
    
    public:
		Series(const string& name, vector<Actor>& cast, int productionCosts, int numberOfSeasons): Production(name, cast, productionCosts)  {
			this->numberOfSeasons = numberOfSeasons;
		}

        int getNumberOfSeasons() { return numberOfSeasons; }
		void setNumberOfSeasons(int numberOfSeasons) { this->numberOfSeasons = numberOfSeasons; }

		/*
            This method should return:
             the production costs of the series + (the cost of Contract of each actor in the cast x the number of seasons)
		 */
		int getBudget();

		/*
            This method should return true if the Series
            has more than 5 seasons and false otherwise
		 */
		bool isClassic();

		/*
            This method should return true if at least ONE of the members of the cast
            has a fameScore of 4 or 5 AND the Series has more than 2 seasons
		 */
		bool isSuccessful();
};


/*
* This method should return the sum of the production cost + the cost
* of Contract of each of the actors
*/
int Movie::getBudget() {

    int product_cost, actor_cost = 0;
    product_cost = getProductionCosts();
    for(Actor c : getCast()){
        actor_cost += c.getCostOfContract();
    }
    return actor_cost + product_cost;
}


/*
* This method should return true if the Movie's year
* of production was more than 10 years ago
*/
bool Movie::isClassic(){

    return (getYearsSinceProduced() > 10);
}


/*
* This method should return true if at least ONE of the members of the cast has 
* a fameScore of 4 or 5 AND the rating is bigger than 4.
*/
bool Movie::isSuccessful(){

    for(Actor famous : this->getCast()){

        int fame = famous.getFameScore();
        int rating = this->getRating();

        if((fame == 4 || fame == 5) && (rating > 4)){
            return true;
        }

    }
    return false;
}


/*
This method should return:
the production costs of the series + (the cost of Contract of each actor in the cast x the number of seasons)
*/
int Series::getBudget(){

    int series_cost, contract, num_of_seasons = 0;

    series_cost = this->getProductionCosts();
    
    for(Actor s_cast : this->getCast()){
        contract = s_cast.getCostOfContract();
        num_of_seasons = this->getNumberOfSeasons();

        series_cost += (contract * num_of_seasons);
    }
    return series_cost;
}


/*
This method should return true if the Series
has more than 5 seasons and false otherwise
*/
bool Series::isClassic(){
    return (this->getNumberOfSeasons() > 5);
}


/*
This method should return true if at least ONE of the members of the cast
has a fameScore of 4 or 5 AND the Series has more than 2 seasons
*/
bool Series::isSuccessful(){

    for(Actor s_famous : this->getCast()){

        int fame = s_famous.getFameScore();
        int seasons = this->getNumberOfSeasons();

        if((fame == 4 || fame == 5) && (seasons > 2)){
            return true;
        }

    }   
    return false;
}


/*--------------------------------------------------------------------------------------------------------------------------------												
                                                        TESTING AREA
----------------------------------------------------------------------------------------------------------------------------------*/

Actor actor1("Brad Pitt", 80000000, 2);
Actor actor2("Jason Bateman", 30000000, 3);
Actor actor3("Jason Statham", 3000000, 2);
Actor actor4("Andrew Garfield", 40000, 4);
Actor actor5("Viola Davis", 450000, 5);
Actor actor6("Benedict Cumberbatch", 10000, 2);
Actor actor7("Mark Sinclair", 150000, 1);
Actor actor8("Scarlett Johanson", 31200000, 2);
Actor actor9("Hayden Christensen", 53000000, 3);
Actor actor10("Christina Wolf", 3200000, 5);

vector<Actor> cast1{actor1, actor3, actor5, actor7};
vector<Actor> cast2{actor2, actor4, actor6, actor8};
vector<Actor> cast3{actor9, actor10, actor5, actor6};
vector<Actor> cast4{actor1, actor2, actor7, actor8};

Movie movie1("{Insert Generic Movie Name Here}", cast1, 124000000, 3, 5);
Movie movie2("C++ Reloaded", cast2, 365000, 2, 3);
Movie movie3("Rise of the Shapes", cast3, 34000, 12,5);
Movie movie4("Interfaces", cast4, 123000000, 18, 1);

Actor actor11("Will Smith", 35000000, 4);
Actor actor12("The Rock", 10000000, 3);
Actor actor13("Adam Sandler", 1000000, 2);
Actor actor14("Kevin James", 100000, 1);
Actor actor15("Angelina Jolie", 45000000, 5);
Actor actor16("SVictoria Eyenoke", 1000000, 2);
Actor actor17("Zack Efron", 15000000, 3);
Actor actor18("Johnny Depp", 3000000, 2);
Actor actor19("Meryl Streep", 5000000, 3);
Actor actor20("Mark Hamill", 300000, 1);

vector<Actor> cast5{actor11, actor13, actor15, actor17};
vector<Actor> cast6{actor12, actor14, actor16, actor18};
vector<Actor> cast7{actor19, actor20, actor15, actor16};
vector<Actor> cast8{actor11, actor12, actor17, actor18};

Series series1("The Royals", cast5, 152000000, 3);
Series series2("The 100", cast6, 521000, 2);
Series series3("Your Funeral", cast7, 62000, 6);
Series series4("That's a No", cast8, 105000000, 7);

void movieImplementsInterfaceTest();
void movieGetBudgetTest();
void movieIsClassicTest();
void movieIsSuccesfulTest();

void seriesImplementsInterfaceTest();
void seriesgetBudgetTest();
void seriesIsClassicTest();
void seriesIsSuccesful();


int main() {
    movieImplementsInterfaceTest();
    movieGetBudgetTest(); 
    movieIsClassicTest();
    movieIsSuccesfulTest();

    seriesImplementsInterfaceTest();
    seriesgetBudgetTest();
    seriesIsClassicTest();
    seriesIsSuccesful();

    cout << "\nSUCCESS: ALL TEST PASSED!";
    return 0;
}


void movieImplementsInterfaceTest() {
    cout << "Beginning movieImplementsInterfaceTest" << endl;
    Filmable* f1 = dynamic_cast<Filmable*>(&movie1);
    Filmable* f2 = dynamic_cast<Filmable*>(&movie2);
    assert(f1 != NULL);
    assert(f2 != NULL);
    cout << "PASSED movieImplementsInterfaceTest" << endl;
}


void movieGetBudgetTest() {
    cout << "Beginning movieGetBudgetTest" << endl;
    assert(207600000 == movie1.getBudget());
    assert(61615000 == movie2.getBudget());
    assert(56694000 == movie3.getBudget());
    assert(264350000 == movie4.getBudget());
    cout << "PASSED movieGetBudgetTest" << endl;
}


void movieIsClassicTest() {
    cout << "Beginning movieIsClassicTest" << endl;
    assert(movie1.isClassic() == false);
    assert(movie2.isClassic() == false);
    assert(movie3.isClassic() == true);
    assert(movie4.isClassic() == true);
    cout << "PASSED movieIsClassicTest" << endl;
}

void movieIsSuccesfulTest() {
    cout << "Beginning movieIsSuccesfulTest" << endl;
    assert(movie1.isSuccessful() == true);
    assert(movie2.isSuccessful() == false);
    assert(movie3.isSuccessful() == true);
    assert(movie4.isSuccessful() == false);
    cout << "PASSED movieIsSuccesfulTest" << endl;
}

void seriesImplementsInterfaceTest() {
    cout << "Beginning seriesImplementsInterfaceTest" << endl;
    Filmable* f1 = dynamic_cast<Filmable*>(&series1);
    Filmable* f2 = dynamic_cast<Filmable*>(&series2);
    assert(f1 != NULL);
    assert(f2 != NULL);
    cout << "PASSED seriesImplementsInterfaceTest" << endl;
}

void seriesgetBudgetTest() {
    cout << "Beginning seriesgetBudgetTest" << endl;
    assert(440000000 == series1.getBudget());
    assert(28721000 == series2.getBudget());
    assert(307862000 == series3.getBudget());
    assert(546000000 == series4.getBudget());
    cout << "PASSED seriesgetBudgetTest" << endl;
}

void seriesIsClassicTest() {
    cout << "Beginning seriesIsClassicTest" << endl;
    assert(series1.isClassic() == false);
    assert(series2.isClassic() == false);
    assert(series3.isClassic() == true);
    assert(series4.isClassic() == true);
    cout << "PASSED seriesIsClassicTest" << endl;
}

void seriesIsSuccesful() {
    cout << "Beginning seriesIsSuccesful" << endl;
    assert(series1.isSuccessful() == true);
    assert(series2.isSuccessful() == false);
    assert(series3.isSuccessful() == true);
    assert(series4.isSuccessful() == true);
    cout << "PASSED seriesIsSuccesful" << endl;
}
