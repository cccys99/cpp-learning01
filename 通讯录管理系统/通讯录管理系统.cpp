#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

struct Person //��ϵ�˽ṹ��
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks //ͨѶ¼�ṹ��
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��ϵ�˸���
	int m_Size;

};

//1.�����ϵ��
void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
	    //�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼�е�����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause"); //�밴���������
		system("cls"); //��������

	}
}

//2.��ʾ������ϵ��
void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��": "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//�����ϵ���Ƿ���ڣ������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks * abs, string name) //����1��ͨѶ¼ ����2�ǶԱ�����
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//3.ɾ��ָ������ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ���Ĳ���
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1]; //����ǰ�ƣ�����
		}
		abs->m_Size--; //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//4.������ϵ��
void findPerson(Addressbooks * abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//5.�޸���ϵ��
void modifyPerson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;	
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//6.�����ϵ��
void cleanPerson(Addressbooks * abs)
{
	abs->m_Size = 0; //����ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;

	system("pause"); //�밴���������
	system("cls"); //��������
}

//�˵���ʾ����
void showMenu()
{
	cout << "****************************" << endl;
	cout << "******  1.�����ϵ��  ******" << endl;
	cout << "******  2.��ʾ��ϵ��  ******" << endl;
	cout << "******  3.ɾ����ϵ��  ******" << endl;
	cout << "******  4.������ϵ��  ******" << endl;
	cout << "******  5.�޸���ϵ��  ******" << endl;
	cout << "******  6.�����ϵ��  ******" << endl;
	cout << "******  0.�˳�ͨѶ¼  ******" << endl;
	cout << "****************************" << endl;

}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0; //�����û�ѡ������ı���

	while (true)
	{
		showMenu(); //�˵�����
		
		cin >> select;
		switch (select)
		{
		case 1: //1.�����ϵ��
			addPerson(&abs);
			break;
		case 2: //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //4.������ϵ��
			findPerson(&abs);
			break;
		case 5: //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //7.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}