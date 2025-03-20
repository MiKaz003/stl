#include "compression.hpp"
#include <stdexcept>
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& img){
    std::vector<std::pair<uint8_t, uint8_t>> result;
    result.reserve(width * height);

    for(auto& row : img){
        auto it = row.begin();
        while(it != row.end()){
            auto next = std::find_if_not(it, row.end(), [it](auto value){return *it == value;});
            size_t count = std::distance(it, next);
            result.emplace_back(*it, count);
            it = next;
        }
    }
    return result;
}

// std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& img) {
//     std::vector<std::pair<uint8_t, uint8_t>> result;
//     result.reserve(width * height);
//     for (const auto& array : img) {
//         int count = 1;
//         uint8_t current = array[0];
//         for (size_t i = 1; i < array.size(); i++) {
//             if (array[i] == current) {
//                 ++count;
//             } else {
//                 result.emplace_back(current, count);
//                 count = 1;
//                 current = array[i];
//             }
//         }
//         result.emplace_back(current, count);
//     }
//     result.shrink_to_fit();
//     return result;
// }


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


// std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& input) {
//     std::array<std::array<uint8_t, width>, height> result = {};
//     uint8_t row = 0;
//     uint8_t column = 0;
//     uint8_t i = 0;
//     while (row < height) {
//         const auto& pair = input[i];
//         for (uint8_t j = 0; j < pair.second; j++) {
//             if (column < width) {
//                 result[row][column] = pair.first;
//                 ++column;
//             } else {
//                 row += 1;
//                 if (row >= height) {
//                     throw std::out_of_range("Unexpected value of row");
//                 } else {
//                     column = 0;
//                     result[row][column] = pair.first;
//                     ++column;
//                 }
//             }
//         }
//         i++;
//     }
//     return result;
// }