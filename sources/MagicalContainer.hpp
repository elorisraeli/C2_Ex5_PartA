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
        vector<int> defaultElements; // stores original insertion order
        vector<int> sideCrossElements; // stores elements in cross order
        vector<int> ascendingElements; // stores elements in ascending order
        vector<int> primeElements;    // stores prime numbers only

        void updateCrossElements();
        bool isPrime(int number) const;

    public:
        MagicalContainer() = default;
        ~MagicalContainer() = default;
        MagicalContainer(const MagicalContainer &other) = default;
        MagicalContainer &operator=(const MagicalContainer &other) = default;
        MagicalContainer(MagicalContainer &&other) noexcept = default;
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;

        void addElement(int element);
        void removeElement(int element);
        size_t size() const;

        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        // Nested classes
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
        ~AscendingIterator() = default;
        AscendingIterator(AscendingIterator &&other) noexcept = default;
        AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;

        AscendingIterator &operator=(const AscendingIterator &other);
        bool operator==(const AscendingIterator &other) const;
        bool operator!=(const AscendingIterator &other) const;
        bool operator>(const AscendingIterator &other) const;
        bool operator<(const AscendingIterator &other) const;

        size_t getPosition() const { return pos; };

        int operator*() const;
        AscendingIterator &operator++();

        AscendingIterator &begin();
        AscendingIterator &end();
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
        ~SideCrossIterator() = default;
        SideCrossIterator(SideCrossIterator &&other) noexcept = default;
        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;

        SideCrossIterator &operator=(const SideCrossIterator &other);
        bool operator==(const SideCrossIterator &other) const;
        bool operator!=(const SideCrossIterator &other) const;
        bool operator>(const SideCrossIterator &other) const;
        bool operator<(const SideCrossIterator &other) const;

        int operator*() const;
        SideCrossIterator &operator++();

        size_t getPosition() const { return pos; };

        SideCrossIterator &begin();
        SideCrossIterator &end();
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
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator &&other) noexcept = default;
        PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;

        PrimeIterator &operator=(const PrimeIterator &other);
        bool operator==(const PrimeIterator &other) const;
        bool operator!=(const PrimeIterator &other) const;
        bool operator>(const PrimeIterator &other) const;
        bool operator<(const PrimeIterator &other) const;

        int operator*() const;
        PrimeIterator &operator++();

        size_t getPosition() const { return pos; };

        PrimeIterator &begin();
        PrimeIterator &end();
    };
} // namespace ariel  

#endif  // MAGICAL_CONTAINER_H

