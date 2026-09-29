//mergeKLists
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
    Node(int x):value(x),next(nullptr){};
};
Node* buildList(const std::vector<int>& values){
    Node dummy(0);
    Node* tail=&dummy;
    for(int value:values){
        Node* fresh=new Node{value};
        tail->next=fresh;
        tail=tail->next;
    }
    return dummy.next;
}
void clearList(Node* head){
    while(head!=nullptr){
        Node* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
/*
class Solution {
public:
    Node* merge2Lists(Node* l1,Node* l2){
        Node dummy(0);
        Node* tail=&dummy;
        while(l1&&l2){
            if(l1->value<=l2->value){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1){
            tail->next=l1;
        }
        else if(l2){
            tail->next=l2;
        }
        return dummy.next;
    }
    Node* mergeKLists(std::vector<Node*>& lists) {
        if(lists.empty())return nullptr;
        Node* head=nullptr;
        size_t count=lists.size();
        for(size_t i=0;i<count;++i){
            head=merge2Lists(head,lists[i]);
        }
        return head;
    }
};
*/
//解法1，耗时，用的是一个一个比较
class Solution{
public:
    Node* merge2Lists(Node* list1,Node* list2){
        Node dummy(0);
        Node* tail=&dummy;
        while(list1&&list2){
            if(list1->value<=list2->value){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        tail->next=list1?list1:list2;
        return dummy.next;
    }
    Node* mergeRange(std::vector<Node*>& lists,int lo,int hi){
        if(lo==hi)return lists[lo];
        int mid=lo+(hi-lo)/2;
        return merge2Lists(mergeRange(lists,lo,mid),mergeRange(lists,mid+1,hi));
        }
    Node* mergeKLists(std::vector<Node*>& lists){
        if(lists.empty())return nullptr;
        return mergeRange(lists,0,(int)lists.size()-1);
    }
};
// ================= 补全的 main =================

// 打印链表
static void printList(Node* head) {
    if (!head) { std::cout << "(空)"; return; }
    for (Node* p = head; p; p = p->next) std::cout << p->value << " ";
}

// 校验：非空且升序
static bool isSorted(Node* head) {
    if (!head) return false;
    while (head->next) {
        if (head->value > head->next->value) return false;
        head = head->next;
    }
    return true;
}

// 数节点数（用来确认没有丢链、没有丢节点）
static int countNodes(Node* head) {
    int n = 0;
    while (head) { ++n; head = head->next; }
    return n;
}

int main() {
    Solution s;

    // 用例 1：经典三条链（LC 官方示例）
    {
        std::vector<Node*> lists = {buildList({1, 4, 5}), buildList({1, 3, 4}), buildList({2, 6})};
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例1 三条链: ";
        printList(ans);
        std::cout << "| 有序:" << (isSorted(ans) ? "PASS" : "FAIL")
                  << " 节点数:" << countNodes(ans) << "(期望8)\n";
        clearList(ans);   // 合并后所有节点都在 ans 里，只 free 这一次就够
    }

    // 用例 2：空 vector
    {
        std::vector<Node*> lists = {};
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例2 空输入: " << (ans == nullptr ? "nullptr PASS" : "FAIL") << "\n";
    }

    // 用例 3：只有一条链
    {
        std::vector<Node*> lists = {buildList({0, 2, 9})};
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例3 单条链: ";
        printList(ans);
        std::cout << "| 有序:" << (isSorted(ans) ? "PASS" : "FAIL") << "\n";
        clearList(ans);
    }

    // 用例 4：中间夹空链
    {
        std::vector<Node*> lists = {buildList({-2, -1}), nullptr, buildList({5})};
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例4 夹空链: ";
        printList(ans);
        std::cout << "| 有序:" << (isSorted(ans) ? "PASS" : "FAIL")
                  << " 节点数:" << countNodes(ans) << "(期望3)\n";
        clearList(ans);
    }

    // 用例 5：全空链
    {
        std::vector<Node*> lists = {nullptr, nullptr};
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例5 全空链: " << (ans == nullptr ? "nullptr PASS" : "FAIL") << "\n";
    }

    // 用例 6：五条链，故意奇数条，考一考"落单链"
    {
        std::vector<Node*> lists = {
            buildList({1, 7}), buildList({3}), buildList({2, 8, 10}),
            buildList({5, 6}), buildList({4, 9})
        };
        Node* ans = s.mergeKLists(lists);
        std::cout << "用例6 五条链: ";
        printList(ans);
        std::cout << "| 有序:" << (isSorted(ans) ? "PASS" : "FAIL")
                  << " 节点数:" << countNodes(ans) << "(期望10)\n";
        clearList(ans);
    }

    std::cout << "\n内存说明：mergeKLists 会把所有节点重新接线进结果链，\n"
                 "所以 main 里只 clearList(ans) 一次，绝不能再对 lists 里的旧指针 clearList（那会 double free）。\n";
    return 0;
}
