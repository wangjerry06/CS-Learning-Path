// C++ 二进制 <-> 十进制 互转 · 全方法示例
// 编译: clang++ -std=c++17 -O2 binary_decimal_convert.cpp -o bd && ./bd
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <charconv>   // C++17: from_chars / to_chars
#include <stdexcept>

// ================= 十进制 -> 二进制 =================

// 方法A：手动「除 2 取余」（原理必掌握）
std::string dec2bin_manual(long long n) {
    if (n == 0) return "0";
    std::string s;
    while (n > 0) {
        s.push_back('0' + (n & 1));   // 取最低位（n&1 等价 n%2）
        n >>= 1;                      // 右移一位（n>>1 等价 n/2）
    }
    std::reverse(s.begin(), s.end()); // 余数倒着读
    return s;
}

// 方法B：std::bitset<W>（固定宽度，自动补前导零）
template <std::size_t W>
std::string dec2bin_bitset(unsigned long long n) {
    return std::bitset<W>(n).to_string();
}

// 方法C：std::to_chars（C++17，无分配、无异常，性能最好）
std::string dec2bin_tochars(long long n) {
    char buf[70];
    auto r = std::to_chars(buf, buf + sizeof(buf), n, 2);
    return std::string(buf, r.ptr);
}

// ================= 二进制 -> 十进制 =================

// 方法A：手动「从左往右累积」 res = res*2 + bit（原理必掌握）
long long bin2dec_manual(const std::string& s) {
    long long r = 0;
    for (char c : s) {
        if (c != '0' && c != '1') throw std::invalid_argument("非二进制字符");
        r = r * 2 + (c - '0');
    }
    return r;
}

// 方法B：std::stoll 指定 base=2（会抛异常，稍慢）
long long bin2dec_stoi(const std::string& s) {
    return std::stoll(s, nullptr, 2);
}

// 方法C：std::bitset<W> 构造 + to_ullong
long long bin2dec_bitset(const std::string& s) {
    return static_cast<long long>(std::bitset<64>(s).to_ullong());
}

// 方法D：std::from_chars（C++17，无异常，最快）
long long bin2dec_fromchars(const std::string& s) {
    long long v = 0;
    std::from_chars(s.data(), s.data() + s.size(), v, 2);
    return v;
}

int main() {
    long long n = 13;
    std::cout << "=== 十进制 " << n << " -> 二进制 ===\n";
    std::cout << "手动除2取余 : " << dec2bin_manual(n)  << "\n";
    std::cout << "bitset<8>   : " << dec2bin_bitset<8>(n) << "\n";
    std::cout << "to_chars    : " << dec2bin_tochars(n) << "\n";

    std::string b = "1101";
    std::cout << "\n=== 二进制 " << b << " -> 十进制 ===\n";
    std::cout << "手动按权累积 : " << bin2dec_manual(b)    << "\n";
    std::cout << "stoll(...,2) : " << bin2dec_stoi(b)      << "\n";
    std::cout << "bitset       : " << bin2dec_bitset(b)    << "\n";
    std::cout << "from_chars   : " << bin2dec_fromchars(b) << "\n";

    return 0;
}
