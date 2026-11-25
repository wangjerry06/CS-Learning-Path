//copy list with random pointer
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* random;
    Node(int _val){
        val=_val;
        next=NULL;
        random=NULL;
    }
};

/*用哈希表储存新表和旧表的联系。
每次遇到一个还未创建的节点，（这个还未创建是在哈希表里查不到）不管是在random还是在next遇到的，
new一个节点然后登记map，递归next和递归random，head经由next/random可达的所有节点都已经在表中了。
这就是记忆化dfs
*/
class Solution{
    unordered_map<Node*,Node*>m;
    public:
    Node* copyRandomList(Node* head){
        if(head==nullptr)return nullptr;
        if(!m.count(head)){
            Node* newHead=new Node(head->val);
            m[head]=newHead;
            newHead->next=copyRandomList(head->next);
            newHead->random=copyRandomList(head->random);
        }
        return m[head];
    }
};

// 按值 + 随机下标打印链表，便于肉眼对比两条链是否等价
//tag是标签，标记这一行是原始的还是副本
static void printList(const vector<int>& vals, Node* head, const char* tag){
    
/*这一part是把整个链表按照next的顺序先存储到vector里，这样才能遍历的时候标记下标
  最后打印随机下标的时候直接按照vector的下标打印
  不能用val反查位置，因为值可能重复
*/
    vector<Node*> nodes;
    for(Node* p=head;p!=nullptr;p=p->next)nodes.push_back(p);
    unordered_map<Node*,int> idx;
    for(int i=0;i<(int)nodes.size();++i)idx[nodes[i]]=i;

/*输出，这里random可能指向空节点，所以我们要把这种情况单独列出来输出"null"
*/
    cout<<tag<<" : ";
    for(int i=0;i<(int)nodes.size();++i){
        cout<<"["<<nodes[i]->val<<",";
        if(nodes[i]->random==nullptr)cout<<"null";
        else cout<<idx[nodes[i]->random];
        cout<<"]";
        if(i+1<(int)nodes.size())cout<<" -> ";
    }
/*这里的endl是输出一个换行符并且把缓冲区刷到设备上，这里只有一条链表，所以没问题，如果有十万次调用的话还是用\n
  但是如果用'\n'，stdout被重定向到文件/管道（全缓冲），光用'\n'可能知道程序结束才一起出现，所以还需要在最后统一cout.flush(）
  最实用的价值是调试检查点，保证【原装链表已打印】在后面的危险操作之前就已经真正写出去了
*/
    cout<<endl;
}

/*释放链表，这个freeList只能沿着next走，不能跟着random，因为多个节点的random可能指向同一个节点
会造成重复删除
*/
static void freeList(Node* head){
    while(head!=nullptr){
        Node* nxt=head->next;
        delete head;
        head=nxt;
    }
}

int main(){
    // 构造 LeetCode 示例: vals = [7,13,11,10,1], random 下标 = [null,0,4,2,0]
    vector<int> vals = {7,13,11,10,1};
    vector<int> randomIdx = {-1,0,4,2,0};

    vector<Node*> origin;
    for(int v : vals)origin.push_back(new Node(v));
    for(int i=0;i<(int)origin.size();++i){
        if(i+1<(int)origin.size())origin[i]->next=origin[i+1];
        if(randomIdx[i]!=-1)origin[i]->random=origin[randomIdx[i]];
    }
    Node* head=origin[0];

    printList(vals, head, "origin");

    Solution sol;
    Node* copy=sol.copyRandomList(head);

    printList(vals, copy, "copy  ");

    // 校验：值序列一致、random 指向的结点值一致、且不是同一批结点
    bool ok=true;
    Node* a=head;
    Node* b=copy;
    while(a!=nullptr&&b!=nullptr){
        if(a==b)ok=false;                       // 必须深拷贝
        if(a->val!=b->val)ok=false;
        int ra = (a->random==nullptr?-1:a->random->val);
        int rb = (b->random==nullptr?-1:b->random->val);
        if(ra!=rb)ok=false;
        a=a->next;
        b=b->next;
    }
    if(a!=nullptr||b!=nullptr)ok=false;
    cout<<(ok?"check passed":"check failed")<<endl;

    freeList(copy);
    freeList(head);
    return 0;
}
