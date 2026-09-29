// leetcode21 — RAII 版：用构造/析构函数自动管理链表生命周期
// 改动思路：把"裸节点 + 手动 clearList"升级为"List 管家类 + 自动析构"
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* next;
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(int x, Node* next) : value(x), next(next) {}
};

class List {
    Node* head;   // 唯一的"财产登记处"：整条链的节点都归 List 对象管
public:
    // 构造函数族：三种出生方式
    List() : head(nullptr) {}                       // 出生即空链
    explicit List(const std::vector<int>& values) : head(nullptr) {
        Node dummy(0);                              // 你原来 buildList 的逻辑搬进来
        Node* tail = &dummy;
        for (int v : values) {
            tail->next = new Node(v);
            tail = tail->next;
        }
        head = dummy.next;
    }

    // ★ 析构函数：对象死亡时自动逐个 delete —— clearList 从此退休
    ~List() { clear(); }

    // 禁止拷贝：两个 List 管同一条链 = 析构时双删（rule of three 伏笔，下次课见）
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    // 移动构造：允许"搬家"——把别人的 head 偷过来，别人置空防止双删
    // （没有它，mergeCopy 里的 return out 无法把局部链表交还给调用方）
    List(List&& other) : head(other.head) { other.head = nullptr; }

    void clear() {                                  // 你原来的 clearList，逻辑不变
        while (head != nullptr) {
            Node* saveNext = head->next;
            delete head;
            head = saveNext;
        }
    }

    Node* headPtr() const { return head; }          // 只读访问，给打印循环用

    // 合并：新建节点版 —— 三条链各管各的节点，析构互不干扰
    // （你原来的 splice 版会"偷"两条输入链的节点，多管家共管一份财产，
    //   析构时会 double free —— 这是下一课 rule of three 要解决的问题）
    List mergeCopy(const List& other) const {
        List out;
        Node dummy(0);
        Node* tail = &dummy;
        Node* p1 = head;
        Node* p2 = other.head;
        while (p1 && p2) {                          // 你的核心算法一行没改
            if (p1->value <= p2->value) {
                tail->next = new Node(p1->value);
                p1 = p1->next;
            } else {
                tail->next = new Node(p2->value);
                p2 = p2->next;
            }
            tail = tail->next;
        }
        for (; p1; p1 = p1->next) { tail->next = new Node(p1->value); tail = tail->next; }
        for (; p2; p2 = p2->next) { tail->next = new Node(p2->value); tail = tail->next; }
        out.head = dummy.next;
        return out;
    }
};

int main() {
    List l1({1, 2, 4, 7, 8});       // 出生：构造函数自动建链
    List l2({1, 3, 4, 5, 8});
    List ans = l1.mergeCopy(l2);

    for (Node* p = ans.headPtr(); p != nullptr; p = p->next) {
        std::cout << p->value << ' ';
    }
    std::cout << '\n';

    return 0;
    // ↓↓ 这里什么都不用写！ans、l2、l1 离开 main 时自动析构，逐个 delete ↓↓
    // 原来的 clearList(ans) 已被 ~List() 全面接管
}
