#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	cout.setf(ios::fixed);

	string str = "11011111"; // Ҫ������ַ���
	string diff = "01"; // ���ܳ��ֵ��ַ� �Ӵ�С����
	double p[10] = {0.125 , 0.875}; // ���ܳ��ֵ��ַ���Ӧ�ĸ��� �Ӵ�С����
	int code[50];  // ������
	// ��������
	double C = 0.0;
	double A = 1.0;
	for(int i = 0;i < str.length();i++)
	{
		if(str[i] == diff[0])
		{
			C = C;
			A = A * p[0];
		}
		else if(str[i] == diff[1])
		{
			C = C + A * p[0];
			A = A * p[1];
		}
	}
	cout << setprecision(12) << "C: " << C << " A: " << A << " C+A: " << C + A << endl;
	
	// ȡC A�е� ��ת��Ϊ2���� ���б��� 
	double middle = C + 0.5 * A;
	cout << "�������е� " << middle << "ת��Ϊ2����" << endl;
	cout << "������Ϊ��0.";
	for(int j=0;j < 50;j++)
	{
		middle = middle * 2;
		if(middle > 1.0)
		{
		    middle = middle - 1;
		    code[j]=1;
		}
		else
		    code[j]=0;

		cout << code[j];
	}
	cout << endl;
	
	// ����
	middle = C + 0.5 * A;
	A = 1.0;
	double qe = p[0];
	int count = 0;
	cout << "������Ϊ��";
	while(count < str.length())
	{
		if(middle > 0 && middle <= qe * A)
		{
			middle = middle;
			A = qe * A;
			cout << diff[0];
		}
		else if(middle < 1 && middle > qe * A)
		{
			middle = middle - qe * A;
			A = A * (1 - qe);
			cout << diff[1];
		}
		count++;
	}
	cout << endl;

	system("pause");
	return 0;
}
