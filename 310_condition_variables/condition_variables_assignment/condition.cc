#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Global variables
mutex mut;
bool dataReady{false};       // Boolean flag replaces condition variable
string sdata{"Empty"};

// Waiting thread
void reader() {
    while (true) {
        lock_guard<mutex> guard(mut);        // Acquire lock
        if (dataReady) {                     // Check the boolean flag
            cout << "Data is " << sdata << endl;
            break;
        }
    }                                        // Lock released, re-acquired each iteration
}

// Modifying thread
void writer() {
    cout << "Writing data..." << endl;
    {
        lock_guard<mutex> lg(mut);           // Acquire lock
        this_thread::sleep_for(2s);          // Pretend to be busy...
        sdata = "Populated";                 // Modify the data
        dataReady = true;                    // Set the flag before releasing lock
    }
}

int main() {
    cout << "Data is " << sdata << endl;
    thread read{reader};
    thread write{writer};

    write.join();
    read.join();
}