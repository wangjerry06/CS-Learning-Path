//intersection of two Linked List
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
    Node(int x):value(x),next(nullptr){};
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
        Node* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
void connect(Node*& head1,Node*& conn){
    Node* p=head1;
    while(p->next!=nullptr){
        p=p->next;
    }
    p->next=conn;
}
class Solution{
    public:
    Node* getIntersectionNode(Node* head1,Node* head2){
        Node* p1=head1;
        Node* p2=head2;
        while(p1!=p2){
            p1=p1?p1->next:head2;
            p2=p2?p2->next:head1;
            /*这里的格式是：
            对象=判断的东西?正确的话赋的值:错误的话赋的值
            作用相当于
            if(p1!=nullptr){p1=p1->next;}
            else p1=head2;
            */
        }
        return p2;
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
    Node* resList=A.getIntersectionNode(head1,head2);
    int res=resList->value;
    std::cout<<res<<'\n';
    clearList(head1);
    while(head2!=resList&&head2!=nullptr){
        Node* saveNext=head2->next;
        delete head2;
        head2=saveNext;
    }
    return 0;
}