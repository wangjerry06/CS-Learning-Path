//min stack
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Node{
    int val;
    int minVal;
    Node* next;
    Node(int value):val(value),next(nullptr){};
};
class MinStack{
    Node* head;
    public:
    MinStack(){
        head=NULL;
    }

    void push(int value){
        int m=value;
        if(head!=NULL){
            m=min(head->minVal,m);
        }
        Node* fresh=new Node(value);
        fresh->next=head;
        fresh->minVal=m;
        head=fresh;
    }

    void pop(){
        if(head==NULL)return;
        Node* victim=head->next;
        delete head;
        head=victim;
    }

    int top(){
        return head->val;
    }

    int getMin(){
        return head->minVal;
    }

    ~MinStack(){
        while(head!=NULL){
            Node* next=head->next;
            delete head;
            head=next;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    MinStack obj;
    string op;
    for(int i = 0; i < n; ++i){
        cin >> op;
        if(op == "MinStack"){
            continue;               // 构造标记，对象已创建
        }
        else if(op == "push"){
            int val;
            cin >> val;
            obj.push(val);
        }
        else if(op == "pop"){
            obj.pop();
        }
        else if(op == "top"){
            cout << obj.top() << '\n';
        }
        else if(op == "getMin"){
            cout << obj.getMin() << '\n';
        }
    }
    return 0;
}