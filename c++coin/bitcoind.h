//
//  main.h
//  c++networking
//
//  Created by NandN on 2017/09/12.
//  Copyright © 2017 NandN. All rights reserved.
//

#ifndef bit_main_h
#define bit_main_h

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
    
    
    
    
    
};

#endif
