#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include "Predic.h"

using namespace std;


template<typename T>
class Rule {
private:
    T value;

public:
    explicit Rule(T value_) : value(value_) {}

    bool operator()(T number) {
        return number > value;
    }
};

template<class T>
class Rule2 {
private:
    T value;

public:
    explicit Rule2(T value_) : value(value_) {}

    bool operator()(T number) {
        return number > value;
    }
};

int main() {
    vector<int> a = {4, 6, -1, 1, 3, 4};

    cout << "Function for vector: \n";
    cout << any_of_(a.begin(), a.end(), Rule2<int>(10)) << endl;
    cout << is_partitioned_(a.begin(), a.end(), Rule<int>(6)) << endl;
    cout << *find_backward_(a.begin(), a.end(), 11) << endl << "\n";


    vector<CPoint> points = {{9, 2}, {1, 4}, {5, 6}, {2, 3}};
    CPoint value = {5, 6};

    cout << "Function for points: \n";
    cout << any_of_(points.begin(), points.end(), Rule2<CPoint>({3, 1})) << endl;
    cout << is_partitioned_(points.begin(), points.end(), Rule<CPoint>({6, 3})) << endl;
    CPoint cout_ = *find_backward_(points.begin(), points.end(), value);
    cout << "{" << cout_.show_x() << " " << cout_.show_y() << "}";
}