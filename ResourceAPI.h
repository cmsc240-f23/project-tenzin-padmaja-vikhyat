#ifndef RESOURCE_API_H
#define RESOURCE_API_H

#include <crow.h>
#include <map>
#include <string>

template <typename T>
class ResourceAPI
{
    public:
        static std::map<std::string, T> resourceMap;
        static crow::response createResource(crow::request req);
        static crow::response readAllResources(crow::request req);
        static crow::response readResource(std::string id);
        static void updateResource(crow::request req, crow::response& res, std::string id);
        static crow::response deleteResource(std::string id);
};

#endif