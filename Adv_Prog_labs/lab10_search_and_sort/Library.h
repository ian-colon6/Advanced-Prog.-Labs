  #include <iostream>
#include <vector>
#include <string>


using namespace std;

class Book {
    private:
        string name;
        string author;
        int yearPublished;
        int numberOfPages;
        int id;

    public:
        Book(int id, string name, string author, int yearPublished, int numberOfPages) {
            this->id = id;
            this->name = name;
            this->author = author;
            this->yearPublished = yearPublished;
            this->numberOfPages = numberOfPages;
        }

        string getName() {
            return name;
        }

        string getAuthor() {
            return author;
        }

        int getYearPublished() {
            return yearPublished;
        }

        int getId() {
            return id;
        }

        int getNumberOfPages() {
            return numberOfPages;
        }

        void toString() {
            cout << "Book [name=" << name << ", author=" << author << ", yearPublished=" << yearPublished << ", numberofPages=" << numberOfPages << ", id="
            << id << "]" << endl;
        }

        /*
         * Compares the target book with b to determine order and returns:
		 * target:  if target > b
		 * equal: if they're equal
		 * book: if target < b
         */
        int compareTo(Book book) {
            return this->getId() - book.getId();
        }

        /*
         * Compares the target book with the parameter obj to determine if they are the same object.
         */
        bool equals(Book obj) {
            return this->getId() == obj.getId() && this->getName().compare(obj.getName()) == 0 && this->getAuthor().compare(obj.getAuthor()) == 0 && this->yearPublished == obj.getYearPublished()
            && this->getNumberOfPages() == obj.getNumberOfPages();
        }
};

class Library {
    private:
        vector<Book> bookshelf;

    public:
        Library(vector<Book> bookshelf) {
            this->bookshelf = bookshelf;
        }

        vector<Book> getBookshelf() {
            return bookshelf;
        }

        /*
        * Helper method to swap the position of two objects in a given array
        *
        * @param bookshelf - vector we're going to work in
        * @param a - index of the first object to swap
        * @param b - index of the second object to swap
        */
        static void swap(vector<Book> &v, int a, int b){
            iter_swap(v.begin() + a, v.begin() + b);
        }

        /*
         * Linear Algorithm to find the index of a given target.
         *
         * @param bookshelf - Array where search takes place
         * @param target - Book to be searched for
         * @return Index of the target book (-1 if not found)
         */
        int interativeLinearSearch(vector<Book> bookshelf, Book target){
            for (int i = 0; i < bookshelf.size(); ++i) {
                if(bookshelf[i].equals(target)) return i; // Book was found
            }
            return -1; // Book was not found
        }

        /*
         * Linear Algorithm to find the index of a given target.
         * Iterates though the whole array having a complexity of O<img class="icon emoticon" alt="No" title="No" src="https://online.upr.edu/theme/image.php/fordson/core/1619200039/s/no" /> in the worst case scenario
         *
         * @param bookshelf - Target array
         * @param target - Target object
         * @return - Index of the target book (-1 if not found)
         */
        int recursiveLinearSearch(vector<Book> bookshelf, Book target) {
            return linearHelper(bookshelf,0, target); // Start at the beginning of the vector, index 0
        }

        /*
         * Linear search helper
         *
         * @param bookshelf -  Vector where the search takes place
         * @param index - Index of the current object we are comparing the target with
         * @param target - Book to be searched for
         * @return Index of what was found (-1 if not found)
         */
        int linearHelper(vector<Book>, int index, Book target) {
            if(index >= bookshelf.size()) return -1; // Book was never found, exiting recursion
            if(target.equals(bookshelf[index])) return index; // Book was found
            return linearHelper(bookshelf, index+1, target); // Increase index to "iterate" through the vector
        }

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
        static int binarySearch(vector<Book> bookshelf, Book target);

        /*
         * Helper method for Binary Search
         */
        static int binarySearchHelper(vector<Book> bookshelf, Book target, int left, int right);

        /*
         * EXERCISE B(20 points):
         * Implement a iterative Bubble Sort for a vector books
         *
         * @param bookshelf - Vector to be sorted
         * @return A sorted copy fo the bookshelf array
         */
        static vector<Book> bubbleSort(vector<Book> bookshelf);

        /*
         * EXERCISE C(20 points):
         * Implement a recursive Insertion Sort for the vector of books using a helper method
         * HINT: USE A HELPER METHOD
         * @param bookshelf - Vector to be sorted
         * @return A sorted copy of the bookshelf vector
         */
        static vector<Book> insertionSort(vector<Book> bookshelf);
        static vector<Book> insertionSortHelper(vector<Book> bookshelf, int i);

        vector<Book> selectionSort(vector<Book> bookshelf) {
            vector<Book> unsortedBookshelf = this->bookshelf;
            return selectionSortHelper(unsortedBookshelf, 0);
        }

        vector<Book> selectionSortHelper(vector<Book> bookshelf, int tailIndex) {
            /*
             * Find the minimun element in the unsorted sub-array [tailIndex.. length -1 ]
             * and swap it with vector[tailIndex]
             */
            int min = tailIndex;
            for(int i = tailIndex + 1; i < bookshelf.size(); i++) {
                if(bookshelf[i].compareTo(bookshelf[min]) < 0) { // If arr[i] element is less, then it is the new minim
                    min = i; // Update index of min element
                }
            }

            // Swap the minimum element in sub-array[tailIndex..length-1] with arr[tailIndex]
            swap(bookshelf, min, tailIndex);
            if(tailIndex + 1 < bookshelf.size() - 1) return selectionSortHelper(bookshelf,tailIndex + 1);
            else return bookshelf;
        }
};