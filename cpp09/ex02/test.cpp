#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    std::set<int> odd = { 3, 1, 5 };
    std::set<int> even = { 2, 4, 6 };

    std::set<int> s;
    std::merge(odd.begin(), odd.end(),
                even.begin(), even.end(),
                std::inserter(s, s.begin()));

    for (auto const &e: s) {
        std::cout << e << ' ';
    }

    return 0;
}
