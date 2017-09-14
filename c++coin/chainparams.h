//
//  chainparams.h
//  c++coin
//
//  Created by NandN on 2017/09/14.
//  Copyright © 2017 NandN. All rights reserved.
//



#include <memory>
#include <vector>

//create inheritance class for main chain


class CChainParams
{

};

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CChainParams &Params();


