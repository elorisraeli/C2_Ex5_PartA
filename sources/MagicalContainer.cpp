#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>
#include <vector>

namespace ariel
{

    /************* MagicalContainer ************/

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

    MagicalContainer::MagicalContainer()
    {
    }

    MagicalContainer::~MagicalContainer()
    {
    }

    MagicalContainer::MagicalContainer(const MagicalContainer &other)
    {
    }

    void MagicalContainer::addElement(int element)
    {
        defaultElements.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        if (defaultElements.size() == 0)
        {
            return;
        }
        defaultElements.erase(remove(defaultElements.begin(),defaultElements.end(), element), defaultElements.end());
    }

    size_t MagicalContainer::size() const
    {
        return defaultElements.size();
    }

    bool MagicalContainer::operator==(const MagicalContainer &other) const
    {
        return false;
    }

    bool MagicalContainer::operator!=(const MagicalContainer &other) const
    {
        return false;
    }

    MagicalContainer &MagicalContainer::operator=(const MagicalContainer &other)
    {
        return *this;
    }


    /************ AscendingIterator ***********/

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), pos(0), it(magicalContainer.ascendingElements.begin())
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : magicalContainer(other.magicalContainer), pos(other.pos), it(other.it)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return true;
    }

    size_t MagicalContainer::AscendingIterator::getPosition() const
    {
        return 0;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return true;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(int)
    {
        return *this;
    }

    vector<int>::iterator &MagicalContainer::AscendingIterator::begin()
    {
        return it;
    }

    vector<int>::iterator &MagicalContainer::AscendingIterator::end()
    {
        return it;
    }

    /************ SideCrossIterator ***********/

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), it(magicalContainer.sideCrossElements.begin()), pos(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magicalContainer(other.magicalContainer), it(other.it), pos(other.pos) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return true;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(int)
    {
        return *this;
    }

    size_t MagicalContainer::SideCrossIterator::getPosition() const
    {
        return pos;
    }

    vector<int>::iterator &MagicalContainer::SideCrossIterator::begin()
    {
        return it;
    }

    vector<int>::iterator &MagicalContainer::SideCrossIterator::end()
    {
        return it;
    }

    // /************* PrimeIterator ***************/

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer) : magicalContainer(&magicalContainer), it(magicalContainer.primeElements.begin()), pos(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : magicalContainer(other.magicalContainer), it(other.it), pos(other.pos) {}

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return true;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(int)
    {
        return *this;
    }

    vector<int>::iterator &MagicalContainer::PrimeIterator::begin()
    {
        return it;
    }

    vector<int>::iterator &MagicalContainer::PrimeIterator::end()
    {
        return it;
    }

}