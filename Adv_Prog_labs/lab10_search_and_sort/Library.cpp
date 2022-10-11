 #include <iostream>
#include <vector>
#include "Library.h"

using namespace std;

/*
* EXERCISE A(20 pts):
* Binary Algorithm to find the index of a given target. Requires array to be sorted.
* Divides the array in half and only checks for the half containing the value while discarding the rest.
* The value is either the middle of the sub-array or in one of the two halves.
*
* By diving the vector in half each iteration, the complexity is at the most O(log<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1619200039/s/no" />)
* which beats the linear search at O<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1619200039/s/no" />
*
* @param bookshelf = Target vector
* @param target - Target Element
* @return - Index of Target Element (-1 if not found)
*/
int Library::binarySearch(vector<Book> bookshelf, Book target) {
    if( bookshelf.empty() || !target.equals(bookshelf[bookshelf.size()-1] )) {return -1;}
    return binarySearchHelper(bookshelf, target, 0, bookshelf.size() - 1); // TEMP RETURN
}

/*
 * Helper method for Binary Search
*/
int Library::binarySearchHelper(vector<Book> bookshelf, Book target, int left, int right) {
    // ADD YOUR CODE
    int mid = (left + right)/2;
    
    if( target.equals(bookshelf[mid]) ) { return mid;}

    else if(target.getId() > bookshelf[mid].getId()){

        return binarySearchHelper(bookshelf, target, mid +1, right);
    }
    
    else if( target.getId() < bookshelf[mid].getId() ) {return -1;}
    
    return binarySearchHelper(bookshelf, target, left, mid-1);
    
    
}
/*
 * EXERCISE B(20 points):
 * Implement a iterative Bubble Sort for a vector books
 *
 * @param bookshelf - Vector to be sorted
 * @return A sorted copy fo the bookshelf array
 */
vector<Book> Library::bubbleSort(vector<Book> bookshelf) {
    vector<Book> unsortedBookshelf = bookshelf;
    bool swap = true;
    // ADD YOUR CODE
    for(int i = 0; i < bookshelf.size(); i++){

        for(int j = 0; j < bookshelf.size() - i - 1; j++){
            
            if( bookshelf[j].getId() > bookshelf[j +1].getId()){

                Library::swap(bookshelf, j, j+1);
            }
        }
    }
    return bookshelf;
}

/*
 * EXERCISE C(20 points):
 * Implement a recursive Insertion Sort for the vector of books using a helper method
 * HINT: USE A HELPER METHOD
 * @param bookshelf - Vector to be sorted
 * @return A sorted copy of the bookshelf vector
 */
vector<Book> Library::insertionSort(vector<Book> bookshelf) {
    return insertionSortHelper(bookshelf, 1);
}

vector<Book> Library::insertionSortHelper(vector<Book> bookshelf, int insertIndex) {
    // ADD YOUR CODE
    if( bookshelf[insertIndex].getId() > bookshelf[insertIndex + 1].getId() ){
        
        Library::swap(bookshelf, insertIndex, insertIndex + 1);
    }
    
    if(insertIndex >= bookshelf.size()){
        return bookshelf;
    }

    return insertionSortHelper(bookshelf, insertIndex + 1);
}

int main() {
    vector<Book> emptyShelf = {};

    vector<Book> bookshelf = {Book(0, "Somebody once told me", "Shrek", 2001, 1000),
                              Book(14, "Hey, now, you're an all-star, get your game on, go play", "Sadly no Bee Movie reference", 2001, 1000),
                              Book(1, "the world is gonna roll me", "Donkey", 2001, 1000),
                              Book(3, "She was looking kind of dumb", "Puss in boots", 2001, 1000),
                              Book(4, "with her finger and her thumb", "Dragon", 2001, 1000),
                              Book(10, "So much to do, so much to see", "Princess Charming", 2001, 1000),
                              Book(6, "Well, the years start coming and they don't stop coming", "Pinocchio", 2001, 1000),
                              Book(7, "Fed to the rules and I hit the ground running", "Doris", 2001, 1000),
                              Book(17, "And all that glitters is gold", "Cookie", 2001, 1000),
                              Book(8, "Didn't make sense not to live for fun", "Lord Farquaad", 2001, 1000),
                              Book(9, "Your brain gets smart but your head gets dumb", "Fairy Godmother", 2001, 1000),
                              Book(11, "So what's wrong with taking the back streets?", "Captain Hook", 2001, 1000)};

    vector<Book> bookshelf2 = Library::bubbleSort(bookshelf);
    for(int i = 1; i < bookshelf.size(); i++) {
        if (bookshelf2[i - 1].compareTo(bookshelf2[i]) < 0) {
            cout << bookshelf2[i-1].getId() << endl;
        }
    }

    cout << "Insertion: "<< endl;
    vector<Book> bookshelf3 = Library::insertionSort(bookshelf);
    for(int i = 1; i < bookshelf.size(); i++) {
        if(bookshelf3[i-1].compareTo(bookshelf3[i]) < 0) {
            cout << bookshelf3[i-1].getId() << endl;
        }
    }

    // After sorting we can do binarySearch 
    cout << "Binary" << endl;
    cout << Library::binarySearch(emptyShelf, Book(0, "Somebody once told me", "Shrek", 2001, 1000)) << endl;
    cout << Library::binarySearch(bookshelf2, Book(10, "So much to do, so much to see", "Princess Charming", 2001, 1000)) << endl;
}