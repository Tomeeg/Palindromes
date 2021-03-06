#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


void palindrome(int n, double value)
{
	int temp = value, index = 0;
	int *remainder = new int[n];

	while (temp > 0)
	{
		remainder[index] = temp % 2;
		temp /= 2;
		index++;
	}

	for (int i = 0; i < n; i++)
	{
		if (remainder[i] != 1)
			remainder[i] = 0;
	}

	int end = n - 1, begin = 0, ok = 1;

	while (begin < end)
	{
		if (remainder[begin] != remainder[end])
		{
			ok = 0;
			break;
		}
		begin++, end--;
	}

	if (ok)
	{
		for (int i = n - 1; i >= 0; i--)
			cout << remainder[i];
	}

	delete remainder;

	if (value > 0)
		palindrome(n, value - 1);	
}

int main()
{
	int n;
	double value;
	while (cin >> n)
	{
		value = pow(2.0, n) - 1;
		palindrome(n, value);
		cout << endl;
	}

	return 0;
}

