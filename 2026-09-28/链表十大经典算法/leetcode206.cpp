//reverse Linked List
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
};
Node* buildlist(const std::vector<int>& values){
    //这里是建表
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int value:values){
        Node* fresh=new Node{value,nullptr};
        if(head==nullptr)head=fresh;
        else tail->next=fresh;
        tail=fresh;
    }
    return head;
}
void clearList(Node*& head){
    //清除内存
    while(head!=nullptr){
        Node* victim=head->next;
        delete head;
        head=victim;
    }
}//以上是leetcode已有的
class Solution{
public:
    Node* reverseList(Node* head){
        Node* A=nullptr;
        Node* B=head;//记得这里是head
        while(B!=nullptr){
            Node* C=B->next;
            B->next=A;
            A=B;
            B=C;
        }
        return A;//这里的A是新head
    }
};
int main(){
    std::vector<int> v={10,20,30,40};
    Node* list=buildlist(v);
    Solution ans;
    Node* res=ans.reverseList(list);
    for(Node* p=res;p!=nullptr;p=p->next){//遍历输出
        std::cout<<p->value<<' ';
    }
    std::cout<<'\n';
    clearList(res);
    //清除内存
    return 0;
}