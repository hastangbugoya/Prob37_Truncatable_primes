// =>748317 Prob37_Truncatable_primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
/*
23
37
53
73
313
317
373
797
3137
3797
739397

=>748317
*/