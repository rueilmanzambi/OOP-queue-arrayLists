// file for derived class


#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H
#include <iostream>
#include <string>
#include "abstractqueue.h"
using namespace std;

struct QueueStruct
{
  string m_name;
  int m_quantity;
  int m_eaten_popplers = 0;
};

template <typename T>
class MyQueue: public AbstractQueue<T>
{
  private:
    int m_length = 4;
    int m_size;
    T *m_queue;
  public:
    MyQueue();
    bool isEmpty() const;
    void grow();
    const T& front() const throw (Oops);
    const T& back() const throw (Oops);
    void enqueue(const T& x);
    void dequeue();
    void clear();
    T& operator[](int i);
    ~MyQueue();
};

#include "derivedclass.hpp"
#endif
