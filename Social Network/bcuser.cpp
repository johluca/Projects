#include "bcuser.h"
#include <iostream>



BCUser::BCUser (int id, std::string name, int age, int zip) : User (id, name, age ,zip)
{}

void BCUser::setDist (int dist_)
{
    dist=dist_;
}

int BCUser::getDist ()
{
    return dist;
}

void BCUser::setNum_sp (double _num_sp)
{
    num_sp=_num_sp;
}

double BCUser::getNum_sp ()
{
    return num_sp;
}

double BCUser::getDelta ()
{
    return delta;
}

void BCUser::setDelta (double _delta)
{
    delta=_delta;
}

double BCUser::getBc()
{
    return bc;
}

void BCUser::setBc (double _bc)
{
    bc=_bc;
}

void BCUser::clearPreds()
{
    preds.clear();
}

void BCUser::pushPreds(int val)
{
    for (int i=0; i<preds.size(); i++)
    {
        if (preds.at(i) == val)
            return;
    }
    
    preds.pushBack(val);
    
}

MyList<int> BCUser::getPreds()
{
    return preds;
}
