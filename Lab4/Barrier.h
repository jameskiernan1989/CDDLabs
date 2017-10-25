/*!\author James Kiernan
    \date 25/10/2017
    \file Barrier.h
    \brief The Barrier class

!
*/
/*! \class Barrier
    \brief Class Barrier is used to cause threads to wait until they each perform a certain function or each reach a particular point in their execution.
*/

class barrier:{
 public:
  barrier(unsigned int t_count=0);
  ~barrier();

  bool wait();
};

