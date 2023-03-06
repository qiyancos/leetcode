#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <exception>
#include <fstream>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <type_traits>
#include <memory>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <set>

#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define TestTag \
    cout << "Test Tag In " << __FILE__ << ":" << __LINE__ << endl;

#define dumpVar(VAR) \
    cout << "Check Variable \"" << #VAR << "\": " << VAR << endl;

bool _beauty = false;
int _indent = 4;
string _indent_str = "    ";
map<const void*, int> print_depth;

void setPrintBeauty(const bool beauty) {
    _beauty = beauty;
}

void setPrintIndent(int indent) {
    _indent = indent;
    _indent_str = string(indent, ' ');
}

#define AUTOGEN1(Type, Left_Bracket, Right_Bracket) \
template<typename T>\
ostream &operator << (ostream &out, const Type<T> &out_data) {\
    const void * hash_key = static_cast<const void*>(&out_data);\
    int indent = 0;\
    if (_beauty && print_depth.find(hash_key) != print_depth.end()) {\
        indent = print_depth[hash_key];\
    }\
    string indent_str(indent * _indent, ' ');\
    if (out_data.size() == 0) {\
        out << Left_Bracket << Right_Bracket;\
        return out;\
    }\
    int index = 0;\
    for (auto item = out_data.begin();item != out_data.end(); item++){\
        string line_str = "";\
        if (item == out_data.begin()) {\
            line_str += _beauty ? Left_Bracket"\n" : Left_Bracket;\
        }\
        line_str += _beauty ? indent_str + _indent_str: "";\
        out << line_str;\
        \
        const void* sub_item_hash_key = static_cast<const void*>(&item);\
        print_depth[sub_item_hash_key] = indent + 1;\
        out << *item;\
        print_depth.erase(sub_item_hash_key);\
        \
        if (index == out_data.size() - 1) {\
            line_str = string() + (_beauty ? "\n" : "") + indent_str + Right_Bracket;\
        } else {\
            line_str = _beauty ? ",\n" : ", ";\
        }\
        out << line_str;\
        index++;\
    }\
    return out;\
}

#define AUTOGEN2(Type, Left_Bracket, Right_Bracket) \
template<typename T1, typename T2>\
ostream &operator << (ostream &out, const Type<T1, T2> &out_data) {\
    const void* hash_key = static_cast<const void*>(&out_data);\
    int indent = 0;\
    if (_beauty && print_depth.find(hash_key) != print_depth.end()) {\
        indent = print_depth[hash_key];\
    }\
    string indent_str(indent * _indent, ' ');\
    if (out_data.size() == 0) {\
        out << Left_Bracket << Right_Bracket;\
        return out;\
    }\
    for (auto item = out_data.begin();item != out_data.end(); item++){\
        string line_str = "";\
        if (item == out_data.begin()) {\
            line_str += _beauty ? Left_Bracket"\n" : Left_Bracket;\
        }\
        line_str += _beauty ? indent_str + _indent_str : "";\
        out << line_str;\
        \
        const T1& key = item->first;\
        bool old_beauty = _beauty;\
        setPrintBeauty(false);\
        out << key << ": ";\
        setPrintBeauty(old_beauty);\
        \
        const T2& value = item->second;\
        const void* sub_item_hash_key = static_cast<const void*>(&value);\
        print_depth[sub_item_hash_key] = indent + 1;\
        out << value;\
        print_depth.erase(sub_item_hash_key);\
        \
        if (item == --out_data.end()) {\
            line_str = string("") + (_beauty ? "\n" : "") + indent_str + Right_Bracket;\
        } else {\
            line_str = _beauty ? ",\n" : ", ";\
        }\
        out << line_str;\
    }\
    return out;\
}

AUTOGEN1(vector, "[", "]");
AUTOGEN1(set, "(", ")");
AUTOGEN1(unordered_set, "(", ")");
AUTOGEN1(list, "[", "]");
AUTOGEN1(queue, "[", "]");
AUTOGEN1(deque, "[", "]");

AUTOGEN2(map, "{", "}");
AUTOGEN2(unordered_map, "{", "}");

template<typename T1, typename T2, typename T3>
ostream &operator << (ostream &out, const priority_queue<T1, T2, T3> &out_data) {
    vector<T1> content;
    priority_queue<T1, T2, T3> out_data_copy= out_data;
    while(!out_data_copy.empty()) {
        content.push_back(out_data_copy.top());
        out_data_copy.pop();
    }
    out << content;
    return out;
}

template<typename T1, typename T2>
ostream &operator << (ostream &out, const pair<T1, T2> &out_data) {
    map<T1, T2> content;
    content[out_data.first] = out_data.second;
    out << content;
    return out;
}

