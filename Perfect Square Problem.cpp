

//Write a program to find and print the first perfect square (i*i) whose last two digits are both odd. 
//Very important. Make sure to check that the answer you get is indeed a perfect square.

#include <iostream>
using namespace std;

int main() 
{
    //prove that only need to check 1 to 51, because after 51 the last 2 digits will be the same.
    int check=51;
    for(int c=1;c<51;check++,c++)
        {
         int a=(check*check)%100;//a=the last 2 digits from 51*51 to 100*100
         int b=(c*c)%100;//b=the last 2 digit from 1*1 to 50*50
         if (a!=b)//check the code if it's correct
         cout<<"error"<<endl;
        }
    
   for (int i=1;i<51;i++) 
   { 
      int n=i*i;
      if (n%2!=0 && (n/10)%2!=0) 
      //if they both are odd, the last number n%2 and the second last (n/10)%2 won't equal to 0
      {
         cout<<n;
         break;
      } 
   }
   
    cout << "no solution"<<endl;
    //if we can't find the first perfect square whose last two digits are both odd.
    //it will just print "no solution"
    return 0;
    
}








