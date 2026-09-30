//Remove nth Node from end of list
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
    Node(int x):value(x),next(nullptr){};
    Node(int x,Node* node):value(x),next(node){};
};
Node* buildList(std::vector<int>& values){
    Node dummy(0);//这个是栈上对象，不用删，{}结束他就死了
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
class Solution{
    public:
    Node* RemoveNthNode(Node* head,int n){
        Node* dummy=new Node{0,head};//这个new的地址在堆上，要记得清
        Node* slow=dummy;//slow要比fast慢n+1，因为我们要让slow->next落在删掉的位置上
        Node* fast=head;
        for(int i=0;i<n;++i){//fast先走n
            fast=fast->next;
        }
        while(fast!=nullptr){//两个同时前进，fast到尾的时候，slow->next刚好就是target
            slow=slow->next;
            fast=fast->next;
        }
        Node* victim=slow->next;
        slow->next=victim->next;
        delete victim;//删掉target
        Node* newhead=dummy->next;//删掉之前要拷贝地址
        delete dummy;//new的要删不能留
        return newhead;
    }
};
int main(){
    std::vector<int> v={1,2,3,4,5,6};
    Node* head=buildList(v);
    Solution A;
    head=A.RemoveNthNode(head,2);
    for(Node* p=head;p!=nullptr;p=p->next){
        std::cout<<p->value<<' ';
    }
    std::cout<<'\n';
    clearList(head);
    return 0;
}