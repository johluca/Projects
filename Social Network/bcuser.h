#ifndef BCUSER_H
#define BCUSER_H
#include "user.h"
#include "llist.h"
#include <string>
#include <iostream>


class BCUser : public User {
public:
    BCUser (int val, std::string name, int age, int zip);
    void setDist (int dist_);
    int getDist ();
    void setNum_sp (double _num_sp);
    double getNum_sp ();
    double getDelta ();
    void setDelta (double _delta);
    double getBc();
    void setBc(double _bc);
    void clearPreds();
    void pushPreds(int val);
    MyList<int> getPreds();
private:
    int dist; //distance to current source vertex
    double num_sp; //number of shortest paths
    MyList<int> preds; //list of predeccesors
    double delta; //partial BC score
    double bc; //total BC score
};


#endif
