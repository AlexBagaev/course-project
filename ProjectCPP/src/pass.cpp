#include "pass.hpp";

namespace pass 
{

Pass::Pass(std::string_view id, std::int32_t accessLevel, bool valid)
    : m_id{ id }
    , m_accessLevel{ accessLevel }
    , m_valid{ valid }
    {}

void Pass::InvalidatePass(bool& m_valid)
{
    if (m_valid)
    {
        m_valid = false;
        std::cout << "The pass " << m_id << "  has been invalidate." << std::endl;
    }
    else 
    {
        std::cout << "The pass " << m_id << "  has already been invalidate." << std::endl;
    }
}

void Pass::Pass::ValidatePass(bool& m_valid)
{
    if (m_valid)
    {
        std::cout << "The pass " << m_id << " has already been valid" << std::endl;
    }
    else
    {
        m_valid = true;
        std::cout << "The pass " << m_id << "  has been validate." << std::endl;
    }
}

Pass::~Pass()
{
    std::cout << "The pass " << m_id << " has been destroyed" << std::endl;
}
 
} // namespace pass 