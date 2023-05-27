#include "MagicalContainer.hpp"
#include <algorithm>

MagicalContainer::MagicalContainer() {
}

MagicalContainer::~MagicalContainer() {
}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
    std::sort(elements.begin(), elements.end());
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

std::vector<int>& MagicalContainer::getElements() {
    return elements;
}

