//merge two sort list
#include<vector>
#include<iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* buildList(std::vector<int>& values){
    ListNode dummy(0);
    ListNode* tail=&dummy;
    for(int value:values){
        ListNode* fresh=new ListNode(value);
        tail->next=fresh;
        tail=fresh;
    }
    return dummy.next;
}
ListNode* mergeTwoList(ListNode* list1,ListNode* list2){
    if(list1==nullptr)return list2;
    if(list2==nullptr)return list1;
    ListNode* newHead=nullptr;
    if(list1->val>=list2->val){
        newHead=list2;
        list2=list2->next;
    }
    else if(list1->val<list2->val){
        newHead=list1;
        list1=list1->next;
    }
    newHead->next=mergeTwoList(list1,list2);
    return newHead;
}

int main(){
    std::vector<int> values1={1,2,4};
    std::vector<int> values2={1,3,4};
    ListNode* list1=buildList(values1);
    ListNode* list2=buildList(values2);
    ListNode* res=mergeTwoList(list1,list2);
    while(res!=nullptr){
        ListNode* victim=res->next;
        std::cout<<res->val<<' ';
        delete res;
        res=victim;
    }
    std::cout<<'\n';
    return 0;
}