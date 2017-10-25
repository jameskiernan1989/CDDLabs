/*! \file Signal.cpp
    \author James Kiernan
    \date 17/10/2017
    \brief file to demo sgnals and waits using semaphores
!
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! \fn void taskOne(std::shard_ptr<Semaphore> the Semaphore)
    \brief This function will be called by thread two
    \param the Semaphore an instance of Semaphore

    taskOne prints out a few statements and calls the signal of the semaphore

 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<< std::endl;
  theSemaphore->Signal();
}

/*! \fn void taskTwo(std::shard_ptr<Semaphore> the Semaphore)
    \brief This function will be called by thread one
    \param the Semaphore an instance of Semaphore

    taskTwo prints out a few statements and calls the signal of the semaphore

 */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second" << std::endl;
}

 /*! \fn int main()
    \brief The eponymous main function
    Creates two threads and assigns them functions, and a semaphore
    instance
*/
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
