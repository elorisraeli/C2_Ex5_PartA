#ifndef ASCENDING_ITERATOR_H
#define ASCENDING_ITERATOR_H

#include "MagicalContainer.hpp"
#include <vector>
#include <iterator>

using namespace std;

class MagicalContainer;

class AscendingIterator {
private:
    MagicalContainer& container;
    std::vector<int>::iterator it;

public:
    AscendingIterator(MagicalContainer& container);
    AscendingIterator(const AscendingIterator& other);
    ~AscendingIterator();

    AscendingIterator& operator=(const AscendingIterator& other);
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;
    bool operator>(const AscendingIterator& other) const;
    bool operator<(const AscendingIterator& other) const;
    int operator*();
    AscendingIterator& operator++();

    AscendingIterator begin();
    AscendingIterator end();
};

#endif // ASCENDING_ITERATOR_H
