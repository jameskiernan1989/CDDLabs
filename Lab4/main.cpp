/*!\author James Kiernan
    \date 25/10/2017
    \file Barrier.cpp
    \brief Class to demonstrate the barrier solution with Semaphores

!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

int task_counter = 0;
 /*! \fn int main()
    \brief Keeps track of how many threads arrive. Mutex provides exclusive access to count so that threads can increment it safely.
Barrier is locked until all threads arrive, then it unlocks.
*/
int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  threadOne=std::thread(task, mutex);
  threadTwo=std::thread(task, mutex);
  threadThree=std::thread(task, mutex);
  threadFour=std::thread(task, mutex);
  std::cout<<"Started from main"<<std::endl;
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  return 0;
}
