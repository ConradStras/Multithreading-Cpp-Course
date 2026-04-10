// Unsynchronized threads which make conflicting accesses.
// But where is the shared memory location?
#include <thread>
#include <iostream>

int counter = 0;

void printAndIncrement(int counter)
{
	// A very artificial way to display a string!
	for (int i = 0; i < 100000; ++i) {
		std::cout << ++counter << std::endl;
	}
}

int main()
{
	
    std::thread thr1(printAndIncrement, counter);
	std::thread thr2(printAndIncrement, counter);
	std::thread thr3(printAndIncrement, counter);
    std::thread thr4(printAndIncrement, counter);
    std::thread thr5(printAndIncrement, counter);
    std::thread thr6(printAndIncrement, counter);
    
	thr1.join();
	thr2.join();
	thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
}