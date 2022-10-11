#include <string>
#include <cmath>
class Triangle {
    private:
        Point2D *p1;
        Point2D *p2;
        Point2D *p3;
    
    public:
        /*
        * Constructs a Triangle object with the given parameters
        */
        Triangle(Point2D *p1, Point2D *p2, Point2D *p3) {
            this->p1 = p1;
            this->p2 = p2;
            this->p3 = p3;
        }
        /*
        * Constructs a Triangle object with the same properties (points)
        * as the parameter Triangle, e.g. copies the target Triangle.
        */
        Triangle(Triangle *t2);
        // Getters
        Point2D* getP1(){ return p1; }
        Point2D* getP2(){ return p2; }
        Point2D* getP3(){ return p3; }
        /*
        * Returns the perimeter of the target Triangle object
        * The perimeter is the sum of the lengths of the sides
        * HINT: Check for useful methods in the Point2D class
        */
        double perimeter();
        
        /*
        * Returns the area of the target Triangle object
        * HINT: Use Heron's formula of area using 3 sides
        */
        double area();
        
        /* 
        * Return a NEW Triangle that represents the translation of the target
        * Triangle by detaX units horizontally and deltaY units vertically.
        * The position of the new Triangle is relative to the target Triangle.
        */
        Triangle* translate(double deltaX, double deltaY);
        
        /*
        * Return the String equilateral, isosceles or scalene depending
        * on the similarity of the sides of the triangle given.
        */
        std::string findType();
        /*
        * Return length of side A of triangle, distance from P1 -> P2
        */
        double getSideALength();
        /*
        * Return length of side B of triangle, distance from P2 -> P3
        */
        double getSideBLength();
        /*
        * Return length of side C of triangle, distance from P3-> P1
        */
        double getSideCLength();
};
