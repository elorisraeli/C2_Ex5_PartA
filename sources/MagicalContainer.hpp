#ifndef MAGICAL_CONTAINER_H
#define MAGICAL_CONTAINER_H

#include "AscendingIterator.hpp"
#include "SideCrossIterator.hpp"
#include "PrimeIterator.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class MagicalContainer {
private:
    std::vector<int> elements;

public:
    MagicalContainer();
    ~MagicalContainer();

    void addElement(int element);
    void removeElement(int element);
    int size() const;

    // To be used by the iterator classes
    std::vector<int>& getElements();
};

#endif  // MAGICAL_CONTAINER_H

