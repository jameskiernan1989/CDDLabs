/*!\author James Kiernan
    \date 8/11/2017
    \file Barrier.cpp
    \brief The Barrier class
    \licence GNU General Public Licence

!
*/
#include "Barrier.h"
/*! \class Barrier
    \brief Class Barrier is used to cause threads to wait until they each perform a certain function or each reach a particular point in their execution.
*/

/*!
\func Barrier
\param int threadCount
\brief Barrier class constructor. This lets the Barrier know how many threads will be passing through it, and initializes the current thread number, which gate is being currently used, semaphore instances of a Mutual Exclusion lock and two barriers to control thread flow.

 */
Barrier::Barrier(int threadCount){
  this->threadCount = threadCount;
  threadNum = 0;
  gate = 0;
  mutex = std::make_shared<Semaphore>(1);
  barrierA = std::make_shared<Semaphore>(0);
  barrierB = std::make_shared<Semaphore>(1);
}
/*!
\func ~Barrier
\param none
\brief Barrier class destructor.
 */
Barrier::~Barrier(){
  // Destructor
}

/*!
\func void setThreadCount
\param int threadCount
\brief Sets the amount of threads that will be using the barrier
 */
void Barrier::setThreadCount(int threadCount){
  this->threadCount = threadCount;
}

/*!
\func getThreadCount
\param none
\brief Returns the amount of threads that are using the barrier
 */
int Barrier::getThreadCount(){
  return this->threadCount;
}

/*!
\func waitForAll
\param none
\brief 
 */
void Barrier::wait(){
  if(gate == 0){
    gateA();
  }
  else{
    gateB();
  }
}
