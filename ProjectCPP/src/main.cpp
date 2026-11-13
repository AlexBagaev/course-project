#include "main.hpp"

int main()
{
    std::cout <<"=== 1. Dynamic array of objects ===\n" << std::endl;
    pass::Pass* passArray = new pass::Pass[2]
    {
        pass::Pass("L0004",1,true),
        pass::Pass("R0001",2,false),
    };
    
    std::cout << "Destroying dynamic array of objects\n";

    delete[] passArray;
    passArray = nullptr;

    std::cout << "\n\n" << std::endl;

    std::cout <<"=== 2.Array of dynamic objects ===\n" << std::endl;
    pass::Pass** passPtrArray = new pass::Pass*[2]
    {
        new pass::Pass("L0020",3,false),
        new pass::Pass("R0012",2,false),
    }; 

    std::cout << "Destroying array of dynamic objects\n" << std::endl;
    for (std::int32_t i = 0; i < 2; i++) 
	{
		delete passPtrArray[i];
		passPtrArray[i] = nullptr;
	}

    delete[] passPtrArray;

    std::cout << "\n\n" << std::endl;

    std::cout <<"=== 3. Composition and agregation ===\n" << std::endl;
    std::cout <<"=== Creating agregation pass\n" << std::endl;
    
    pass::Pass* pass = new pass::Pass("L0009",2,true);

    std::cout <<"=== Creating coposition checkpoint\n" << std::endl;
    checkpoint::Checkpoint* checkpoint = new checkpoint::Checkpoint("MainEntr","Mainrule",2,*pass);
    checkpoint->ScanPass();
    checkpoint->PrintScanRezult();

    delete checkpoint;
    checkpoint = nullptr;
    delete pass;
    pass = nullptr;
    
    return 0;

}