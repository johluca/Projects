#include <iostream>
//#include "llist_sol.h"
#include "llist.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
//  LList<int> mylist;
//  mylist.push_back(5);
//  mylist.push_back(6);
//  mylist.push_back(7);
//  cout << "Front item is: " << mylist.peek_front() << endl;
//  cout << "Item at location 1 is " << mylist.at(2) << endl;
//
//  cout << "List contents (and removal)" << endl;
//  cout << "Size: " << mylist.size() << endl;
//  while(!mylist.empty()){
//    cout << mylist.peek_front() << endl;
//    mylist.pop_front();
//  }
    
    Queue<int> q1;
    Stack<int> s1;
    
    int input=0;
    int input2=0;
    int allowPop=0;

    while (input != 5)
    {
    cout << "Enter 1 to push to stack, 2 to pop and print top of stack, 3 to push to queue, 4 to pop and print front of queue, or 5 to exit" <<endl;
        
        cin >> input;
        if (input ==1 )
        {
            cout << "enter value to be pushed to stack " << endl;
            cin >> input2;
            s1.push(input2);
            allowPop++;
            
        }
        
        if (input == 2)
        {
            if (allowPop==0)
                cout<<"attempting to display size of empty stack"<<endl;
            else
            {
                
                cout << "top of stack after pop: "<< s1.top() << endl;
                s1.pop();
                allowPop--;
            }
            
        }
        
        if (input == 3)
        {
            cout << "enter value to be pushed back to queue " << endl;
            cin>> input2;
            q1.push_back(input2);
            allowPop++;
            
        }
        
        if (input == 4)
        {
            if (allowPop==0)
                cout << "attempting to display size of empty queue"<<endl;
           else
            {
                
                cout << "front of queue after pop: " << q1.front() << endl;
                q1.pop_front();
                allowPop--;
            }
            
        }
    }
    
//    s1.push_back(4);
//    s1.pop_front();
//
//    s1.pop_front();//this pops beyond size of list (which starts at size zero) without any seg fault
//
//    
//    for (int i = 0; i<5 ; i++)
//    {
//        s1.push_back(i);
//        cout<<"front of queue = "<< s1.front() << endl;
//        cout<< "back of queue = "<<s1.back() << endl;
//    }
//    while(!s1.empty())
//    {
//        cout<<"front of queue after pop = "<< s1.front() << endl;
//        s1.pop_front();
//    }
    
  return 0;
}
