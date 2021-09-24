#include<stdio.h>

void Rep_space(char str[], int n)
{
	if (str == NULL || n < 0)
		return;
	int i = 0;
	int numblank = 0;//空格数
	int originalLength = 0;//数组的实际长度
	int newLength = 0;//空格被替换后，数组的长度
	int indexOriginal = 0;//初始值为原数组的最后一个元素
	int indexNew = 0;//初始值为空格被替换后，数组的最后一个元素
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