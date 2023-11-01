#include "pch.h"
#include "CppUnitTest.h"
#include "..\Poiis\MarkovAlgorithm.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
        TEST_METHOD(PositiveTest) {
            vector<Rule> rules
            {
                Rule("aa", "bb"),
                    Rule("bb", "c"),
                    Rule("c", "")
            };
            MarkovAlgorithm ma(rules);

            // Задаем входные данные и ожидаемый результат
            string input = "abaab";
            string expectedOutput = "a";

            // Применяем правила к входным данным
            string actualOutput = ma.apply(input);

            // Проверяем, что фактический результат совпадает с ожидаемым
            Assert:: AreEqual(actualOutput, expectedOutput);
        }
        TEST_METHOD(NoRulesTest) {
            vector<Rule> rules;
            MarkovAlgorithm ma(rules);

            // Задаем входные данные и ожидаемый результат
            string input = "A";
            string expectedOutput = "A";

            // Применяем правила к входным данным
            string actualOutput = ma.apply(input);

            // Проверяем, что фактический результат совпадает с ожидаемым
            Assert::AreEqual(actualOutput, expectedOutput);
        }
        TEST_METHOD(EmptyStringTest)
        {
            vector<Rule> rules
            {
                Rule ("A", "B"),
                Rule ("B", "C"),
                Rule ("C", "")
            };
            MarkovAlgorithm algorithm(rules);

            // Задаем входные данные и ожидаемый результат
            string input = "ACACAC";
            string expectedOutput = "";

            // Применяем правила к входным данным
            string actualOutput = algorithm.apply(input);

            // Проверяем, что фактический результат совпадает с ожидаемым
            Assert::AreEqual(actualOutput, expectedOutput);
        }

	};
}
