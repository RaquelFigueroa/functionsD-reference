//Name:Raquel Figueroa
//Date:15 October 2015
//Description:figueroa_reference.cpp

#include <iostream>//cin, cout
#include <cassert>//assert
#include <cmath>//fabs

using namespace std;

//****************************************************************
void sort(int& numA, int& numB, int& numC);
//Summary:Sorts three numbers in increasing order.
//Precondition:Three ints between 0 and 100, inclusive, are passed
//by reference into the function.
//Postcondition:The ints are sorted in ascending order; A < B < C.
//
//****************************************************************

//****************************************************************
void numDigits(int valA, int& n);   
//Summary:Determines the number of digits in an int.
//Precondition:An int, between -10,000 and 10,000, inclusive, is
//passed by copy into the function. One int is passed by reference
//to hold the number of digits in the int.
//Postcondition:The total number of digits is held in the pass by 
//reference variable.
//
//****************************************************************

//****************************************************************
void computeSphere(double& a, double& v, double r);
//Summary:Calculates the area and volume of a sphere.
//Precondition:A radius of type double is passed by copy into the 
//function. The variable r is of a value between 0 and 10000, inclusive.
//Postcondition:An area and volume, each of type double, are determined
//and saved in variables that are passed by reference into the function.
//
//****************************************************************

//****************************************************************
void swap(int& A, int& B);
//Summary:Swaps the values of A and B variables.
//Precondition:Two positive ints are passed by reference into the
//function.
//Postcondition:The initial value for A becomes the value for B
//and the initial value for B becomes the final value for A.
//
//****************************************************************

int main()
{
    double e = .00001;
    
    //asserts for sort function passed!
    int a(4), b(98), c(2);
    sort(a, b, c);
    assert((a == 2) && (b == 4) && (c== 98));
    
    a = 100;
    b = 1;
    c = 99;
    sort(a, b, c);
    assert((a == 1) && (b == 99) && (c == 100));

    //asserts for numDigits function passed!
    int num(-1), numInt;
    numDigits(num, numInt);
    assert(numInt == 1);
    
    num = 9876;
    numDigits(num, numInt);
    assert(numInt = 5);
    
    //assert for computeSphere function passed!
    double area, volume, radius(4.3);
    computeSphere(area, volume, radius);
    assert((fabs(area) - 232.2344 < e) && (fabs(volume) - 332.869307 < e));
    
    radius = 0.12;
    computeSphere(area, volume, radius);
    assert((fabs(area) - 0.18086 < e) && (fabs(volume) - 0.007234 < e));
    
    //asserts for swap function passed!
    int numberA(101), numberB(1001);
    swap(numberA, numberB);
    assert((numberA == 1001) && (numberB == 101));  
    
    numberA = 0;
    numberB = 36849;
    swap(numberA, numberB);
    assert((numberA == 36849) && (numberB == 0));  
    
    return 0;
}
void sort(int& numA, int& numB, int& numC)
{
    assert(numA >= 0 && numA <= 100);
    assert(numB >= 0 && numB <= 100);
    assert(numC >= 0 && numC <= 100);
    
    int tempA(0), tempB(0), tempC(0);
    
    if (numA < numB && numA < numC)
        tempA = numA;
    else if (numB < numA && numB < numC)
        tempA = numB;
    else
        tempA = numC;
    
    if ((numA < numB && numA > numC) || (numA > numB && numA < numC))
        tempB = numA;
    else if ((numB < numA && numB > numC) || (numB > numA && numB < numC))
        tempB = numB;
    else 
        tempB = numC;
       
    if (numA > numB && numA > numC)
        tempC = numA;
    else if (numB > numA && numB > numC)
        tempC = numB;
    else 
        tempC = numC;
        
    numA = tempA;
    numB = tempB;
    numC = tempC;    

}//end sort fuction

void numDigits(int valA, int& n)
{
    assert(valA >= -10000 && valA <= 10000);
    valA = fabs(valA);
    
    if (valA >= 0 && valA <= 9)
        n = 1;
    else if (valA >= 10 && valA <= 99)
        n = 2;
    else if (valA >= 100 && valA <= 999)
        n = 3;
    else if (valA >= 1000 && valA <= 9999)
        n = 4;
    else 
        n = 5;
}//end numDigits function

void computeSphere(double& a, double& v, double r)
{
    const double PI = 3.14;
    a = 4 * PI * r * r;
    v = 4 / 3 * PI * r * r * r;
}//end computeSphere function

void swap(int& A, int& B)
{
    assert(A >=0 && B >=0);
    int temp;
    temp = A;
    A = B;
    B = temp;

}//end swap function
