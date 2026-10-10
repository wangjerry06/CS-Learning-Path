//add two list II
#include<iostream>
#include<vector>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode* node):val(x),next(node){};
};
ListNode* buildList(const std::vector<int>& values){
    ListNode dummy(0);
    ListNode* tail=&dummy;
    for(int value:values){
        ListNode* fresh=new ListNode(value,nullptr);
        tail->next=fresh;
        tail=fresh;
    }
    return dummy.next;
}
void clearList(ListNode* head){
    while(head){
        ListNode* saveNext=head->next;
        delete head;
        head=saveNext;
    }
}
class Solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* past=nullptr;
        ListNode* cur=head;
        while(cur){
            ListNode* fut=cur->next;
            cur->next=past;
            past=cur;
            cur=fut;
        }
        return past;
    }
    ListNode* addTwoList(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        int carry=0;
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* r1=l1;
        ListNode* r2=l2;
        while(l1||l2||carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* fresh=new ListNode{sum%10,nullptr};
            tail->next=fresh;
            tail=fresh;
        }
        clearList(r1);
        clearList(r2);
        return reverseList(dummy.next);
    }
};
int main(){
    std::vector<int> a={7,2,4,3},b={5,6,4};
    ListNode* l1=buildList(a);
    ListNode* l2=buildList(b);
    Solution A;
    ListNode* head=A.addTwoList(l1,l2);
    while(head){
        ListNode* saveNext=head->next;
        std::cout<<head->val<<' ';
        delete head;
        head=saveNext;
    }
    std::cout<<'\n';
    return 0;
}