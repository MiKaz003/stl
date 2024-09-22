#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& f_list) {
    std::deque<std::string> result;
        for(auto& el : f_list){
            if(result.empty()){
                result.push_back(el);
            }   
            else {
                auto it = result.begin();
                while(it != result.end() && el.length() > it->length() || el.length() == it->length() && el > *it){
                    *it++;
                }
                result.insert(it, el);
            }
        }
        return result;
    }