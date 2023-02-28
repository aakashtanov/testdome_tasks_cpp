#include <iostream>
#include <vector>
#include <utility>

#include <unordered_map>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    std::unordered_map<int, int> seen;

    for(size_t index = 0; index < list.size(); ++index)
    {
        if(seen.find(sum - list[index]) != seen.end())
        {
            return { index , seen[sum - list[index]] };
        }

        seen[list[index]] = index;
    }

    return { -1, -1 };
}

int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << std::endl << indices.second;
}