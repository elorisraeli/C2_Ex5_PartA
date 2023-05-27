#include "SideCrossIterator.hpp"
#include "stdexcept"

SideCrossIterator::SideCrossIterator(MagicalContainer& container) 
    : container(container), 
      forward_it(container.getElements().begin()), 
      reverse_it(container.getElements().rbegin()),
      isForward(true) {
}

SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) 
    : container(other.container), 
      forward_it(other.forward_it), 
      reverse_it(other.reverse_it),
      isForward(other.isForward) {
}

SideCrossIterator::~SideCrossIterator() {
}

SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        forward_it = other.forward_it;
        reverse_it = other.reverse_it;
        isForward = other.isForward;
    }
    return *this;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return forward_it == other.forward_it && reverse_it == other.reverse_it && isForward == other.isForward;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return forward_it > other.forward_it || reverse_it.base() < other.reverse_it.base();
}

bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return forward_it < other.forward_it || reverse_it.base() > other.reverse_it.base();
}

int SideCrossIterator::operator*() {
    return isForward ? *forward_it : *reverse_it;
}

SideCrossIterator& SideCrossIterator::operator++() {
    if (isForward) {
        ++forward_it;
    } else {
        ++reverse_it;
    }
    isForward = !isForward;
    return *this;
}

SideCrossIterator SideCrossIterator::begin() {
    return SideCrossIterator(container);
}

SideCrossIterator SideCrossIterator::end() {
    SideCrossIterator temp(container);
    temp.forward_it = container.getElements().end();
    temp.reverse_it = container.getElements().rend();
    return temp;
}
