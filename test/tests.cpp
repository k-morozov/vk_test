//
// Created by focus on 15.05.22.
//

#include "gtest/gtest.h"
#include "FirstNRepeatingStream.h"


TEST(TestContext, firstFromTask) {
    constexpr int N = 1;
    FirstNRepeatingStream stream(N);

//    a   ->   a
    auto result = stream.next('a');
    std::optional<char> expected = 'a';
    ASSERT_EQ(result, expected);

//    b   ->   a
    result = stream.next('b');
    expected = 'a';
    ASSERT_EQ(result, expected);

//    b   ->   a
    result = stream.next('b');
    expected = 'a';
    ASSERT_EQ(result, expected);

//    c   ->   a
    result = stream.next('c');
    expected = 'a';
    ASSERT_EQ(result, expected);

//    a   ->   c
    result = stream.next('a');
    expected = 'c';
    ASSERT_EQ(result, expected);

//    c   ->   nullopt
    result = stream.next('c');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

//    f   ->   f
    result = stream.next('f');
    expected = 'f';
    ASSERT_EQ(result, expected);

//    g   ->   f
    result = stream.next('g');
    expected = 'f';
    ASSERT_EQ(result, expected);
}

TEST(TestContext, secondFromTask) {
    constexpr int N = 2;
    FirstNRepeatingStream stream(N);

    // b   ->   b
    auto result = stream.next('b');
    std::optional<char> expected = 'b';
    ASSERT_EQ(result, expected);

// c   ->   b
    result = stream.next('c');
    expected = 'b';
    ASSERT_EQ(result, expected);

// f   ->   b
    result = stream.next('f');
    expected = 'b';
    ASSERT_EQ(result, expected);

// b   ->   b
    result = stream.next('b');
    expected = 'b';
    ASSERT_EQ(result, expected);

// f   ->   b
    result = stream.next('f');
    expected = 'b';
    ASSERT_EQ(result, expected);

// c   ->   b
    result = stream.next('c');
    expected = 'b';
    ASSERT_EQ(result, expected);

// b   ->   c
    result = stream.next('b');
    expected = 'c';
    ASSERT_EQ(result, expected);

// c   ->   f
    result = stream.next('c');
    expected = 'f';
    ASSERT_EQ(result, expected);

// c   ->   f
    result = stream.next('c');
    expected = 'f';
    ASSERT_EQ(result, expected);

// f   ->   nullopt
    result = stream.next('f');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

// c   ->   nullopt
    result = stream.next('c');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

// c   ->   nullopt
    result = stream.next('c');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

// b   ->   nullopt
    result = stream.next('b');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

// b   ->   nullopt
    result = stream.next('b');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);
}

TEST(TestContext, zeroSize) {
    constexpr int N = 0;
    FirstNRepeatingStream stream(N);

    auto result = stream.next('b');
    std::optional<char> expected = std::nullopt;
    ASSERT_EQ(result, expected);

    result = stream.next('b');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);

    result = stream.next('a');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);
}

TEST(TestContext, repeatBy3) {
    constexpr int N = 2;
    FirstNRepeatingStream stream(N);

    auto result = stream.next('a');
    std::optional<char> expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('b');
    expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('b');
    expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('b');
    expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('c');
    expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('a');
    expected = 'a';
    ASSERT_EQ(result, expected);

    result = stream.next('a');
    expected = 'c';
    ASSERT_EQ(result, expected);

    result = stream.next('c');
    expected = 'c';
    ASSERT_EQ(result, expected);

    result = stream.next('c');
    expected = std::nullopt;
    ASSERT_EQ(result, expected);
}