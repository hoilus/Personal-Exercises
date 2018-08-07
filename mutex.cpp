#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mtx;

void print_block(int n, char c) {
  //critical section: exclusive access to
  //std::cout signalled by locking mutex.
  mtx.lock();
  for (int i = 0; i < n; i++)
    cout << c;
  cout << '\n';
  mtx.unlock();
}

int main() {
  thread th1(print_block, 50, '*');
  thread th2(print_block, 50, '$');
  th1.join();
  th2.join();
  
  return 0;
}

