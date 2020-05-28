#include <iostream>
#include <vector>
#include <string>

class BigNumber {
private:
    std::vector<int> arr;
    int basis = 1000000000;

public:
    void clear_zeros() {
        while (arr.size() > 1 && arr.back() == 0) {
            arr.pop_back();
        }
    }

    size_t size() {
        return arr.size();
    }

    bool empty() {
        return size() == 0;
    }

    const int operator [] (size_t i) const {
        return arr[i];
    }

    BigNumber() = default;

    BigNumber(const std::string& s) {
        for (int i = s.size(); i > 0; i -= 9) {
            if (i < 9) {
                arr.push_back(std::atoi(s.substr(0, i).c_str()));
            } else {
                arr.push_back(std::atoi(s.substr(i-9, 9).c_str()));
            }
        }
        clear_zeros();
    }

    BigNumber add(BigNumber& other) {
        int tmp = 0;
        for (size_t i = 0; (i < std::max(size(), other.size())) || tmp; ++i) {
            if (i == size()) {
                arr.push_back(0);
            }
            arr[i] += tmp;
            if (i < other.size()) {
                arr[i] += other[i];
            }
            tmp = basis <= arr[i];
            if (tmp) {
                arr[i] -= basis;
            }
        }
        return *this;
    }

    void print() {
        if (empty()) {
            printf("%d", 0);
        } else {
            printf("%d", arr.back());
        }
        for (int i = arr.size() - 2; i >= 0; --i)
            printf ("%09d", arr[i]);
    }
};

int main() {
    std::string x, y;
    std::cin >> x >> y;
    BigNumber a(x);
    BigNumber b(y);
    BigNumber c;
    c = a.add(b);
    c.print();
}