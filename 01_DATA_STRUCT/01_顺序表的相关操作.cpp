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
	//�ж�pos�Ƿ�Ϸ�
	if (pos < 1 || pos > L.len + 1)
		return false;
	
	//���λ������
	if (L.len >= MAXSIZE)
		return false;

	//�Ѻ����Ԫ������������
	for (int j = L.len; j >= pos; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	//����Ҫ�����Ԫ��
	L.data[pos - 1] = element;
	L.len++;
	return true;
}

//ʵ��˳����˳���ӡ
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
	bool ret;	//�洢�����ķ���ֵ
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