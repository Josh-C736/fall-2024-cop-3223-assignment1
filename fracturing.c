//********************************************************
// fracturing.c
// Author: Joshua Carrizales
// Date: 8/9/2024
// Class: COP 3223, Professor Parra
// Purpose: This program takes a user's input, reads it,
// and then prints the values calculated after running the inputs thorugh
// the premmade, separate functions. This demonstrates my ability
// to initialise variables, use the scan and print functions properly,
// and use mathamatic functions to calculate desired values.
// Input: x1 value for a point, x2 value for a point, y1 value for a point, y2 value for a point
//
// Output: (to the command line) User's inputted values + desired calculated value (distance, area, etc)
// //********************************************************

#include <stdio.h>
#include <math.h> // needed maths implementation in order to run functions such as square root (sqrt) and power (pow)

#define PI 3.14159

// the types of each function must be declared prior to their calling in main
double calculateDistance(); // calculates the distance between two points
double calculatePerimeter(); // calculates the parameter around two points
double calculateArea(); // calculates the area of two points
double calculateWidth(); // calculates the distance between two points
double calculateHeight(); // calculates the distance between two points

int main(void) 

{
    //needed text statements to instruct the user on what to do to get their desired outcome:

    printf("\nEnter values to calculate the distance between two points. Enter the values in the following order: x1, y1, x2, y2 \n");

    calculateDistance();

    printf("\nEnter values to calculate the perimeter around two points. Enter the values in the following order: x1, y1, x2, y2 \n");

    calculatePerimeter();

    printf("\nEnter values to calculate the area of two points. Enter the values in the following order: x1, y1, x2, y2 \n");

    calculateArea();

    printf("\nEnter values to calculate the width (horizontal space) between two points. Enter the values in the following order: x1, x2 \n");

    calculateWidth();

    printf("\nEnter values to calculate the height (vertical space) between two points. Enter the values in the following order: y1, y2 \n");

    calculateHeight();

    return 0;
}

double askForUserInput() // attempt at ask for user input function + function to be used in each sub function

{
    double input;
    printf("\nEnter a value: \n");
    scanf("%lf", &input);
    return input;
}

double calculateDistance() // function to calculate the distance between two points

{
    double x1 = askForUserInput();
    double y1 = askForUserInput();
    double x2 = askForUserInput();
    double y2 = askForUserInput();
    
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    printf("Point #1 entered: x1 = %.2lf; y1 = %.2lf\n", x1, y1);
    printf("Point #2 entered: x2 = %.2lf; y2 = %.2lf\n", x2, y2);
    printf("The distance between the two points is %.2lf\n", distance);
    
    return distance;
    return 3; // Difficulty rating
}

double calculatePerimeter() // function to calculate the perimeter around two points (using a circular calculation given that the points represent diameter)

{
    double distance = calculateDistance();
    double perimeter = 2 * PI * (distance / 2); // Distance = diameter and in order to get the perimeter we need the radius, thus we divide the distance by 2 (radius = diameter/2)

    printf("The perimeter of the city is %.2lf\n", perimeter);
    return 3; // Difficulty rating
}

double calculateArea() // function to calculate the area of two points (using a circular calculation given that the points represent diameter)

{
    double distance = calculateDistance(); // Reference to previously calculated distance formula so as to not repeat onesself
    double radius = distance / 2; // area = pi*radius^2 so first we must calculate the radius; no global variables allowed to radius must be redefined each time
    double area = PI * radius * radius; // area formula
    
    printf("The area of the city is %.2lf\n", area);
    return 4; // Difficulty rating
}

double calculateWidth() // function to calculate the width (horizontal distance) between two points

{
    double x1 = askForUserInput("Enter x1: ");
    double x2 = askForUserInput("Enter x2: ");

    double width = fabs(x2 - x1);  // use fabs (floating-point absolute) to calculate the absolute value of the double number to avoid a negative answer

    printf("The width between the two cities is %.2lf\n", width);
    
    return width;
    return 2; // Difficulty rating
}

double calculateHeight() // function to calculate the height (vertical distance) between two points

{
    double y1 = askForUserInput("Enter y1: "); 
    double y2 = askForUserInput("Enter y2: ");

    double height = fabs(y2 - y1);  // use fabs (floating-point absolute) to calculate the absolute value of the double number to avoid a negative answer

    printf("The height between the two cities is %.2lf\n", height);
    
    return height;
    return 2; // Difficulty rating
}
