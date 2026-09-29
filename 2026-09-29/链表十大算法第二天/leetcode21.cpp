//merge two sorted lists
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
    Node(int x):value(x),next(nullptr){};
    Node(int x,Node* next):value(x),next(next){};
};
Node* buildList(std::vector<int>& values){
    Node dummy(0);//等价写法：Node dummy=Node{0,nullptr};但是由于我们前面多定义了几行，所以方便一点
    Node* tail=&dummy;
    for(int value:values){
        Node* fresh=new Node{value,nullptr};
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
    Node* mergeTowList(Node* List1,Node* List2){
        Node dummy(0);
        Node* tail=&dummy;
        while(List1&&List2){
            if(List1->value <= List2->value){
                tail->next=List1;
                List1=List1->next;
            }
            else{
                tail->next=List2;
                List2=List2->next;
            }
            tail=tail->next;
        }
        if(List1){
            tail->next=List1;
        }
        else if(List2){
            tail->next=List2;
        }
        return dummy.next;
    }
};
int main(){
    std::vector<int> v1={1,2,4,7,8};
    std::vector<int> v2={1,3,4,5,8};
    Node* List1=buildList(v1);
    Node* List2=buildList(v2);
    Solution res;
    Node* ans=res.mergeTowList(List1,List2);
    for(Node* p=ans;p!=nullptr;p=p->next){
        std::cout<<p->value<<' ';
    }
    std::cout<<'\n';
    clearList(ans);
    return 0;
}