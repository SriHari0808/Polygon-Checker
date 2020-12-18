//This Unit Test project tests all the functions used in PolygonChecker

#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
	#include "triangleSolver.h"
	#include "main.h"
    #include "rectangleSolver.h"
    #include"TriAngles.h"
    #include"rectangleSolver.c"
    #include"TriAngles.c"
    #include"triangleSolver.c"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(Rectangle_Points)
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
			const double EXPECTED = 144.039;
			double tolerance = 0.039;

			//Act
			double ResultPerimeter = Perimeter(a, b, c, d);

			//Assert
			Assert::AreEqual(EXPECTED, ResultPerimeter, tolerance);
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
			const int EXPECTED = 1.000;

			//Act
			int ResultArea = Area(a, b, c);

			//Assert
			Assert::AreEqual(EXPECTED, ResultArea);

		}
		TEST_METHOD(T007_IsNotRectangle_pointaANDbANDcANDd_0)
		{
			//Assign
			point a, b, c, d;
			a.x = 2;
			a.y = 1;
			b.x = 2;
			b.y = 3;
			c.x = 3;
			c.y = 5;
			d.x = 4;
			d.y = 7;
			//test case if (ab_x == 0 || cd_x == 0) and (ab_x != cd_x)
			const double EXPECTED = 0;

			//Act
			double Result = analyzeRectangle(a, b, c, d);

			//Assert
			Assert::AreEqual(EXPECTED, Result);

		}
		TEST_METHOD(T008_IsNotRectangle_pointaANDbANDcANDd_0)
		{
			//Assign
			point a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 1;
			b.y = 3;
			c.x = 3;
			c.y = 9;
			d.x = -1;
			d.y = 5;
			//test case if (ab_y / ab_x != cd_y / cd_x)
			const int EXPECTED = 0;

			//Act
			int Result = analyzeRectangle(a, b, c, d);

			//Assert
			Assert::AreEqual(EXPECTED, Result);

		}
		TEST_METHOD(T009_IsNotRectangle_pointaANDbANDcANDd_0)
		{
			//Assign
			point a, b, c, d;
			a.x = 0;
			a.y = 1;
			b.x = 1;
			b.y = 3;
			c.x = 3;
			c.y = 9;
			d.x = -1;
			d.y = 5;
			//test case if (ab_y / ab_x != cd_y / cd_x)
			const int EXPECTED = 0;

			//Act
			int Result = analyzeRectangle(a, b, c, d);

			//Assert
			Assert::AreEqual(EXPECTED, Result);

		}
		TEST_METHOD(T0010_IsNotRectangle_pointaANDbANDcANDd_0)
		{
			//Assign
			point a, b, c, d;
			a.x = 34;
			a.y = 23;
			b.x = 45;
			b.y = 23;
			c.x = 87;
			c.y = 54;
			d.x = -23;
			d.y = 12;
			//test case if (ab_y * ab_y + ab_x * ab_x != cd_y * cd_y + cd_x * cd_x)
			const int EXPECTED = 0;

			//Act
			int Result = analyzeRectangle(a, b, c, d);

			//Assert
			Assert::AreEqual(EXPECTED, Result);

		}
		
	};
	TEST_CLASS(Type_Of_Triangle)
	{
	public:

		TEST_METHOD(T001_TypeOfTriangle_ZeroAndMinusTwoAndFour_NotATraingle)
		{
			//Arrange
			int side1 = 0;
			int side2 = -2;
			int side3 = 4;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(T002_TypeOfTriangle_FiveAndFiveAndFive_EquilateralTriangle)
		{
			//Arrange
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(T003_TypeOfTriangle_EightAndEightAndFive_IsoscelesTriangle)
		{
			//Arrange
			int side1 = 8;
			int side2 = 8;
			int side3 = 5;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Isosceles triangle", result);
		}


		TEST_METHOD(T004_TypeOfTriangle_SevenAndFiveAndSeven_IsoscelesTriangle)
		{
			//Arrange
			int side1 = 7;
			int side2 = 5;
			int side3 = 7;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(T005_TypeOfTriangle_FourAndFiveAndFive_IsoscelesTriangle)
		{
			//Arrange
			int side1 = 4;
			int side2 = 5;
			int side3 = 5;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(T006_TypeOfTriangle_TenAndFiveAndSix_ScaleneTriangle)
		{
			//Arrange
			int side1 = 10;
			int side2 = 5;
			int side3 = 6;

			//Act
			char* result = analyzeTriangle(side1, side2, side3);

			//Assert
			Assert::AreEqual("Scalene triangle", result);
		}
	};
	
	
	TEST_CLASS(Angle_Of_Triangle)
	{
	public:

		TEST_METHOD(T001_Sides_13_13_13_Angle_60_60_60)
		{
			//Arrange
			int side1 = 13;
			int side2 = 13;
			int side3 = 13;

			float Expected_Angle1 = 60.000000;
			float Expected_Angle2 = 60.000000;
			float Expected_Angle3 = 60.000000;
			float tolerace = 0.030434;
			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1, tolerace);
			Assert::AreEqual(Expected_Angle2, angle2, tolerace);
			Assert::AreEqual(Expected_Angle3, angle3, tolerace);
		}

		TEST_METHOD(T002_Sides_2_2_2_Angle_60_60_60)
		{
			//Arrange
			int side1 = 2;
			int side2 = 2;
			int side3 = 2;

			float Expected_Angle1 = 60.000000;
			float Expected_Angle2 = 60.000000;
			float Expected_Angle3 = 60.000000;
			float tolerace = 0.030434;
			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1, tolerace);
			Assert::AreEqual(Expected_Angle2, angle2, tolerace);
			Assert::AreEqual(Expected_Angle3, angle3, tolerace);
		}

		TEST_METHOD(T003_Sides_2_3_2_Angle_41_97_41)
		{
			//Arrange
			int side1 = 2;
			int side2 = 3;
			int side3 = 2;

			float Expected_Angle1 = 41.430626;
			float Expected_Angle2 = 97.230057;
			float Expected_Angle3 = 41.430626;

			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1);
			Assert::AreEqual(Expected_Angle2, angle2);
			Assert::AreEqual(Expected_Angle3, angle3);
		}

		TEST_METHOD(T004_Sides_24_19_24_Angle_66p715866_46p635914_66p715866)
		{
			//Arrange
			int side1 = 24;
			int side2 = 19;
			int side3 = 24;

			float Expected_Angle1 = 66.715866;
			float Expected_Angle2 = 46.635914;
			float Expected_Angle3 = 66.715866;
			float tolerance = 0.030434;

			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1, tolerance);
			Assert::AreEqual(Expected_Angle2, angle2, tolerance);
			Assert::AreEqual(Expected_Angle3, angle3, tolerance);
		}

		TEST_METHOD(T005_Sides_12_14_13_angle_52p643490_68p010170_59p437645)
		{
			//Arrange
			int side1 = 12;
			int side2 = 14;
			int side3 = 13;

			float Expected_Angle1 = 52.643490;
			float Expected_Angle2 = 68.010170;
			float Expected_Angle3 = 59.437645;

			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1);
			Assert::AreEqual(Expected_Angle2, angle2);
			Assert::AreEqual(Expected_Angle3, angle3);
		}



		TEST_METHOD(T006_Sides_3_6_4_Angle_26p397715_117p339096_36p354488)
		{
			//Arrange
			int side1 = 3;
			int side2 = 6;
			int side3 = 4;

			float Expected_Angle1 = 26.397715;
			float Expected_Angle2 = 117.339096;
			float Expected_Angle3 = 36.354488;


			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			float tolerance = 0.720383;
			// Assert
			Assert::AreEqual(Expected_Angle1, angle1);
			Assert::AreEqual(Expected_Angle2, angle2);
			Assert::AreEqual(Expected_Angle3, angle3);
		}

		TEST_METHOD(T007_Sides_20_18_22_Angle_59p022343_50p504406_70p564552)
		{
			//Arrange
			int side1 = 20;
			int side2 = 18;
			int side3 = 22;

			float Expected_Angle1 = 59.022343;
			float Expected_Angle2 = 50.504406;
			float Expected_Angle3 = 70.564552;

			// Act
			float angle1 = Angle_A(side1, side2, side3);
			float angle2 = Angle_B(side1, side2, side3);
			float angle3 = Angle_C(side1, side2, side3);

			// Assert
			Assert::AreEqual(Expected_Angle1, angle1);
			Assert::AreEqual(Expected_Angle2, angle2);
			Assert::AreEqual(Expected_Angle3, angle3);
		}

	};
		
}

