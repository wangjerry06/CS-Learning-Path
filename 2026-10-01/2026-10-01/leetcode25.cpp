//reserve nodes in k-group
#include<iostream>
#include<vector>
struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(nullptr){};
};
ListNode* buildList(std::vector<int> values){
    ListNode dummy(0);
    ListNode* tail=&dummy;
    for(int value:values){
        ListNode* fresh=new ListNode(value);
        tail->next=fresh;
        tail=fresh;
    }
    return dummy.next;
}
void clearList(ListNode*& head){
    while(head!=nullptr){
        ListNode* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
bool check(ListNode* head,int k){
    for(int i=0;i<k;++i){
        if(head==nullptr)return false;
        head=head->next;
    }
    return true;
}
ListNode* reserve(ListNode* head,ListNode*& tail,int k){
    ListNode* past=nullptr;
    ListNode* present=head;
    for(int i=0;i<k;++i){
        tail=head;
        ListNode* future=present->next;
        present->next=past;
        past=present;
        present=future;
    }
    return past;
}
ListNode* reserveKGroup(ListNode* head,int k){
    ListNode dummy(0);
    // 【批注1】错误：prevTail 用来挂接反转后的新段。第一次"前一段"就是哑节点 dummy 本身，
    //           写成 dummy.next 会得到 nullptr，导致循环里 prevTail->next=newHead 触发空指针解引用崩溃。
    //           正确写法：ListNode* prevTail=&dummy;
    ListNode* prevTail=&dummy;
    ListNode* groupHead=head;
    while(check(groupHead,k)){
        ListNode* nextGroup=groupHead;
        for(int i=0;i<k;++i){
            nextGroup=nextGroup->next;
        }
        ListNode* groupTail=nullptr;
        ListNode* newHead=reserve(groupHead,groupTail,k);
        prevTail->next=newHead;
        // 【批注2】错误：反转 k 个节点之后，原来的 groupHead 已经变成该段的尾部，下一轮迭代必须推进到 nextGroup 指向的下一段。
        //           写成 groupHead=newHead 会反复在同一段上"反转 → 反转回"，永远走不到 3、5、7 等后续段。
        //           正确写法：groupHead=nextGroup;
        groupHead=nextGroup;
        // 【批注3】错误：reserve() 已经把 groupTail 正确地设为原 groupHead（即反转后该段的真正尾部），正是用来更新 prevTail 的。
        //           这里再被 nextGroup 覆盖，prevTail 就永远停在 dummy，导致循环结束后的 prevTail->next=groupHead 无法挂到正确位置。
        //           正确写法：prevTail=groupTail;
        prevTail=groupTail;
    }
    prevTail->next=groupHead;
    return dummy.next;
}
int main(){
    std::vector<int> values={1,2,3,4,5,6,7,8,9,10};
    int k=2;
    ListNode* head=buildList(values);
    ListNode* res=reserveKGroup(head,k);
    for(ListNode* p=res;p!=nullptr;p=p->next){
        std::cout<<p->value<<' ';
    }
    std::cout<<'\n';
    clearList(res);
}