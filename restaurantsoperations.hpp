// hpp file for restaurantsoperation.h


#include <iostream>
using namespace std;


template <typename T>
void operations(MyQueue<T>& queue, int nbrCustomers)
{
  int total_quantity = 0;
  int least_eaten_quantity = 0;
  int most_eaten_quantity = 0;
  string most_customer;
  string least_customer;
  int new_qty = 0;
  int round = 0;

  int customers;
  bool morefood = false;
  bool anotheround = true;
  int newroundCustomers= 0;
  bool firstRound = true;
  bool first_cust_done = true;

  bool firstNumbers = true;
  int randNumbers;
  int* arrayNumbers;// for array of random numbers
  arrayNumbers = NULL;

  while (anotheround == true)
  {
    if (firstRound)
    {
      customers = nbrCustomers;
      firstRound = false;
    }
    else
      customers = newroundCustomers;
    randNumbers = 0;
    newroundCustomers = 0;
    round +=1;
    cout << "\nRound " << round <<endl;
    cout << endl;
    generateNumbers(queue, customers,randNumbers, arrayNumbers, firstNumbers);
    firstNumbers = false;

    for (int i=0;i<customers;i++)
    {
      eat(queue, i, queue[i].m_quantity, total_quantity);
      morefood = eatagain(new_qty, queue[i].m_quantity, randNumbers, arrayNumbers);
      if (!morefood)
      {
        customerdone(queue,i, queue[i].m_eaten_popplers, queue[i].m_quantity, first_cust_done, most_customer, most_eaten_quantity, least_customer, least_eaten_quantity);
        first_cust_done = false;
        i--;
        customers--;
      }
      else
      {
        customereatagain(queue,i,queue[i].m_eaten_popplers, queue[i].m_quantity, most_customer, most_eaten_quantity, new_qty);
        newroundCustomers += 1;
        i--;
        customers--;
      }

      if (queue.isEmpty())
        anotheround = false;
    }
  }
  finalresult(total_quantity, most_customer, most_eaten_quantity, least_customer, least_eaten_quantity);
  delete [] arrayNumbers;
  arrayNumbers = NULL;

  return;
}

template <typename T>
void generateNumbers(MyQueue<T>& queue, int customers, int& randNumbers, int* &arrayNumbers, bool firstNumbers)
{
  randomEngine re;
  for (int i = 0; i < customers; i++)
    randNumbers += ((queue[i].m_quantity + 4)/5)*5;

  if (!firstNumbers)
    delete [] arrayNumbers;
  arrayNumbers = new int[randNumbers];

  for (int i = 0; i < randNumbers; i++)
    arrayNumbers[i] = re.rollD(6);

  return;
}

template <typename T>
void eat(MyQueue<T>& queue, int cust, int qty, int& total_qty)
{
  int qtytoeat = ((qty+4)/5) * 5;
  queue[cust].m_eaten_popplers += qtytoeat;
  total_qty += qtytoeat;
  return;
}

// generates a new quantity for the customer, update the randNumbers array
bool eatagain(int& newqty, int qty,int &randNumbers, int* &arrayNumbers)
{
  int sixes = 0;
  int qtytoeat = ((qty + 4)/5)*5;

  for (int k = 0; k< qtytoeat; k++)
  {
    if (arrayNumbers[k] == 6)
      sixes += 1;
  }

  newqty = sixes;
  int* temp = new int[randNumbers-qtytoeat];

  for (int k = 0; k <(randNumbers-qtytoeat); k++)
     temp[k] = arrayNumbers[k+qtytoeat];

  delete [] arrayNumbers;
  arrayNumbers = new int[randNumbers-qtytoeat];

  for (int k = 0; k < (randNumbers-qtytoeat); k++)
    arrayNumbers[k] = temp[k];

  delete [] temp;

  randNumbers = randNumbers - qtytoeat;
  if (sixes > 0)
    return true;
  else
    return false;
}

template <typename T>
void customerdone(MyQueue<T>& queue, int cust, int eaten_popplers, int qty, bool firstDone, string& mostcustomer, int& mosteatenquantity, string& leastcustomer, int& leasteatenquantity)
{
  if (firstDone)
  {
    leastcustomer = queue[cust].m_name;
    leasteatenquantity = eaten_popplers;
  }

  if ((eaten_popplers) > mosteatenquantity)
  {
    mostcustomer = queue[cust].m_name;
    mosteatenquantity = eaten_popplers;
  }
  cout << queue[cust].m_name << " eats " << ((qty+4)/5)*5 <<" popplers. " << queue[cust].m_name << " is satisfied after eating " << eaten_popplers << " popplers.";
  cout << endl;
  queue.dequeue();
  return;
}

template <typename T>
void customereatagain(MyQueue<T>& queue, int cust, int eaten_popplers, int qty, string& mostcustomer, int& mosteatenquantity, int newqty)
{
  if ((eaten_popplers) > mosteatenquantity)
  {
    mostcustomer = queue[cust].m_name;
    mosteatenquantity = eaten_popplers;
  }
  cout << queue[cust].m_name << " eats " << ((qty+4)/5)*5 <<" popplers. " << queue[cust].m_name << " wants ";
  (newqty==1)?cout<<"one poppler.":cout<<newqty<<" popplers.";
  cout << endl;

  T newstruct;
  newstruct.m_name = queue[cust].m_name;
  newstruct.m_quantity = newqty;
  newstruct.m_eaten_popplers = eaten_popplers;

  queue.dequeue();
  queue.enqueue(newstruct);
  return;
}

void finalresult(int totqty, string mostcustomer, int mosteatenquantity, string leastcustomer, int leasteatenquantity)
{
  cout << "\nA total of " << totqty << " popplers were eaten." << endl;
  cout << mostcustomer << " ate the most popplers: " << mosteatenquantity << endl;
  cout << leastcustomer <<" ate the fewer popplers: " << leasteatenquantity << endl;
  return;
}
