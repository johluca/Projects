//
//  part1.cpp
//  
//
//  Created by Jack Lucas on 2/3/13.
//
//

#include "mylist.h"
#include <string>;
#include <vector>;
#include <iostream>;
using namespace std;

int main(){
    MyList<int> intList;
    MyList<string> stringList;
    
    
    intList.pushBack(1);
    intList.pushBack(7);
    intList.pushBack(3);
    
    stringList.pushBack("hello");
    stringList.pushBack("there");
    stringList.pushBack("Friend!");
    
    for (int i=0; i<intList.size(); i++)//check if data is entered correctly
        cout<<intList.at(i)<<endl;
    for (int j=0; j<stringList.size(); j++)
        cout<<stringList.at(j)<<endl;
}