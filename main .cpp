#include <iostream>
#include "sorted_list.hpp"
#include "seriailze.hpp"
#include "deserialize.hpp"

int main() {
    SortedList<int> sl;
    sl.push_back(8);
    sl.print();

    sl.push_back(2);
    sl.print();

    sl.push_back(9);
    sl.print();

    sl.push_back(7);
    sl.print();

    sl.push_back(7);
    sl.print();

    sl.erase(1);
    sl.print();

    sl.erase(4);
    sl.print();

    sl.push_back(0);
    sl.print();

    sl.push_back(10);
    sl.print();

    sl.erase(2);
    sl.print();

    sl.pop_back();
    sl.print();

    std::string file = "serialized_list.txt";
    Serialize<int> s(file, &sl);
    SortedList<int> newList;
    Deserialize<int> d(file, &newList);
    newList.pop_back();
    newList.erase(2);
    newList.print();
    return 0;
}