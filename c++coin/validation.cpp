//
//  validation.cpp
//  c++coin
//
//  Created by NandN on 2017/09/21.
//  Copyright © 2017 NandN. All rights reserved.
//


#include "validation.h"
#include "util.h"
#include "checkqueue.h"



bool CScriptCheck::operator()() {
    const CScript &scriptSig = ptxTo->vin[nIn].scriptSig;
    const CScriptWitness *witness = &ptxTo->vin[nIn].scriptWitness;
    return VerifyScript(scriptSig, scriptPubKey, witness, nFlags, CachingTransactionSignatureChecker(ptxTo, nIn, amount, cacheStore, *txdata), &error);
}

static CCheckQueue<CScriptCheck> scriptcheckqueue(128);


void ThreadScriptCheck() {
    RenameThread("bitcoin-scriptch");
    scriptcheckqueue.Thread();
}
