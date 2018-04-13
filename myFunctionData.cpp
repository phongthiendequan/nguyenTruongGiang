#include"myFunctionData.h"
void createSudokuChange(int *sudokuUpdate,int *sudokuZero)
{
    srand(time(NULL));

  for(int k=1;k<rand()%5;k++)
  {
      for(int j=0;j<3;j++)
  for(int i=0;i<9;i++)
  {
      int tmp ;
     tmp= *(sudokuUpdate+9*i+j);
     *(sudokuUpdate+9*i+j)=*(sudokuUpdate+9*(i)+j+3);
     *(sudokuUpdate+9*i+j+3)=tmp;
     tmp= *(sudokuZero+9*i+j);
     *(sudokuZero+9*i+j)=*(sudokuZero+9*(i)+j+3);
     *(sudokuZero+9*i+j+3)=tmp;
  }
  for(int i=0;i<3;i++)
  for(int j=0;j<9;j++)
  {
      int tmp ;
     tmp= *(sudokuUpdate+9*i+j);
     *(sudokuUpdate+9*i+j)=*(sudokuUpdate+9*(i+3)+j);
     *(sudokuUpdate+9*(i+3)+j)=tmp;
     tmp= *(sudokuZero+9*i+j);
     *(sudokuZero+9*i+j)=*(sudokuZero+9*(i+3)+j);
     *(sudokuZero+9*(i+3)+j)=tmp;
  }
  }

  for(int k=1;k<rand()%3;k++)
  {
      for(int i=3;i<6;i++)
     for(int j=0;j<9;j++)
    {
      int tmp ;
     tmp= *(sudokuUpdate+9*i+j);
     *(sudokuUpdate+9*i+j)=*(sudokuUpdate+9*(i+3)+j);
     *(sudokuUpdate+9*(i+3)+j)=tmp;
     tmp= *(sudokuZero+9*i+j);
     *(sudokuZero+9*i+j)=*(sudokuZero+9*(i+3)+j);
     *(sudokuZero+9*(i+3)+j)=tmp;
    }

    for(int j=0;j<3;j++)
  for(int i=0;i<9;i++)
  {
      int tmp ;
     tmp= *(sudokuUpdate+9*i+j);
     *(sudokuUpdate+9*i+j)=*(sudokuUpdate+9*(i)+j+3);
     *(sudokuUpdate+9*i+j+3)=tmp;
     tmp= *(sudokuZero+9*i+j);
     *(sudokuZero+9*i+j)=*(sudokuZero+9*(i)+j+3);
     *(sudokuZero+9*i+j+3)=tmp;
  }

  }
}
void changeIntergerToString(string *a,int*sudokuUpdate)
{
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
   {

      *(a+i*9+j)=to_string(*(sudokuUpdate+i*9+j));
   }

}
bool checkAddNumber(int x,int y,int *sudokuBegin )
{
  return (*(sudokuBegin+(y-100)*9/40+(x-100)/40)==0?true : false);
}
void loadData(int *sudokuUpdate, string a)
{
    ifstream file(a.c_str());
    file.is_open();
   for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
   {
      file>> *(sudokuUpdate+9*i+j);
   }

}
void  createSudoku(int *sudokuUpdate,int *sudokuCheck,int k)
{
    string a[4]={"level_1.txt","level_2.txt","level_3.txt","level_4.txt"};
    int i=1;
    srand(NULL);
    i=rand()%4;
    ifstream file(a[i].c_str());
    file.is_open();
   for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
   {
      file>> *(sudokuUpdate+9*i+j);
     *(sudokuCheck+9*i+j)= *(sudokuUpdate+9*i+j);
   }

}
bool checkWin(int *sudokuUpdate,int *sudokuResult )
{

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(*(sudokuResult+9*i+j)!=*(sudokuUpdate+9*i+j))
            {
               return false;

            }
        }
    return true;
}
void check3x3(int x,int y,int *sudokuUpdate,int *sudokuZero)
{
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++)
    {

       for(int m=x;m<x+3;m++)
        for(int n=y;n<y+3;n++)
        if(*(sudokuUpdate+9*i+j)!=0&&*(sudokuUpdate+9*i+j)==*(sudokuUpdate+9*m+n)&&(9*i+j!=9*m+n))
        *(sudokuZero+9*i+j) =1;
    }
}
void checkfull(int *sudokuUpdate,int *sudokuZeRo)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        *(sudokuZeRo +9*i+j)=0;
    }
   for(int i=0;i<9;i++)
       for(int j=0;j<9;j++)
        for(int k=0;k<9;k++)
 {
        if(*(sudokuUpdate+9*i+j)!=0&&*(sudokuUpdate+9*i+j)==*(sudokuUpdate+9*i+k)&&(9*i+j!=9*i+k))
        {
            *(sudokuZeRo+9*i+j) =1;
        }
    }
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
        for(int k=0;k<9;k++)
    {
        if(*(sudokuUpdate+9*j+i)!=0&&*(sudokuUpdate+9*j+i)==*(sudokuUpdate+9*k+i)&&(9*j+i!=9*k+i))
        {
            *(sudokuZeRo+9*j+i) =1;

       }
    }
    for(int i=0;i<9;i=i+3)
        for(int j=0;j<9;j=j+3)
    check3x3(i,j,sudokuUpdate,sudokuZeRo);


    }
void changeSudoku(int *sudokuUpdate,int *sudokuCheck,int *sudokuResult)
{
    createSudoku(sudokuUpdate,sudokuCheck,0);
    createSudokuChange(sudokuUpdate,sudokuCheck);
    backtracking(sudokuUpdate,0,0,sudokuResult);
}
void writeFile(string a,int*data)
{
    ofstream outfile;
    outfile.open(a.c_str(), ios::out | ios::trunc );
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        outfile<<*(data+9*i+j) <<" ";
        outfile<<endl;
    }

        outfile.close();
}
bool checkDK(int *S,int x,int y,int k)
{
    int i=0,j=0;
    for(i=0;i<9;i++)
        if (*(S+9*x+i) == k) return false;
    for(j=0;j<9;j++)
       if(*(S+9*j+y)== k)  return false;
    int a=x/3;int b=y/3;
    for(i=a*3;i<a*3+3;i++)
        for(j=b*3;j<b*3+3;j++)
        if(*(S+9*i+j)==k) return false;
       // cout<<"1";
        return true;

}
void backtracking(int *S,int x, int y,int *Su)
{

    if(y==9)
    {
        if(x==8)
          {
            for(int i=0;i<9;i++)
             for(int j=0;j<9;j++)
                *(Su+9*i+j)=*(S+9*i+j);

          }
          else
          {
              backtracking(S,x+1,0,Su);


          }

    } else if(*(S+9*x+y)==0)
    {

        for(int k=1;k<=9;k++)
        {
            if (checkDK(S,x,y,k))
        {

            *(S+9*x+y)=k;
           backtracking(S,x,y+1,Su);

            *(S+9*x+y)=0;
        }
        }
    } else
    backtracking(S,x,y+1,Su) ;
}
