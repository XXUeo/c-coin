//
//  init.cpp
//  c++coin
//
//  Created by NandN on 2017/09/14.
//  Copyright © 2017 NandN. All rights reserved.
//

#include "init.h"
#include "chainparams.h"
#include "fs.h"
#include "util.h"
#include "tinyformat.h"
#include "ui_interface.h"
#include "script/sigcache.h"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/bind.hpp>
#include <boost/interprocess/sync/file_lock.hpp>
#include <boost/thread.hpp>


#define PACKAGE_NAME


static bool LockDataDirectory(bool probeOnly)
{
    std::string strDataDir = GetDataDir().string();
    
    // Make sure only a single Bitcoin process is using the data directory.
    fs::path pathLockFile = GetDataDir() / ".lock";
    FILE* file = fsbridge::fopen(pathLockFile, "a"); // empty lock file; created if it doesn't exist.
    if (file) fclose(file);
    
    try {
        static boost::interprocess::file_lock lock(pathLockFile.string().c_str());
        if (!lock.try_lock()) {
            return InitError(strprintf("Cannot obtain a lock on data directory %s. %s is probably already running."));
        }
        if (probeOnly) {
            lock.unlock();
        }
    } catch(const boost::interprocess::interprocess_exception& e) {
        return InitError(strprintf(_("Cannot obtain a lock on data directory %s. %s is probably already running.") + " %s.", strDataDir,_(PACKAGE_NAME), e.what()));
    }
    return true;
}




bool AppInitMain(boost::thread_group& threadgroup)
{
    const CChainParams& chainparams = Params();
    //  const CChainParams& chainparams = Params();
    //reference to Params. 'chainparams' as argument
    
    

    if (!LockDataDirectory(false)) {
        //It go through LockDataDirectory and return true if
        //there is no problem. It returns InitError if
        //there is some problem. passing false make sure its locked
        // Detailed error printed inside LockDataDirectory.
        return false;
    }


    
    threadgroup.create_thread(&ThreadScriptCheck);
    
    
    
    
    return true;
    
}
