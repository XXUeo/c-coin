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


static std::unique_ptr<CChainParams> globalChainParams;
//unique_ptr from <memory>.

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}
