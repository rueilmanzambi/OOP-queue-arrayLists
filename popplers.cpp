////////////////////////
//                    //
// Rueil Manzambi     //
// main homework file //
//                    //
////////////////////////


#include <iostream>
#include <string>
#include <cstdlib>
#include "derivedclass.h"
#include "randomengine.h"
#include "restaurantsoperations.h"

using namespace std;

int main()
{
  MyQueue<QueueStruct> cust_queue;
  QueueStruct queuestruct;
  int numberOfCustomer;
  string name;
  int quantity;

  cin >> numberOfCustomer;
  for (int i=0; i<numberOfCustomer; i++)
  {
    cin >> name >> quantity;
    queuestruct.m_name = name;
    queuestruct.m_quantity = quantity;
    cust_queue.enqueue(queuestruct);
  }

  operations(cust_queue,numberOfCustomer);
  cust_queue.clear();

  return 0;
}
