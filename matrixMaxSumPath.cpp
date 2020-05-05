/*

So in this problem we are starting from the initial member of a matrix (0.0) and we have to reach the last member
i.e (size.size) and we can only move one step to the right or one down.
and we have to calculate the maximum possible sum of the paths

I worked the problem in a way that the size of matrix is decided by the user and then it will be dynamically allocated

code : amine dakhli

*/
#include <iostream>

using namespace std;

int ** visited ;

int ** previousAnswer ;



int max_sum(int ** matrix , pair<int,int>  start , pair<int,int> end){

  //cout << start.first ;
  if(start.first == end.first && start.second == end.second) return matrix[start.first][start.second] ;
  if(visited[start.first][start.second]) return previousAnswer[start.first][start.second] ;

  pair<int,int>  nextstartdown (start.first + 1 , start.second);
  pair<int,int>  nextstartright (start.first, start.second + 1);

  visited[start.first][start.second] = 1 ;
  int & maxsum = previousAnswer[start.first][start.second] ;

  if(start.second < end.second and start.first < end.first )
  maxsum = matrix[start.first][start.second] + max(max_sum(matrix,nextstartdown,end),
      max_sum(matrix,nextstartright,end)) ;
  else if(start.second == end.second) maxsum = matrix[start.first][start.second] +
      max_sum(matrix,nextstartdown,end);
  else  maxsum = matrix[start.first][start.second] + max_sum(matrix,nextstartright,end);

  return maxsum ;
}



int main(){

  int matrixSize ;

  cin >> matrixSize ;

  int ** matrix = new int * [matrixSize] ;

  for(int i=0 ; i < matrixSize ; i++)
    matrix[i] = new int [matrixSize] ;

  visited = new int * [matrixSize] ;
  for(int i=0 ; i < matrixSize ; i++)
    visited[i] = new int [matrixSize] ;

  previousAnswer = new int * [matrixSize];
  for(int i=0 ; i < matrixSize ; i++)
    previousAnswer[i] = new int [matrixSize] ;

  // Now fill the matrix you way want,

  int lastj = 0 ;

  for(int i=0 ; i < matrixSize ; i++){

    for(int j=0 ; j < matrixSize ; j++){

      matrix[i][j] = lastj + j + 1 ;

    }
    lastj += matrixSize ;
  }

  for(int i=0 ; i < matrixSize ; i++){

    for(int j=0 ; j < matrixSize ; j++){

      cout << matrix[i][j] << ' ' ;

    }
    cout << endl ;

  }

  pair<int,int> start (0,0) ;
  pair<int,int> end (matrixSize - 1,matrixSize - 1) ;

int s = max_sum(matrix , start , end );

cout << s ;

//now free the allocated memory

  for(int i=0 ; i < matrixSize ; i++)
    delete[] matrix[i];

  for(int i=0 ; i < matrixSize ; i++)
      delete[] visited[i];

  for(int i=0 ; i < matrixSize ; i++)
      delete[] previousAnswer[i];

  delete[] matrix ;
  delete[] visited ;
  delete[] previousAnswer ;

  return 0;
}
