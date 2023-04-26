//
// Created by liulei on 2023/4/14.
//

#include <memory>
#include <iostream>

class Node;

class Node {
public:
    Node(int value) : value_(value) {}
    void SetPrev(std::shared_ptr<Node> prev) {
        prev_ = prev;
    }
    void SetNext(std::shared_ptr<Node> next) {
        next_ = next;
    }
    std::weak_ptr<Node> GetPrev() const {
        return prev_;
    }
    std::weak_ptr<Node> GetNext() const {
        return next_;
    }
    int GetValue() const {
        return value_;
    }
private:
    int value_;
    std::weak_ptr<Node> prev_;
    std::weak_ptr<Node> next_;
};

int main() {
    std::shared_ptr<Node> a(new Node(1));
    std::shared_ptr<Node> b(new Node(2));
    std::shared_ptr<Node> c(new Node(3));

    // 将三个节点连接成双向链表
    a->SetNext(b);
    b->SetPrev(a);
    b->SetNext(c);
    c->SetPrev(b);

    // 遍历链表并输出每个节点的值
    std::weak_ptr<Node> current = a;
    while (!current.expired()) {
        std::shared_ptr<Node> node = current.lock();
        std::cout << node->GetValue() << std::endl;
        current = node->GetNext();
    }

    return 0;
}
