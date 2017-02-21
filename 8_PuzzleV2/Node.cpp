//
//  Node.cpp
//  8_PuzzleV2
//
//  Created by David Zhu on 2/20/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#include "Node.hpp"
#include <iostream>
using namespace std;

Node::Node(int g, int h, vector<vector<int>> puzz)
{
    gn = g;
    hn = h;
    puzzle = puzz;
}

void Node::operator=(const Node& n)
{
    gn = n.gn;
    hn = n.hn;
    for(int i = 0; i < puzzle.size(); i++)
        puzzle[i] = n.puzzle[i];
}

void Node::print()
{
    for(int i = 0; i < puzzle.size(); i++)
    {
        for(int j = 0; j < puzzle[i].size(); j++)
            cout << puzzle[i][j] << " ";
        cout << endl;
    }
}
