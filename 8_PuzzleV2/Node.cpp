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
    cout << endl;
}

bool Node::moveBlankUp()
{
    if(blanky == 0)
        return false;
    else
    {
        swap(puzzle[blanky][blankx], puzzle[blanky-1][blankx]);
        blanky--;
        return true;
    }
    return false;
}

bool Node::moveBlankDown()
{
    if(blanky == puzzle.size()-1)
        return false;
    else
    {
        swap(puzzle[blanky][blankx], puzzle[blanky+1][blankx]);
        blanky++;
        return true;
    }
    return false;
}

bool Node::moveBlankLeft()
{
    if(blankx == 0)
        return false;
    else
    {
        swap(puzzle[blanky][blankx], puzzle[blanky][blankx-1]);
        blankx--;
        return true;
    }
    return false;
}

bool Node::moveBlankRight()
{
    if(blankx == puzzle[0].size()-1)
        return false;
    else
    {
        swap(puzzle[blanky][blankx], puzzle[blanky][blankx+1]);
        blankx++;
        return true;
    }
    return false;
}
