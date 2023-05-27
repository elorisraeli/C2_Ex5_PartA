#include "PrimeIterator.hpp"
#include <cmath>

PrimeIterator::PrimeIterator(MagicalContainer& container) 
    : container(container), it(container.getElements().begin()) {
    // Advance to the first prime number
    while (it != container.getElements().end() && !isPrime(*it)) {
        ++it;
    }
}

PrimeIterator::PrimeIterator(const PrimeIterator& other) 
    : container(other.container), it(other.it) {
}

PrimeIterator::~PrimeIterator() {
}

PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        it = other.it;
    }
    return *this;
}

bool PrimeIterator::operator==(const PrimeIterator& other) const {
    return it == other.it;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return it != other.it;
}

bool PrimeIterator::operator>(const PrimeIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return it > other.it;
}

bool PrimeIterator::operator<(const PrimeIterator& other) const {
    if (&container != &(other.container)) {
        throw std::runtime_error("Comparing iterators from different containers");
    }
    return it < other.it;
}

int PrimeIterator::operator*() {
    return *it;
}

PrimeIterator& PrimeIterator::operator++() {
    // Advance to the next prime number
    do {
        ++it;
    } while (it != container.getElements().end() && !isPrime(*it));
    return *this;
}

PrimeIterator PrimeIterator::begin() {
    return PrimeIterator(container);
}

PrimeIterator PrimeIterator::end() {
    PrimeIterator temp(container);
    temp.it = container.getElements().end();
    return temp;
}

bool PrimeIterator::isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
