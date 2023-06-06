#ifndef MAGICAL_CONTAINER_H
#define MAGICAL_CONTAINER_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <list>

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
        vector<int> defaultElements; 
        vector<int> sideCrossElements;
        vector<int> ascendingElements;
        vector<int> primeElements;

        bool isPrime(int number) const;

    public:
        MagicalContainer();
        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        MagicalContainer &operator=(const MagicalContainer &other);

        void addElement(int element);
        void removeElement(int element);
        size_t size() const;

        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator
    {
    private:
        MagicalContainer *magicalContainer;
        vector<int>::iterator it;
        size_t pos;

    public:
        AscendingIterator(MagicalContainer &magicalContainer);
        AscendingIterator(const AscendingIterator &other);
        ~AscendingIterator();

        AscendingIterator &operator=(const AscendingIterator &other);
        bool operator==(const AscendingIterator &other) const;
        bool operator!=(const AscendingIterator &other) const;
        bool operator>(const AscendingIterator &other) const;
        bool operator<(const AscendingIterator &other) const;

        size_t getPosition() const;

        int operator*() const;
        AscendingIterator &operator++();
        AscendingIterator &operator++(int);

        vector<int>::iterator &begin();
        vector<int>::iterator &end();
    };

    class MagicalContainer::SideCrossIterator
    {
    private:
        MagicalContainer *magicalContainer;
        vector<int>::iterator it;
        size_t pos;

    public:
        SideCrossIterator(MagicalContainer &magicalContainer);
        SideCrossIterator(const SideCrossIterator &other);
        ~SideCrossIterator();

        SideCrossIterator &operator=(const SideCrossIterator &other);
        bool operator==(const SideCrossIterator &other) const;
        bool operator!=(const SideCrossIterator &other) const;
        bool operator>(const SideCrossIterator &other) const;
        bool operator<(const SideCrossIterator &other) const;

        int operator*() const;
        SideCrossIterator &operator++();
        SideCrossIterator &operator++(int);

        size_t getPosition() const;

        vector<int>::iterator &begin();
        vector<int>::iterator &end();
    };

    class MagicalContainer::PrimeIterator
    {
    private:
        MagicalContainer *magicalContainer;
        vector<int>::iterator it;
        size_t pos;

    public:
        PrimeIterator(MagicalContainer &magicalContainer);
        PrimeIterator(const PrimeIterator &other);
        ~PrimeIterator();

        PrimeIterator &operator=(const PrimeIterator &other);
        bool operator==(const PrimeIterator &other) const;
        bool operator!=(const PrimeIterator &other) const;
        bool operator>(const PrimeIterator &other) const;
        bool operator<(const PrimeIterator &other) const;

        int operator*() const;
        PrimeIterator &operator++();
        PrimeIterator &operator++(int);

        size_t getPosition() const;

        vector<int>::iterator &begin();
        vector<int>::iterator &end();
    };
} // namespace ariel  

#endif  // MAGICAL_CONTAINER_H

