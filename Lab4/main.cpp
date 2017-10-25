/*!\author James Kiernan
    \date 25/10/2017
    \file Barrier.cpp
    \brief Class to demonstrate the barrier solution with Semaphores

!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

std::shared_ptr<Semaphore> barrier(new Semaphore(0)); /*Global instance of a barrier semaphore*/
int count = 0; /*Holds the count of the number of threads*/
int n = 4; /*The number of threads */

/*! \fn void task(std::shared_ptr<Semaphore> mutex)
  \brief This function will be called by each thread.
  \param mutex A semaphore instance used for a  mutual exclusion lock
 */
void task(std::shared_ptr<Semaphore> mutex){
  std::cout<<"Current value of count:"<< count << std::endl;
  mutex.wait();
  count = count + 1;
  std::cout<<"Count is now:" << count << std:endl;
  mutex.signal();

  if(count == n){
    std::cout<<"All threads entered. Unlocking barrier..."<<std::endl;
    barrier.signal();
  }

  barrier.wait();
  barrier.signal();
}

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
