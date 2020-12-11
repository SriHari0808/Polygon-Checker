#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	#include "triangleSolver.h"
	#include "main.h"
    #include "rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(PolygonCheckerTests)
	{
	public:
		
        TEST_METHOD(T001_IsARectangle_pointaANDbANDcANDd_1)
        {
            //Assign
            point a, b, c, d;
            a.x = 2;
            a.y = 1;
            b.x = 5;
            b.y = 4;
            c.x = 4;
            c.y = -1;
            d.x = 7;
            d.y = 2;
            const int EXPECTED = 1;
            
            //Act
            int Result = analyzeRectangle(a, b, c, d);

            //Assert
            Assert::AreEqual(EXPECTED, Result);
        }

        TEST_METHOD(T002_CheckOfFaileRectangle_pointaANDbANDcANDd_1)
        {
            point a, b, c, d;
            a.x = 3;
            a.y = 4;
            b.x = 5;
            b.y = 6;
            c.x = 7;
            c.y = 8;
            d.x = 9;
            d.y = 2;
            const int EXPECTED = 0;

            int Result = analyzeRectangle(a, b, c, d);

            Assert::AreEqual(EXPECTED, Result);

        }
        TEST_METHOD(T009_CheckOfPerimeter)
        {
            point a, b, c, d;
            a.x = 5;
            a.y = 23;
            b.x = 12;
            b.y = 21;
            c.x = 65;
            c.y = 34;
            d.x = 12;
            d.y = 43;

            int ResultPerimeter = Perimeter(a, b, c, d);

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
