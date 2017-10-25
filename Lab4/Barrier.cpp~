/*! \file signal.cpp
    \brief Demos mutual exclusion using a Semaphore to control threads

!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

int value = 0;

/*! \fn void taskA(std::shard_ptr<Semaphore> the Semaphore)
    \brief This function will be called by threadOne
    \param the Semaphore an instance of Semaphore

   taskA obtains the mutex lock, modifies the value and gives back the lock.
 */
void taskA(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << value << std::endl;
  theSemaphore->Wait();
  value++;
  theSemaphore->Signal();
  
}
/*! \fn void taskB(std::shard_ptr<Semaphore> the Semaphore)
    \brief This function will be called by threadTwo
    \param the Semaphore an instance of Semaphore

   taskB obtains the mutex lock, modifies the value and gives back the lock.
 */
void taskB(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << value << std::endl;
  theSemaphore->Wait();
  value++;
  theSemaphore->Signal();
}

 /*! \fn int main()
    \brief The eponymous main function
    Creates two threads and assigns them functions, and a semaphore
    instance
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  threadOne=std::thread(taskA, mutex);
  threadTwo=std::thread(taskB, mutex);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  std::cout << value << std::endl;
  return 0;
}
