//
// Created by Egor-Always-AFK on 03.12.2023.
//
#include <gtest/gtest.h>
#include "../src/BST.hpp"
#include <string>

TEST(BstTest, DefaultConstructorTestSuccess) {
    //give && when
    gadzainc_prod::BST<int> tree = gadzainc_prod::BST<int>();

    //then
    ASSERT_FALSE(tree.findNode(0));
}

TEST(BstTEst, InsertAndFindIntSuccessTest) {
    gadzainc_prod::BST<int> tree = gadzainc_prod::BST<int>();
    tree.insertNode(100);

    ASSERT_TRUE(tree.findNode(100));
}

TEST(BstTest, InsertAndFindCharSuccessTest) {
    gadzainc_prod::BST<char> tree = gadzainc_prod::BST<char>();
    tree.insertNode('c');

    ASSERT_TRUE(tree.findNode('c'));
}

TEST(BstTest, InsertDoubleSuccessTest) {
    gadzainc_prod::BST<double> tree = gadzainc_prod::BST<double>();
    tree.insertNode(10.0);

    ASSERT_TRUE(tree.findNode(10.0));
}

TEST(Bst, InsertAndFindLongTest) {
    gadzainc_prod::BST<long> tree = gadzainc_prod::BST<long>();
    tree.insertNode(100L);

    ASSERT_TRUE(tree.findNode(100L));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}