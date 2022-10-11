#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* Exercise 1:
*  The least common multiple (lcm) of two numbers is the smallest number which can be divided by both numbers.
*  By example: lcm(2,3) = 6. Find the lcm(a,b) using the relation lcm(a,b) = a*b/gcd(a,b)

Hint: Use the Euclidean algorithm: The greatest common denominator of values a and b also divides their difference.
* For any (a, b) we have:
*      if a > b: gcd(a,b) is the same as gcd(b, a%b)
*      Analyze example: For hints on edge cases.
*/
int gcd(int a, int b)
{
    if (a > b)
    {
        return gcd(b, a % b);
    }
    else
    {
        return a;
    }
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

/* Exercise 2:
 * Decimal To Binary: For a given decimal number, calculate it's binary representation.
 * To convert:
 *      When dec == 0 -> 0
 *      Otherwise 10 * [10 * (...) + dec mod 2] + dec mod 2
 */
static int decimalToBinary(int dec)
{
    if (dec == 0)
        return 0;
    else
    {
        return 10 * decimalToBinary(dec--) + dec % 2;
    }
}

/*
 * Exercise 3:
 *
 * Pascal's Triangle: It may be constructed in the following manner.
 * In row 0 (the topmost row), there is a unique nonzero entry 1.
 * Each entry of each subsequent row is constructed by adding the number
 * above and to the left with the number above and to the right,
 * treating blank entries as 0.
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 *
 * Given the position (row,col) of the Pascal's Triangle T, define a function
 * to calculate the value T(rows,col) and the recursion required.
 * Example: In the position (2,1) the output is:
 * value: 2, recursion: T(1,0)+T(1,1)
 *
 * Hint:
 *   -Determinate the edge condition.
 *   -Use to_string function to convert int to string
 */
string pascalT(int row, int col)
{

    if (row >= 0 && (col == 0 || col == row))
    {
        return "1";
    }
    else
    {
        return pascalT(row - 1, col) + pascal(row - 1, col - 1);
    }
}

/*
 *Exercise 4:
 *
 *k Digit: Define  a recursive function to found the k-digit from right to left.
 *                 if the k-digit doesn't exist then return -1.
 *By example: the 2nd digit of 1234 is 3 and the 4-digit from 12 is -1.
 *
 *Hint: Remember that the first digit of a number is calculated by n%10.
 */
int k_digit(int n, int k)
{
    return 0; // dummy return
}

/*Exercise 5:

*A sequence of Fibonnacci of strings F = {f0,f1,...,fn} is defined
*by f0 = "a", f1 = "b", and fn = fn-2 + fn-1, where + is the addition of two strings
*Define a function  given a string s, such that if s is a term of the Fibonacci
*sequence of strings return the position associated. Otherwise return -1.

*By example: the string s="bab" correspond to the term f_3 of the sequence, then
*the output is 3.

*Hint:
       -Use a helper function to complete the implementation.
       -Use the instance .compare of the class string to compare strings
*
*/
int Pos_Fibonacci(string s)
{
    if (s.empty())
    {
        return -1;
    }
    return Pos_FibHelper(s, "a", "b");
}

int Pos_FibHelper(string ab, string a, string b)
{

    int index = -1;
    index++;
    if (ab.compare(a) == 0 || ab.compare(b) == 0)
    {
        return index;
    }

    else if (ab.compare(a) != 0 || ab.compare(b) != 0)
    {
        return Pos_FibHelper(ab, a + b, b + a);
    }
    else if (index > ab.size())
    {
        return -1;
    }
}

/*Exercise 6 (BONUS):
*
*You must find recursively the number of ways to
*generate all distinct ways to write n
*as the sum of positive integers. For example,
*with n = 4, the options are
*
*4,
*3 + 1,
*2 + 1+ 1,
*2 + 2, and
*1 + 1 + 1 + 1.
*
*Hint: -Observe the diagram showed to generalize the recursion
       -Use an helper function
*/
int PowerSum(int n)
{
    return 0; // Dummy return
}

int main()
{

    // test Exercise 1
    cout << "lcm(" + to_string(30) + "," + to_string(7) + ") = " << lcm(30, 7) << endl;
    cout << "lcm(" + to_string(12) + "," + to_string(8) + ") = " << lcm(12, 8) << endl;
    cout << "lcm(" + to_string(15) + "," + to_string(60) + ") = " << lcm(15, 60) << endl;
    cout << "lcm(" + to_string(7) + "," + to_string(0) + ") = " << lcm(7, 0) << endl;
    cout << "lcm(" + to_string(11) + "," + to_string(121) + ") = " << lcm(11, 121) << endl;

    // test Exercise 2
    cout << "Decimal to Binary " << 25 << " = " << decimalToBinary(25) << endl;
    cout << "Decimal to Binary " << 10 << " = " << decimalToBinary(10) << endl;
    cout << "Decimal to Binary " << 7 << " = " << decimalToBinary(7) << endl;
    cout << "Decimal to Binary " << 120 << " = " << decimalToBinary(120) << endl;

    // test Exercise 3
    cout << "Secuence T(" + to_string(2) + "," + to_string(0) + ") = " << pascalT(2, 0) << endl;
    cout << "Secuence T(" + to_string(3) + "," + to_string(2) + ") = " << pascalT(3, 2) << endl;
    cout << "Secuence T(" + to_string(5) + "," + to_string(3) + ") = " << pascalT(5, 3) << endl;
    cout << "Secuence T(" + to_string(6) + "," + to_string(4) + ") = " << pascalT(6, 4) << endl;

    // test Exercise 4
    cout << "The " + to_string(3) + " Digit of " + to_string(1537) + " is: " << k_digit(1537, 3) << endl;
    cout << "The " + to_string(5) + " Digit of " + to_string(2021) + " is: " << k_digit(2021, 5) << endl;
    cout << "The " + to_string(4) + " Digit of " + to_string(123) + " is: " << k_digit(123, 4) << endl;
    cout << "The " + to_string(5) + " Digit of " + to_string(18334) + " is: " << k_digit(18334, 5) << endl;
    cout << "The " + to_string(4) + " Digit of " + to_string(135334) + " is: " << k_digit(135334, 4) << endl;

    // test Exercise 5
    cout << "s = "
         << " bab."
         << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("bab") << endl;
    cout << "s = "
         << "abbb."
         << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("abbb") << endl;
    cout << "s = "
         << "abbab."
         << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("abbab") << endl;
    cout << "s = "
         << "bababbab."
         << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("bababbab") << endl;
    cout << "s = "
         << "babbab."
         << " Position in the Fibonacci Sequence = " << Pos_Fibonacci("babbab") << endl;

    // test Exercise 6
    cout << "Powersum of " + to_string(3) << " = " << PowerSum(3) << endl;
    cout << "Powersum of " + to_string(4) << " = " << PowerSum(4) << endl;
    cout << "Powersum of " + to_string(5) << " = " << PowerSum(5) << endl;
    cout << "Powersum of " + to_string(6) << " = " << PowerSum(6) << endl;
    cout << "Powersum of " + to_string(8) << " = " << PowerSum(8) << endl;
}
