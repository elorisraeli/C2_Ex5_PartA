#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MagicalContainer.hpp"
#include "AscendingIterator.hpp"
#include "SideCrossIterator.hpp"
#include "PrimeIterator.hpp"

TEST_CASE("Test 1: Adding elements to MagicalContainer") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(9);
    CHECK(container.size() == 3);
}

TEST_CASE("Test 2: Removing elements from MagicalContainer") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(9);
    container.removeElement(3);
    CHECK(container.size() == 2);
}

TEST_CASE("Test 3: Iterating over MagicalContainer in ascending order") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(9);
    AscendingIterator ascIter(container);
    CHECK(*ascIter++ == 3);
    CHECK(*ascIter++ == 5);
    CHECK(*ascIter == 9);
}

TEST_CASE("Test 4: Iterating over empty MagicalContainer in ascending order") {
    MagicalContainer container;
    AscendingIterator ascIter(container);
    CHECK(ascIter == ascIter.end());
}

TEST_CASE("Test 5: Iterating over MagicalContainer in cross order") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(9);
    SideCrossIterator crossIter(container);
    CHECK(*crossIter++ == 3);
    CHECK(*crossIter++ == 9);
    CHECK(*crossIter == 5);
}

TEST_CASE("Test 6: Iterating over empty MagicalContainer in cross order") {
    MagicalContainer container;
    SideCrossIterator crossIter(container);
    CHECK(crossIter == crossIter.end());
}

TEST_CASE("Test 7: Iterating over MagicalContainer with prime numbers only") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(9);
    PrimeIterator primeIter(container);
    CHECK(*primeIter++ == 3);
    CHECK(*primeIter == 5);
}

TEST_CASE("Test 8: Iterating over empty MagicalContainer with prime numbers only") {
    MagicalContainer container;
    PrimeIterator primeIter(container);
    CHECK(primeIter == primeIter.end());
}

TEST_CASE("Test 9: Equality of iterators") {
    MagicalContainer container;
    container.addElement(5);
    AscendingIterator it1(container);
    AscendingIterator it2(container);
    CHECK(it1 == it2);
}

TEST_CASE("Test 10: Inequality of iterators") {
    MagicalContainer container;
    container.addElement(5);
    AscendingIterator it1(container);
    AscendingIterator it2 = it1;
    it2++;
    CHECK(it1 != it2);
}

TEST_CASE("Test 11: Size of MagicalContainer after adding elements") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
}

TEST_CASE("Test 12: Size of MagicalContainer after removing elements") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.removeElement(2);
    CHECK(container.size() == 2);
}

TEST_CASE("Test 13: AscendingIterator end") {
    MagicalContainer container;
    container.addElement(1);
    AscendingIterator it = container.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(it == container.end());
}

TEST_CASE("Test 14: SideCrossIterator end") {
    MagicalContainer container;
    container.addElement(1);
    SideCrossIterator it = container.begin();
    CHECK(*it == 1);
    ++it;
    CHECK(it == container.end());
}

TEST_CASE("Test 15: PrimeIterator end") {
    MagicalContainer container;
    container.addElement(2);
    PrimeIterator it = container.begin();
    CHECK(*it == 2);
    ++it;
    CHECK(it == container.end());
}

TEST_CASE("Test 16: AscendingIterator with multiple elements") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(2);
    container.addElement(1);
    AscendingIterator it = container.begin();
    CHECK(*it++ == 1);
    CHECK(*it++ == 2);
    CHECK(*it == 3);
}

TEST_CASE("Test 17: SideCrossIterator with multiple elements") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(2);
    container.addElement(1);
    SideCrossIterator it = container.begin();
    CHECK(*it++ == 1);
    CHECK(*it++ == 3);
    CHECK(*it == 2);
}

TEST_CASE("Test 18: PrimeIterator with multiple elements") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(3);
    container.addElement(2);
    PrimeIterator it = container.begin();
    CHECK(*it++ == 2);
    CHECK(*it == 3);
}

TEST_CASE("Test 19: Copy constructor for AscendingIterator") {
    MagicalContainer container;
    container.addElement(2);
    AscendingIterator it1 = container.begin();
    AscendingIterator it2(it1);
    CHECK(*it2 == 2);
}

TEST_CASE("Test 20: Assignment operator for AscendingIterator") {
    MagicalContainer container;
    container.addElement(2);
    AscendingIterator it1 = container.begin();
    AscendingIterator it2;
    it2 = it1;
    CHECK(*it2 == 2);
}
