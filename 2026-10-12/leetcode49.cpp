//group anagrams
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
class Solution{
    public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs){
        std::unordered_map<std::string,std::vector<std::string>> map;
        for(std::string s:strs){
            std::string key=s;
            std::sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        std::vector<std::vector<std::string>> ans;
        for(auto& [k,v]:map){
            ans.push_back(std::move(v));
        }
        return ans;
    }
};
std::vector<std::vector<std::string>> normalize(std::vector<std::vector<std::string>> g) {
    for (auto& row : g) std::sort(row.begin(), row.end());
    std::sort(g.begin(), g.end());
    return g;
}

void check(const std::string& name, std::vector<std::vector<std::string>> got,
           std::vector<std::vector<std::string>> want) {
    bool ok = (normalize(got) == normalize(want));
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
    if (!ok) {
        std::cout << "  got : ";
        for (auto& r : got) { std::cout << "["; for (auto& s : r) std::cout << s << " "; std::cout << "] "; }
        std::cout << "\n";
    }
}

int main() {
    // case 1: 标准样例
    check("case1", Solution().groupAnagrams({"eat","tea","tan","ate","nat","bat"}),
          {{"bat"}, {"nat","tan"}, {"ate","eat","tea"}});

    // case 2: 空串（空串的 sort 结果也是空串，自己一组）
    check("case2 空串", Solution().groupAnagrams({""}), {{""}});

    // case 3: 单字符
    check("case3 单字符", Solution().groupAnagrams({"a"}), {{"a"}});

    // case 4: 全互不同构
    check("case4 全不同", Solution().groupAnagrams({"a","b","c"}),
          {{"a"},{"b"},{"c"}});

    // case 5: 大小写敏感验证 —— "A" 和 "a" 不是异位词（ASCII 不同）
    check("case5 大小写", Solution().groupAnagrams({"A","a"}),
          {{"A"},{"a"}});

    std::cout << "全部用例跑完\n";
    return 0;
}