#include <iostream>
#include <functional>
#include <vector>

template<class T>
std::function<T (T)> makePipeline(const std::vector<std::function<T (T)>>& funcs)
{
    return [&funcs](const T& arg)
    {
        T tmp = arg;
        for(auto& func : funcs)
        {
            tmp = func(tmp);
        }
        return tmp;
    };
}

int main()
{
    std::vector<std::function<int (int)>> functions;
    functions.emplace_back([] (int x) -> int { return x * 3; });
    functions.emplace_back([] (int x) -> int { return x + 1; });
    functions.emplace_back([] (int x) -> int { return x / 2; });

    std::function<int (int)> func = makePipeline(functions);
    std::cout << func(3); // should print 5
}