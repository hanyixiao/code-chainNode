#include <iostream>
using namespace std;
template<class T>
class maxHeap
{
public:
	maxHeap<T>() {};
	~maxHeap<T>() {};
	void pop();
	void changLength(T* theHeap, int arraylens)
	{
		//delete[]heap;
		heap = new T[2 * arraylens];
		for (int i = 0; i < arrayLength+1; i++)
		{
			heap[i] = theHeap[i];
		}
		//  arrayLength=arraylens;
		cout << "chang length ok" << endl;
	}
	T top();
	void push(const T& theElement);
	void initialize(T* theHeap, int theSize);
	int size()
	{
		return heapSize;
	}
private:
	int arrayLength=0;
	int heapSize=0;
	T* heap = new T[arrayLength];
};
template<class T>
void maxHeap<T>::pop()
{
	//如果堆为空 则抛出异常
	if (heapSize == 0)
	{
		cout << "heapSize Error" << endl;
		return;
	}
	//删除第一个元素
	heap[1].~T();
	//删除最后一个元素 然后重新建堆
	T lastElement = heap[heapSize];
	heap[heapSize].~T();
	//从根开始为最后一个元素寻找位置
	int currentNode = 1;
	int child = 2;
	while (child < heapSize)
	{
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;
		//可以把lastElement放在heap[currentNode]吗?
		if (lastElement >= heap[child])
			break;//可以
		//不可以
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;//移动到下一层
	}
	heap[currentNode] = lastElement;
	heapSize--;
}
template<class T>
T maxHeap<T>::top()
{
	if (heapSize == 0)
	{
		cout << "heapSize ERRO" << endl;
		return 0;
	}
	return heap[1];
}
template<class T>
void maxHeap<T>::initialize(T * theHeap, int theSize)
{
	//在数组[1:theSize]中新建大根堆
	//delete[]heap;
	heap = new T[theSize];
	arrayLength = theSize;
	heapSize = theSize;
	heap = theHeap;

	//堆化
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];

		//为元素rootElement寻找位置
		int child = 2 * root;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] < heap[child + 1])
			{
				child++;
			}
			if (rootElement >= heap[child])
				break;//可以
			heap[child / 2] = heap[child];
			child *= 2;   //移动到下一层
		}
		heap[child / 2] = rootElement;
	}
}
template<class T>
void maxHeap<T>::push(const T & theElement)
{
	//必要时增加数组长度
	if (heapSize > arrayLength - 1)
	{
		changLength(heap, arrayLength);
		arrayLength *= 2;
	}
	//为新元素寻找位置
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < theElement)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = theElement;
	//heapSize++;
}
int main(int argc, char** argv)
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	maxHeap<int> hep;
	hep.initialize(a, 9);
	hep.push(10);
	hep.push(11);
	hep.push(25);
    for(int i=0;i<100;i++)
    {
        hep.push(i*2);
    }
	while (hep.size())
	{
		cout << hep.top() << "->";
		hep.pop();
	}
	cout << "end" << endl;
	return 0;

}