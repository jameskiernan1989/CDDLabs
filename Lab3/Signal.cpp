/*! \file signal.cpp
    \brief Demos mutual exclusion using a Semaphore to control threads

!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

int value = 0;

/*! \fn void taskOne(std::shard_ptr<Semaphore> the Semaphore)
    \brief This function will be called by threadOne and threadTwo
    \param the Semaphore an instance of Semaphore

   taskOne obtains the mutex lock, modifies the value and gives back the lock.
 */
void task(std::shared_ptr<Semaphore> theSemaphore){
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
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  threadOne=std::thread(task, sem);
  threadTwo=std::thread(task, sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
