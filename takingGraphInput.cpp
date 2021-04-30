#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int adj[100][100];
 int main(){
     freopen("input.txt", "r", stdin);
     int node, edge;
     cin >> node >> edge;
     
    //  cout << "now enter the inputs: " << endl;

     int number1, number2;

     for(int i = 0; i < edge; i++){
         cin >> number1 >> number2;
         adj[number1][number2] = 1;
         adj[number2][number1] = 1;
     }
    
    //  cout << "Result: " << endl;
     for(int i = 0; i < node; i++){
         for(int j = 0; j < node; j++){
             cout << adj[i][j] << " ";
     }
     cout << endl;
     }
     return 0;
 }