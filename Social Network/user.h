#ifndef USER_H
#define USER_H
#include "mylist.h"



class User {
protected:
    string name_;
    int age_;
    int zip_;
    int idNum_;
    MyList<int> friends_;//collection of User's friend's identified by ID number
//    MyList<string> friends_;

public:
    User(int id, string name, int age, int zip);
    User();
    ~User();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setZip(int zip);
    int getZip();
    void setIdNum(int idNum);
    int getIdNum();
    void addFriend(int friendsId);
    MyList<int>& getFriendId();
    void printUser();
};




#endif
