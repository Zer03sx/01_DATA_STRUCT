#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int Element;

typedef struct {
	Element data[MAXSIZE];
	int len;
}SqlList;

bool ListInsert(SqlList& L, int pos, Element element)
{
	//判断pos是否合法
	if (pos < 1 || pos > L.len + 1)
		return false;
	
	//如果位置满了
	if (L.len >= MAXSIZE)
		return false;

	//把后面的元素依次往后移
	for (int j = L.len; j >= pos; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	//放入要插入的元素
	L.data[pos - 1] = element;
	L.len++;
	return true;
}

//实现顺序表的顺序打印
void PrintSqList(SqlList L)
{
	for (int i = 0; i < L.len; i++)
	{
		cout << L.data[i] << endl;
	}
}

int main()
{
	SqlList L;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.len = 3;
	PrintSqList(L);
	bool ret;	//存储函数的返回值
	ret = ListInsert(L, 2, 10);

	if (ret)
	{
		cout << "Insert success!" << endl;
	}
	else
	{
		cout << "Insert fail!" << endl;
	}

	PrintSqList(L);
	system("pause");
	return 0;
}
