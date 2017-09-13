//
//  main.cpp
//  c++networking
//
//  Created by NandN on 2017/09/06.
//  Copyright © 2017 NandN. All rights reserved.
//

#include "main.h"

#include <iostream>


#include <miniupnpc/miniwget.h>
#include <miniupnpc/miniupnpc.h>
#include <miniupnpc/upnpcommands.h>
#include <miniupnpc/upnperrors.h>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/thread.hpp>




bool fDiscover = true;
bool fListen = true;

//check bitcoind for entry point.
bool AppInit(int argc, char* argv[])
{
    boost::thread_group threadGroup;
    CScheduler scheduler;
    
    
    return AppInitMain(threadGroup, scheduler);
}

bool AppInitMain(boost::thread_group& threadGroup, CScheduler& scheduler)
{
    
}


int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    unsigned char ip[16];
    std::cout << ip;
    
    return (AppInit(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
    
}
