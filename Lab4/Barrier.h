/*!\author James Kiernan
    \date 25/10/2017
    \file Barrier.h
    \brief The Barrier class
	\GNU General Public Licence

!
*/
#include "Semaphore.h"
#include <iosteam>
#include <thread>
/*! \class Barrier
    \brief Class Barrier is used to cause threads to wait until they each perform a certain function or each reach a particular point in their execution.
*/

class barrier
{
 public:
  barrier(std::shared_ptr<Semaphore> sem, unsigned int t_count=0);
  ~barrier();

  bool wait();
  bool signal();
};

