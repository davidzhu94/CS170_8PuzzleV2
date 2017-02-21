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

//queue<Node> uniformTraversed;
//priority_queue<Node, vector<Node>, compareNode> aTraversed;

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1, 8, 2}, {4, 6, 3}, {0, 7, 5}};
    vector<vector<int>> goalState = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    
    int defSelect;

    cout << "Welcome to dzhu006's 8-puzzle solver!" << endl;
    cout << "Please press 1 to use the default puzzle or 2 to enter your own" << endl;
    cin >> defSelect;
    if(defSelect == 2)
    {
        //cout << "Please enter your "
    }
    
    
    Node test(0, 0, grid, goalState);
    test.blankx = 0;
    test.blanky = 2;
    test.aStarMis();
    return 0;
}
