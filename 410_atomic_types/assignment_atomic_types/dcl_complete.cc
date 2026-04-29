#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>

class some_type {
public:
    void do_it() {
        std::cout << "doing it on thread " << std::this_thread::get_id() << std::endl;
    }
};

std::atomic<some_type*> ptr{nullptr};   // Atomic pointer replaces raw pointer
std::mutex process_mutex;

void process() {
    // First check — no lock, uses acquire semantics to safely read ptr
    some_type* p = ptr.load(std::memory_order_acquire);

    if (!p) {
        std::lock_guard<std::mutex> lk(process_mutex);

        // Second check — inside the lock, re-read ptr
        p = ptr.load(std::memory_order_relaxed);

        if (!p) {
            p = new some_type;
            ptr.store(p, std::memory_order_release);  // Publish with release semantics
        }
    }

    p->do_it();
}

int main() {
    // Launch several threads to demonstrate safe lazy initialization
    std::thread t1(process);
    std::thread t2(process);
    std::thread t3(process);

    t1.join();
    t2.join();
    t3.join();
}