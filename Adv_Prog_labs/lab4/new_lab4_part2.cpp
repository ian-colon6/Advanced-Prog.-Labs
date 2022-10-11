#include<iostream>
#include<string>
#include<cmath>

using namespace std;

/*
  Base class Point2D represents a point in two dimensional space
*/
class Point2D {
    private:
        double x; 
        double y;   

    public:     
        Point2D(){
            x = 0.0;
            y = 0.0;
        }

        Point2D(double x1, double y1){
            this->setX(x1);
            this->setY(y1);
        }
        
        // Setters
        void setX(double x2){x = x2;}
        void setY(double y2){y = y2;}

        // Getters 
        double getX(){return x;}
        double getY(){return y;}

        /*
        *   Returns the distance of the target object and the parameter Point2D p2.
        */
        double distance(Point2D p2){
            double deltaX = p2.getX() - this->getX();
            double deltaY = p2.getY() - this->getY();
            return sqrt(deltaX * deltaX + deltaY * deltaY);
        } 
};


/*
  Triangle class without side lengths methods implemented
*/
class Triangle {
    private:
        Point2D point1;
        Point2D point2;
        Point2D point3;
    
    public:

        /*
        * Constructs a Triangle object with the given parameters
        */
        Triangle(Point2D p1, Point2D p2, Point2D p3) {
            point1 = p1;
            point2 = p2;
            point3 = p3;
        }

        /*
        * Constructs a Triangle object with the same properties (points)
        * as the parameter Triangle, e.g. copies the target Triangle.
        */
       /*
        Triangle(Triangle &t2){
            this->point1 = t2.point1;
            this->point2 = t2.point2;
            this->point3 = t2.point3;
        }
        */

        // Getters
        Point2D getP1(){ return point1; }
        Point2D getP2(){ return point2; }
        Point2D getP3(){ return point3; }

        /*
        * Returns the perimeter of the target Triangle object
        * The perimeter is the sum of the lengths of the sides
        * HINT: Check for useful methods in the Point2D class
        */
        double perimeter(){
            double sum, side1, side2, side3;

            side1 = this->point1.distance(this->point2);
            side2 = this->point2.distance(this->point3);
            side3 = this->point3.distance(this->point1);

            sum = side1 + side2 + side3;

            return sum;
        }
        
        /*
        * Returns the area of the target Triangle object
        * HINT: Use Heron's formula of area using 3 sides
        */
        double area(){
            double sideA, sideB, sideC, S, result;

            sideA = this->point1.distance(this->point2);
            sideB = this->point2.distance(this->point3);
            sideC = this->point3.distance(this->point1);

            S = sideA + sideB + sideC;

            result = sqrt(S * (S-sideA) * (S-sideB) * (S-sideC));

            return result;
        }
        
        /* 
        * Return a NEW Triangle that represents the multiplication of the target
        * Triangle by k units all around.
        */
        Triangle multiply(double k){
            Point2D m_point1, m_point2, m_point3;
            double X_1, Y_1, X_2, Y_2, X_3, Y_3;

            X_1 = this->getP1().getX() * k;
            Y_1 = this->getP1().getY() * k;

            X_2 = this->getP2().getX() * k;
            Y_2 = this->getP2().getY() * k;

            X_3 = this->getP3().getX() * k;
            Y_3 = this->getP3().getY() * k;

            m_point1 = Point2D(X_1, Y_1);
            m_point2 = Point2D(X_2, Y_2);
            m_point3 = Point2D(X_3, Y_3);

            return Triangle(m_point1, m_point2, m_point3);

        }
        
        /*
        * Return the String equilateral, isosceles or scalene depending
        * on the similarity of the sides of the triangle given.
        */
        std::string findType(){
            double s1, s2, s3;

            s1 = this->getSideALength();
            s2 = this->getSideBLength();
            s3 = this->getSideCLength();

            if(s1 == s2 && s2 == s3 && s1 == s3){
                return "Equilateral";
            }
            else if(s1 == s2 || s1 == s3 || s2 == s3){
                return "Isosceles";
            }
            else{
                return "Scalene";
            }
        }

        /*
        * Return length of side A of triangle, distance from P1 -> P2
        */
        double getSideALength(){
            double dist1_2 = this->point1.distance(this->point2);

            return dist1_2;
        }


/*
* Return length of side B of triangle, distance from P2 -> P3
*/
        double getSideBLength(){
            double dist2_3 = this->point2.distance(this->point3);

            return dist2_3;
        }


/*
* Return length of side C of triangle, distance from P3 -> P1
*/
        double getSideCLength(){
            double dist3_1 = this->point3.distance(this->point1);

            return dist3_1;
        }
};



int main()
{
    cout << "COPY/TRY TEST CASES HERE" << endl;
    Triangle t1(Point2D(2.0, 4.0), Point2D(1.0, 1.0), Point2D(3.0, 3.0));
    Triangle neo_t1 = t1.multiply(3.0);

    cout << "The multiplication x3 of t1 is (" << neo_t1.getP1().getX() << ',' << neo_t1.getP1().getY() << ") ";
    cout << '(' << neo_t1.getP2().getX() << ',' << neo_t1.getP2().getY() << ") ";
    cout << '(' << neo_t1.getP3().getX() << ',' << neo_t1.getP3().getY() << ')';

    return 0;
}