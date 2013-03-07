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
#include <stdexcept>
using namespace std;

int main(){
    MyList<int> intList;
    MyList<string> stringList;
    int b;
    cin>>b;
    intList.pushBack(1);
    intList.pushBack(7);
    intList.pushBack(3);
    
    stringList.pushBack("my");
    stringList.pushBack("name");
    stringList.pushBack("is");
    try{
        intList.at(b);
        intList.pop(1);
    }
    catch(invalid_argument& ia){
        cerr<<ia.what()<<endl;
    }
    
    
    
    
    stringList.remove("is");
    
    for (int i=0; i<intList.size(); i++)//check if data is entered correctly
        cout<<intList.at(i)<<endl;
    for (int j=0; j<stringList.size(); j++)
        cout<<stringList.at(j)<<endl;
}