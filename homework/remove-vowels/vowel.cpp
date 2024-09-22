#include "vowel.hpp"
#include <vector>
#include <algorithm>


void removeVowels(std::vector<std::string>& vector){
    std::vector<char> vowels {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};
    for (auto& sentence : vector){
        for (auto vowel : vowels){  
            sentence.erase(std::remove(sentence.begin(), sentence.end(), vowel), sentence.end());
        }
    }
//    vector.erase(std::remove(vector.begin(), vector.end(), vowel), vector.end());
}