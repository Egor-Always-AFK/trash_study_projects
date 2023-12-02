//
// Created by Egor-Always-AFK on 02.12.2023.
//

#ifndef REP_FOR_SMALL_PROJECTS_NODE_HPP
#define REP_FOR_SMALL_PROJECTS_NODE_HPP

namespace gadzainc_utils {
    template<typename T>
    class Node {
    private:
        // value part
        T value;
    public:
        // inheritance part
        gadzainc_utils::Node<T> *left, *right, *parent;

        Node() = default;
        Node(T value): right(nullptr), left(nullptr), parent(nullptr) {
            this->value = value;
        }
        Node(T value,
             gadzainc_utils::Node<T> *left,
             gadzainc_utils::Node<T>* right,
             gadzainc_utils::Node<T> *parent): left(left), right(right), parent(parent) {
            this->value = value;
        };

        Node(gadzainc_utils::Node<T> &node): right(node.getRight()),
                                                    left(node.getLeft()),
                                                    parent(node.getParent()) {
            this->value = node.getValue();
        }
        ~Node() = default;

        T getValue() { return value; }

        gadzainc_utils::Node<T> *getLeft() { return left; }

        gadzainc_utils::Node<T> *getRight() { return right; }

        gadzainc_utils::Node<T> *getParent() { return parent; }
    };
} // gadzainc

#endif //REP_FOR_SMALL_PROJECTS_NODE_HPP
