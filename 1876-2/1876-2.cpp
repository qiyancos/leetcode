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
        // 顺序拷贝并合并链表
        Node* node_now = head;
        while (node_now) {
            Node* new_node = new Node(*node_now);
            new_node->next = node_now->next;
            node_now->next = new_node;
            node_now = node_now->next->next;
        }
        // 随机指针更新
        node_now = head;
        Node* new_head = head->next;
        while (node_now) {
            Node* new_node = node_now->next;
            if (node_now->random) {
                new_node->random = node_now->random->next;
            }
            node_now = node_now->next->next;
        }
        // 列表拆分
        node_now = head;
        while (node_now) {
            Node* new_node = node_now->next;
            node_now->next = new_node->next;
            if (node_now->next) {
                new_node->next = node_now->next->next;
            }
            node_now = node_now->next;
        }
        return new_head;
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
