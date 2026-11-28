//remove duplicates from sorted List II
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
    ListNode* build(vector<int> nums){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        for(int num:nums){
            ListNode* fresh=new ListNode(num);
            tail->next=fresh;
            tail=fresh;
        }
        return dummy.next;
    }
    void release(ListNode*& head){
        while(head!=nullptr){
            ListNode* victim=head->next;
            delete(head);
            head=victim;
        }
    }
    ListNode* deleteDuplicates(ListNode* head){
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        while(prev->next!=nullptr){
            ListNode* cur=prev->next;
            if(cur->next!=nullptr&&cur->next->val==cur->val){
                const int dup=cur->val;
                while(cur!=nullptr&&cur->val==dup){
                    ListNode* victim=cur->next;
                    delete cur;
                    cur=victim;
                }
                prev->next=cur;
            }
            else{
                prev=cur;
            }
        }
        return dummy.next;
    }
};

int main(){
    Solution s;
    struct Case{
        vector<int> in;
        vector<int> expect;
    };
    vector<Case> cases={
        {{1,2,3,3,4,4,5},{1,2,5}},
        {{1,1,1,2,3},{2,3}},
        {{1,2,3},{1,2,3}},
        {{1,1,2,2},{}},
        {{1},{1}},
        {{},{}},
    };

    int pass=0;
    for(auto& c:cases){
        ListNode* head=s.build(c.in);
        head=s.deleteDuplicates(head);

        vector<int> got;
        for(ListNode* p=head;p!=nullptr;p=p->next) got.push_back(p->val);

        bool ok=(got==c.expect);
        pass+=ok;
        cout<<(ok?"PASS  ":"FAIL  ")<<"in: ";
        for(int v:c.in) cout<<v<<' ';
        cout<<"| expect: ";
        for(int v:c.expect) cout<<v<<' ';
        cout<<"| got: ";
        for(int v:got) cout<<v<<' ';
        cout<<'\n';

        s.release(head);
    }
    cout<<pass<<"/"<<cases.size()<<" passed"<<endl;
    return 0;
}