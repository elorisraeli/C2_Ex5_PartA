#include "AscendingIterator.hpp"

AscendingIterator::AscendingIterator(MagicalContainer& container) 
    : container(container), it(container.getElements().begin()) {
}

AscendingIterator::AscendingIterator(const AscendingIterator& other) 
    : container(other.container), it(other.it) {
}

AscendingIterator::~AscendingIterator() {
}

AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        it = other.it;
    }
    return *this;
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return it == other.it;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return it != other.it;
}

bool AscendingIterator::operator>(const AscendingIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return it > other.it;
}

bool AscendingIterator::operator<(const AscendingIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return it < other.it;
}

int AscendingIterator::operator*() {
    return *it;
}

AscendingIterator& AscendingIterator::operator++() {
    ++it;
    return *this;
}

AscendingIterator AscendingIterator::begin() {
    return AscendingIterator(container);
}

AscendingIterator AscendingIterator::end() {
    AscendingIterator temp(container);
    temp.it = container.getElements().end();
    return temp;
}
