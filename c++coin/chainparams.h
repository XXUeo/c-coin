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
 * Creates and returns a std::unique_ptr<CChainParams> of the chosen chain.
 * @returns a CChainParams* of the chosen chain.
 * @throws a std::runtime_error if the chain is not supported.
 */
//by using const, it can maintain the ownership with the passed arguents.
std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain);



/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CChainParams &Params();


