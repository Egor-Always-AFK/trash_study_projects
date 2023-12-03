//
// Created by Egor-Always-AFK on 02.12.2023.
//

#ifndef REP_FOR_SMALL_PROJECTS_BST_HPP
#define REP_FOR_SMALL_PROJECTS_BST_HPP

#include "Node.hpp"
#include <iostream>

namespace gadzainc_prod {
    template<typename T>
    class BST {
    private:
        gadzainc_utils::Node<T> *root = nullptr;

        void insert(gadzainc_utils::Node<T> *&dst, gadzainc_utils::Node<T> *src) {
            if (!dst) {
                dst = new gadzainc_utils::Node<T>(src->getValue());
            } else if (src->value <= dst->value) {
                insert(dst->left, src);
            } else {
                insert(dst->right, src);
            }
        }

        bool find(gadzainc_utils::Node<T> *dst, gadzainc_utils::Node<T> *src) {
            if (!dst) {
                return false;
            } else if (dst->getValue() == src->getValue()) {
                return true;
            } else if (src->getValue() <= dst->getValue()) {
                find(dst->left, src);
            } else {
                find(dst->right, src);
            }
        }
    public:
        BST() = default;
        ~BST() = default;
        explicit BST(gadzainc_utils::Node<T> node): root(node) {}

        void insertNode(gadzainc_utils::Node<T> node) {
            insert(root, node);
        }

        void insertNode(T value) {
            insert(root, new gadzainc_utils::Node<T>(value));
        }

        bool findNode(gadzainc_utils::Node<T> node) {
            return find(root, node);
        }

        bool findNode(T value) {
            return find(root, new gadzainc_utils::Node<T>(value));
        }
    };
}
#endif //REP_FOR_SMALL_PROJECTS_BST_HPP
