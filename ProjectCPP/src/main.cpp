#include "main.hpp"

int main()
{   
    std::cout <<"=== Smart pointers demonstration ===" << std::endl;
    std::cout <<"=== Array of dynamic objects ===" << std::endl;
    std::cout <<"=== 1.Show unique_ptr ===" << std::endl;
    
    {
        std::cout << "Local scope" << std::endl;
        auto passArray = std::make_unique<pass::Pass[]>(2);

        passArray[0].SetId("L0004");
        passArray[0].SetAccessLevel(1);
        passArray[0].SetValid(true);
        passArray[1].SetId("R0001");
        passArray[1].SetAccessLevel(2);
        passArray[1].SetValid(false);

        std::cout << "passArray[0]:" << passArray[0].GetId() << " level access: " << passArray[0].GetAccessLevel() << std::endl;
        std::cout << "passArray[1]:" << passArray[1].GetId() << " level access: " << passArray[1].GetAccessLevel() << std::endl;

        std::cout << "Leaving local scope" << std::endl;
    }

    std::cout << "\n\n";

    std::cout << "=== 2.Show shared_ptr ===" << std::endl;
    {
        std::cout << "Local scope" << std::endl;
        auto first = std::make_shared<pass::Pass>("L0001",2,false);
        std::cout << "Owners - " << first.use_count() << std::endl;
        {   
            std::shared_ptr<pass::Pass> copy = first;
            std::cout << "Owners - " << first.use_count() << std::endl;
        }
        std::cout << "Owners - " << first.use_count() << std::endl;
        std::cout << "Leaving the local scope" << std::endl;
    }

    std::cout << "\n\n";

    std::cout << "=== 3.Show weak_ptr ===" << std::endl;

    {
    std::shared_ptr<pass::Pass> first =
        std::make_shared<pass::Pass>("12345", 2, true);

    std::weak_ptr<pass::Pass> weakPass = first;

    if (auto temp = weakPass.lock())
    {
        std::cout << "ID: " << temp->GetId() << '\n';
        std::cout << "Access level: " << temp->GetAccessLevel() << '\n';
        std::cout << "Valid: " << temp->GetValid() << '\n';
    }

    first.reset();

    if (auto temp = weakPass.lock())
    {
        std::cout << "ID: " << temp->GetId() << '\n';
    }
    else
    {
        std::cout << "Pass no longer exists!\n";
    }
    }

    std::cout <<"=== 4.Dynamic array of objects ===\n" << std::endl;
    {
    auto passPtrArray = std::make_unique<std::unique_ptr<pass::Pass>[]>(2);

    passPtrArray[0] = std::make_unique<pass::Pass>("L0020", 3, false);
    passPtrArray[1] = std::make_unique<pass::Pass>("R0012", 2, false);

    std::cout << "passPtrArray[0]: " << passPtrArray[0]->GetId() << "\n";
    std::cout << "passPtrArray[1]: " << passPtrArray[1]->GetId() << "\n";

    std::cout << "Destroying array of dynamic objects...\n";
}
    return 0;
}