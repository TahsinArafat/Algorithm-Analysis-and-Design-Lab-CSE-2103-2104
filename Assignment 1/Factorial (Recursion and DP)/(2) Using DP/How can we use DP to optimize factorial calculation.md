# How can we use DP to optimize factorial calculation?
We can optimize factorial calculation using dynamic programming. By storing the results of subproblems in an array and reusing them when needed, we can avoid redundant calculations. This approach significantly reduces the time complexity of calculating factorials, especially for large numbers.
The naive approach of factorial calculation works as follows:

 1. Taking the number for which we need to calculate the factorial.
 2. Recursively calculate the lower numbers until zero, for F(x) we need to know F(x-1)

## Optimizing Approach
We observed that for each F(x) we need to calculate F(x-1), but if we need to calculate multiple factorial values then we have to calculate same values over and over. For example:

 - Factorial of 5
 - Factorial of 4
For 5, we need to calculate F(4), **F(3), F(2), F(1)**.
For 4, we need to calculate **F(3), F(2), F(1)**

Here we see some repeated calculation of F(1) to F(3). Using DP, storing this values, not calculating over and over we can optimize the factorial calculation.

## Pseudocode
    Function Factorial(n)
	    if n <= 1
		    return 1
		if fact[n] != 0
		    return fact[n]
	    fact[n] = n * Factorial(n - 1)
	    return fact[n]
	
