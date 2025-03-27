#include "compression.hpp"
#include <stdexcept>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& img) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    result.reserve(width * height);

    std::for_each(img.begin(), img.end(), [&](const auto& row) {
        auto it = row.begin();
        std::for_each(row.begin(), row.end(), [&](uint8_t) {
            if (it == row.end()) return;  

            auto next = std::find_if_not(it, row.end(), [it](uint8_t value) { return *it == value; });

            result.emplace_back(*it, std::distance(it, next));
            it = next;
        });
    });

    return result;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& input) {
    std::array<std::array<uint8_t, width>, height> result = {};
    auto it = result[0].begin(); 

    for (const auto& [value, count] : input) {
        if (std::distance(it, result[height - 1].end()) < count) {
            throw std::out_of_range("Too many pixels in input data");
        }
        it = std::fill_n(it, count, value); 
    }

    return result;
}

