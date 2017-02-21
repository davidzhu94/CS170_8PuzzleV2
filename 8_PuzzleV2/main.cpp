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
    Node root;
    root.puzzle = grid;
    root.blankx = 0;
    root.blanky = 2;
    int defSelect;
    int algoSelect;

    cout << "Welcome to dzhu006's 8-puzzle solver!" << endl;
    cout << "Please press 1 to use the default puzzle or 2 to enter your own" << endl;
    cin >> defSelect;
    if(defSelect == 2)
    {
        vector<vector<int>> newPuzzle = {{}, {}, {}};
        int holder;
        cout << "To enter your puzzle, please type the numbers (seperated by spaces) that you want per row, with 0 indicating the blank space" << endl;
        for(int i = 0; i < grid.size(); i++)
        {
            cout << "Please enter row number " << i+1 << endl;
            for(int j = 0; j < grid[i].size(); j++)
            {
                cin >> holder;
                if(holder == 0)
                {
                    root.blanky = i;
                    root.blankx = j;
                }
                newPuzzle[i].push_back(holder);
            }
        }
        root.puzzle = newPuzzle;
    }
    cout << "Please select an algorithm: " << endl << "1: Uniform Cost" << endl << "2: A* with Misplaced" << endl << "3: A* with Manhattan" << endl;
    cin >> algoSelect;
    if(algoSelect == 1)
        root.uniform();
    else if(algoSelect == 2)
        root.aStarMis();
    else
        root.aStarMan();
    return 0;
}
