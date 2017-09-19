//
//  fs.cpp
//  c++coin
//
//  Created by NandN on 2017/09/17.
//  Copyright © 2017 NandN. All rights reserved.
//

#include "fs.h"

#include <boost/filesystem.hpp>

namespace fsbridge {
    
    FILE *fopen(const fs::path& p, const char *mode)
    {
        return ::fopen(p.string().c_str(), mode);
    }
    
    FILE *freopen(const fs::path& p, const char *mode, FILE *stream)
    {
        return ::freopen(p.string().c_str(), mode, stream);
    }
    
} // fsbridge
