#include <stdio.h>
#include <math.h>
#include"TriAngles.h"
#define pi 3.14

void AnalyzeInnerAngles(int side1, int side2, int side3)
{
    float sideA = side1;
    float sideB = side2;
    float sideC = side3;

    float A1 = Angle_A(sideA, sideB, sideC);
    float A2 = Angle_B(sideA, sideB, sideC);
    float A3 = Angle_C(sideA, sideB, sideC);

    printf("\n\t$$$  THE THREE INNER ANGLE OF TRIANGLE  $$$ ");
    printf("\n$ Angle 1: %f", A1);
    printf("\n$ Angle 2: %f", A2);
    printf("\n$ Angle 3: %f\n\n", A3);
}

float Angle_A(float sideA, float sideB, float sideC)
{
    float angle_1 = sideA * sideA;
    float angle_2 = sideB * sideB;
    float angle_3 = sideC * sideC;

    float angle1 = acos((angle_2 + angle_3 - angle_1) / (2 * sideB * sideC));
    angle1 = angle1 * 180 / pi;

    return angle1;
}

float Angle_B(float sideA, float sideB, float sideC)
{
    float angle_1 = sideA * sideA;
    float angle_2 = sideB * sideB;
    float angle_3 = sideC * sideC;

    float angle2 = acos((angle_1 + angle_3 - angle_2) / (2 * sideA * sideC));

    angle2 = angle2 * 180 / pi;

    return angle2;
}

float Angle_C(float sideA, float sideB, float sideC)
{
    float angle_1 = sideA * sideA;
    float angle_2 = sideB * sideB;
    float angle_3 = sideC * sideC;

    float angle3 = acos((angle_1 + angle_2 - angle_3) / (2 * sideA * sideB));
    angle3 = angle3 * 180 / pi;

    return angle3;
}