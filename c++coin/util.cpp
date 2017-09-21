//
//  util.cpp
//  c++coin
//
//  Created by NandN on 2017/09/16.
//  Copyright © 2017 NandN. All rights reserved.
//

#include "fs.h"
#include "util.h"
#include "chainparamsbase.h"





#ifdef HAVE_SYS_PRCTL_H
#include <sys/prctl.h>
#endif

ArgsManager gArgs;


bool ArgsManager::IsArgSet(const std::string& strArg)
{
    LOCK(cs_args);
    return mapArgs.count(strArg);
}




fs::path GetDefaultDataDir()
{
    // Windows < Vista: C:\Documents and Settings\Username\Application Data\Bitcoin
    // Windows >= Vista: C:\Users\Username\AppData\Roaming\Bitcoin
    // Mac: ~/Library/Application Support/Bitcoin
    // Unix: ~/.bitcoin
#ifdef WIN32
    // Windows
    return GetSpecialFolderPath(CSIDL_APPDATA) / "Bitcoin";
#else
    fs::path pathRet;
    char* pszHome = getenv("HOME");
    if (pszHome == NULL || strlen(pszHome) == 0)
        pathRet = fs::path("/");
    else
        pathRet = fs::path(pszHome);
#ifdef MAC_OSX
    // Mac
    return pathRet / "Library/Application Support/Bitcoin";
#else
    // Unix
    return pathRet / ".bitcoin";
#endif
#endif
}




static fs::path pathCached;
static fs::path pathCachedNetSpecific;
static CCriticalSection csPathCached;

const fs::path &GetDataDir(bool fNetSpecific)
{
    
    LOCK(csPathCached);
    
    fs::path &path = fNetSpecific ? pathCachedNetSpecific : pathCached;
    
    // This can be called during exceptions by LogPrintf(), so we cache the
    // value so we don't have to do memory allocations after that.
    if (!path.empty())
        return path;
    
    if (IsArgSet("-datadir")) {
        path = fs::system_complete(GetArg("-datadir", ""));
        if (!fs::is_directory(path)) {
            path = "";
            return path;
        }
    } else {
        path = GetDefaultDataDir();
    }
    if (fNetSpecific)
        path /= BaseParams().DataDir();
    
    fs::create_directories(path);
    
    return path;
}



void RenameThread(const char* name)
{
#if defined(PR_SET_NAME)
    // Only the first 15 characters are used (16 - NUL terminator)
    ::prctl(PR_SET_NAME, name, 0, 0, 0);
#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__))
    pthread_set_name_np(pthread_self(), name);
    
#elif defined(MAC_OSX)
    pthread_setname_np(name);
#else
    // Prevent warnings for unused parameters...
    (void)name;
#endif
}




