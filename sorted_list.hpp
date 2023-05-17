#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include <stdexcept>

template <typename T>
struct ListNode {
    T value;
    ListNode* prev;
    ListNode* next;
    ListNode* next_max;
    ListNode* prev_min;

    ListNode() : value(0) , prev(nullptr), next(nullptr), next_max(nullptr), prev_min(nullptr) {}
    ListNode(const T& val) : value(val), prev(nullptr), next(nullptr), next_max(nullptr), prev_min(nullptr) {}
};

template <typename T>
class SortedList {
public:

    SortedList() : size(0), head(nullptr), tail(nullptr), min(nullptr), max(nullptr) {}
    ~SortedList();

    void push_back(const T& val);
    void print() const;
    void erase(int position);  // erase the position-th element from the sorted list
    void pop_back();
    int getSize() const;
    ListNode<T>* getHead() const;
    int getNodeNumber(const ListNode<T>*) const;
    ListNode<T>* getNodeFromNumber(int position) const;

private:
    void eraseNode(ListNode<T>*);
    
private:
    ListNode<T>* min;
    ListNode<T>* max;
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
};

#include "sorted_list.tpp"

#endif // SORTED_LIST_HPP