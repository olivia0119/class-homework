
//Question:Redo the 8 queens 1 dimensional array program with backtracking WITHOUT gotos.

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[],int c){ //like the for statement we did with goto
                        // but here if the queen in column c is ok, returns true.
    for(int i=0;i<c;i++){
        if (q[i]==q[c]||c-i==abs(q[c]-q[i])) 
        // q[i]==q[c] check the row. c-i==abs(q[c]-q[i])check the updiagonal and downdiagonal
            return false;
    }
    return true;
}

void print(int q[]){  //print 1d and 2d versions
    static int sol_num = 1;
    cout << "Solution #" << sol_num++ << ": ";
    int b[8][8] = {0}; // create a 2d array
    
    for (int i = 0; i < 8; i++) { //print 1d array version
        cout << q[i];
        b[q[i]][i] = 1; //row is q[i], column is i. place the queen into the 2d array.
    }
    cout << "\n";

    for(int i = 0; i < 8; i++) { //print 2d 8 queens version
        for (int j = 0; j < 8; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int q[8]={}; //create a 1d array
    int c=0; 
    
    while(c>=0){ // End the loop if the backtrack from the first column
        c++; //Move to the next column.
        if (c==8){ //  If we are in the last column, print and backtrack
            print(q);
            c--; 
        }
        else q[c]=-1; // If we are not in the last column, move to one before the first row of the next column
    
        while(c>=0){ 
            q[c]++; //move to the next row
            if (q[c]==8) c--; // If passed the end of the column, backtrack
            else if (ok(q,c)) break; 
            // Otherwise, if the queen is ok, break (go back to the beginning of the outer loop)
        }
    }
    
    return 0;
    
    
}




