#include "Semaphore.h"
#include <iostream>
#include <thread>

int i = 0;

void task(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << i << " hello there" << std::endl;
  i++;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem(new Semaphore);
  threadOne=std::thread(task, sem);
  threadTwo=std::thread(task, sem);
  std::cout << "Launched from main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
