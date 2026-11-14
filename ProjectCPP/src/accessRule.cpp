#include "accessRule.hpp"

namespace rules 
{

AccessRules::AccessRules(std::string_view rulesName, std::int32_t zoneAccessLevel)
    : m_rulesName{ rulesName }
    , m_zoneAccessLevel { zoneAccessLevel }
    {}

bool AccessRules::IsPassValid(bool passValid)
{
    if (!passValid) 
    {
        std::cout << "The pass isn't valid" << std::endl;
        return false;
    }
    return true;
}

bool AccessRules::IsAccessLevelCorrespond(std::int32_t passAccessLevel)
{
    if(m_zoneAccessLevel == passAccessLevel)
    {
    return true;
    }
    else
    {
        std::cout << "The access level of this pass does not match the zone access level." << std::endl;
        return false;
    }
}

AccessRules::~AccessRules()
{
    std::cout << "The access rules " << m_rulesName << " has been destroyed" << std::endl;
}

} // namespace rules