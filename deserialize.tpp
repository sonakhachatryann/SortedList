#ifndef DESERIALIZE_TPP
#define DESERIALIZE_TPP

#include "deserialize.hpp"

template <typename T>
Deserialize<T>::Deserialize(const std::string& file, SortedList<T>* newList) 
    : filename{ file }
    , list{ newList } {
    readFromFile();
}

template <typename T>
void Deserialize<T>::readFromFile() {
    std::ifstream in(filename);
    if (in.is_open()) {
        int first{};
        int second{};
        std::unordered_map<int, int> myMap;
        int index{};
        while (in >> first >> second) {
            myMap[second] = index + 1;
            ++index;
            list->push_back(first);
        }
        for (auto& it : myMap) {
            if (it.first != myMap.size()) {
                list->getNodeFromNumber(it.first)->next_max = list->getNodeFromNumber(it.first + 1);
            }
            if (it.first != 1) {
                list->getNodeFromNumber(it.first)->prev_min = list->getNodeFromNumber(it.first - 1);
            }
        }
    }
}

#endif // DESERIALIZE_TPP