#include <iostream>
#include "Lattice.hpp"
#include "Element.hpp"

using namespace KnuSkillz2020;


int main()
{
    // Set up lattice
    Lattice lattice(3);

    // Do all joins
    auto results = lattice.apply2(std::function<bool(const Element&, const Element&)>(implies));

    return 0;
}

