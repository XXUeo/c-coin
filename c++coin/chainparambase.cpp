//
//  chainparambase.cpp
//  c++coin
//
//  Created by NandN on 2017/09/14.
//  Copyright © 2017 NandN. All rights reserved.
//


#include "chainparamsbase.h"
#include "util.h"
#include "tinyformat.h"
#include <assert.h>




static std::unique_ptr<CBaseChainParams> globalChainBaseParams;



const CBaseChainParams& BaseParams()
{
    assert(globalChainBaseParams);
    return *globalChainBaseParams;
}
