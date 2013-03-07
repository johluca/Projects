#ifndef LLIST_H
#define LLIST_H
#include <stdexcept>
#include <iostream>

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void push_back(const T& new_val);
    void push_front(const T& new_val); //created to handle push in stack
  void pop_front();
  T& peek_front() const;
    T& peek_back() const;
  T& at(int loc) const;
  //bool remove(const T& val);
  void clear();
    
 private:
  Item<T> *getNodeAt(int loc) const;
    int size_;
 private:
  Item<T> *head_, *tail_;

};

// Write the constructor here
template <typename T>
LList<T>::LList()
{
    head_=NULL;
    tail_=NULL;
    size_=0;
    
}




// Write the destructor here
template <typename T>
LList<T>::~LList()
{
  clear();
}





template <typename T>
bool LList<T>::empty() const
{
    return head_==NULL;

}

template <typename T>
int LList<T>::size() const
{

    return size_;


}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
    if (loc<0 || loc>size_)
        throw std::invalid_argument("Invalid Location");//ensures location exists in linked list
    Item<T>* temp=head_;
    
    while (temp!= NULL && loc>0)
    {
        temp=temp->next;
        loc--;
    }
    return temp;

}

template <typename T>
void LList<T>::push_back(const T& new_val)
{
    Item<T>* newNode;
    newNode = new Item<T>;
    newNode->val = new_val;
    newNode->next = NULL;
    
    if (head_== NULL)//sets head and tail equal to push back value if list is empty
    {
        head_= newNode;
        tail_= newNode;
    }
    else
    {
        tail_->next=newNode;
        tail_=tail_->next;
    }
    size_++;

}

template <typename T>
void LList<T>::push_front(const T& new_val)
{
    Item<T>* newNode;
    newNode = new Item<T>;
    newNode->val = new_val;
    newNode->next = NULL;
    
    if (head_== NULL)//sets head and tail equal to push front value if list is empty
    {
        head_= newNode;
        tail_= newNode;
    }
    
    else
    {
        newNode->next=head_;
        head_=newNode;
    }
    size_++;
    
}

template <typename T>
void LList<T>::pop_front()
{
    if (size_<=0)//if user pops empty list, will still function
        return;
    else
    {
        head_=head_->next;
       
    }
     size_--;

}

template <typename T>
T& LList<T>::peek_front() const
{

    return head_->val;

}


template <typename T>
T& LList<T>::peek_back() const
{
    return tail_->val;
}

//template <typename T>
//bool LList<T>::remove(const T& val)
//{
//
//}

template <typename T>
T& LList<T>::at(int loc) const
{
    return getNodeAt(loc)->val;
    
}


template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}


#endif
