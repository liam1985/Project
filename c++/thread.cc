#include <thread>
#include <mutex>
#include <iostream>

int g_i = 0;
std::mutex g_i_mutex;
std::recursive_mutex r_mutex;


void safe_increment(){
    std::lock_guard<std::mutex> lock(g_i_mutex);
    for (int i; i< 20; i++) {
        ++g_i;
        std::cout << std::this_thread::get_id() << ": " << g_i << std::endl;
    }
}

void recursive_increment() {
    std::lock_guard<std::recursive_mutex> lock(r_mutex);
    std::cout << std::this_thread::get_id() << ": " << g_i << std::endl;
    if (g_i % 20 == 0 && g_i != 0) {
        ++g_i;
        return;
    } else{
        ++g_i;
        recursive_increment();
    }
}

int main() {
    std::cout << "main: " << g_i << std::endl;
    //std::thread t1(safe_increment);
    //std::thread t2(safe_increment);
    std::thread t1(recursive_increment);
    std::thread t2(recursive_increment);
    
    t1.join();
    t2.join();

    std::cout << "main: " << g_i << std::endl;
}
