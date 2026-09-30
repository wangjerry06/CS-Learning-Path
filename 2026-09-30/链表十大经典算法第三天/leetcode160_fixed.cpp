//intersection of two Linked List (fixed)
#include<iostream>
#include<vector>              // FIX 0: 补上 vector 头文件（原版靠编译器施舍才过编译）
struct Node{
    int value;
    Node* next;
    Node(int x):value(x),next(nullptr){};   // FIX 1: value(x)，原版写成了 value(0) 把参数扔了
};
Node* buildList(std::vector<int> values){
    Node dummy(0);
    Node* tail=&dummy;
    for(int value:values){
        Node* fresh=new Node{value};
        tail->next=fresh;
        tail=fresh;
    }
    return dummy.next;
}
void clearList(Node*& head){
    while(head!=nullptr){
        Node* saveNext=head->next;   // FIX 2: 先存 next，原版存的是 head 自己 → 死循环+反复 delete
        delete head;
        head=saveNext;
    }
}
void connect(Node* head1,Node* conn){   // FIX 3: 找的是"最后一个节点"而不是 nullptr 本身
    Node* p=head1;
    while(p->next!=nullptr){
        p=p->next;
    }
    p->next=conn;                        // 原版 p=conn 只改了局部变量，链表纹丝不动
}
class Solution{
    public:
    Node* getIntersectionNode(Node* head1,Node* head2){
        Node* p1=head1;
        Node* p2=head2;
        while(p1!=p2){
            p1=p1?p1->next:head2;
            p2=p2?p2->next:head1;
        }
        return p1;
    }
};
int main(){
    std::vector<int> inter{3,4,5};
    std::vector<int> v1{1,2};
    std::vector<int> v2{1,2,3};
    Node* intersection=buildList(inter);
    Node* head1=buildList(v1);
    Node* head2=buildList(v2);
    connect(head1,intersection);
    connect(head2,intersection);
    Solution A;
    Node* resNode=A.getIntersectionNode(head1,head2);
    std::cout<<(resNode?resNode->value:-1)<<'\n';   // 期望 3
    // FIX 4: 两条链共享尾段，clearList(head1) 已把共享节点清掉，
    // head2 只能清自己的独享前缀，走到交点就停，否则 double free
    clearList(head1);
    while(head2!=resNode && head2!=nullptr){
        Node* s=head2->next;
        delete head2;
        head2=s;
    }
    return 0;
}
