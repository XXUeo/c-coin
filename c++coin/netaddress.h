//
//  netaddress.h
//  c++networking
//
//  Created by NandN on 2017/09/13.
//  Copyright © 2017 NandN. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

enum Network
{
    NET_IPV4,
    NET_IPV6
};

class CNetAddr
{
protected:
    unsigned char ip[16];
    uint32_t scopeId;
    
public:
    CNetAddr();
    void Init();
    void SetIP(const CNetAddr& ip);//default
    
    
    
    
    
};


