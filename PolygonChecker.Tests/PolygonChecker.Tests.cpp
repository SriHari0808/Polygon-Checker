//This Unit Test project tests all the functions used in PolygonChecker

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

        TEST_METHOD(T002_CheckOfFaileRectangle_pointaANDbANDcANDd_0)
        {
            //Assign
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

            //Act
            int Result = analyzeRectangle(a, b, c, d);

            //Assert
            Assert::AreEqual(EXPECTED, Result);

        }

        TEST_METHOD(T003_CheckOfPerimeter_pointaANDbANDcANDd_137point160)//point = '.'
        {
            //Assign
            point a, b, c, d;
            a.x = 5;
            a.y = 23;
            b.x = 12;
            b.y = 21;
            c.x = 65;
            c.y = 34;
            d.x = 12;
            d.y = 43;
            const float EXPECTED = 137.160;

            //Act
            float ResultPerimeter = Perimeter(a, b, c, d);

            //Assert
            Assert::AreEqual(EXPECTED, ResultPerimeter);
        }

        TEST_METHOD(T004_CheckOfRectangleArea_pointaANDbANDcANDd_1)
        {
            //Assign
            point a, b, c, d;
            a.x = 0;
            a.y = 0;
            b.x = 0;
            b.y = 1;
            c.x = 1;
            c.y = 0;
            d.x = 1;
            d.y = 1;
            const int EXPECTED = 1;

            //Act
            int ResultArea = Area(a, b, c);

            //Assert
            Assert::AreEqual(EXPECTED, ResultArea);

        }
		
	};
}
