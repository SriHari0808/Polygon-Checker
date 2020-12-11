//Group Project - Polygon Calculator
//Bowen Zheng, Sri Hari, Le Minh, Raven So
//Date: Dec 11, 2020
//CSCN71020
//
//This is a program made to..
//take 3 sides lengths and if they form a triangle 
//the program will also output its 3 angles
//or the program will collect 4 points given by the user and determine whether 
//or not the points can create a rectangle if so it will output the perimeter and area
//

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {

	

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1://triangle 
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		
		case 2://rectangle
			printf_s("Rectangle selected.\n");
			printRectanglePoints();
			printf_s("Please enter 4 coordinates values.\n");

			point a, b, c, d;
			printf("point 1:\n");
			scanf_s("%lf %lf", &a.x, &a.y);
			printf("point 2:\n");
			scanf_s("%lf %lf", &b.x, &b.y);
			printf("point 3:\n");
			scanf_s("%lf %lf", &c.x, &c.y);
			printf("point 4:\n");
			scanf_s("%lf %lf", &d.x, &d.y);

			if (analyzeRectangle(a, b, c, d)) {
				printf_s("These 4 points can form an rectangle.\n");
				Perimeter(a, b, c, d);
				Area(a, b, c);
			}
			else {
				printf_s("These 4 points can not form an rectangle.\n");
				Perimeter(a, b, c, d);
			}

			return 0;
		
		case 3://quit
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("3. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

void printRectanglePoints()
{
	printf("\nThese are the points of the rectangle:\n");
	printf_s(" A********************B\n");
	printf_s(" *                    *\n");
	printf_s(" *                    *\n");
	printf_s(" *                    *\n");
	printf_s(" *                    *\n");
	printf_s(" C********************D\n");
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

