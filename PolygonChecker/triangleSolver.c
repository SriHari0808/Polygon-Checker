//This file contains the descriptions for triangleSolver.h

#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

void analyzeTriangle(float side1, float side2, float side3)
{

    float angle1, angle2, angle3, R, s, pi, area;
    pi = acos(-1);
    s = (side1 + side2 + side3) / 2;
    area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    R = (side1 * side2 * side3) / (4 * area);

    angle1 = (180 / pi) * asin(side1 / (2 * R));
    angle2 = (180 / pi) * asin(side2 / (2 * R));
    angle3 = (180 / pi) * asin(side3 / (2 * R));
    char* result = "";

    if (side1 <= 0 && side2 <= 0 && side3 <= 0)
    {
        printf("Not a triangle");
    }

    else if ((side1 == side2 && side1 == side3) && (angle1 == angle2 && angle1 == angle3))
    {
        printf("The three angles are: %.2f,  %.2f  ,%.2f\n", angle1, angle2, angle3);
        printf("Equilateral Triangle");
    }

    else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1) 
        && (angle1 == angle2 && angle1 != angle3) || (angle1 == angle3 && angle1 != angle2) || (angle2 == angle3 && angle2 != angle1))
    {
        printf("The three angles are: %.2f,  %.2f  ,%.2f\n", angle1, angle2, angle3);
        printf("Isoceles Triangle");
    }

    else
    {
        printf("The three angles are: %.2f,  %.2f  ,%.2f\n", angle1, angle2, angle3);
        printf("Scalene Triangle");
    }

}