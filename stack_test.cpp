#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
  /*Stack<int> d;
  d.push(3);
  d.push(4);
  d.push(5);

  int top = d.top();
  cout << top << endl;
  d.pop();
  top = d.top();
  cout << top << endl;
  d.push(6);
  top = d.top();
  cout << top << endl;
  d.pop();
  d.pop();
  d.pop();
  bool isEmpty = d.empty();
  cout<< isEmpty << endl;
  try {
    d.pop();
  }
  catch(std::underflow_error& e)
  {
    cerr << e.what() <<endl;
    return -1;
  }*/
  //std::cout << d.pop() << std::endl;
  //std::cout << d.top() << std::endl;


  Stack<string> d;
  d.push("hello");
  d.push("hi");
  d.push("my name");

  string top = d.top();
  cout << top << endl;
  d.pop();
  top = d.top();
  cout << top << endl;
  d.push("heyo");
  top = d.top();
  cout << top << endl;
  d.pop();
  d.pop();
  d.pop();
  bool isEmpty = d.empty();
  cout<< isEmpty << endl;
  try {
    d.pop();
  }
  catch(std::underflow_error& e)
  {
    cerr << e.what() <<endl;
    return -1;
  }
}