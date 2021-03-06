#ifndef SHORTURL_CONTROLLER_GETURLCONTROLLER_H
#define SHORTURL_CONTROLLER_GETURLCONTROLLER_H

#include "drogon/HttpSimpleController.h"

using namespace drogon;

namespace shorturl {
namespace controller {
class GetUrlController : public drogon::HttpSimpleController<GetUrlController> {
public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req,
                                        std::function<void (const HttpResponsePtr &)>&&callback) override;

    std::string getShortUrl(const std::string& url);

    PATH_LIST_BEGIN
        PATH_ADD("/short", Post);
    PATH_LIST_END
};
}
}

#endif //SHORTURL_CONTROLLER_GETURLCONTROLLER_H
