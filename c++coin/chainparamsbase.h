//
//  chainparambase.h
//  c++coin
//
//  Created by NandN on 2017/09/14.
//  Copyright © 2017 NandN. All rights reserved.
//
#include <memory>
#include <string>
#include <vector>



/**
 * CBaseChainParams defines the base parameters (shared between bitcoin-cli and bitcoind)
 * of a given instance of the Bitcoin system.
 */
class CBaseChainParams
{
public:
    /** BIP70 chain name strings (main, test or regtest) */
    static const std::string MAIN;

    const std::string& DataDir() const { return strDataDir; }
    int RPCPort() const { return nRPCPort; }
    
protected:
    CBaseChainParams() {}
    
    int nRPCPort;
    std::string strDataDir;
};

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CBaseChainParams& BaseParams();
