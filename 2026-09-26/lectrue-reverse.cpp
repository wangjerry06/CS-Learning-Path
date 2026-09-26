//reverse linked list
#include<iostream>
#include<vector>
struct Node{
    int value;
    Node* next;
};
Node* build(const std::vector<int>&values){//建表
    Node* head=nullptr;
    Node* tail=nullptr;//先定义头和尾是空的
    for(int value:values){
        Node* fresh=new Node{value,nullptr};//把对应的这一个输入进来，变成一个Node
        if(head==nullptr){//这个fresh是第一个进来的
            head=fresh;
        }
        else{
            tail->next=fresh;//后面进来的，就放在加在tail

        }
        tail=fresh;//一定要记得重新定义tail
    }
    return head;
}
int main(){
    std::vector<int> values;
    int k=0;
    while(std::cin>>k){
        values.push_back(k);
    }
    size_t count=values.size();
    Node* head=build(values);
    int i=0;
    for(Node* p=head;p!=nullptr;p=p->next){//遍历
        p->value=values[count-i-1];
        std::cout<<p->value<<' ';
        ++i;
    }
    std::cout<<'\n';
}