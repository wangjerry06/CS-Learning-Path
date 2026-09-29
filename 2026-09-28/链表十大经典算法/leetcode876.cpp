//链表的中间节点
#include<iostream>
#include<vector>

struct Node{
    int value;
    Node* next;
};

Node* buildList(std::vector<int> values){
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int value:values){
        Node* fresh=new Node{value,nullptr};//记得new，和{}
        if(head==nullptr){
            head=fresh;
        }
        else{
            tail->next=fresh;
        }
        tail=fresh;
    }
    return head;
}

void clearList(Node*& head){
    while(head!=nullptr){
        Node* nextNode=head->next;
        delete head;
        head=nextNode;
    }
}

class Solution{
public:
    Node* middleNode(Node* head){//计数器解法
        Node* res=head;
        int i=0;
        for(Node* p=head;p!=nullptr;p=p->next){
            ++i;
            if(i%2==0){
                res=res->next;
            }
        }
        return res;
    }
    Node* middleNodeFS(Node* head){//快慢指针解法
        Node* fast=head;
        Node* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;//如果总表是偶数，slow先动可以保证中位数在中间的两个中的后一个
        }
        return slow;
    }
};

int main(){
    std::vector<int> v={10,20,30,40,50};
    Node* values=buildList(v);
    Solution res;
    std::cout<<res.middleNode(values)->value<<'\n';
    std::cout<<res.middleNodeFS(values)->value<<'\n';
    clearList(values);
    return 0;
}
