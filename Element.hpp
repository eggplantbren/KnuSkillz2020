#ifndef KnuSkillz2020_Element_hpp
#define KnuSkillz2020_Element_hpp

#include <cmath>
#include <deque>
#include <ostream>
#include <vector>

namespace KnuSkillz2020
{

class Element
{
    static constexpr int num_atoms = 3;

    private:
        std::deque<bool> bits;

    public:
        Element(std::uint32_t x=0);
        Element join(const Element& other) const;
        bool implies(const Element& other) const;
        std::ostream& operator >> (std::ostream& out) const;
};

Element join(const Element& x, const Element& y);
bool implies(const Element& x, const Element& y);
std::ostream& operator << (std::ostream& out, const Element& s);

/* IMPLEMENTATIONS FOLLOW */




Element::Element(std::uint32_t x)
:bits(num_atoms, 0)
{
    for(int i=0; i<num_atoms; ++i)
    {
        std::uint32_t y = pow(2, num_atoms-i-1);
        bits[i] = (x & y) != 0;
    }
}

Element Element::join(const Element& other) const
{
    Element result;
    for(int i=0; i<num_atoms; ++i)
        result.bits[i] = bits[i] | other.bits[i];
    return result;
}

bool Element::implies(const Element& other) const
{
    for(size_t i=0; i<bits.size(); ++i)
        if(bits[i] && !other.bits[i])
            return false;
    return true;
}


std::ostream& Element::operator >> (std::ostream& out) const
{
    for(int i=0; i<num_atoms; ++i)
        out << bits[i];
    return out;
}


Element join(const Element& x, const Element& y)
{
    return x.join(y);
}

bool implies(const Element& x, const Element& y)
{
    return x.implies(y);
}

std::ostream& operator << (std::ostream& out, const Element& s)
{
    s >> out;
    return out;
}

} // namespace

#endif

