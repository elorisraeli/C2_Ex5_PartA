#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

/*******************************************
************** MagicalContainer ************
********************************************/

bool MagicalContainer::isPrime(int num) const
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void MagicalContainer::updateCrossElements()
{
    sideCrossElements.clear();
    auto start_it = ascendingElements.begin();
    auto end_it = ascendingElements.end();
    --end_it;

    while (start_it != ascendingElements.end())
    {
        // insert the smaller element first
        sideCrossElements.push_back(*start_it);
        if (start_it != end_it)
        {
            // if there is another element, insert the bigger element next
            sideCrossElements.push_back(*end_it);
        }
        ++start_it;
        if (end_it != start_it && start_it != ascendingElements.end())
        {
            --end_it;
        }
    }
}

void MagicalContainer::addElement(int element)
{
    defaultElements.push_back(element);
    ascendingElements.push_back(element);
    if (isPrime(element))
    {
        primeElements.push_back(element);
    }
    updateCrossElements();
}

void MagicalContainer::removeElement(int element)
{
    defaultElements.erase(std::remove(defaultElements.begin(), defaultElements.end(), element), defaultElements.end());
    ascendingElements.erase(std::remove(ascendingElements.begin(), ascendingElements.end(), element), ascendingElements.end());  
    if (isPrime(element))
    {
        primeElements.erase(std::remove(primeElements.begin(), primeElements.end(), element), primeElements.end());
    }
    updateCrossElements();
}

size_t MagicalContainer::size() const
{
    return defaultElements.size();
}

bool MagicalContainer::operator==(const MagicalContainer &other) const
{
    return defaultElements == other.defaultElements;
}

bool MagicalContainer::operator!=(const MagicalContainer &other) const
{
    return defaultElements != other.defaultElements;
}

/*******************************************
************* AscendingIterator ************
********************************************/

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), pos(0), it(magicalContainer.ascendingElements.begin()) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : magicalContainer(other.magicalContainer), pos(other.pos), it(other.it) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    magicalContainer = other.magicalContainer;
    pos = other.pos;                          
    it = other.it;                            
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Can't compare iterators from different MagicalContainers");

    return pos == other.pos;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Can't compare iterators from different MagicalContainers");

    return pos != other.pos;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Can't compare iterators from different MagicalContainers");

    return pos < other.pos;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos > other.pos;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    if (it == magicalContainer->ascendingElements.end())
        throw std::out_of_range("AscendingIterator out of range");
    return *it;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (it == magicalContainer->ascendingElements.end())
    {
        throw std::out_of_range("AscendingIterator out of range");
        return *this;
    }
    ++it; 
    ++pos;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
{
    it = magicalContainer->ascendingElements.begin();
    pos = 0;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
{
    it = magicalContainer->ascendingElements.end(); 
    pos = magicalContainer->size();
    return *this;
}

/*******************************************
************* SideCrossIterator ************
********************************************/

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), it(magicalContainer.sideCrossElements.begin()), pos(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magicalContainer(other.magicalContainer), it(other.it), pos(other.pos) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    magicalContainer = other.magicalContainer;
    pos = other.pos;                          
    it = other.it;                            
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos == other.pos;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos != other.pos;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos < other.pos;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos > other.pos;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    if (it == magicalContainer->sideCrossElements.end())
        throw std::out_of_range("SideCrossIterator out of range");
    return *it;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (it == magicalContainer->sideCrossElements.end())
    {
        throw std::out_of_range("SideCrossIterator out of range");
        return *this;
    }
    ++it;
    ++pos;
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
{
    it = magicalContainer->sideCrossElements.begin(); 
    pos = 0;                                      
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
{
    it = magicalContainer->sideCrossElements.end(); 
    pos = magicalContainer->size();
    return *this;
}

/*******************************************
************** PrimeIterator ***************
********************************************/

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), it(magicalContainer.primeElements.begin()), pos(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : magicalContainer(other.magicalContainer), it(other.it), pos(other.pos) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    magicalContainer = other.magicalContainer;
    pos = other.pos;                          
    it = other.it;                            
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");
    return pos == other.pos;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");
    return pos != other.pos;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos < other.pos;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if (this->magicalContainer != other.magicalContainer)
        throw std::invalid_argument("Cant compare iterators from different MagicalContainers");

    return pos > other.pos;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    if (it == magicalContainer->primeElements.end())
        throw std::out_of_range("PrimeIterator out of range");
    return *it;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (it == magicalContainer->primeElements.end())
    {
        throw std::out_of_range("PrimeIterator out of range");
        return *this;
    }
    ++it; 
    ++pos;
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
{
    it = magicalContainer->primeElements.begin();
    pos = 0;
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
{
    it = magicalContainer->primeElements.end();   
    pos = magicalContainer->primeElements.size();
    return *this;
}