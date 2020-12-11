#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	#include "triangleSolver.h"
	#include "main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(PolygonCheckerTests)
	{
	public:
		
        TEST_METHOD(T007_CheckOfRectangle)
        {
            point a, b, c, d;
            int a.x = 2;
            int a.y = 1;
            int b.x = 5;
            int b.y = 4;
            int c.x = 4;
            int c.y = -1;
            int d.x = 7;
            int d.y = 2;


            char* Result = analyzeRectangle(point a, point b, point c, point d);

            Assert::AreEqual("These 4 points can form an rectangle.", Result);

            int* ResultArea = Area(point a, point b, point c, point d);

            Assert::AreEqual(6, ResultArea);

        }

        TEST_METHOD(T008_CheckOfFaileRectangle)
        {
            int a.x = 3;
            int a.y = 4;
            int b.x = 5;
            int b.y = 6;
            int c.x = 7;
            int c.y = 8;
            int d.x = 9;
            int d.y = 2;

            char* Result = analyzeRectangle(point a, point b, point c, point d);

            Assert::AreEqual("These 4 points can not form an rectangle.", Result);

        }
        TEST_METHOD(T009_CheckOfPerimeter)
        {
            int a.x = 5;
            int a.y = 23;
            int b.x = 12;
            int b.y = 21;
            int c.x = 65;
            int c.y = 34;
            int d.x = 12;
            int d.y = 43;

            int* ResultPerimeter = Perimeter(point a, point b, point c, point d);

            Assert::AreEqual(137.160, ResultPerimeter);

        }
        TEST_METHOD(T0010_CheckOfRectangleArea)
        {
            int a.x = 0;
            int a.y = 0;
            int b.x = 0;
            int b.y = 1;
            int c.x = 1;
            int c.y = 0;
            int d.x = 1;
            int d.y = 1;

            int* ResultArea = Area(point a, point b, point c, point d);

            Assert::AreEqual(0.5, ResultArea);

        }
		
	};
}
