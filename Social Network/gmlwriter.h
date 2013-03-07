#ifndef GML_WRITER_H
#define GML_WRITER_H
#include "bcuser.h"
#include "user.h"
#include <iostream>
#include <string>
#include "mylist.h"
using namespace std;

class GMLWriter{

private:
    
public:
    void write(char* n, MyList<BCUser*>);
    
};




#endif
