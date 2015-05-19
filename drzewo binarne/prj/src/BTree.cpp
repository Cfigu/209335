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

/*
void wypisz(string sp, string sn, BTree * A)
{
  string s;

  string cr,cl,cp;
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;
  

  if(A)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    wypisz(s + cp, cr, A->right);

    s = s.substr(0,sp.length()-2);
    cout << s << sn << A->data << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    wypisz(s + cp, cl, A->left);
  }
}

*/