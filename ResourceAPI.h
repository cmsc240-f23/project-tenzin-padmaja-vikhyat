#ifndef RESOURCE_API_H
#define RESOURCE_API_H

#include <crow.h>
#include <map>
#include <string>

template <typename T>
class ResourceAPI{
    public:
        static std::map<std::string, T> resourceMap;
        static crow::response createResource(request req);
        static crow::response readResource(request req);
        static crow::response readAllResources(request req);
        static crow::response updateResource(request req);
        static crow::response deleteResource(request req);
}

#endif