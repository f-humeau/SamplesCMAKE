#pragma once

#include <string>

namespace NH
{
    class myClass
    {
    public:
        myClass() = default;

        const std::string &name() const;
        std::string &name();

    private:
        std::string _name{"Dupont"};
    };
}