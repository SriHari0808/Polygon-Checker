#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3)
{
	printf("\n\t$$$ TYPE OF TRIANGLE $$$\n ");
	char* result = "";

	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3)
	{
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1))
	{
		result = "Isosceles triangle";
	}

	else if (side1 != side2 && side2 != side3 && side3 != side1)
	{
		result = "Scalene triangle";
	}

	return result;
}

