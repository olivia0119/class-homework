

#include <iostream>
#include <cmath>
using namespace std;

/* the cross labeled as:
  1 4 
0 2 5 7
  3 6 
 */
bool okay(int q[], int c) {
    static int a[8][5] = { // Helper Array
                            {-1}, // 0
                            {0,-1}, // 1
                            {0,1,-1}, // 2
                            {0,2,-1}, // 3
                            {1,2,-1}, // 4
                            {1,2,3,4,-1}, // 5
                            {2,3,5,-1}, // 6
                            {4,5,6,-1} // 7
                        };

//check if the number in position c has already been used
    for(int i=0;i<c;i++)
        if (q[i]==q[c]) return false;
        
//check if numbers are consecutive
    for (int i=0; a[c][i]!=-1;i++)
        if (abs(q[c]-q[a[c][i]])==1) return false;
        
    return true;
}

void backtrack(int& c){ //Backtrack 
    c--; //move to the last column
    if (c < 0)
        exit (1);
}

void print(int q[]) {
    static int sol = 1;
    cout << "Solution#:" << sol++ << endl;
    cout << " " << q[1] << q[4] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[6] << endl;
    cout << endl;
}

int main() {
    int q[8];
    int c = 0;
    q[c] = 1;//place number 1 at position 0
    
           
    while (c >= 0) { // end the loop if you have no square to backtrack
        c++; // Move to the next position c
        if (c==8)// if you have passed the last position, print and backtrack
        {
            print(q);//print this solution
            backtrack(c);// backtrack to look for next sol
        }
        else// Otherwise, move num to 0, which is one num smaller than 1
        {
        q[c]=0;
        }
                
        while (c>= 0) {
            q[c]++;// Move to the next num
            if (q[c]>8)//if no num can be placed at current position c
            {
                backtrack(c);
                continue;// backtrack to previous position
            }
            else // else if number is ok break and go to next position c
            {
                if (okay(q,c)) 
                break;
            }
        }
    }    
}




