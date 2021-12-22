// header file for restaurant simulation


#ifndef RESTAURANTSOPERATIONS_H
#define RESTAURANTSOPERATIONS_H

#include <iostream>
#include "derivedclass.h"
#include "randomengine.h"

using namespace std;

template <typename T>
void operations(MyQueue<T>& queue, int nbrCustomers);
template <typename T>
void eat(int cust, int qty, int& total_qty);
bool eatagain(int& newqty, int qty,int &randNumbers, int* &arrayNumbers);
void finalresult(int totqty, string mostcustomer, int mosteatenquantity, string leastcustomer, int leasteatenquantity);
template <typename T>
void customerdone(MyQueue<T>& queue, int cust, int eaten_popplers, int qty, bool firstDone, string& mostcustomer, int& mosteatenquantity, string& leastcustomer, int& leasteatenquantity);
template <typename T>
void customereatagain(MyQueue<T>& queue, int cust, int eaten_popplers, int qty, string& mostcustomer, int& mosteatenquantity, int newqty);
template <typename T>
void generateNumbers(MyQueue<T>& queue, int customers, int& randNumbers, int* &arrayNumbers, bool firstNumbers);

#include "restaurantsoperations.hpp"
#endif
