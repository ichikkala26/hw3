#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
  /*Heap<int> h1;
  
  h1.push(4);
  int top = h1.top();
  cout << "top: " << top << endl; //top: 4
  h1.push(2);
  top = h1.top();
  cout << "top: " << top << endl; //top: 4
  h1.push(7);
  top = h1.top();
  cout << "top: " << top << endl; //top: 4
  size_t heapSize = h1.size();
  cout << "size: " << heapSize << endl;

  h1.pop();
  top = h1.top();
  cout << "top: " << top << endl;
  heapSize = h1.size();
  cout << "size: " << heapSize << endl;
  top = h1.top();
  cout << "top: " << top << endl;*/

  Heap<int> heap(4);
  heap.push(4);
  heap.push(2);
  heap.push(7);
  heap.push(8);
  heap.push(5);

  int top = heap.top();
  cout << "top: " << top << endl;
  heap.pop();






}