#ifndef MYFUNCTIONDATA_H_INCLUDED
#define MYFUNCTIONDATA_H_INCLUDED
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
void createSudokuChange(int *sudokuUpdate,int *sudokuZero);
void changeIntergerToString(string *a,int*sudokuUpdate);
bool checkAddNumber(int x,int y,int *sudokuBegin);
void loadData(int *sudokuUpdate,string a);
void createSudoku(int *sudokuUpdate,int *sudokuCheck,int k);
bool checkWin(int *sudokuUpdate,int *sudokuResult );
void check3x3(int x,int y,int *sudokuUpdate,int *sudokuZero);
void checkfull(int *sudokuUpdate,int *sudokuZeRo);
void changeSudoku(int *sudokuUpdate,int *sudokuCheck,int *sudokuResult);
void writeFile(string a,int*data);
bool checkDK(int *S,int x,int y,int k);
void backtracking(int *S,int x, int y,int *Su);
#endif // MYFUNCTIONDATA_H_INCLUDED
