//
// Created by Egor-Always-AFK on 03.12.2023.
//
#include <gtest/gtest.h>
#include "../src/Node.hpp"

TEST(NodeTest, DefaultConstructorSuccessTest) {
    gadzainc_utils::Node<int> node = gadzainc_utils::Node<int>();
    ASSERT_EQ(0, node.getValue());
    ASSERT_EQ(nullptr, node.getLeft());
    ASSERT_EQ(nullptr, node.getRight());
    ASSERT_EQ(nullptr, node.getParent());
}

