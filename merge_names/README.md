# Merge names #

Implement the `unique_names` method.
When passed two vectors of names,
it will return a vector containing the names
that appear in either or both vectors.
The returned vector should have no duplicates.

For example, calling
```c++
std::vector<std::string> a{"Ava", "Emma", "Olivia"};
std::vector<std::string> b{"Olivia", "Sophia", "Emma"};
unique_names(a, b);
``` 
should return a vector containing 
`Ava`, `Emma`, `Olivia`, and `Sophia` in any order.
