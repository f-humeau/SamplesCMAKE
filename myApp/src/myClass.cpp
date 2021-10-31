
#include "myClass.h"

namespace NH
{
    const std::string &myClass::name() const
    {
        return _name;
    }

    std::string &myClass::name()
    {
        return _name;
    }

}