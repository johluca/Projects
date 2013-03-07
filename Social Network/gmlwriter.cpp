#include "user.h"
#include "bcuser.h"
#include "gmlwriter.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void GMLWriter::write(char* n, MyList<BCUser*> list)
{
    ofstream outputFile;
    outputFile.open(n);
    if (outputFile.is_open())
    {
        outputFile<< "graph [\n";
        for (int i= 0; i<list.size(); i++)//gets info for each User
        {
            outputFile<<"  node ["<<endl;
            outputFile<<"    id "<<list[i]->getIdNum()<<endl;
            outputFile<<"    name \""<<list[i]->getName()<<"\""<<endl;
            outputFile<<"    age "<<list[i]->getAge()<<endl;
            outputFile<<"    zip "<<list[i]->getZip()<<endl;
            outputFile<<"  ]"<<endl;
        }
        
        for (int j = 0; j < list.size(); j++)
        {
            if (list[j]->getFriendId().size()!=0)//get info for each edge
            {
                for (int k=0; k<list[j]->getFriendId().size(); k++ ){
                outputFile<<"  edge ["<<endl;
                outputFile<<"   source "<< list[j]->getIdNum()<<endl;
                outputFile<<"   target "<< list[j]->getFriendId()[k]<<endl;
                outputFile<<"  ]"<<endl;
                }
            }
        }
        outputFile<<"]"<<endl;
        
        outputFile.close();
    }
}