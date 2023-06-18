#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrice.h"
#include"vecteur.h"
void GaussRSL(matrice A,vecteur B,vecteur *X);
int main(){
  int m,n=0;
  matrice A=matriceNulle(m,n);//初始化系数矩阵
  vecteur B=vecteurNulle(m);//初始化右边矩阵
  vecteur *X;
  char *f="data_matrice";
  lireMatrice(A,f);
  GaussRSL(A,B,X);
  ecrieVecteur(X);
  return EXIT_SUCCESS;
}
void GaussRSL(matrice A,vecteur B,vecteur *X){
  matrice *m=A;
  int max_index=0;
  int top_linge;
  T max_value=0;
  T times=0;
  //高斯消元法进行矩阵对角化
  for(int j=0;j<m->nbl;j++){
    
    for(int i=0;i<m->nbc;i++){//找到第i列的最大数作为主元，并记录索引和值
      T abs_value=fabs(getM(A,i,j));
      if(abs_value>max_value){
        max_value=abs_value;
        max_index=i;
      }
    }
    for(int j=0;j<m->nbl;j++){
      m->mat[i*m->nbc+j]/=max_value;//主元所在行的主元归一化，并交换到最上面
      echangerLingesM(top_ligne,max_index);//echange lignes
    }
    top_ligne++;
    
    for(int i=1;i<m->nbc;i++){//主元所在行同成一一个合适的数，再减去其余各行的所有元素，来消去每行第一列未知数，变为0
      times=m->mat[i*m->nbc+j]/m->mat[0*m->nbc+j];
      for(int j=0;j<m->nbl;j++){
      m->mat[i*m->nbc+j]-=times*(m->mat)[0*m->nbc+j];
      }
    }
    
  }
  
  //对角化后在从下往上消元，把所有行的未知数都变成1
  for()