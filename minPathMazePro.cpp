#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class position {
public:
	int row;
	int col;
	position() {};
	position(int r, int c) :row(r), col(c) {};
	~position() {};
	void show()
	{
		cout << '(' << row << ',' << col << ')';
	};
	void operator =(position rhs)
	{
		this->row = rhs.row;
		this->col = rhs.col;
	};
};
bool findPath(position start, position finish, int grid[9][9], 
	int size,int &pathLength,vector<position>&pvec)
{
	//寻找从开始点到终点的位置
	//找到时返回true，否则返回false
	if ((start.row == finish.row) && (start.col == finish.row))
	{//起始点==终点
		pathLength = 0;
		return true;
	}
	//初始化偏移量
	position offset[4];
	offset[0].row = 1; offset[0].col = 0;//向下
	offset[1].row = 0; offset[1].col = 1;//向右
	offset[2].row = -1; offset[2].col = 0;//向上
	offset[3].row = 0; offset[3].col = -1;//向左
	//初始化网格周围的数据
	for (int i = 0; i <= size + 1; i++)
	{
		grid[0][i] = grid[size + 1][i] = 1;
		grid[i][0] = grid[i][size + 1] = 1;
	}

	for(int i=0;i<=size+1;i++)
	{
		for(int j=0;j<=size+1;j++)
		{
			cout<<grid[i][j];
		}
		cout << endl;
	}

	position here = start;
	//用grid[i][j]=1来代表被封锁的距离
	//用grid[i][j]>1来来表示距离起始距离grid[i][j]-2的距离
	grid[start.row][start.col] = 2;//初始位置距离0
	int numOfNbrs = 4;//记录相邻位置数

	//对可以到达的位置进行标记
	queue<position> q;
	position nbr;
	do
	{
		//给相邻的位置坐标记
		for (int i = 0; i < numOfNbrs; i++)
		{
			//检查相邻位置
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == 0)
			{//对不可标记的
				grid[nbr.row][nbr.col] =
					grid[here.row][here.col] + 1;
				if ((nbr.row == finish.row) && (nbr.col == finish.col)) break;
				//把后者插入到队列中
				q.push(nbr);
			}
		}
		//是否到达终点
		cout << endl;
		for (int i = 0; i <= size + 1; i++)
		{
			for (int j = 0; j <= size + 1; j++)
			{
				if (grid[i][j] >= 10) cout << grid[i][j] << "  ";
				else cout << grid[i][j] << "   ";
			}
			cout << endl;
		}
		if ((nbr.row == finish.row) && (nbr.col == finish.col)) break;

		//终点不可到达可以移到nbr吗？
		if (q.empty()) return false;
		here = q.front();//取下一个位置
		q.pop();

	} while (true);

	//构造路径
	pathLength = grid[finish.row][finish.col] - 2;
	position *path = new position[pathLength];

	//从终点回溯
	here = finish;
	for (int j = pathLength - 1; j >= 0; j--)
	{
		path[j] = here;
		//寻找祖先位置
		for (int i = 0; i < numOfNbrs; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == j + 2) break;
		}
		here = nbr;//移向祖先
	}
	vector<position>p(path, path + 12);
	pvec = p;
	return true;
}
int main()
{
	int maze[9][9] = {
	{0,0,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,1,1,1},
	{1,0,1,1,1,1,1,1,1},
	{1,0,1,1,1,0,0,0,1},
	{1,0,1,1,1,0,1,0,1},
	{1,0,0,1,1,0,1,0,1},
	{1,1,0,0,1,0,1,0,1},
	{1,1,1,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,0,0},
	};
	int pathlen;
	vector<position> vecp;
	cout << findPath(position(1, 1), position(7, 7), maze, 7,pathlen,vecp);
	cout << endl;
	cout << "the length of maze path:  " << pathlen << endl;
	cout << "THE PLAN:" << endl;
	for (int i = 0; i < vecp.size()-1; i++)
	{
		vecp[i].show();
		cout << "---->>>";
	}
	vecp[vecp.size() - 1].show();
	cout << endl;
	return 0;
}
