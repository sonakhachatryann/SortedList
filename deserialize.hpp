#ifndef DESERIALIZE_HPP
#define DESERIALIZE_HPP

#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "sorted_list.hpp"

template <typename T>
class Deserialize {

public:
    Deserialize(const std::string& file, SortedList<T>* newList);
    ~Deserialize() = default;

private:
    void readFromFile();

private:
    std::string filename;
    SortedList<T>* list;
};

#include "deserialize.tpp"

#endif // DESERIALIZE_HPP