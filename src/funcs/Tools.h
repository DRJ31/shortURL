#ifndef SHORTURL_FUNCS_TOOLS_H
#define SHORTURL_FUNCS_TOOLS_H

#include <json/json.h>
#include <string>

#define BUFSIZE 1000

namespace shorturl {
namespace funcs {
namespace Tools {
std::string getDbInfo(const std::string& fileName);
}
}
}

#endif //SHORTURL_FUNCS_TOOLS_H