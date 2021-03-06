#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "..\\AISTRD3semKurszchPrefics\functionsPrefics.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsForPrefics
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod_ReadString)
		{
			string waited = "5+5";
			string real = "5+5";
			Calculator prefics;
			prefics.readString(real);
			Assert::AreEqual(prefics.str, waited);
		}

		TEST_METHOD(TestMethod_ReadStringForEmpty)
		{
			string waited = "";
			string real = "";
			Calculator prefics;
			prefics.readString(real);
			Assert::AreEqual(prefics.str, waited);
		}


		TEST_METHOD(TestMethod_ReadString_WhiteSpace)
		{
			string waited = " ";
			string real = " ";
			Calculator prefics;
			prefics.readString(real);
			Assert::AreEqual(prefics.str, waited);
		}

		TEST_METHOD(TestMethod_Sum)
		{
			string waited = " + 5 5";
			string real = "5+5";
			double waitedSum=10;
			double realSum=0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real,waited);
			Assert::AreEqual(realSum,waitedSum);
		}

		TEST_METHOD(TestMethod_Multipl)
		{
			string waited = " * 10 10";
			string real = "10*10";
			double waitedSum = 100;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}  

		TEST_METHOD(TestMethod_Delenie)
		{
			string waited = " / 100 10";
			string real = "100/10";
			double waitedSum = 10;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Minus)
		{
			string waited = " - 10 10";
			string real = "10-10";
			double waitedSum = 0;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Pow)
		{
			string waited = " ^ 10 2";
			string real = "10^2";
			double waitedSum = 100;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Unar_Minus)
		{
			string waited = " - - 10 100";
			string real = "-(10-100)";
			double waitedSum = 90;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_CosAndPi)
		{
			string waited = " cos pi";
			string real = "cospi";
			double waitedSum = -1;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_SinAndPi)
		{
			string waited = " sin / pi 2";
			string real = "sin(pi/2)";
			double waitedSum = 1;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Tg)
		{
			string waited = " tg 0";
			string real = "tg(0)";
			double waitedSum =0;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Ctg)
		{
			string waited = " ctg / pi 4";
			string real = "ctg(pi/4)";
			double waitedSum = 1;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			realSum = 1;
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Sqrt)
		{
			string waited = " sqrt 100";
			string real = "sqrt100";
			double waitedSum = 10;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_LnAndE)
		{
			string waited = " ln e";
			string real = "ln(e)";
			double waitedSum = 1;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Log)
		{
			string waited = " log 100";
			string real = "log100";
			double waitedSum = 2;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_PiAndE)
		{
			string waited = " + sin / pi 2 ln e";
			string real = "sin(pi/2)+lne";
			double waitedSum = 2;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_PriorytiWithMultipl)
		{
			string waited = " + * 5 5 5";
			string real = "5*5+5";
			double waitedSum = 30;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_PriorytiWithCkobki)
		{
			string waited = " * 5 + 5 5";
			string real = "5*(5+5)";
			double waitedSum = 50;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_SumWithUnarMinus)
		{
			string waited = " + - + 50 50 100";
			string real = "-(50+50)+100";
			double waitedSum = 0;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_SumWith)
		{
			string waited = " + 10 + * 20 30 40";
			string real = "10+20*30+40";
			double waitedSum = 650;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_Sum_WITH_multipl)
		{
			string waited = " * + 10 10 + 10 * 10 2";
			string real = "(10+10)*(10+10*2)";
			double waitedSum = 600;
			double realSum = 0;
			Calculator prefics;
			prefics.readString(real);
			prefics.validation();
			prefics.inficToPrefics();
			real = prefics.readPreficsForm(prefics.infics);
			prefics.evaluate();
			realSum = prefics.readEvaluate(prefics.sum);
			Assert::AreEqual(real, waited);
			Assert::AreEqual(realSum, waitedSum);
		}

		TEST_METHOD(TestMethod_ExceptionWithWhiteSpace)
		{
			string real = "5+ 5";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithScobki)
		{
			string real = "(5+5)-4)";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithFirstOperating)
		{
			string real = "+5+5";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithLastOperating)
		{
			string real = "5+5+";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithNoNumbers)
		{
			string real = "*++";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithOperatinWtihOneArgumentWothoutArgument)
		{
			string real = "cos";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithExponentWithNumbers)
		{
			string real = "123e2+32";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}


		TEST_METHOD(TestMethod_ExceptionWithExponentWithPi)
		{
			string real = "pie+3";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}


		TEST_METHOD(TestMethod_ExceptionWithMistakeInOneArgument)
		{
			string real = "sen(5)";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

		TEST_METHOD(TestMethod_ExceptionWithIncurrentSimvol)
		{
			string real = "cos(5)+&";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}


		TEST_METHOD(TestMethod_ExceptionWithoutOperatoin)
		{
			string real = "1231";
			Calculator prefics;
			prefics.readString(real);
			try
			{
				prefics.validationForTests(prefics.str);
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Incorrect input.", error.what());
			}
		}

	};
}