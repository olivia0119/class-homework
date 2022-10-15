
#include <iostream>
using namespace std;

int main() {
   int q[8][8]={0}; //set a 8*8 chessboard
   int r;//row
   int c=0;//column
   q[0][0]=1;//1=queen, put the queen in the upper left side
    int numsol=1;

nc: //next column
    c++; //label next column
    if (c==8) goto print;//if c=8 means find one of Solution and print out 
    r=-1; //reset row evey time
    
nr: //next row 
    r++; //label next row
    if (r==8) goto backtrack;
    
//test 1.row 2.updiagonal 3.downdiagonal

    for (int i=0;i<c;i++)//row test
        if(q[r][i]==1) goto nr;
        
    for (int i=1;r-i>=0&&c-i>=0;i++)//updiagonal 
        if(q[r-i][c-i]==1) goto nr;
        
    for (int i=1;r+i<8&&c-i>=0;i++)//downdiagona
        if (q[r+i][c-i]==1) goto nr;
    
    q[r][c]=1; //place the queen
    goto nc;
    
backtrack:
    c--;//back to last column
    if (c==-1) return 0; //c=-1 end Program
    r=0;
    while (q[r][c]!=1) r++; //find the queen in column
    q[r][c]=0; //remove queens
    goto nr;
    
print:
   cout << "Solution #" << numsol++ << ":\n";//print the Solution
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
         cout << q[i][j];
      cout << "\n";
   }
   goto backtrack;

}
    
    
    
    
    
    
    
    
    
    
    
    
    





