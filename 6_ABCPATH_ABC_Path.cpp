/*
ABCPATH - ABC Path
no tags 

You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':

ABC
One such path is:

path

Input
Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.

Output
For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.

Example
Sample Input:
4 3
ABE
CFG
BDH
ABC
0 0

Sample Output:
Case 1: 4
*/
#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int hashmap[100][100];
 
int testCount = 1;
int findPath( int x, int y, char ch, int m, int n, vector<string> &matrix){
    
    // We should be inside boundary and ch must be equal to character present at x,y
    if( x<0 || y<0 || x>= m || y>= n || matrix[x][y]!=ch )
        return 0;
    
    // If already calculated then return !
    // if 'D' is present at x,y and if we have already calculated then 
    if(hashmap[x][y]!=0) return hashmap[x][y];
    
    // now we need to check all eight possible directions;
    int arr[8][2] = {
                     {x-1,y-1},{x-1,y},{x-1,y+1},{x,y-1},{x,y+1},{x+1,y-1},                     {x+1,y},{x+1,y+1}
                    };
    
    int max = 0;
    for(int i=0;i<8;i++){
            
       int next_x = arr[i][0];
       int next_y = arr[i][1];
       
       int len = findPath(next_x, next_y, ch+1, m , n , matrix );
       if( len > max )
       max = len;
    }
    
    // Save it for future !
    hashmap[x][y] = max + 1;
    
    return max+1;
}
 
int main(){
  
  while(true){
    int m,n;
    
    cin >> m >> n;
    
    if(m==0&&n==0) break;
    
    vector<string> matrix;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         hashmap[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++){
        string temp;
        cin>>temp;
        matrix.push_back(temp);        
    }
    
    int max_answer = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // Let say we will start from i,j
            int temp = findPath(i , j, 'A' , m, n, matrix);
            if(temp > max_answer){
               max_answer = temp;
            }
        }        
    }
    
    cout<< "Case "<<testCount<<": "<<max_answer<<endl;   
    
    testCount++;
  }
  
  return 0;   
}