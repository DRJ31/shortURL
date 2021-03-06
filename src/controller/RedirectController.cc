#include "RedirectController.h"
#include <cstdio>
#include "drogon/HttpAppFramework.h"
#include "funcs/Tools.h"
#include "config.h"

namespace shorturl {
namespace controller {
void RedirectController::redirect(const HttpRequestPtr& req,
              std::function<void (const HttpResponsePtr &)> &&callback) {
    std::string shortUrl = getAbbreviation(req->getPath());
    const std::string host = req->getHeader("host");

    std::string fullUrl = getFullUrl(host, shortUrl);

    auto resp = HttpResponse::newRedirectionResponse(fullUrl, k302Found);
    callback(resp);
}

std::string RedirectController::getFullUrl(const std::string& host, const std::string& shortUrl) {
    const char* queryFormat = "SELECT * FROM shorturl WHERE abbreviation='%s'";
    const std::string SCHEME = funcs::Tools::getScheme(CONFIG_PATH);
    char querySql[BUFSIZE];

    auto clientPtr = funcs::Tools::getDbClient(CONFIG_PATH, DB_THREADS);
    if (!clientPtr)
        return SCHEME + host + "/404";
    std::sprintf(querySql, queryFormat, shortUrl.data());
    auto result = clientPtr->execSqlSync(querySql);
    if (result.empty())
        return SCHEME + host + "/404";

    return result.at(0).at("url").as<std::string>();
}

std::string RedirectController::getAbbreviation(const std::string& path) {
    std::string::const_iterator it = path.begin();
    std::string result;

    it++;
    while (it != path.end() && *it != '/') {
        result += *it;
        it++;
    }

    return result;
}
}
}