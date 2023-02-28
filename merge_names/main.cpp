#include <iostream>
#include <vector>

#include <unordered_set>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::unordered_set<std::string> set;

    for(const auto& name : names1)
    {
        set.emplace(name);
    }
    for(const auto& name : names2)
    {
        set.emplace(name);
    }

    std::vector<std::string> result;
    std::copy(set.begin(), set.end(), std::back_inserter(result));

    return result;
}

int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

    std::vector<std::string> result = unique_names(names1, names2);
    for(const auto& element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}