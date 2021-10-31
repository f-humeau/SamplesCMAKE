#pragma once

#include <string>

// version inline ...
namespace NH
{
    class myClassUser
    {
    public:
        myClassUser() = default;

        /*inline*/ const std::string &name() const { return _name; }
        /*inline*/ std::string &name() { return _name; }

    private:
        std::string _name{"Smith"};
    };
}
