// Lab Exercise 1: SimpleCalculator.cpp

#include "SimpleCalculator.h"

// default constructor
SimpleCalculator::SimpleCalculator() {
    answer = 0;
}  // end class SimpleClassculator constructor

// function add definition
void SimpleCalculator::add(double a, double b) {
    answer = a + b;
}  // end function add

// function subtract definition
void SimpleCalculator::subtract(double a, double b) {
    answer = a - b;
}  // end function subtract

// function multiply definition
void SimpleCalculator::multiply(double a, double b) {
    answer = a * b;
}  // end function multiply

// function divide definition
void SimpleCalculator::divide(double a, double b) {
    answer = a / b;
}  // end function divide

// return answer
double SimpleCalculator::getAnswer() const {
    return answer;
}  // end function getAnswer
 
