//insert delete getrandom O(1)
#include<vector>
#include<random>
#include<unordered_map>
class RandomizedSet{
    std::vector<int> nums;
    std::unordered_map<int,int> m;
    std::mt19937 rng{std::random_device{}()};
    public:
    RandomizedSet(){};
    bool insert(int val){
        if(m.count(val))return false;
        nums.push_back(val);
        int n=(int)nums.size()-1;
        m[val]=n;
        return true;
    }
    bool remove(int val){
        if(!m.count(val))return false;
        int n=(int)nums.size()-1;
        int pos=m[val];
        //处理向量里的
        std::swap(nums[pos],nums[n]);
        nums.pop_back();
        //处理表里的
        m.erase(val);
        if(pos!=n)m[nums[pos]]=pos;
        return true;
    }
    int getrandom(){
        int n=(int)nums.size()-1;
        std::uniform_int_distribution<int> dist(0,n);
        return nums[dist(rng)];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 /**
-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.
 */