#ifndef MYLIST_H
#define MYLIST_H


#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

const int DEFAULT_LIST_SIZE = 100;

template <class Type>
class MyList{
    
 private:
  int size_; //understand current size of list
  Type* data_;
  int capacity_; //what list can hold
    
 public:
  void pushBack(Type val);
  MyList();
  MyList(int capacity);
  ~MyList();
  int size() const;
  Type& operator[](int loc) const;
  Type& at(int loc) const;
  bool remove(Type item);
  Type pop(int loc);
    void clear();
    
};
template <class Type>
void MyList<Type>::pushBack(Type val){
  if (size_ == capacity_){
    Type* data= new Type [size() * 2];
    for (int i=0; i<size(); i++){ //makes new array, copies over values, and deletes old array
      data[i]=data_[i];
    }
        
    capacity_=size() * 2;
    delete[] data_;
    data_=data;
  }
    
  data_[size_]= val;
  size_++;
    
}

template <class Type>
int MyList<Type>::size() const{
  return size_;
}

template <class Type>
Type& MyList<Type>::at(int loc) const{
  if (loc>= size_ || loc<0)
    throw invalid_argument("error: attempt to access location beyond list");          //stops user from accessing locations beyond List
  return data_[loc];
}

template <class Type>
Type& MyList<Type>::operator[](int loc) const{//overload [] operator to return value at [loc]
  try {
    if (loc>= size_ || loc<0)
      throw invalid_argument("error: attempt to access location beyond list");
  }
  catch (invalid_argument& ia){
    cerr<<ia.what()<<endl;
  }//stops user from accessing locations beyond List
  return data_[loc];
}

template <class Type>
MyList<Type>::MyList(int capacity){
  capacity_=capacity;
}
template <class Type>
MyList<Type>::MyList(){ //default constructor
  size_ = 0;
  data_ = new Type [DEFAULT_LIST_SIZE];
  capacity_=DEFAULT_LIST_SIZE;
}
template <class Type>
MyList<Type>::~MyList(){
    data_ = NULL;
    delete[] data_;
}

template <class Type>
bool MyList<Type>::remove(Type item){
  for (int i=0; i<size(); i++){
    if (data_[i]==item){
      size_--;//account for loss of one item from list
      for (int j=i; j<size(); j++)
          data_[j]=data_[j+1];
      return true;
    }
  }
        
  cout<<"item not found"<<endl;
  return false;
}

template <class Type>
Type MyList<Type>::pop(int loc){
  try {
    if (loc<0 || loc>size_)
      throw invalid_argument("error: attempt to access location beyond list");
    size_--;
    cout<<"size is "<<size_<<endl;
    for (int i=loc; i<size_; i++)
      data_[i]=data_[i+1];
    return data_[loc];
  }
  catch (invalid_argument& ia){
    cerr<<ia.what()<<endl;
  }
}
      
template <class Type>
void MyList<Type>::clear(){
    delete [] data_;
    capacity_ = 1;
    data_ = new Type [1];
    size_=0;
}




#endif
