// Algorithm call with predicate
// Using lambda expression
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec{4, 2, 3, 5, 1};
	
	std::cout << "Elements of vector: ";

	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << '\n';

	int divisor;
	std::cout<< "Enter a radix for divisibility check: ";
	std::cin >> divisor;

	if (divisor == 0) {
		std::cout<<"Cannot divide by zero."<<std::endl;
	}

	// Call std::count_if() algorithm using a lambda expression as predicate
	auto n_divisible = std::count_if(vec.begin(), vec.end(), 
	
		// The lambda definition goes inside the call!
		[divisor] (int n)
		{ 
			return (n % divisor == 0);
		}
	);

	std::cout << "The vector has " << n_divisible << " element(s) that are divisible by "<<divisor<<"\n";
}