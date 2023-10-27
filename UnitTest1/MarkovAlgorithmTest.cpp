#include "pch.h"
#include "CppUnitTest.h"
#include "..\Poiis\MarkovAlgorithm.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
        TEST_METHOD(TestMethod2) {
            vector<Rule> rules
            {
                Rule("aa", "bb"),
                    Rule("bb", "c"),
                    Rule("c", "")
            };
            MarkovAlgorithm ma(rules);

            // ������ ������� ������ � ��������� ���������
            string input = "abaab";
            string expectedOutput = "a";

            // ��������� ������� � ������� ������
            string actualOutput = ma.apply(input);

            // ���������, ��� ����������� ��������� ��������� � ���������
            Assert:: AreEqual(actualOutput, expectedOutput);
        }
        TEST_METHOD(TestMethod3) {
            vector<Rule> rules;
            MarkovAlgorithm ma(rules);

            // ������ ������� ������ � ��������� ���������
            string input = "A";
            string expectedOutput = "A";

            // ��������� ������� � ������� ������
            string actualOutput = ma.apply(input);

            // ���������, ��� ����������� ��������� ��������� � ���������
            Assert::AreEqual(actualOutput, expectedOutput);
        }
        TEST_METHOD(TestMethod1)
        {
            vector<Rule> rules
            {
                Rule ("A", "B"),
                Rule ("B", "C"),
                Rule ("C", "D")
            };
            MarkovAlgorithm algorithm(rules);

            // ������ ������� ������ � ��������� ���������
            string input = "ACACAC";
            string expectedOutput = "DDDDDD";

            // ��������� ������� � ������� ������
            string actualOutput = algorithm.apply(input);

            // ���������, ��� ����������� ��������� ��������� � ���������
            Assert::AreEqual(actualOutput, expectedOutput);
        }

	};
}
