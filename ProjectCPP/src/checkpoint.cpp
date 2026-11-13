#include "checkpoint.hpp"

namespace checkpoint 
{

Checkpoint::Checkpoint(std::string_view checkpointName, std::string_view rulesName, std::int32_t zoneAccessLevel, pass::Pass& currentPass)
    : m_checkpointName{ checkpointName }
    , m_currentPass{ currentPass }
    {
       m_rules = new rules::AccessRules( rulesName, zoneAccessLevel );
    }

bool Checkpoint::ScanPass()
{
    bool check1 = m_rules->IsPassValid(m_currentPass.GetValid());
    bool check2 = m_rules->IsAccessLevelCorrespond(m_currentPass.GetAccessLevel());
    if (check1 && check2 )
    {
        return m_scanRezult = true;
    }
    else
    {
        return m_scanRezult = false;
    }
}

void Checkpoint::PrintScanRezult()
{
    if (m_scanRezult)
    {
        std::cout << "Entry allowed" << std::endl;
    }
    else 
    {
        std::cout << "Entry disallow" << std::endl;
    }
}

Checkpoint::~Checkpoint()
{
    std::cout << "The checkpoint " << m_checkpointName << " has been destroyed" << std::endl;
    delete m_rules;
}


} // namespace checkpoint