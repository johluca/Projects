//
//  Lab03.cpp
//  
//
//  Created by Jack Lucas on 1/27/13.
//
//
#include <string>;
#include <vector>;
#include <iostream>;
using namespace std;

const int DEFAULT_LIST_SIZE = 100;

class ListString {
    
private:
    int size_; //understand current size of list
    string* data_;
    int capacity_; //what list can hold
public:
    void pushBack(string);
    ListString();
    ListString(int capacity);
    ~ListString();
    int size() const;
    string at(int loc) const;
    
};

void ListString::pushBack(string val){
    if (size_ == capacity_){
        string* data= new string [size() * 2];
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

int ListString::size() const{
    return size_;
}

string ListString::at(int loc) const{
    if (loc>= size_ || loc<0)
        return NULL;            //stops user from accessing locations beyond List
    return data_[loc];
}

ListString::ListString(int capacity){
    capacity_=capacity;
    }
ListString::ListString(){
    size_ = 0;
    data_ = new string [DEFAULT_LIST_SIZE];
    capacity_=DEFAULT_LIST_SIZE;
    }
ListString::~ListString(){
    delete[] data_;
}
//from this point on I am creating the User Class

class User {
private:
    string name_;
    int age_;
    ListString friends_;
public:
    void setName(string name) {
        name_=name;
    }
    string getName(){
        return name_;
    }
    void setAge(int age){
        age_=age;
    }
    int getAge(){
        return age_;
    }
    void addFriend(string friendsName){
        friends_.pushBack(friendsName);
    }
    void printUser(){
        cout<<"User Name: "<< getName()<<endl;
        cout<<"User Age: "<< getAge()<<endl;
        cout << "User Friends: ";
        for (int i=0; i<friends_.size(); i++){
           
            cout<< friends_.at(i)<<" ";
        }
        cout << endl;
        cout << endl;
    }
};




int main ()
{
    string name;
    int age;
    string userName;
    string friendName;
    vector<User*> userList;
    User* u;
    
    while (true)
    {
        cout<< "Enter the first name and age separated by a space. type 'done' when you are done"<<endl;
        cin>>name; //input info on same line
        if (name=="done")
            break;
        cin>>age;
        u= new User();
        u->setName(name);
        u->setAge(age);
        userList.push_back(u);
        
    }
    
    while (true){
        cout<<"input user name and friend separated by a space. When finished type done"<< endl;
        cin>> userName;
        if (userName=="done" || friendName=="done")
            break;
        cin>> friendName;
        for (unsigned int j=0; j<userList.size(); j++){
            
            if (userList[j]->getName() == userName) {//iterate through vector until inputted name is found stored
                userList[j]->addFriend(friendName);
                cout<< friendName << " added to " <<userName << "'s friend list" << endl;
                break;
            }
        }
    }
    
    for (unsigned int i = 0; i<userList.size(); i++)
        userList[i]->printUser();


    
}


