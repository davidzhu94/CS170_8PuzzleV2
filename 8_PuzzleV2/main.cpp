//
//  main.cpp
//  8_PuzzleV2
//
//  Created by David Zhu on 2/20/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include <iostream>
#include "Node.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Node test(1, 1, grid);
    test.print();
    test.blankx = 2;
    test.blanky = 2;
    test.moveBlankUp();
    test.print();
    test.moveBlankDown();
    test.print();
    test.moveBlankDown();
    test.print();
    test.moveBlankRight();
    test.print();
    test.moveBlankLeft();
    test.print();
    test.moveBlankRight();
    test.print();
    return 0;
}
