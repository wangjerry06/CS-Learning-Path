//palidrome Linked List
#include<iostream>
#include<vector>
struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(nullptr){};
    ListNode(int x,ListNode* node):value(x),next(node){};
};
ListNode* buildList(std::vector<int> values){
    ListNode dummy(0);
    ListNode* tail=&dummy;  // 修复1: tail 必须从 dummy 出发,原先是 nullptr,第一次 tail->next 就段错误
    for(int value:values){
        ListNode* fresh=new ListNode(value,nullptr);
        tail->next=fresh;
        tail=tail->next;
    }
    return dummy.next;
}
void clearList(ListNode* head){
    while(head!=nullptr){
        ListNode* saveNext=head->next;
        delete head;
        head=saveNext;  // 修复2: 必须用提前存好的后继。原写法 delete 后再 head=head->next 是 use-after-free
    }
}
class Solution{
    public:
    ListNode* reverse(ListNode* head){  // 顺手改成值传递,引用没必要
        ListNode* past=nullptr;
        ListNode* present=head;
        while(present!=nullptr){
            ListNode* future=present->next;  // 先存后继
            present->next=past;              // 再改指向
            past=present;                    // 修复3: past 前进到当前节点
            present=future;                  // 修复4: present 去真正的后继
        }                                    // 原先 future=present; present=past; 两行把三个指针搅成一团
        return past;                         // 修复5: 返回 past(新头)。present 此时必然是 nullptr
    }
    bool isPalindrome(ListNode* head){  // 原名 isPalidroem 少打了个字母,顺手正名
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=nullptr)slow=slow->next;
        slow=reverse(slow);
        ListNode* q=head;
        for(ListNode* p=slow;p!=nullptr;p=p->next,q=q->next){
             if(p->value != q->value)return false;
        }
        return true;
    }
};
int main(){
    std::vector<int> v={1,1,2,1};
    ListNode* head=buildList(v);
    // 修复6: 先把所有节点指针登记在册再测试。
    // isPalindrome 里的 reverse 会原地打断链表(后半段被翻过来),
    // 事后从 head 只能走到一半,clearList 会漏删节点造成泄漏
    std::vector<ListNode*> all;
    for(ListNode* p=head;p!=nullptr;p=p->next) all.push_back(p);
    Solution A;
    bool res=A.isPalindrome(head);
    std::cout<<std::boolalpha<<res<<'\n';
    for(ListNode* n:all) delete n;
    return 0;
}