#include<stdio.h>

void Rep_space(char str[], int n)
{
	if (str == NULL || n < 0)
		return;
	int i = 0;
	int numblank = 0;//�ո���
	int originalLength = 0;//�����ʵ�ʳ���
	int newLength = 0;//�ո��滻������ĳ���
	int indexOriginal = 0;//��ʼֵΪԭ��������һ��Ԫ��
	int indexNew = 0;//��ʼֵΪ�ո��滻����������һ��Ԫ��
	while (str[i] != '\0')
	{
		++originalLength;
		if (str[i] == ' ')
			++numblank;
		++i;
	}
	newLength = originalLength + numblank * 2;
	if (newLength < originalLength)
		return;
	indexNew = newLength;
	indexOriginal = originalLength;
	while (indexOriginal >= 0 && indexNew>indexOriginal)
	{
		if (str[indexOriginal] == ' ')
		{
			str[indexNew--] = '0';
			str[indexNew--] = '2';
			str[indexNew--] = '%';
		}
		else
		{
			str[indexNew--] = str[indexOriginal];
		}
		indexOriginal--;
	}
}

void main()
{
	char str[20] = "abc defgx yz";
	int n = sizeof(str) / sizeof(str[0]);
	Rep_space(str, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%c", str[i]);
	}
	printf("\n");

}