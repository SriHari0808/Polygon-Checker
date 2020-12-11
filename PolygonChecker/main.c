//This file contains the definitions for the main program's functions

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

