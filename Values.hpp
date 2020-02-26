#ifndef KnuSkillz2020_Values_hpp
#define KnuSkillz2020_Values_hpp

#include <vector>

namespace KnuSkillz2020
{

class Values
{
    private:
        std::vector<int> vs;

    public:
        Values(int size);
};

Values::Values(int size)
:vs(size)
{

}

} // namespace

#endif

