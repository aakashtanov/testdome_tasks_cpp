#include <tuple>
#include <iostream>

#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{
    const auto sD = std::sqrt(b * b - 4 * a * c);

    return { (-b - sD) / (2 * a), (-b + sD) / (2 * a)};
}

int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " << roots.first << ", " << roots.second;
}

