// Example of std::thread with a functor
#include <thread>
#include <iostream>
#include <vector>

// Functor class with overloaded () operator
class Fizzbuzz {
    std::vector<std::string> childNames = {"Conrad", "Claudia", "Anria", "Isabelle"};
    int countingUntil = 30;
	public:
	void operator()() { 
        for (size_t i = 1; i <= countingUntil; i++)
        {
            std::string childName = childNames[i % 4];
            std::string keyword = "none";
            if (i % 3 == 0 && i % 5 == 0) keyword = "fizzbuzz";
            else if (i % 3 == 0) keyword = "fizz";
            else if (i % 5 == 0) keyword = "buzz";
            if (keyword == "none") std::cout << childName << " says " << i << std::endl;
            else std::cout << childName << " says " << keyword << std::endl;
        }
    }
};

int main() {
	Fizzbuzz fizzbuzz;
	
	std::thread thr(fizzbuzz);
	
	thr.join();
}