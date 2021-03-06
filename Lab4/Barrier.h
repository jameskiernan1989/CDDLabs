/*!\author James Kiernan
    \date 8/11/2017
    \file Barrier.h
    \brief The Barrier class
	\GNU General Public Licence

!
*/
#include "Semaphore.h"
#include <iosteam>
#include <stdio.h>
/*! \class Barrier
    \brief Class Barrier is used to cause threads to wait until they each perform a certain function or each reach a particular point in their execution.
*/

class barrier{
  
 private:
  int threadCount; // Number of threads using the barrier
  int threadNum; // current thread
  int gate; // current gate active
  std::shared_ptr<Semaphore> mutex; //mutex to control thread execution
  std::shared_ptr<Semaphore> barrierA; // first gate 
  std::shared_ptr<Semaphore> barrierB; // second gate

  void gateA(); // first gate of the barrier
  void gateB(); // second gate of the barrier
  
 public:
  
  /*!
\func Barrier()
\param int threadCount - The amount of threads that will be using the barrier
\brief Barrier class constructor. This lets the Barrier know how many threads will be passing through it, and initializes the current thread number, which gate is being currently used, semaphore instances of a Mutual Exclusion lock and two barriers to control thread flow.

 */
  Barrier(int threadCount);
  
  /*!
\func ~Barrier
\param none
\brief Barrier class destructor.
 */
  ~Barrier();

  /*!
\func void setThreadCount
\param int threadCount
\brief Sets the amount of threads that will be using the barrier
 */
  void setThreadCount(int threadCount);

  /*!
\func getThreadCount
\param none
\brief Returns the amount of threads that are using the barrier
 */
  int getThreadCount();

  /*!
\func waitForAll
\param none
\brief 
 */
  void wait();
};
