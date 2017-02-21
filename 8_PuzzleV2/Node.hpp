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

class Node
{
public:
    Node(int g, int h, vector<vector<int>> puzz);
    void operator=(const Node& n);
    void print();
    bool moveBlankUp();
    bool moveBlankDown();
    bool moveBlankLeft();
    bool moveBlankRight();
    int gn;
    int hn;
    int blankx;
    int blanky;
    vector<vector<int>> puzzle;
    
};


struct compareNode
{
    bool operator()(Node a, Node b)
    {
        return (a.gn+a.hn) > (b.gn+b.hn);
    }
};




#endif /* Node_hpp */
