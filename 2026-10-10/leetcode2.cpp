//add two numbers
#include<iostream>
#include<vector>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value):val(value),next(nullptr){};
    ListNode(int value,ListNode* add):val(value),next(add){};
};
class Solution{
    public:
    ListNode* buildList(const std::vector<int>& values){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        for(int value:values){
            ListNode* fresh=new ListNode{value,nullptr};
            tail->next=fresh;
            tail=tail->next;
        }
        return dummy.next;
    }
    void clearList(ListNode*& head){
        while(head){
            ListNode* victim=head->next;
            delete head;
            head=victim;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        int carry=0;
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
            tail=tail->next;
        }
        return dummy.next;
    }
};
int main(){
    std::vector<int> a={2,4,3},b={5,6,4};
    Solution A;
    ListNode* l1=A.buildList(a);
    ListNode* l2=A.buildList(b);
    ListNode* head=A.addTwoNumbers(l1,l2);
    while(head){
        std::cout<<head->val<<' ';
        ListNode* saveNext=head->next;
        delete head;
        head=saveNext;;
    }
    std::cout<<'\n';
    A.clearList(l1);
    A.clearList(l2);
    return 0;
}