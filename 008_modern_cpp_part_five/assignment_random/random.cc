// Example of using the features in <random>
#include <iostream>
#include <random>

// Create an engine object
std::mt19937 mt;

int main()
{
	// We want ints in the range 0 to 10
	std::cout << "10 random integers between 0 and 10:\n";
	std::uniform_int_distribution<int> uid(0, 10);

	// Get 10 random numbers
	for (int i = 0; i < 10; ++i) {
		// Invoking the distribution returns the next number in the sequence
		std::cout << uid(mt) << ", ";
	}

	std::cout << "\n\n";

	// We want doubles in the range 0 to 100
	std::cout << "5 random floating-point numbers between 0 and 100:\n";
	std::uniform_real_distribution<double> did(0, 100);

	// Get 5 random numbers
	for (int i = 0; i < 5; ++i) {
		// Invoking the distribution returns the next number in the sequence
		std::cout << did(mt) << ", ";
	}

	std::cout << '\n';
}