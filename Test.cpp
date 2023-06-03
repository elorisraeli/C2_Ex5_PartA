#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <algorithm>

using namespace ariel;

TEST_CASE("Test addElement")
{
    MagicalContainer mc;
    mc.addElement(3);
    mc.addElement(2);
    mc.addElement(1);
    CHECK(mc.size() == 3);
}

TEST_CASE("Test removeElement")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.removeElement(2);
    CHECK(mc.size() == 1);
}

TEST_CASE("Test equality of MagicalContainers")
{
    MagicalContainer mc1;
    MagicalContainer mc2;
    mc1.addElement(1);
    mc1.addElement(2);
    mc2.addElement(1);
    mc2.addElement(2);
    CHECK(mc1 == mc2);
}

TEST_CASE("Test inequality of MagicalContainers")
{
    MagicalContainer mc1;
    MagicalContainer mc2;
    mc1.addElement(1);
    mc2.addElement(2);
    CHECK(mc1 != mc2);
}

TEST_CASE("Test prime iterator")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);
    mc.addElement(6);

    MagicalContainer::PrimeIterator it(mc);
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
}

TEST_CASE("Test ascending iterator")
{
    MagicalContainer mc;
    mc.addElement(5);
    mc.addElement(3);
    mc.addElement(1);

    MagicalContainer::AscendingIterator it(mc);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 5);
}

TEST_CASE("Test side cross iterator")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);

    MagicalContainer::SideCrossIterator it(mc);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
}

TEST_CASE("Test iterator begin")
{
    MagicalContainer mc;
    mc.addElement(5);
    mc.addElement(3);
    mc.addElement(1);

    MagicalContainer::AscendingIterator it(mc);
    it.begin();
    CHECK(*it == 1);
}

TEST_CASE("Test iterator remove")
{
    MagicalContainer mc;
    mc.addElement(5);
    mc.addElement(3);
    mc.addElement(1);

    MagicalContainer::AscendingIterator it(mc);
    mc.removeElement(5);
    CHECK(*it == 3);
}

TEST_CASE("Test iterator equality")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);

    MagicalContainer::SideCrossIterator it1(mc);
    MagicalContainer::SideCrossIterator it2(mc);
    CHECK(it1 == it2);
}

TEST_CASE("Test iterator inequality")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);

    MagicalContainer::SideCrossIterator it1(mc);
    MagicalContainer::SideCrossIterator it2(mc);
    ++it2;
    CHECK(it1 != it2);
}

TEST_CASE("Test iterator increment")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);

    MagicalContainer::SideCrossIterator it(mc);
    ++it;
    CHECK(*it == 3);
}

TEST_CASE("Test iterator decrement")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);

    MagicalContainer::SideCrossIterator it(mc);
    mc.removeElement(3);
    CHECK(*it == 2);
}

TEST_CASE("Test container size after removing all elements")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.removeElement(1);
    mc.removeElement(2);
    mc.removeElement(3);
    CHECK(mc.size() == 0);
}

TEST_CASE("Test container size after adding duplicates")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(1);
    mc.addElement(2);
    CHECK(mc.size() == 3);
}

TEST_CASE("Test container size after removing duplicates")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(1);
    mc.addElement(2);
    mc.removeElement(1);
    CHECK(mc.size() == 2);
}

TEST_CASE("Test removeElement when container is empty")
{
    MagicalContainer mc;
    CHECK_THROWS(mc.removeElement(1));
}

TEST_CASE("Test removeElement when element is not in the container")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    CHECK_THROWS(mc.removeElement(4));
}

TEST_CASE("Test addElement with negative values")
{
    MagicalContainer mc;
    mc.addElement(-1);
    mc.addElement(-2);
    CHECK(mc.size() == 2);
}

TEST_CASE("Test removeElement with negative values")
{
    MagicalContainer mc;
    mc.addElement(-1);
    mc.addElement(-2);
    mc.removeElement(-1);
    CHECK(mc.size() == 1);
}
