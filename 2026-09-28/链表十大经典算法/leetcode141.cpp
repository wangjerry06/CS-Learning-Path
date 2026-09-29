//Linked List Cycle
#include<iostream>
#include<vector>
#include<unordered_set>
struct Node{
    int value;
    Node* next;
};
Node* buildList(const std::vector<int>& values, int pos, std::vector<Node*>& nodes) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int value : values) {
        Node* fresh = new Node{value,nullptr};
        nodes.push_back(fresh);
        if (head == nullptr) head = fresh;
        else tail->next = fresh;
        tail = fresh;
    }
    if (pos >= 0 && tail != nullptr) {
        tail->next = nodes[pos];   // 尾巴咬回去，环就成了
    }
    return head;
}
void clearList(Node*& head){
    while(head!=nullptr){
        Node* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
class Solution{
public:
    bool hasCycle(Node*& head){
        std::unordered_set<Node*> seen;
        for(Node* p=head;p!=nullptr;p=p->next){
            if(!seen.insert(p).second){
                return true;
            }
        }
        return false;
    }
    /*
    bool hasCycleFS(Node*& head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
    */
};
void runTest(const std::vector<int>& values, int pos, bool expected, int idx) {
    std::vector<Node*> nodes;
    Node* head = buildList(values, pos, nodes);

    Solution sol;
    bool got = sol.hasCycle(head);

    std::cout << "用例 " << idx << " (pos=" << pos << "): 期望 "
              << (expected ? "true" : "false") << " | 输出 "
              << (got ? "true" : "false")
              << (got == expected ? " [通过]" : " [失败]") << '\n';

    // 带环链表的清理铁律：先断环，再 clearList，否则死循环 + 重复 delete
    if (!nodes.empty() && pos >= 0) {
        nodes.back()->next = nullptr;      // tail 是最后一个节点，把它的 next 摘掉
    }
    clearList(head);
}

int main() {
    runTest({3, 2, 0, -4}, 1, true, 1);    // 经典环：尾接回中间
    runTest({1, 2}, 0, true, 2);           // 尾接回头节点
    runTest({1}, -1, false, 3);            // 单节点无环
    runTest({1}, 0, true, 4);              // 单节点自咬成环
    runTest({1, 2, 3, 4, 5}, -1, false, 5);// 普通链表
    runTest({}, -1, false, 6);             // 空链表（边界）
    return 0;
}