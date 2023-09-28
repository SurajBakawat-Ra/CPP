#include <iostream>

#define PRINT_PERSON_DETAILS(name, age, gender) {\
std::cout<<"Name: "<<name<<std::endl; \
std::cout<<"Age: "<<age<<std::endl; \
std::cout<<"Gender: "<<gender<<std::endl; \
}

int main()
{
    PRINT_PERSON_DETAILS("Suraj", 22, "M")
    return 0;
}