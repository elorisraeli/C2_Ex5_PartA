#ifndef SIDE_CROSS_ITERATOR_H
#define SIDE_CROSS_ITERATOR_H

#include "MagicalContainer.hpp"
#include <vector>
#include <iterator>

using namespace std;

class MagicalContainer;

class SideCrossIterator {
private:
    MagicalContainer& container;
    std::vector<int>::iterator forward_it;
    std::vector<int>::reverse_iterator reverse_it;
    bool isForward;
    bool isEnd = false;

public:
    SideCrossIterator(MagicalContainer& container);
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();

    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;
    int operator*();
    SideCrossIterator& operator++();

    SideCrossIterator begin();
    SideCrossIterator end();
};

#endif // SIDE_CROSS_ITERATOR_H
