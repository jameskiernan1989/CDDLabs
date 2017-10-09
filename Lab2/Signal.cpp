#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Rabbit";
  theSemaphore->Signal();
  theSemaphore->Wait();
  std::cout << "Rabbit";
}

void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Dog";
  theSemaphore->Signal();
  theSemaphore->Wait();
  std::cout << "Dog";
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  threadOne=std::thread(taskTwo, sem);
  threadTwo=std::thread(taskOne, sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
