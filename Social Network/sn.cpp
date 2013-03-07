#include <iostream>
#include <fstream>
#include <sstream>
#include "gmlreader.h"
#include "user.h"
#include <string>
#include "mylist.h"
#include "gmlwriter.h"

int main()
{
    return 0;
}
//// Add appropriate headers here
//
//using namespace std;
//
//int attributeOrder(string str){ //function that defines what part of user is being defined
//    if (str=="id")
//        return 1;
//    if (str=="name")
//        return 2;
//    if (str=="age")
//        return 3;
//    if (str=="zip")
//        return 4;
//    else
//        return -1;
//    
//}
//
//int main(int argc, char *argv[])
//{
//  if(argc < 4){//ensures correct number of arguments are given to main
//    cerr << "Please provide the input GML file, command file, and output file" << endl;
//    return 1;
//  }
//    fstream inputFile;
//    inputFile.open(argv[1]);
//    if (inputFile.fail()){//ensures that input GML file exists
//        cerr<<"Cannot open GML input file"<<endl;
//        return 1;
//    }
//
//    
//    MyList<User*> userList;
//    vector<string> nodes;
//    vector<string> edges;
//    
//    GMLReader reader;
//    reader.read(argv[1], nodes, edges);//calls GMLReader class to read input file
//    
//    GMLWriter writer;
//    
//    string temp;
//    string name;
//    int id, age, zip, source, target;
//    
//    //populate nodes with correct info regardless of order it is input
//    
//    for (unsigned int i = 0; i < nodes.size(); i++) {
//        stringstream s(nodes[i]);
//        for (int k = 0; k < 4; k++) {
//            getline(s, temp, ' ');
//            switch(attributeOrder(temp))
//            {
//                case 1:
//                    s >> id;
//                    getline(s, temp, ' ');
//                    break;
//                case 2:
//                    getline(s, temp, '\"');
//                    getline(s, name, '\"');
//                    getline(s, temp, ' ');
//                    break;
//                case 3:
//                    s >> age;
//                    getline(s, temp, ' ');
//                    break;
//                case 4:
//                    s >> zip;
//                    getline(s, temp, ' ');
//                    break;
//            }
//        }
//        userList.pushBack(new User(id, name, age, zip));//add User pointer to MyList of User pointers
//    }
//
//    
//    for (unsigned int j = 0; j< edges.size(); j++)//gives each user specified edge connections from input file
//    {
//        stringstream e(edges[j]);
//        getline(e, temp, ' ');
//        e >> source;
//        getline(e, temp, ' ');
//        getline(e, temp, ' ');
//        e >> target;
//        
//        userList[source]->addFriend(userList[target]->getIdNum());
//        
//
//    }
//    //Below is process for using command file to add or remove friends
//    string temp2;
//    string action;
//    string name1;
//    string name2;
//    ifstream commandFile (argv[2]);
//    
//    if (commandFile.is_open())//verifying input file is good
//    {
//        while (!commandFile.eof())
//        {
//            getline(commandFile, action, ' ');
//            getline(commandFile, temp2, '\"');
//            getline(commandFile, name1, '\"');
//            getline(commandFile, temp2, '\"');
//            getline(commandFile, name2, '\"');
//            getline(commandFile, temp2);
//            //if action is not "a" or "r", that line in commands wiil be skipped and this while loop will start over on next line dure to if statements specifications
//            
//            //add friend action below
//            if (action=="a")
//            {
//                for (int i=0; i<=userList.size(); i++)
//                {
//                    if (i==userList.size())//checks if user name exists
//                    {
//                        cout<<"User "<<name1<< " does not exist."<<endl;
//                    }
//                    else if (userList[i]->getName()==name1)
//                    {
//                        for (int j=0; j<=userList.size(); j++)
//                        {
//                            if (j==userList.size())//checks if user to be added exists
//                            {
//                                cout<<"User "<<name2<< " does not exist."<<endl;
//                            }
//                            else if (userList[j]->getName()==name2)
//                            {
//                                userList[i]->getFriendId().pushBack(userList[j]->getIdNum());//connects first user to second user and vice versa
//                                userList[j]->getFriendId().pushBack(userList[i]->getIdNum());
//                                break;
//                            }
//                        }
//                        break;
//                    }
//                }
//            }
//            //remove friend action below
//            if (action=="r"){
//                for (int i=0; i<=userList.size(); i++)
//                {
//                    if (i==userList.size())//checks if user name exists
//                    {
//                        cout<<"User "<<name1<< " does not exist."<<endl;
//                    }
//                    else if (userList[i]->getName()==name1)
//                    {
//                        
//                        for (int j=0; j<userList.size(); j++)
//                        {
//                            if (j==userList.size())//checks if user to be removed exists
//                            {
//                                cout<<"User "<<name2<< " does not exist."<<endl;
//                            }
//                            else if (userList[j]->getName()==name2)
//                            {
//                                userList[i]->getFriendId().remove(userList[j]->getIdNum());//removes second user from first user and vice versa
//                                userList[j]->getFriendId().remove(userList[i]->getIdNum());
//                                break;
//                            }                            
//                        }
//                        break;
//                    }
//                }
//            }
//        }//end of while
//    }
//    else
//        cerr<<"Cannot open the command file"<<endl;
//    
//    //create new GML file with current nodes and edges in correct format
//    writer.write(argv[3], userList);
//    
//
//
//  return 0;
//}
