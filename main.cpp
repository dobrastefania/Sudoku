#include <fstream>
using namespace std;
ifstream f("sudoku.in");
ofstream g("sudoku.out");
int sudoku[9][9];
int validitate(int sudoku[9][9],int n,int p,int q)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[p][i]==n && q!=i)
        {
            return 0;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][q]==n && p!=i)
        {
            return 0;
        }
    }
    int bx=q/3;
    int by=p/3;
    for(int i=by*3;i<by*3+3;i++)
    {
        for(int j=bx*3;j<bx*3+3;j++)
        {
            if(sudoku[i][j]==n && i!=p && j!=q)
            {
                return 0;
            }
        }
    }
    return 1;
}
int b(int sudoku[9][9],int *r,int *c)
{
    for(*r=0;*r<9;(*r)++)
    {
        for(*c=0;*c<9;(*c)++)
        {
            if(sudoku[*r][*c]==0)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool solutie(int sudoku[9][9])
{
    int r=0,c=0;
    int x=-1,y=-1;
    if (!b(sudoku, &r, &c))
        return 1;
    for(int i=1;i<=9;i++)
    {
        if(validitate(sudoku,i,r,c))
        {
            sudoku[r][c]=i;
            if(solutie(sudoku))
            {
                return 1;
            }
            sudoku[r][c]=0;
        }
    }
    return 0;
}
void TIPAR_sudoku(int sudoku[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            g<<sudoku[i][j]<<" ";
        }
        g<<'\n';
    }
}
int main()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            f>>sudoku[i][j];
    if(solutie(sudoku)==1)
        TIPAR_sudoku(sudoku);
    f.close();
    g.close();
    return 0;
}
