//Linked List Cycle II
#include<iostream>
#include<vector>
#include<unordered_set>
struct Node{
    int value;
    Node* next;
};
Node* buildList(std::vector<int>& values){
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int value:values){
        Node* fresh=new Node{value,nullptr};
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
        Node* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
class Solution{
public:
    Node* detectCycle(Node* head){
        std::unordered_set<Node*> seen;
        for(Node* p=head;p!=nullptr;p=p->next){
            if(!seen.insert(p).second){return p;}
        }
        return nullptr;
    }
};