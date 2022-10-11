#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string model;
    int year;
    string brand;
    double price;
public:
    Car(string model, int year, string brand, double price) {
        this->model = model;
        this->year = year;
        this->brand = brand;
        this->price = price;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    string getBrand() {
        return brand;
    }

    double getPrice() {
        return price;
    }

    void toString() {
        cout << "Car [model=" << model << ", year=" << year << ", brand=" << brand << ", price=" << price << endl;
    }

    bool equals(Car obj) {
        return this->getModel().compare(obj.getModel()) && this->getBrand().compare(obj.getBrand()) &&
               this->getYear() == obj.getYear() && this->getPrice() == obj.getPrice();
    }
};

/*
 * BONUS PROBLEM (10PTS): Finish the merge algorithm for the Merge Sort and the comparator for it to work
 *
 * Create a comparator for the class type Car
 */
class CarComparator {
    public:
        int operator()(Car a, Car b);
};

class Dealer {
private:
    vector<Car> stock;

    /*
    * Helper method to swap the position of two objects in a given array
    *
    * @param stock - vector we're going to work in
    * @param a - index of the first object to swap
    * @param b - index of the second object to swap
    */
    void swap(vector<Car>, int a, int b) {
        Car temp = stock[a];
        stock[a] = stock[b];
        stock[b] = temp;
    }
public:
    Dealer(vector<Car> stock) {
        this->stock = stock;
    }

    /*
     * Stock will always be full, no nulls
     */
    vector<Car> getStock() {
        return stock;
    }

    /*

    /*  BONUS PROBLEM (15PTS): Finish the merge algorithm for the Merge Sort and the comparator for it to work
     *  Recursive Merge Sort for an array
     *
     *  @param stock - vector to be sorted
     *  @param comp - comparator object to compare cars
     */
    void mergeSort(CarComparator comp, vector<Car> stock) {
        int n = stock.size();
        if(n < 2) return;
        int mid = n / 2;
        vector<Car> S1;
        vector<Car> S2;
        for(int i = 0; i < mid; i++) {
            S1.push_back(stock[i]);
        }
        for(int i = mid; i < n; i++){
            S2.push_back(stock[i]);
        }
        mergeSort(comp, S1);
        mergeSort(comp, S2);
        merge(comp, S1, S2, stock);
    }

    /*
     *
     * A helper method that distributes the items with a pivot and returns the index of where it stopped
     * @param stock - array to be sorted
	 * @param S1 - left section of to be sorted
	 * @param S2 - right section to be sorted
	 * @param comp - comparator object to compare cars
	 * @return the index of the partition
     */
    void merge(CarComparator comp, vector<Car> S1, vector<Car> S2, vector<Car> stock);
};