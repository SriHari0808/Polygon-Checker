//This .h file holds the library used to solve rectangles

#pragma once
typedef struct {

    double x;
    double y;

}point;

int analyzeRectangle(point, point, point, point);
int Perimeter(point, point, point, point);
int Area(point, point, point);