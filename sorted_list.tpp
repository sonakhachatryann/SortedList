#ifndef SORTED_LIST_TPP
#define SORTED_LIST_TPP

#include "sorted_list.hpp"

template <typename T>
SortedList<T>::~SortedList() {
    ListNode<T>* tmp1 = head;
    while (tmp1) {
        head = head->next;
        delete tmp1;
        tmp1 = head;
    }    
}

template <typename T>
void SortedList<T>::push_back(const T& val) {
    if (size == 0) {
        ListNode<T>* newnode = new ListNode(val);
        head = tail = min = max = newnode;
        ++size;
        return;
    }
    ListNode<T>* newnode = new ListNode(val);
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    if (val <= min->value) {
        newnode->next_max = min;
        min->prev_min = newnode;
        min = newnode;
        ++size;
        return;
    }
    ListNode<T>* tmp = min;
    while (tmp && val > tmp->value) {
        tmp = tmp->next_max;
    }
    if (!tmp) {
        max->next_max = newnode;
        newnode->prev_min = max;
        max = newnode;
        ++size;
        return;
    }
    tmp->prev_min->next_max = newnode;
    newnode->prev_min = tmp->prev_min;
    newnode->next_max = tmp;
    tmp->prev_min = newnode;
    ++size;
}

template <typename T>
void SortedList<T>::print() const {
    if (min) {
        ListNode<T>* tmp = min;
        while (tmp != max) {
            std::cout << tmp->value << " ";
            tmp = tmp->next_max;
        }
        std::cout << tmp->value << std::endl;
    }
}

template <typename T>
void SortedList<T>::erase(int position) {
    if (position > size || position < 1) {
        throw std::invalid_argument("The position is out of range.");
    }
    ListNode<T>* current = min;
    while (position - 1 > 0) {
        current = current->next_max;
        --position;
    }
    if (size == 1) {
        delete head;
        --size;
        return;
    }
    if (current == min) {
        min = current->next_max;
        min->prev_min = nullptr;
        eraseNode(current);
        return;
    }
    if (current == max) {
        max = current->prev_min;
        max->next_max = nullptr;
        eraseNode(current);
        return;
    }
    current->prev_min->next_max = current->next_max;
    current->next_max->prev_min = current->prev_min;
    eraseNode(current);
    // the size has been decremented in the eraseNode() function
}

template <typename T>
void SortedList<T>::eraseNode(ListNode<T>* node) {
    if (node == head) {
        head = head->next;
        head->prev = nullptr;
        delete node;
        --size;
        return;
    }
    if (node == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete node;
        --size;
        return;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --size;
}

template <typename T>
void SortedList<T>::pop_back() {
    erase(size);
}

template <typename T>
int SortedList<T>::getSize() const {
    return size;
}

template <typename T>
int SortedList<T>::getNodeNumber(const ListNode<T>* node) const {
    int number{};
    ListNode<T>* tmp = min;
    while (tmp != node) {
        ++number;
        tmp = tmp->next_max;
    }
    return number + 1;
}

template <typename T>
ListNode<T>* SortedList<T>::getHead() const {
    return head;
}

template <typename T>
ListNode<T>* SortedList<T>::getNodeFromNumber(int position) const {
    ListNode<T>* tmp = min;
    while (position - 1) {
        tmp = tmp->next_max;
        --position;
    }
    return tmp;
}

#endif // SORTED_LIST_TPP