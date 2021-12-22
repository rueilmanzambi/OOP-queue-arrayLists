// hpp file for derivedclass.h

#include <iostream>
#include <string>


using namespace std;



template <typename T>
MyQueue<T>::MyQueue()
{
  m_size = 0;
  m_length =4;
  m_queue = new T[m_length];
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
  if (m_size <= 0)
    return true;
  else
    return false;
}

template <typename T>
const T& MyQueue<T>::front() const throw(Oops)
{
  Oops error("Error! The queue is empty!");
  try
  {
    if (m_size <= 0)
      throw(error);
  }
  catch (Oops error)
  {
    cout << error.getMsg() << endl;
  }
  return m_queue[0];
}

template <typename T>
const T& MyQueue<T>::back() const throw(Oops)
{
  Oops error("Error! The queue is empty!");
  try
  {
    if (m_size <= 0)
      throw(error);
  }
  catch (Oops error)
  {
    cout << error.getMsg() << endl;
  }
  return m_queue[m_size-1];
}

template <typename T>
void MyQueue<T>::grow()
{
  T* tmp;
  tmp = new T[m_length * 2];
  for (int i =0; i<m_size; i++)
    tmp[i] = m_queue[i];
  delete [] m_queue;
  m_queue = tmp;
  m_length = m_length * 2;
  return;
}

template <typename T>
void MyQueue<T>::enqueue(const T& x)
{
  if (!(m_size < m_length))
    grow();
  m_queue[m_size] = x;
  m_size++;
  return;
}

template <typename T>
void MyQueue<T>::dequeue()
{
  if (m_size>0)
  {
    T* tmp;
    tmp = new T[m_length];
    for (int i=0;i<m_size-1;i++)
      tmp[i] = m_queue[i+1];
    delete [] m_queue;
    m_queue = tmp;
    m_size--;
  }
  return;
}

template <typename T>
void MyQueue<T>::clear()
{
  delete [] m_queue;
  m_size = 0;
  m_length = 4;
  m_queue = new T[m_length];
  return;
}

template <typename T>
MyQueue<T>::~MyQueue()
{
    delete [] m_queue;
}

template <typename T>
T& MyQueue<T>::operator[](int i)
{
  return m_queue[i];
}

