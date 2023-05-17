#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <fstream>
#include <string>
#include "sorted_list.hpp"

template <typename T>
class Serialize {
public:
    Serialize(const std::string& file, SortedList<T>* newList);
    ~Serialize() = default;

private:
    void writeIntoFile() const;

private:
    std::string filename;
    SortedList<T>* list;
};

#include "serialize.tpp"

#endif // SERIALIZE_HPP