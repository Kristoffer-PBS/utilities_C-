#pragma once

#include <memory>
#include <utility>


template <typename T>
class SinglyLinkedList {
    private:
        struct Node {
            T val{};
            std::unique_ptr<Node> next = nullptr;
            Node(const T& val) : val(val) {}

            /* Node(const T& val, Node& other) : val(val) { */
            /*     this->next = std::make_unique(other); */
            /* } */
        };

        std::size_t _size = 0;

        // sentinel nodes
        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;
        /* Node* head; */
        /* Node* tail; */

    public:
        SinglyLinkedList() {
            _size = 0;
            head = std::make_unique<Node>();
            tail = std::make_unique<Node>();
            head->next = tail;
        }

        ~SinglyLinkedList() { clear(); }
        std::size_t size() const { return _size; }
        bool empty() const { return _size == 0; }
        void clear();
        void push_front(const T& item) {
            auto node = Node(item);
            node.next = head->next;
            head->next = std::make_unique<Node>(node);
        }

        void insert(const T& item, std::size_t pos);
        std::size_t find_kth(std::size_t pos);
        T pop_front();
        T remove(std::size_t pos);
};



