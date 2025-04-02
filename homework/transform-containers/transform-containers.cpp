#include "transform-containers.hpp"
#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>&
                                                               list,
                                                           std::deque<int>& deque) {
    std::map<int, std::string> result;
    list.sort();
    std::sort(deque.begin(), deque.end());
    std::unique(list.begin(), list.end());
    std::unique(deque.begin(), deque.end());

    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(result, result.begin()), [](auto& lhs, auto& rhs) {
        return std::make_pair(lhs, rhs);
    });
    return result;
}
