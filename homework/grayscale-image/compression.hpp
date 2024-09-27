#pragma once
#include <vector>
#include <utility>
#include <cstdint>
#include <array>
#include <stddef.h>



constexpr size_t width = 32;
constexpr size_t height = 32;
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& img);
std::array<std::array<uint8_t, 32>, 32>  decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& input);