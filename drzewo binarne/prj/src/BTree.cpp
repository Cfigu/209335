#include "BTree.h"


using namespace std;

BTree * czytaj(int n)
{
  BTree * root;
  BTree ** A;          
  int i;
  int dane;
  int lewo,prawo;
              
  
  A = new BTree * [n]; 
  
  for(i = 0; i < n; i++)
    A[i] = new BTree; 
  
  for(i = 0; i < n; i++)
    {
      cin >> dane >> lewo >> prawo;     
      
      A[i]->data = dane;        
      
      if(lewo) A[i]->left = A[lewo];
     
      else  A[i]->left = NULL;  
      
      if(prawo) A[i]->right = A[prawo];
     
      else  A[i]->right = NULL;  
    }
  
  root = A[0];            
  
  delete [] A;    

  return root;        
  
}


void usun(BTree * A)
{
  if(A)
  {
    usun(A->left);   
    usun(A->right);  
    delete A;             
  }
}
