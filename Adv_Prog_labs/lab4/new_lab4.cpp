#include <iostream>
#include <cmath>
using namespace std;
class Fraction
{
private:
    float numerator;
    float denominator;
public:
    Fraction(float num, float den)
    {
        numerator = num;
        denominator = den;
    }
    float getNumerator()
    {
        return numerator;
    }
    float getDenominator()
    {
        return denominator;
    }
    /*
    * Returns the percentage equivalent of the target fraction.
    * HINT: Check the percentage formula. Use the floor method,
    * you may review how the floor works by viewing the API.
    *  Note that the tests expect values that are whole numbers. 
    */
    int percentage(){
        int percent;

        percent = (this->getNumerator()/this->getDenominator()) * 100;

        int result = floor(percent);

        return result;
    }
    /*
    * Return a NEW fraction representing the addition of the target fraction and the inverse
    * of the argument fraction. The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object and use getNumerator & getDenominator.
    */
    Fraction addInverseOf(Fraction f2){
        float nume, deno;

        nume = (this->getNumerator()*f2.getNumerator()) + (this->getDenominator()*f2.getDenominator());

        deno = (this->getDenominator()*f2.getNumerator());

        return Fraction(nume, deno);
    }
    /*
    * Return a NEW fraction representing the sqrt of the target object.
    * The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object.
    */
    Fraction squareRoot(){
        float num, den;

        num = sqrt(this->getNumerator());
        den = sqrt(this->getDenominator());


        return Fraction(num, den);
    }
    /*
    * Returns a NEW fraction representing the division of the target fraction
    * by the argument fraction.  Remember that a/b divided by c/d is equivalent
    * to a/b times d/c.  The resulting fraction may not be expressed in minimal
    * terms. You must create a NEW fraction object and able to use getNumerator 
    * and getDenominator for the tests
    */
    Fraction divide(Fraction f2){
        float div_num, div_den;

        div_num = this->getNumerator() * f2->getDenominator();
        div_den = this->getDenominator() * f2->getNumerator();

        return Fraction(div_num, div_den);
    }
    /*
    * Return a NEW fraction representing the power of n of the target fraction.
    * The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object.
    */
    Fraction powerOf(int n){
        float pow_num, pow_den;

        pow_num = pow(this->getNumerator(), n);
        pow_den = pow(this->getDenominator(), n);

        return Fraction(pow_num, pow_den);
    }
};