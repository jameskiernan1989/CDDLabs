/*! \file Rendezvous.cpp
    \author James Kiernan
    \date 17/10/2017
    \brief file to demo Rendezvous using semaphores
    \licence GNU General Public Licence
!
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

std::shared_ptr<Semaphore> semA( new Semaphore);
std::shared_ptr<Semaphore> semB( new Semaphore);

/*! \fn void taskOne()
    \brief This function will be called by threadA
    \param none

    taskOne prints out a statement, signals semA and waits semB. It will print out one more statement when it finishes.

 */
void taskOne(){
  std::cout << "One ";
  semA->Signal();
  semB->Wait();
  std::cout << "Three";
}

/*! \fn void taskTwo()
    \brief This function will be called by threadB
    \param none

    taskOne prints out a statement, waits semA and signals semB. It will print out one more statement when it finishes.

 */
void taskTwo(){
  std::cout << "Two";
  semA->Wait();
  semB->Signal();
  std::cout << "Four";
}

 /*! \fn int main()
    \brief The eponymous main function
    Creates two threads and assigns them functions, and a semaphore
    instance
*/
int main(void){
  std::thread threadA, threadB;
  threadA=std::thread(taskTwo);
  threadB=std::thread(taskOne);
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
}
