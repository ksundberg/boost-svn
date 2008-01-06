
// Copyright 2006-2007 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This test creates the containers with members that meet their minimum
// requirements. Makes sure everything compiles and is defined correctly.

#include <boost/unordered_map.hpp>

#include <iostream>
#include <boost/detail/lightweight_test.hpp>
#include "../objects/minimal.hpp"
#include "./compile_tests.hpp"

void test0()
{
    typedef std::pair<test::minimal::assignable const,
            test::minimal::copy_constructible> value_type;
    value_type value(
            test::minimal::assignable::create(),
            test::minimal::copy_constructible::create());

    std::cout<<"Test unordered_map.\n";
    boost::unordered_map<
        test::minimal::assignable,
        test::minimal::copy_constructible,
        test::minimal::hash<test::minimal::assignable>,
        test::minimal::equal_to<test::minimal::assignable>,
        test::minimal::allocator<value_type> > map;

    container_test(map, value);

    std::cout<<"Test unordered_multimap.\n";
    boost::unordered_multimap<
        test::minimal::assignable,
        test::minimal::copy_constructible,
        test::minimal::hash<test::minimal::assignable>,
        test::minimal::equal_to<test::minimal::assignable>,
        test::minimal::allocator<value_type> > multimap;

    container_test(multimap, value);
}

void test1()
{
    boost::hash<int> hash;
    std::equal_to<int> equal_to;
    int value = 0;
    std::pair<int const, int> map_value(0, 0);

    std::cout<<"Test unordered_map.\n";

    boost::unordered_map<int, int> map;

    unordered_unique_test(map, map_value);
    unordered_map_test(map, value, value);
    unordered_test(map, value, map_value, hash, equal_to);
    unordered_map_functions(map, value, value);

    std::cout<<"Test unordered_multimap.\n";

    boost::unordered_multimap<int, int> multimap;

    unordered_equivalent_test(multimap, map_value);
    unordered_map_test(multimap, value, value);
    unordered_test(multimap, value, map_value, hash, equal_to);
}

void test2()
{
    test::minimal::assignable assignable
        = test::minimal::assignable::create();
    test::minimal::copy_constructible copy_constructible
        = test::minimal::copy_constructible::create();
    test::minimal::hash<test::minimal::assignable> hash
        = test::minimal::hash<test::minimal::assignable>::create();
    test::minimal::equal_to<test::minimal::assignable> equal_to
        = test::minimal::equal_to<test::minimal::assignable>::create();

    typedef std::pair<test::minimal::assignable const,
            test::minimal::copy_constructible> map_value_type;
    map_value_type map_value(assignable, copy_constructible);

    std::cout<<"Test unordered_map.\n";

    boost::unordered_map<
        test::minimal::assignable,
        test::minimal::copy_constructible,
        test::minimal::hash<test::minimal::assignable>,
        test::minimal::equal_to<test::minimal::assignable>,
        test::minimal::allocator<map_value_type> > map;

    unordered_unique_test(map, map_value);
    unordered_map_test(map, assignable, copy_constructible);
    unordered_test(map, assignable, map_value, hash, equal_to);


    boost::unordered_map<
        test::minimal::assignable,
        test::minimal::default_copy_constructible,
        test::minimal::hash<test::minimal::assignable>,
        test::minimal::equal_to<test::minimal::assignable>,
        test::minimal::allocator<map_value_type> > map2;

    test::minimal::default_copy_constructible default_copy_constructible;

    unordered_map_functions(map2, assignable, default_copy_constructible);

    std::cout<<"Test unordered_multimap.\n";

    boost::unordered_multimap<
        test::minimal::assignable,
        test::minimal::copy_constructible,
        test::minimal::hash<test::minimal::assignable>,
        test::minimal::equal_to<test::minimal::assignable>,
        test::minimal::allocator<map_value_type> > multimap;

    unordered_equivalent_test(multimap, map_value);
    unordered_map_test(multimap, assignable, copy_constructible);
    unordered_test(multimap, assignable, map_value, hash, equal_to);
}

int main()
{
    test0();
    test1();
    test2();

    return boost::report_errors();
}
