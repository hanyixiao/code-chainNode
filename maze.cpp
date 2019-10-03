#include <iostream>
#include <stack>

using namespace std;
class position{
public:
    int row;
    int col;
    ~position(){};
    position(){};
    position(int row,int col):row(row),col(col){};
};
bool findPath(bool *srcmaze,int row,int col,int size,position target)
{//寻找一条从入口到达出口的路lujing
// 如果找到返回true否则返回false    
    //初始化偏移量
    stack<position> *path;
    path=new stack<position>;
    position offset[4];
    offset[0].row=0;offset[0].col=1;//右
    offset[1].row=1;offset[1].col=0;//下
    offset[2].row=0;offset[2].col=-1;//左
    offset[3].row=-1;offset[3].col=0;//上
    //get the dimension of array
//    int row=sizeof(maze[0])/sizeof(bool);
//    int col=sizeof(maze)/sizeof(bool);
    printf("row is %d\n",row);
    printf("col is %d\n",col);
    printf("srcmaze %d\n",srcmaze[(row-1)*col+7]);
    bool maze[size+1][size+1]={};
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<size+1;j++)
        {
            maze[i][j]=1;
        }
    }
    for(int i=1;i<row+1;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            maze[i][j]=srcmaze[(i-1)*col+(j-1)];
        }
    }
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<size+1;j++)
        {
            cout<<maze[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;

    position here;
    here.row=1;
    here.col=1;
    maze[1][1]=1;
    int option=1;
    int lastOption=3;
    //寻找一条路径
    while(here.row!=target.row||here.col!=target.col)
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
    printf("%d\n",sizeof(mymaze1)/sizeof(bool));
    position target(6,8);
    cout<<findPath((bool *)mymaze1,6,9,10,target)<<endl;
    cout<<"game end"<<endl;
    
    return 0;
}