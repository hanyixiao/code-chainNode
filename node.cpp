#include <iostream>
#include <sstream>
using namespace std;
template<class T>
struct chainNode{
    T element;
    chainNode<T> *next;
    //方法
    chainNode(){};
    chainNode(const T& element){
        this->element=element;
    }
    chainNode(const T& element,chainNode<T> *next){
        this->element=element;
        this->next=next;
    }
}
template<class T>
class chain
{
public:
    chain(int initCapacity=10);
    chain(const chain<T>&);
    ~chain();
    //抽象数据类型
    bool empty()const {return listSize==0};
    int size()const {return listSize};
    T& get(int theIndex)const;
    int indexOf(const T& the element) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream &out)const;
protected:
    void checkIndex(int theIndex)const;
    chainNode<T> *firstNode;
    int listSize;
}
template<class T>
chain<T>::chain(int initCapacity)
{
    if(initCapacity<1)
    {
        ostringstream s;
        s<<"initial capacity="<<initCapacity<<"must be >0";
        throw illegalParameterValue(s.str());
    }
    firstNode =NULL;
    listSize=0;
}
//复制构造函数
template<class T>
chain<T>::chain(const chain<T>&theList)
{
    listSize=theList.size();
    if(listSize==0)
    {
        //链表为空
        firstNode=NULL;
        return;
    }
    //链表为非空
    chainNode<T>*sourceNode = theList.firstNode;
    firstNode =new chainNode<T>(sourceNode->element):
    sourceNode=souceNode->next;
    chainNode<T> *targetNode=firstNode;
    //当前链表的最后一个节点
    while(sourceNode!=NULL)
    {
        targetNode->next=new chainNode<T>(sourceNode->element);
        targetNode=targetNode->next;
        sourceNode=sourceNode->next;
    }
    targetNode->next=NULL;
}
template<class T>
chain::~chain()
{
    //链表析构函数
    while(firstNode!=NULL)
    {
        chainNode<T> nextNode=fristNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
}
//get 方法
template<class T>
T& chain::get(int theIndex) const
{
    //移动向需要的节点
    chainNode<T> *currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
    {
        currentNode=currentNode->next;
    }
    return currentNode->element;
}
//方法IndextOf（）
template<class T>
T& chain::indexOf(const T &theElement)const
{
    //搜索元素TheElement首次出现的位置    
    //若该元素不存在则返回-1
    chainNode<T>*currentNode=firstNode;
    for(int i=0;currentNode!=NULL&&i<listSize;i++)
    {
        if(currentNode->element==theElement)
        {
            return i;
        }
        currentNode=currentNode->next;
    }
    return -1;
}
//方法erase（）
template<class T>
void chain<T>::erase(int theIndex)
{
    chainNode<T> *currentNode;
    if(theIndex==0){
        currentNode=firstNode;
        firstNode=firstNode->next;
    }
    else
    {
        for(int i=0;i<theIndex;i++)
        {
            currentNode=firstNode;
            
        }
    }
    

}
int main(int argc,char **argv)
{
    chainNode header=new chainNode();
    for(int  i=0;i<10;i++)
    {
        chainNode data=new chainNode(i);
        header->next=data;
        header=header->next;
        delete data;
    }
    
}
