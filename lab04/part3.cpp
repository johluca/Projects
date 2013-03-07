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
    intList.pushBack(1);
    intList.pushBack(7);
    intList.pushBack(3);
    int x=intList[0];
    intList[0]=76;
    int b;
    cin>>b;
    intList.pop(b);
    cout<<"TEST="<<x<<endl;//should state TEST=1 b/c 1 is at first position in intList
    
    
    stringList.pushBack("my");
    stringList.pushBack("name");
    stringList.pushBack("is");
//        try{
//        }
//        catch(invalid_argument& ia){
//            cerr<<ia.what()<<endl;
//        }
    
    
    
    
    stringList.remove("is");
    
    for (int i=0; i<intList.size(); i++)//check if data is entered correctly
        cout<<intList[i]<<endl;
    for (int j=0; j<stringList.size(); j++)
        cout<<stringList[j]<<endl;
}