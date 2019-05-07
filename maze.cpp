#include <iostream>
#include <stack>

using namespace std;
class position{
public:
    int row;
    int col;
};
bool findPath(bool **maze,int size,stack<position> *path)
{//寻找一条从入口到达出口的路lujing
// 如果找到返回true否则返回false    
    //初始化偏移量
    path=new stack<position>;
    position offset[4];
    offset[0].row=0;offset[0].col=1;//右
    offset[1].row=1;offset[1].col=0;//下
    offset[2].row=0;offset[2].col=-1;//左
    offset[3].row=-1;offset[3].col=0;//上

    //初始化迷宫外围的墙壁
    for(int i=0;i<=size+1;i++)
    {
        maze[0][i]=maze[size+1][i]=1;
        maze[i][0]=maze[i][size+1]=1;
    }

    position here;
    here.row=1;
    here.col=1;
    maze[1][1]=1;
    int option=1;
    int lastOption=3;
    //寻找一条路径
    while(here.row!=size||here.col!=size)
    {   //没有找到出口
        //找到要移动的相邻的一步
        int r,c;
        while(option<=lastOption)
        {
            r=here.row+offset[option].row;
            c=here.col+offset[option].col;
            if(maze[r][c]==0) break;
            option++;
        }
        //相邻一步是否找到
        if(option<=lastOption)
        {
            //移动到maze[r][c]
            path->push(here);
            here.row=r;
            here.col=c;
            maze[r][c]=1;//防止重复走到此地
            option=0;
        }
        else{
            //没有相邻的一步走则返回
            if(path->empty())
                return false;
            position next=path->top();
            path->pop();
            if(next.row==here.row)
                option=2+next.col-here.col;
            else option = 3+next.row-here.row;
            here=next;
        }
    }
    return true;
}
int main(int argc,char **argv)
{
    cout<<"maze qustion"<<endl;
    bool mymaze1[6][9]={
    {0,0,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1},
    {1,0,0,1,1,1,1,1,1},
    {1,1,0,0,1,1,1,1,1},
    {1,1,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,0,0},
    };
    for(int i=0;i<6;i++)
    {  
        for(int j=0;j<9;j++)
        {
            cout<<mymaze1[i][j]<<',';
        }
        cout<<endl;
    }
    stack<position> *path;
    cout<<findPath((bool **)mymaze1,40,path);
 /*   for(int i=0;i<path.size();i++)
    {
        cout<<path->top.row<<','<<path->top.row<<endl;
        path->pop();
    }
*/    cout<<"game end"<<endl;
    
    return 0;
}