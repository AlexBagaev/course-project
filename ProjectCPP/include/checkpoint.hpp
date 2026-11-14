#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include "accessRule.hpp"
#include "pass.hpp"

namespace checkpoint 
{
class Checkpoint 
{
private:
    std::string m_checkpointName{ };
    pass::Pass& m_currentPass;
    rules::AccessRules* m_rules{ nullptr };
    bool m_scanRezult{ }; 

public:
    Checkpoint(std::string_view checkpointName, std::string_view rulesName, std::int32_t zoneAccessLevel, pass::Pass& currentPass);

    Checkpoint()                            = delete;
    Checkpoint(const Checkpoint&)           = delete;
    Checkpoint(Checkpoint&&)                = delete;
    Checkpoint operator=(const Checkpoint&) = delete;
    Checkpoint operator=(Checkpoint&&)      = delete;
    ~Checkpoint();
    
    
    bool ScanPass();
    void PrintScanRezult();
        

};
} // namespace checkpoint 