#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "user.h"


User::User(int id, string name, int age, int zip)//constructor for social network
{
    idNum_ = id;
    name_ = name;
    age_ = age;
    zip_ = zip;
}

User::User(){

}

User::~User(){
    
}

string User::getName(){
    return name_;
}

void User::setName(string name) {
    name_=name;
}

void User::setAge(int age){
    age_=age;
}

int User::getAge(){
    return age_;
}

void User::setZip(int zip){
    zip_=zip;
}

int User::getZip(){
    return zip_;
}

void User::setIdNum(int idNum){
    idNum_=idNum;
}

int User::getIdNum(){
    return idNum_;
}

void User::addFriend(int friendsId){
    friends_.pushBack(friendsId);
}

MyList<int>& User::getFriendId(){
    return friends_;
}

void User::printUser(){
    cout<<"User Name: "<< getName()<<endl;
    cout<<"User Age: "<< getAge()<<endl;
    cout << "User Friends: ";
    for (int i=0; i<friends_.size(); i++){
        
        cout<< friends_.at(i)<<" ";
    }
    cout << endl;
    cout << endl;
}



