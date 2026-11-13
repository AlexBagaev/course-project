#pragma once

#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>

namespace pass 
{
    

class Pass 
{
private:
    std::string m_id{ };
    std::int32_t m_accessLevel{ };
    bool m_valid{ false };

public:
    Pass(std::string id, std::int32_t accessLevel, bool Valid);

    Pass()                      = delete;
    Pass(const Pass&)           = delete;
    Pass(Pass&&)                = delete;
    Pass operator=(const Pass&) = delete;
    Pass& operator=(Pass&&)     = delete;
    ~Pass()                     = default;
        
    void InvalidatePass(bool& m_valid){};
    void ValidatePass(bool& m_valid){};

    [[nodiscard]] bool GetValid() const
    {
        return m_valid;
    }

    [[nodiscard]] std::string GetId() const
    {
        return m_id;
    }
        
    [[nodiscard]] std::int32_t GetAccessLevel() const
    {
        return m_accessLevel;
    }
        
    void SetId(std::string_view id) {
        m_id = std::string(id);
    }

    void SetAccessLevel (std::int32_t accessLevel)
    {
        m_accessLevel = accessLevel;
    }
        
    };

} // namespace pass
