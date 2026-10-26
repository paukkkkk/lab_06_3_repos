#include "pch.h"
#include "CppUnitTest.h"

int Max(int* a, const int size, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}

template <typename T>
T Max(T* a, const int size, int i, T max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max<T>(a, size, i + 1, max);
    else
        return max;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0631
{
	TEST_CLASS(UnitTest0631)
	{
	public:
		
        TEST_METHOD(TestMethod_Max_Int)
        {
            const int n = 5;
            int a[n] = { -5, 3, 12, 0, 8 };

            // Очікуваний результат: 12
            int expected = 12;
            int actual = Max(a, n, 1, a[0]);

            Assert::AreEqual(expected, actual);
        }

        // Тест для шаблонної функції Max<double>
        TEST_METHOD(TestMethod_Max_Double)
        {
            const int n = 4;
            double b[n] = { 1.5, -2.3, 9.8, 4.1 };

            // Очікуваний результат: 9.8
            double expected = 9.8;
            double actual = Max<double>(b, n, 1, b[0]);

            Assert::AreEqual(expected, actual);
        }
	};
}
