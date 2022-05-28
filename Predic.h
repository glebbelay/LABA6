#pragma once

#include <iostream>




template<typename T, class F>
bool any_of_(const T &begin, const T &end, F func) {
    for (T it = begin; it != end; it++) {
        if (func(*it)) {
            return true;
        }
    }
    return false;
}



template<typename T, class F>
bool is_partitioned_(const T &begin, const T &end, F func) {
    T it = begin;
    while (it != end && func(*it)) {
        it++;
    }
    while (it != end) {
        if (func(*it)) {
            return false;
        }
        it++;
    }
    return true;
}



template<typename T, typename N>
T find_backward_(const T &begin, const T &end, const N &value) {
    for (T it = end - 1; it != begin - 1; it--) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}




class CPoint {
private:
    float x;
    float y;
    static float dist(float x2, float y2, float x1, float y1) {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

public:
    CPoint(float x_, float y_) : x(x_), y(y_) {}
    CPoint() = default;
    float show_x(){
        return x;
    }
    float show_y(){
        return y;
    }
    bool operator>(const CPoint &other) const {
        return (dist(this->x, this->y, 0, 0) > dist(other.x, other.y, 0, 0));
    }
    bool operator<(const CPoint &other) const {
        return (dist(this->x, this->y, 0, 0) < dist(other.x, other.y, 0, 0));
    }
    bool operator==(const CPoint &other) const {
        return ((this->x == other.x) && (this->y == other.y));
    }

};