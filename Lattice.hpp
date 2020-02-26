#ifndef KnuSkillz2020_Lattice_hpp
#define KnuSkillz2020_Lattice_hpp

#include <cmath>
#include <functional>
#include <iostream>
#include "Element.hpp"
#include <vector>

namespace KnuSkillz2020
{

/* REALLY JUST A BOOLEAN LATTICE */

class Lattice
{
    private:
        std::vector<Element> Elements;

    public:
        // Construct a boolean lattice from the given number of atoms
        Lattice(int num_atoms);

        // Apply a function to each Element
        template<typename T>
        std::vector<T> apply(const std::function<T(const Element&)>& f) const;

        // Apply a function to every pair of Elements
        template<typename T>
        std::vector<std::vector<T>> apply2
          (const std::function<T(const Element&, const Element&)>& f) const;

        // Assign some values to the lattice elements
        bool test_values(const std::vector<double>& vs) const;

};

Lattice::Lattice(int num_atoms)
{
    for(int i=0; i<pow(2, num_atoms); ++i)
        Elements.emplace_back(i);
}


template<typename T>
std::vector<T> Lattice::apply(const std::function<T(const Element&)>& f) const
{
    std::vector<T> results;
    for(size_t i=0; i<Elements.size(); ++i)
        results.emplace_back(f(Elements[i]));
    return results;
}

template<typename T>
std::vector<std::vector<T>> Lattice::apply2
        (const std::function<T(const Element&, const Element&)>& f) const
{
    std::vector<std::vector<T>> results(Elements.size());
    for(size_t i=0; i<Elements.size(); ++i)
        for(size_t j=0; j<Elements.size(); ++j)
        {
            results[i].emplace_back(f(Elements[i], Elements[j]));
            std::cout << Elements[i] << ' ' << Elements[j] << ' ';
            std::cout << results[i].back() << std::endl;
        }
    return results;
}


// 
bool Lattice::test_values(const std::vector<double>& vs) const
{
    
}

// 



} // namespace

#endif

