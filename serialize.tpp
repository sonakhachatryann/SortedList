#ifndef SERIALIZE_TPP
#define SERIALIZE_TPP

#include "seriailze.hpp"

template <typename T>
Serialize<T>::Serialize(const std::string& file, SortedList<T>* newList) 
    : filename{ file }
    , list{ newList } {
    writeIntoFile();
}

template <typename T>
void Serialize<T>::writeIntoFile() const {
    std::ofstream out;
    out.open(filename, std::ofstream::app);
    ListNode<T>* tmp = list->getHead();
    while (tmp) {
        out << tmp->value << " " << list->getNodeNumber(tmp) << '\n';
        tmp = tmp->next;
    }
    out.close();
}

#endif // SERIALIZE_TPP