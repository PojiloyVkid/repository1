#include <iostream>
#include <chrono>
#include <array>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>

using namespace std;

string array_time() {
    array<int, 1000> a{};
    for (int i = 0; i < 1000; i++) {
        a.at(i) = pow(-1, i) * pow(i, 2);
    }
    auto start = chrono::steady_clock::now();
    sort(a.begin(), a.end());
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    return "array elapsed time: " + to_string(elapsed_seconds.count()) + "s\n";
}

string vector_time() {
    vector<int> a;
    a.reserve(1000);
    for (int i = 0; i < 1000; i++) {
        a.push_back(pow(-1, i) * pow(i, 2));
    }
    auto start = chrono::steady_clock::now();
    sort(a.begin(), a.end());
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    return "vector elapsed time: " + to_string(elapsed_seconds.count()) + "s\n";
}

string deque_time() {
    deque<int> a;
    a.resize(1000);
    for (int i = 0; i < 1000; i++) {
        a.push_back(pow(-1, i) * pow(i, 2));
    }
    auto start = chrono::steady_clock::now();
    sort(a.begin(), a.end());
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    return "deaue elapsed time: " + to_string(elapsed_seconds.count()) + "s\n";
}

string list_time() {
    list<int> a;
    a.resize(1000);
    for (int i = 0; i < 1000; i++) {
        a.push_front(pow(-1, i) * pow(i, 2));
    }
    auto start = chrono::steady_clock::now();
    a.sort();
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    return "list elapsed time: " + to_string(elapsed_seconds.count()) + "s\n";
}

string forward_list_time() {
    forward_list<int> a;
    a.resize(1000);
    for (int i = 0; i < 1000; i++) {
        a.push_front(pow(-1, i) * pow(i, 2));
    }
    auto start = chrono::steady_clock::now();
    a.sort();
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    return "forward list elapsed time: " + to_string(elapsed_seconds.count()) + "s\n";
}

int main() {
    array<string, 5> time_table;
    time_table[0] = array_time();
    time_table[1] = vector_time();
    time_table[2] = deque_time();
    time_table[3] = list_time();
    time_table[4] = forward_list_time();
    for (int i = 0; i < 5; i++)
    {
        cout << time_table[i] << endl;
    }
}