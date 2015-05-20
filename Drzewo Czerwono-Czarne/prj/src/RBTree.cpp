#include "RBTree.h"


using namespace std;

/*!
*\file
*\brief Plik RBTree.cpp
*
*Zawiera definicje metod klasy RBTree
*/       

RBTree::RBTree()
{
  cr = cl = cp = "  ";
  cr[0] = 114; cr[1] = 45; //cr[0] =218 "┌"; cr[1] =196 "─";
  cl[0] = 76; cl[1] = 45; //cl[0] =192 "└"; cl[1] = "─"; 
  cp[0] = 124;              //cp[0] =179 "│"; 
  S.kolor = 'B';         
  S.up    = &S;
  S.left  = &S;
  S.right = &S;
  korzen    = &S;         
}

RBTree::~RBTree()
{
  usun(korzen);    
}

void RBTree::usun(RBT * p)
{
  if(p != &S)
  {
    usun(p->left);  
    usun(p->right); 
    delete p;             
  }
}

void RBTree::wypisz(string sp, string sn, RBT * p)
{
  string t;

  if(p != &S)
  {
    t = sp;
    if(sn == cr)
      t[t.length() - 2] = ' ';
    
    wypisz(t+cp,cr,p->right);

    t = t.substr(0,sp.length()-2);
    cout << t << sn << p->kolor << ":" << p->klucz << endl;

    t = sp;
    if(sn == cl)
      t[t.length() - 2] = ' ';
    
    wypisz(t+cp,cl,p->left);
  }
}


void RBTree::pokaz()
{
  wypisz("","",korzen);
}


RBT * RBTree::szukajRBT(int k)
{
  RBT * p;

  p = korzen;
  while((p != &S) && (p->klucz != k))
    {
      if(k < p->klucz) 
	p = p->left;
      else           
	p = p->right;
    }
  if(p == &S) 
    return NULL;
  
  return p;
}


RBT * RBTree::minRBT(RBT * p)
{
  if(p != &S)
    while(p->left != &S) 
      p = p->left;
  
  return p;
}


RBT * RBTree::nastRBT(RBT * p)
{
  RBT * r;

  if(p != &S)
  {
    if(p->right != &S) 
      return minRBT(p->right);
    
    else
    {
      r = p->up;
      while((r != &S) && (p == r->right))
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return &S;
}


void RBTree::obrocLewo(RBT * A)
{
  RBT * B, * p;

  B = A->right;
  if(B != &S)
  {
    p = A->up;
    A->right = B->left;
    if(A->right != &S) 
      A->right->up = A;

    B->left = A;
    B->up = p;
    A->up = B;

    if(p != &S)
    {
      if(p->left == A) 
	p->left = B; 
      else 
	p->right = B;
    }
    else 
      korzen = B;
  }
}

void RBTree::obrocPrawo(RBT * A)
{
  RBT * B, * p;

  B = A->left;
  if(B != &S)
  {
    p = A->up;
    A->left = B->right;
    if(A->left != &S) 
      A->left->up = A;

    B->right = A;
    B->up = p;
    A->up = B;

    if(p != &S)
    {
      if(p->left == A) 
	p->left = B; 
      else 
	p->right = B;
    }
    else 
      korzen = B;
  }
}


void RBTree::wstawRBT(int k)
{
  RBT * X, * Y;

  X = new RBT;        
  X->left  = &S;        
  X->right = &S;
  X->up    = korzen;
  X->klucz   = k;
  if(X->up == &S) 
    korzen = X; 
  else
    while(true)             
      {
	if(k < X->up->klucz)
	  {
	    if(X->up->left == &S)
	      {
		X->up->left = X;  
		break;
	      }
	    X->up = X->up->left;
	  }
	else
	  {
	    if(X->up->right == &S)
	      {
		X->up->right = X; 
		break;
	      }
	    X->up = X->up->right;
	  }
      }
  X->kolor = 'R';        
  while((X != korzen) && (X->up->kolor == 'R'))
    {
      if(X->up == X->up->up->left)
	{
	  Y = X->up->up->right; 
	  
	  if(Y->kolor == 'R') 
	    {
	      X->up->kolor = 'B';
	      Y->kolor = 'B';
	      X->up->up->kolor = 'R';
	      X = X->up->up;
	      continue;
      }
	  
	  if(X == X->up->right) 
	    {
	      X = X->up;
	      obrocLewo(X);
      }
	  
	  X->up->kolor = 'B'; 
	  X->up->up->kolor = 'R';
	  obrocPrawo(X->up->up);
	  break;
	}
    else
      {                
      Y = X->up->up->left;
      
      if(Y->kolor == 'R')
	{
	  X->up->kolor = 'B';
	  Y->kolor = 'B';
	  X->up->up->kolor = 'R';
	  X = X->up->up;
	  continue;
	}
      
      if(X == X->up->left) 
	{
	  X = X->up;
	  obrocPrawo(X);
	}
      
      X->up->kolor = 'B'; 
      X->up->up->kolor = 'R';
      obrocLewo(X->up->up);
      break;
      }
    }
  korzen->kolor = 'B';
}


void RBTree::usunRBT(RBT * X)
{
  RBT * W, * Y, * Z;
  
  if((X->left == &S) || (X->right == &S))
    Y = X;
  else
    Y = nastRBT(X);
  
  if(Y->left != &S)
    Z = Y->left;
  else
    Z = Y->right;

  Z->up = Y->up;

  if(Y->up == &S)
    korzen = Z;
  else if(Y == Y->up->left)
    Y->up->left  = Z;
  else
    Y->up->right = Z;

  if(Y != X)
    X->klucz = Y->klucz;

  if(Y->kolor == 'B')   
    while((Z != korzen) && (Z->kolor == 'B'))
      if(Z == Z->up->left)
      {
        W = Z->up->right;

        if(W->kolor == 'R')
        {             
          W->kolor = 'B';
          Z->up->kolor = 'R';
          obrocLewo(Z->up);
          W = Z->up->right;
        }

        if((W->left->kolor == 'B') && (W->right->kolor == 'B'))
        {            
          W->kolor = 'R';
          Z = Z->up;
          continue;
        }

        if(W->right->kolor == 'B')
        {           
          W->left->kolor = 'B';
          W->kolor = 'R';
          obrocPrawo(W);
          W = Z->up->right;
        }

        W->kolor = Z->up->kolor;
        Z->up->kolor = 'B';
        W->right->kolor = 'B';
        obrocLewo(Z->up);
        Z = korzen;         i
      }
      else
      {                
        W = Z->up->left;

        if(W->kolor == 'R')
        {              
          W->kolor = 'B';
          Z->up->kolor = 'R';
          obrocPrawo(Z->up);
          W = Z->up->left;
        }

        if((W->left->kolor == 'B') && (W->right->kolor == 'B'))
        {              
          W->kolor = 'R';
          Z = Z->up;
          continue;
        }

        if(W->left->kolor == 'B')
        {             
          W->right->kolor = 'B';
          W->kolor = 'R';
          obrocLewo(W);
          W = Z->up->left;
        }

        W->kolor = Z->up->kolor; 
        Z->up->kolor = 'B';
        W->left->kolor = 'B';
        obrocPrawo(Z->up);
        Z = korzen;         
      }

  Z->kolor = 'B';

  delete Y;
}


