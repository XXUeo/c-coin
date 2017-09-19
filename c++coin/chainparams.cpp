//
//  chainparams.cpp
//  c++coin
//
//  Created by NandN on 2017/09/14.
//  Copyright © 2017 NandN. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

#include "chainparams.h"
#include "chainparamsbase.h"

#include "util.h"

#include <assert.h>
const std::string CBaseChainParams::MAIN = "main";




/**
 * Main network
 */
class CBaseMainParams : public CBaseChainParams
{
public:
    CBaseMainParams()
    {
        nRPCPort = 8332;
    }
};

/**

static std::unique_ptr<CChainParams> globalChainParams;
//unique_ptr from <memory>.

const CChainParams &Params() { //&Params is guranteed to be non null.
    assert(globalChainParams);
    return *globalChainParams;
}


**/
