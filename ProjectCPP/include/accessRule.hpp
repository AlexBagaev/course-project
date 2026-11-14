#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>

namespace rules 
{

class AccessRules 
{
private:
    std::int32_t m_zoneAccessLevel{ };
    std::string m_rulesName{ };

public:
    AccessRules(std::string_view rulesName, std::int32_t zoneAccessLevel);

    AccessRules()                             = delete;
    AccessRules(const AccessRules&)           = delete;
    AccessRules(AccessRules&&)                = delete;
    AccessRules operator=(const AccessRules&) = delete;
    AccessRules operator=(AccessRules&&)      = delete;
    ~AccessRules();

   bool IsPassValid(bool passValid);
   bool IsAccessLevelCorrespond(std::int32_t passAccessLevel);
    
};

} // namespace rules