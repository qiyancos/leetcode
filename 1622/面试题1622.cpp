// 面试题1622.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class Board {
public:
    unordered_map<int, char> board;
    // 蚂蚁的方向
    char ant;
    // 蚂蚁所在位置的颜色
    char ant_v;
    // 蚂蚁所在位置的xy坐标
    int ant_x;
    int ant_y;
    // 当前的地图边界
    int max_x;
    int min_x;
    int max_y;
    int min_y;

    // 初始化函数
    Board() {
        ant = 'R';
        ant_v = '_';
        max_x = min_x = max_y = min_y = ant_x = ant_y = 0;
        board[get_coord(ant_x, ant_y)] = ant_v;
    }

    // 蚂蚁走一步
    void step() {
        // 更新方向
        switch (ant)
        {
            case 'L': ant = ant_v == '_' ? 'U' : 'D'; break;
            case 'R': ant = ant_v == '_' ? 'D' : 'U'; break;
            case 'U': ant = ant_v == '_' ? 'R' : 'L'; break;
            case 'D': ant = ant_v == '_' ? 'L' : 'R'; break;
        }
        // 改变颜色
        change_ant_color();
        // 走一步
        switch (ant)
        {
        case 'D': ant_y--;min_y = min(min_y, ant_y); break;
        case 'U': ant_y++; max_y = max(max_y, ant_y); break;
        case 'R': ant_x++; max_x = max(max_x, ant_x); break;
        case 'L': ant_x--; min_x = min(min_x, ant_x);  break;
        }
        ant_v = get_color(ant_x, ant_y);
        //cout << ant_x << " " << ant_y << "(" << get_coord(ant_x, ant_y) << ")" << ": " << ant_v << endl;
    }

    vector<string> print() {
        vector<string> result;
        for (int y = max_y; y >= min_y; y--) {
            string line = "";
            for (int x = min_x; x <= max_x; x++) {
                line.push_back(get_color(x, y, true));
            }
            result.push_back(line);
        }
        return result;
    }

private:
    // 获取指定坐标的颜色字符
    char get_color(int x, int y, bool include_ant = false) {
        if (include_ant and x == ant_x and y == ant_y) {
            return ant;
        }
        int real_coord = get_coord(x, y);
        if (board.find(real_coord) == board.end()) {
            return '_';
        }
        else {
            return board[real_coord];
        }
    }

    // 转换颜色
    void change_ant_color() {
        int ant_coord = get_coord(ant_x, ant_y);
        char old_color;
        if (board.find(ant_coord) == board.end()) {
            old_color = '_';
        }
        else {
            old_color = board[ant_coord];
        }
        board[ant_coord] = old_color == 'X' ? '_' : 'X';
    }

    // 坐标系转一维坐标
    int get_coord(int x, int y) {
        int coord = 0;
        short* x_c = reinterpret_cast<short*>(&coord);
        short* y_c = x_c + 1;
        *x_c = x;
        *y_c = y;
        return coord;
    }
};

class Solution {
public:
    vector<string> printKMoves(int K) {
        Board board;
        while (K--) {
            board.step();
        }
        return board.print();
    }
};

int main()
{
    Solution solution;
    for (int step = 0; step <= 10; step++) {
        vector<string> result = solution.printKMoves(step);
        for (auto& item : result) {
            cout << item << endl;
        }
        cout << endl;
    }
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
