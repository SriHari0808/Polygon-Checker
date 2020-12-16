#include <stdio.h>
#include <math.h>
#include"TriAngles.h"

int* InnerTriAngles(int side1, int side2, int side3)
{
	float sideA = side1;
	float sideB = side2;
	float sideC = side3;

	float angle1, angle2, angle3;
	float pi = acos(-1);

	float SemiPerimeter = (sideA + sideB + sideC) / 2;

	float AreaOfTriangle = sqrt(SemiPerimeter * (SemiPerimeter - sideA) * (SemiPerimeter - sideB) * (SemiPerimeter - sideC));

	float Radius = (sideA * sideB * sideC) / (4 * AreaOfTriangle);

	angle1 = (180 / pi) * asin(sideA / (2 * Radius));
	angle2 = (180 / pi) * asin(sideB / (2 * Radius));
	angle3 = (180 / pi) * asin(sideC / (2 * Radius));

	printf("\n\t$$$  THE THREE INNER ANGLE OF TRIANGLE  $$$ ");
	printf("\n$ Angle 1: %.2f", angle1);
	printf("\n$ Angle 2: %.2f", angle2);
	printf("\n$ Angle 3: %.2f\n\n", angle3);

	//change the return with the way ur(Raven) testing
	return 0;   //int angles[] = { sideA, sideB, sideC };
				//return angles;
}