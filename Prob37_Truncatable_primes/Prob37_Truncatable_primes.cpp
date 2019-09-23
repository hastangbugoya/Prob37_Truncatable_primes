// Prob37_Truncatable_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int IsPrime(unsigned long long int n)
{
	int i;
	if (n == 1) return 0;
	unsigned long long root;
	root = sqrtl(n);
	for (i = 2; i <= root && n % i > 0; i++);
	return i > root;
}

int main()
{
	unsigned long long int n, temp, left, right, bigsum = 0;
	int power = 1, allprime = 1;
	for (n = 8; n <= 1000000; n++)
	{
		temp = n; power = 1; right = 0;
		allprime = IsPrime(temp);
		while (allprime && temp > 0)
		{
			left = temp / 10;
			right = power * (temp % 10) + right;
			allprime = allprime && IsPrime(left) && IsPrime(right);
			power *= 10;
			temp = temp / 10;
		}
		if (allprime)
		{
			printf("\n%lld", n);
			bigsum += n;
		}
			
	}
	printf("\n\n=>%lld", bigsum);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
