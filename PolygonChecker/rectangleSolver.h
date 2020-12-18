//This .h file holds the library used to solve rectangles

#pragma once
typedef struct {

    double x;
    double y;

}point;

int analyzeRectangle(point a, point b, point c, point d);
double Perimeter(point a, point b, point c, point d);
double Area(point a, point b, point c);