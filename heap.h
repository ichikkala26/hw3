#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <cmath>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> myHeapVec;
  void trickleUp(int loc);
  int m_;
  void heapify(int idx);
  PComparator c_;
  void mySwap(T& a, T& b);



};

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c):
  m_(m),c_(c)
{

}

//destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{ 
  
}


// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::mySwap(T& a, T& b)
{
  T tmp=a;
  a=b;
  b=tmp;
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return myHeapVec.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

  throw std::underflow_error("Topping on an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return myHeapVec[0];
  }


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  unsigned int leftChild = (idx*m_) + 1;

  //checking if index is child
  if(leftChild>=myHeapVec.size())
  {
    return;
  }
  else
  { 
    int numOfComparisons = m_ - 1;
    //int leftChild = m_*idx - 1;
    unsigned int currChild = leftChild;
    unsigned int bestChild = leftChild;

      while(numOfComparisons>0 && currChild<=myHeapVec.size()-1)
      {
        currChild = currChild + 1;
        if(c_(myHeapVec[currChild],myHeapVec[bestChild]))
        {

          bestChild = currChild;
        }
        numOfComparisons--;
      }

    if(c_(myHeapVec[bestChild],myHeapVec[idx]))
    {
      mySwap(myHeapVec[bestChild], myHeapVec[idx]);
      heapify(bestChild);
    }
    else
    {
      return;
    }
  }

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("Popping on an empty heap");

  }
  else
  {
    myHeapVec[0] = myHeapVec.back();
    myHeapVec.pop_back();
    heapify(0);

  }

}



template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(myHeapVec.empty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  myHeapVec.push_back(item);
  trickleUp(myHeapVec.size()-1);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
  if(loc>0)
  {
    int parent = (int) ((loc-1)/m_);
    while(parent>=0 && c_(myHeapVec[loc],myHeapVec[parent]))
    {
      mySwap(myHeapVec[loc],myHeapVec[parent]);
      loc = parent;
      parent = (int) ((loc-1)/m_);
      if(parent<0)
      {
        break;
      }

    }
  }
  else if(loc==0)
  {
    return;
  }

}


#endif

