//
//  netaddress.cpp
//  c++networking
//
//  Created by NandN on 2017/09/13.
//  Copyright © 2017 NandN. All rights reserved.
//


#include "netaddress.h"


void CNetAddr::Init()
{
    
    //set the first num bytes of the block of memory.
    //set value 0 in ip
    memset(ip, 0, sizeof(ip));
    scopeId = 0;
}


void CNetAddr::SetIP(const CNetAddr& ipIn)
{
    memcpy(ip, ipIn.ip, sizeof(ip));
    //check the input match the size
}


