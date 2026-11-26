//reverse Linked List II
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value):val(value),next(nullptr){};
};
class Solution{
    public:
    ListNode* build(vector<int>values){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        for(int value:values){
            ListNode* fresh=new ListNode(value);
            tail->next=fresh;
            tail=fresh;
        }
        return dummy.next;
    }
    void clearList(ListNode* head){
        if(head==nullptr)return;
        while(head!=nullptr){
            ListNode* victim=head->next;
            delete head;
            head=victim;
        }
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* now=head;
        while(now!=nullptr){
            ListNode* carry=now->next;
            now->next=prev;
            prev=now;
            now=carry;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next=head;
        int counter=0;
        ListNode* pointer=&dummy;
        while(counter<left-1){
            counter++;
            pointer=pointer->next;
        }
        ListNode* start=pointer;
        while(counter<right){
            counter++;
            pointer=pointer->next;
        }
        ListNode* end=pointer->next;
        pointer->next=nullptr;
        start->next=reverse(start->next);
        ListNode* tail=start->next;
        while(tail->next!=nullptr){
            tail=tail->next;
        }
        tail->next=end;
        return dummy.next;
    }
};
void printList(ListNode* head){
    for(ListNode* p=head;p!=nullptr;p=p->next){
        cout<<p->val;
        if(p->next!=nullptr)cout<<" -> ";
    }
    cout<<"\n";
}
int main(){
    Solution s;
    vector<vector<int>> inputs = {{1,2,3,4,5},{5},{3,5},{1,2,3,4,5},{1,2,3,4,5}};
    int lefts[] = {2,1,1,1,3};
    int rights[] = {4,1,2,5,3};
    int count = 5;
    for(int i=0;i<count;i++){
        ListNode* head = s.build(inputs[i]);
        cout<<"第"<<i+1<<"组  left="<<lefts[i]<<" right="<<rights[i]<<"\n";
        cout<<"  输入: ";
        printList(head);
        ListNode* result = s.reverseBetween(head,lefts[i],rights[i]);
        cout<<"  输出: ";
        printList(result);
        s.clearList(result);
    }
}