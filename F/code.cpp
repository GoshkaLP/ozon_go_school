#include <iostream>
#include <fstream>
#include <unordered_set>

int main() {
    int target, x, tmp;
    bool flag = false;
    std::unordered_set<int> arr;
    std::ifstream in("input.txt");
    in >> target;
    while (in >> x) {
        if (arr.empty()) {
            arr.insert(x);
        } else {
            tmp = target - x;
            if (arr.find(tmp) != arr.end()) {
                flag = true;
                break;
            } else {
                arr.insert(x);
            }
        }
    }
    in.close();
    std::ofstream out("output.txt");
    if (flag) {
        out << "1";
    } else {
        out << "0";
    }
    out.close();
}