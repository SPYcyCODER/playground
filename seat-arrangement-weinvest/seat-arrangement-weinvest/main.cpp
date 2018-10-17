#include <iostream>
#include <vector>
using namespace std;
void seatArrangement(vector<vector<vector<int> > >& _grids,int passengerCount){
    int numGrids=(int)_grids.size();
    int maxRows=0;
    //calculating
    for(int gridInd=0;gridInd<numGrids;gridInd++){
        int curRowSize=(int)_grids[gridInd].size();
        maxRows = (maxRows > curRowSize ? maxRows : curRowSize);
    }
    
    int passCount=1;
    //fill aisle seats
    for(int row=0;row < maxRows; row++){
        for(int gridInd=0;gridInd<numGrids;gridInd++){
            int numRows=(int)_grids[gridInd].size();
            if(row >= numRows)
                continue;
            if(passCount > passengerCount)
                return;
            int numCols=(int)_grids[gridInd][0].size();
            if(gridInd == 0){                               //First Grid
                _grids[gridInd][row][numCols-1]=passCount;
                passCount++;
            }else if(gridInd == numGrids-1){                // Last Grid
                _grids[gridInd][row][0]=passCount;
                passCount++;
            }else{                                          //Middle Grids
                if(numCols > 1){
                    _grids[gridInd][row][0]=passCount;
                    passCount++;
                }
                if(passCount > passengerCount)
                    return;
                _grids[gridInd][row][numCols-1]=passCount;
                passCount++;
            }
        }
    }
    
    if(passCount > passengerCount)
        return;
    
    //fill window seats
    int fstGridSize=(int)_grids[0].size();
    int lstGridSize=(int)_grids[numGrids-1].size();
    int maxRowSize=(int)std::max(fstGridSize,lstGridSize);
    for(int row=0;row < maxRowSize;row++){
        if(row < fstGridSize){              //First Grid Window Seats
            _grids[0][row][0]=passCount;
            passCount++;
        }
        if(passCount > passengerCount)
            return;
       int cols=(int)_grids[numGrids-1][0].size();
       if(row < lstGridSize){               //Last Grid window seats
            _grids[numGrids-1][row][cols-1]=passCount;
            passCount++;
       }
        if(passCount > passengerCount)
            return;
    }
    
    //fill middle seats
    for(int row=0;row < maxRows; row++){
        for(int gridInd=0;gridInd<numGrids;gridInd++){
            int numRows=(int)_grids[gridInd].size();
            if(row >= numRows)
                continue;
            int numCols=(int)_grids[gridInd][0].size();
            for(int col=1;col<numCols-1;col++){         //Leaving window and aisle seats, allocating middle seats to passengers
                if(passCount > passengerCount)
                    return;
                _grids[gridInd][row][col]=passCount;
                passCount++;
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    vector<vector<vector<int> > > _grids;
    int numPassengers;
    cout<<"Enter number of passengers : ";
    cin>>numPassengers;
    if(numPassengers <= 0){
        cout<<"Seating is not possible with 0 entries\nExiting...\n";
        return 0;
    }
    int numGrids;
    cout<<"Enter number of Grids : ";
    cin>>numGrids;
    int gridCnt=1;
    //reading row and column sizes for each grid
    while(gridCnt <= numGrids){
        int rows,cols;
        printf("Enter no.of seats in row wise in grid %d:",gridCnt);
        cin>>rows;
        printf("Enter no.of seats in column wise in grid %d:",gridCnt);
        cin>>cols;
        vector<vector<int> > _tmp(cols,vector<int>(rows,0));
        _grids.push_back(_tmp);
        gridCnt++;
    }
    seatArrangement(_grids, numPassengers);

    cout<<"\n SEATING OUTPUT \n";
    cout<<"*****************************\n";
    for(int gridInd=0;gridInd<numGrids;gridInd++){
        for(int row=0;row<_grids[gridInd].size();row++){
            for(int col=0;col<_grids[gridInd][0].size();col++){
                cout<<_grids[gridInd][row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<"----------------------\n";
    }
    cout<<"*****************************\n\n";
    
    
    return 0;
}
