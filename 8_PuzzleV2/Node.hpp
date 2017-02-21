//
//  Node.hpp
//  8_PuzzleV2
//
//  Created by David Zhu on 2/20/17.
//  Copyright © 2017 David Zhu. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct compareNode;

class Node
{
public:
    Node();
    Node(int g, int h, vector<vector<int>> puzz, vector<vector<int>> goalState);
    void operator=(const Node& n);
    void print() const;
    bool moveBlankUp();
    bool moveBlankDown();
    bool moveBlankLeft();
    bool moveBlankRight();
    bool sameNode(Node check) const;
    bool hasNotTraversedUniform(queue<Node> list, Node checkMe);
    bool hasNotTraversedA(priority_queue<Node, vector<Node>, compareNode> list, Node checkMe);
    
    void uniform();
    
    int misplaced();
    int manhattan();
    int getValue(int selector);
    
    void aStarMis();
    void aStarMan();
    
    int gn;
    int hn;
    int blankx;
    int blanky;
    vector<vector<int>> puzzle;
    vector<vector<int>> goal;
};


struct compareNode
{
    bool operator()(Node a, Node b)
    {
        return (a.gn+a.hn) > (b.gn+b.hn);
    }
};




#endif /* Node_hpp */
