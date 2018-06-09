//
//  main.cpp
//  findpath-grid
//
//  Created by Phanindra Saggurthi on 09/06/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool getPath(int r,int c, int rows,int cols,vector<vector<bool>>& grid,map<pair<int,int>,bool>& visited){
    if( r >= rows || c >= cols || !grid[r][c])
        return false;
    
    if(visited.find(make_pair(r,c)) != visited.end())
        return visited[make_pair(r,c)];
    
    bool isItEnd=(r == rows-1 && c == cols-1);
    bool success=false;
    if(isItEnd || getPath(r,c+1,rows,cols,grid,visited) || getPath(r+1, c, rows, cols, grid, visited)){
        success=true;
    }
    visited.insert(make_pair(make_pair(r,c),success));
    return success;
}
bool getPath(vector<vector<bool>>& grid){
    int rows=(int)grid.size();
    int cols=(int)grid[0].size();
    map<pair<int,int>,bool> visited;
    return getPath(0,0,rows,cols,grid,visited);
}
int main(int argc, const char * argv[]) {
    vector<vector<bool>> grid(4,vector<bool>(4,true));
    grid[0][2]=false;
    grid[1][1]=false;
    grid[2][3]=false;
    grid[2][2]=false;
    grid[3][1]=false;
    if(getPath(grid))
        std::cout<<"Path is available\n";
    else
        std::cout<<"Path is not available\n";
    return 0;
}
