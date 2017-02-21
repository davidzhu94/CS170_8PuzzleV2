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

Node::Node()
{
    gn = 0;
    hn = 0;
    puzzle = {{0}, {0}, {0}};
    goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
}

Node::Node(int g, int h, vector<vector<int>> puzz, vector<vector<int>> goalState)
{
    gn = g;
    hn = h;
    puzzle = puzz;
    goal = goalState;
}

void Node::operator=(const Node& n)
{
    gn = n.gn;
    hn = n.hn;
    for(int i = 0; i < puzzle.size(); i++)
        puzzle[i] = n.puzzle[i];
    blankx = n.blankx;
    blanky = n.blanky;
}

void Node::print() const
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

bool Node::sameNode(Node check) const
{
    for(int i = 0; i < puzzle.size(); i++)
    {
        if(puzzle[i] != check.puzzle[i])
            return false;
    }
    return true;
}

bool Node::hasNotTraversedUniform(queue<Node> list, Node checkMe)
{
    while(!list.empty())
    {
        if(list.front().sameNode(checkMe))
            return false;
        list.pop();
    }
    return true;
}
bool Node::hasNotTraversedA(priority_queue<Node, vector<Node>, compareNode> list, Node checkMe)
{
    while(!list.empty())
    {
        if(list.top().sameNode(checkMe))
            return false;
        list.pop();
    }
    return true;
}

void Node::uniform(queue<Node> &traversed)
{
    int tempCount = 1;
    int maxCount = 0;
    int exploreCount = 0;
    Node goal;
    goal.puzzle = this->goal;
    Node temp;
    queue<Node> frontier;
    frontier.push(*this);
    while(!frontier.empty())
    {
        temp = frontier.front();
        tempCount--;
        if(temp.sameNode(goal))
        {
            cout << "Goal! The end state is :" << endl;
            temp.print();
            cout << "With a depth of " << temp.gn << endl;
            cout << "Expanded nodes: " << exploreCount << endl;
            cout << "Max number of nodes in queue: " << maxCount << endl;
            return;
        }
        else
        {
            cout << "Expanding Node with depth of " << temp.gn << endl;
            temp.print();
            temp.gn++;
            if(hasNotTraversedUniform(traversed, temp))
            {
                cout << "whu " << endl;
                if(temp.moveBlankLeft())
                {
                    tempCount++;
                    exploreCount++;
                    frontier.push(temp);
                    traversed.push(temp);
                }
                temp.puzzle = frontier.front().puzzle;
                if(temp.moveBlankRight())
                {
                    tempCount++;
                    exploreCount++;
                    frontier.push(temp);
                    traversed.push(temp);
                }
                temp.puzzle = frontier.front().puzzle;
                if(temp.moveBlankUp())
                {
                    tempCount++;
                    exploreCount++;
                    frontier.push(temp);
                    traversed.push(temp);
                }
                temp.puzzle = frontier.front().puzzle;
                if(temp.moveBlankDown())
                {
                    tempCount++;
                    exploreCount++;
                    frontier.push(temp);
                    traversed.push(temp);
                }
                if(tempCount > maxCount)
                    maxCount = tempCount;
            }
        }
        frontier.pop();
    }
}
