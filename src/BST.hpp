//
// Created by Egor-Always-AFK on 02.12.2023.
//

#ifndef REP_FOR_SMALL_PROJECTS_BST_HPP
#define REP_FOR_SMALL_PROJECTS_BST_HPP

#include "Node.hpp"

namespace gadzainc_prod {
    template<typename T>
    class BST {
    private:
        gadzainc_utils::Node<T> *root;

        void insert(gadzainc_utils::Node<T> *node) {
            if (root == nullptr) {
                root = new gadzainc_utils::Node<T>(node->getValue());
            } else if (node->getValue() <= root->getValue()) {
                insert(root->left);
            } else {
                insert(root->right);
            }
        }

        bool find(gadzainc_utils::Node<T> *node) {
            if (root == nullptr) {
                return false;
            } else if (node->getValue() == root->getValue()) {
                return true;
            } else if (node->getValue() <= root->getValue()) {
                find(root->left);
            } else {
                find(root->right);
            }
        }
    public:
        BST() = default;
        explicit BST(gadzainc_utils::Node<T> node): root(node) {}

        void insertNode(gadzainc_utils::Node<T> node) {
            insert(node);
        }

        void insertNode(T value) {
            insert(new gadzainc_utils::Node<T>(value));
        }

        bool findNode(gadzainc_utils::Node<T> node) {
            return find(node);
        }

        bool findNode(T value) {
            return find(new gadzainc_utils::Node<T>(value));
        }
    };
}
#endif //REP_FOR_SMALL_PROJECTS_BST_HPP
