#include "transform-containers.hpp"
#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>&
                                                               list,
                                                           std::deque<int>& deque) {
    std::map<int, std::string> result;
    list.sort();
    std::sort(deque.begin(), deque.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());
    deque.shrink_to_fit();

    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(result, result.begin()), [](auto& lhs, auto& rhs) {
        return std::make_pair(lhs, rhs);
    });
    return result;
}
