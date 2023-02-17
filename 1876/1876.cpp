// 1876.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        map<Node*, int> old_new_map;
        vector<Node*> new_node_list;
        Node* node_now = head;
        // 顺序拷贝
        while (node_now) {
            Node* new_node = new Node(*node_now);
            new_node_list.push_back(new_node);
            old_new_map[node_now] = new_node_list.size() - 1;
            node_now = node_now->next;
        }
        // 指针更新
        for (int new_node_index = 0; new_node_index < new_node_list.size() - 1; new_node_index++) {
            Node* node_now = new_node_list[new_node_index];
            node_now->next = new_node_list[new_node_index + 1];
            if (node_now->random) {
                node_now->random = new_node_list[old_new_map[node_now->random]];
            }
        }
        if (new_node_list.back()->random) {
            new_node_list.back()->random = new_node_list[old_new_map[new_node_list.back()->random]];
        }
        return new_node_list[0];
    }
};

int main()
{
    Solution solution;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
