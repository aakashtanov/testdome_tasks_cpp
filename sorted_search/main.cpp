#include <vector>
#include <iostream>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    int left = 0;
    int right = sortedVector.size() - 1;
    int floor = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(sortedVector[mid] == lessThan)
        {
            while(mid >= 0 && sortedVector[mid] == lessThan )
            {
                mid--;
            }
            if (mid == -1)
            {
                return 0;
            }
            else
            {
                return mid + 1;
            }
        }
        if (sortedVector[mid] > lessThan)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            floor = mid;
        }
    }
    if (floor == -1)
    {
        return -1;
    }
    else
    {
        return floor + 1;
    }
}

int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}

