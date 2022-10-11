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

    int percentage(){
        int percent;

        percent = (getNumerator()/getDenominator())*100;

        int result = floor(percent);

        return result;
    };
    /*
    * Returns a NEW fraction representing the addition of the target and argument
    * fractions.  The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object and use getNumerator & getDenominator
    */
    Fraction add(Fraction *f2){
        float nume, deno;

        nume = (this->getNumerator()*f2->getDenominator()) + (this->getDenominator()*f2->getNumerator());

        deno = (this->getDenominator()*f2->getDenominator());

        return Fraction(nume, deno);
    };
    
    /*
    * Returns a NEW fraction representing the subtraction of the target and argument
    * fractions.  The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object and use getNumerator & getDenominator
    */
    Fraction subtract(Fraction *f2){
        float numera, denomi;

        numera = (this->getNumerator()*f2->getDenominator()) - (this->getDenominator()*f2->getNumerator());

        denomi = (this->getDenominator()*f2->getDenominator());

        return Fraction(numera, denomi);
    };
    /*
    * Returns a NEW fraction representing the sum of the target and argument
    * fractions.  The resulting fraction may not be expressed in minimal terms.
    * You must create a NEW fraction object and able to use getNumerator 
    * and getDenominator for the tests
    */
    Fraction multiply(Fraction *f2){
        float neo_num, neo_den;

        neo_num = (this->getNumerator()) * (f2->getNumerator());
        neo_den = (this->getDenominator()) * (f2->getDenominator());

        return Fraction(neo_num, neo_den);
    };
    /*
    * Returns a NEW fraction representing the division of the target fraction
    * by the argument fraction.  Remember that a/b divided by c/d is equivalent
    * to a/b times d/c.  The resulting fraction may not be expressed in minimal
    * terms. You must create a NEW fraction object and able to use getNumerator 
    * and getDenominator for the tests
    */
    Fraction divide(Fraction *f2){
        float div_num, div_den;

        div_num = this->getNumerator() * f2->getDenominator();
        div_den = this->getDenominator() * f2->getNumerator();

        return Fraction(div_num, div_den);
    }
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    new Fraction *f1 = Fraction(2.0, 3.0);

    cout << f1->getNumerator() << endl;

    return 0;
}

