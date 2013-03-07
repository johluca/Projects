#include <iostream>
#include <fstream>
#include <sstream>
#include "gmlreader.h"
#include "user.h"
#include <string>
#include "mylist.h"
#include "gmlwriter.h"
#include "queue.h"
#include "stack.h"


using namespace std;


class BCAlg//class that has members for finding and normalizing BC scoresg
{
public:
    MyList<double>* computeBC(MyList<BCUser*> &userList, char* n);//primary algorithm
    BCUser* findFriend(MyList<BCUser*> &userList, int id);//find user (friend) based off of ID number
    MyList<double>* normalizeBC(MyList<double>* list);//returns normalized BC score
    void writing(char* n, MyList<BCUser*> list, MyList<double>* normalizeList);//create output file
};

//================================================================================

void BCAlg :: writing(char* n, MyList<BCUser*> list, MyList<double>* normalizeList)
{
    ofstream outputFile;
    outputFile.open(n);
    if (outputFile.is_open())
    {
        for (int i = 0; i < list.size(); i++)//go through each BCUser
        {
            outputFile<< "USER ID: " << list[i]->getIdNum() << " BC SCORE: "<< normalizeList->at(i)  <<endl;
        }
        outputFile.close();
    }
}

//================================================================================

BCUser* BCAlg :: findFriend(MyList<BCUser*> &userList, int id) //find friend based off id number
{
    for (int i = 0; i<userList.size(); i++)
    {
        if (userList[i]->getIdNum() == id) 
            return userList[i];
    }
    return NULL;
}

//================================================================================

MyList<double>* BCAlg :: normalizeBC(MyList<double>* list)
{

        
    MyList<double>* listNorm = new MyList<double>();//create list for normalized scores
    double score = list->at(0);
    double min = score;
    double max = score;
    
    for (int i = 0; i < list->size(); i++)//find min
    {
        if (list->at(i) < min)
            min = list->at(i);
    }
    
    for (int j = 0; j< list->size(); j++)//find max
    {
        if (list->at(j) > max)
            max = list->at(j);
    }
            for (int n=0; n<list->size(); n++)
            {
                score = list->at(n);
                


                listNorm->pushBack((score - min) / (max - min));//push normalized score into list
                cout << "SCORE" << score <<endl;
                cout << "MAX" << max <<endl;
                cout << "MIN" << min <<endl;
                cout<<"NORMALIZED "<< n <<": " <<listNorm->at(n)<<endl;
            }//end for
    
    return listNorm;
}

//================================================================================

MyList<double>* BCAlg::computeBC(MyList<BCUser*> &userList, char* n)
{
    BCUser* s; //source
    BCUser* v; //vertex
    BCUser* w; //friends
    BCUser* t; //target
    Stack<BCUser*> stack;
    Queue<BCUser*> queue;
    int listSize = userList.size();//this way, userlist's size is only calculated once eg. faster

    
    for (int i=0; i<listSize; i++)//betweeness centrality initialized at zero for all
    {
        v = userList[i];
        v->setBc(0);
    }
    //try with one node before all
    for (int j = 0; j<listSize; j++)//picks source node
    {
        cout<<"Calculating User "<< j + 1 << " of "<< listSize << endl;
        for (int k = 0; k<listSize; k++)
        {
            t = userList[k];//set t as target vertex
            t->clearPreds();
            t->setNum_sp(0);
            t->setDist(-1);
            t->setDelta(0.0);
            
        }//end of third for
        //initialize all nodes to same values so finding new nodes is easier
        s= userList[j];
        s->setNum_sp(1);
        s->setDist(0);
        stack.clear();
        queue.clear();
        queue.push_back(s);
        
        while (!queue.empty())
        {
            v = queue.front();
            queue.pop_front();
            stack.push(v);//put elements of queue into stack to be analyzed
            for ( int l = 0; l< v->getFriendId().size(); l++)
            {
                w = findFriend(userList, v->getFriendId()[l]);
                if (w->getDist()==-1)//if source user's friend hasnt been found
                {
                    queue.push_back(w);
                    w->setDist(v->getDist()+1);
                }
                if (w->getDist()==v->getDist()+1)//if vertex is next in line
                {
                    w->setNum_sp(w->getNum_sp()+v->getNum_sp());
                    w->pushPreds(v->getIdNum());
                }
            }
        }//end of while
        while (!stack.empty())
        {
            w = stack.top();
            stack.pop();//look through organized data in queue one by one
            for (int n=0; n< w->getPreds().size(); n++)
            {
                v = findFriend(userList, w->getPreds()[n]);
                v->setDelta(v->getDelta() + ((v->getNum_sp()/w->getNum_sp()) * (1 + w->getDelta())));
            }
            w->setBc(w->getBc() + w->getDelta());
        }
    }//end of second for
    MyList<double>* list= new MyList<double>;//create list of BC scores to be normalized

    for (int g = 0; g < listSize; g++)
    {
        list->pushBack(userList[g]->getBc());//put BC score in list
    }
    writing( n, userList, normalizeBC(list));
    return list;
}//end of algorithm

//================================================================================
//================================================================================

int attributeOrder(string str){ //function that defines what part of user is being defined
    if (str=="id")
        return 1;
    if (str=="name")
        return 2;
    if (str=="age")
        return 3;
    if (str=="zip")
        return 4;
    else
        return -1;
    
}
//================================================================================
//MAIN
//================================================================================

int main(int argc, char *argv[])
{
  if(argc < 3){//ensures correct number of arguments are given to main
    cerr << "Please provide the input GML file, command file, and output file" << endl;
    return 1;
  }
    fstream inputFile;
    inputFile.open(argv[1]);
    if (inputFile.fail()){//ensures that input GML file exists
        cerr<<"Cannot open GML input file"<<endl;
        return 1;
    }
    
    BCAlg alg;

    
    MyList<BCUser*> userList;
    vector<string> nodes;
    vector<string> edges;
    
    GMLReader reader;
    reader.read(argv[1], nodes, edges);//calls GMLReader class to read input file
    
    
    string temp;
    string name;
    int id, age, zip, source, target;
    
    //populate nodes with correct info regardless of order it is input
    
    for (unsigned int i = 0; i < nodes.size(); i++) {
        stringstream s(nodes[i]);
        for (int k = 0; k < 4; k++) {
            getline(s, temp, ' ');
            switch(attributeOrder(temp))
            {
                case 1:
                    s >> id;
                    getline(s, temp, ' ');
                    break;
                case 2:
                    getline(s, temp, '\"');
                    getline(s, name, '\"');
                    getline(s, temp, ' ');
                    break;
                case 3:
                    s >> age;
                    getline(s, temp, ' ');
                    break;
                case 4:
                    s >> zip;
                    getline(s, temp, ' ');
                    break;
            }
        }
        userList.pushBack(new BCUser(id, name, age, zip));//add User pointer to MyList of User pointers
    }

    
    for (unsigned int j = 0; j< edges.size(); j++)//gives each user specified edge connections from input file
    {
        stringstream e(edges[j]);
        getline(e, temp, ' ');
        e >> source;
        getline(e, temp, ' ');
        getline(e, temp, ' ');
        e >> target;
        
        userList[source]->addFriend(userList[target]->getIdNum());
        

    }
    //Below is process for using command file to add or remove friends
    string temp2;
    string action;
    string name1;
    string name2;
    
    alg.computeBC(userList, argv[2]);
    
    


  return 0;
}
