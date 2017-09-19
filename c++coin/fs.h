//
//  fs.h
//  c++coin
//
//  Created by NandN on 2017/09/16.
//  Copyright © 2017 NandN. All rights reserved.
//

#include <stdio.h>
#include <string>


#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/detail/utf8_codecvt_facet.hpp>


/** Filesystem operations and types */
namespace fs = boost::filesystem;

/** Bridge operations to C stdio */
namespace fsbridge {
    FILE *fopen(const fs::path& p, const char *mode);
    FILE *freopen(const fs::path& p, const char *mode, FILE *stream);
};
