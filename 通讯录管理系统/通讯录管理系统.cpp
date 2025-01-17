#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

struct Person //联系人结构体
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks //通讯录结构体
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前联系人个数
	int m_Size;

};

//1.添加联系人
void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
	    //添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录中的人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏操作

	}
}

//2.显示所有联系人
void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男": "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//检测联系人是否存在，若存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks * abs, string name) //参数1是通讯录 参数2是对比姓名
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

//3.删除指定的联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//查找到人，要进行删除的操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1]; //数据前移，覆盖
		}
		abs->m_Size--; //更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//4.查找联系人
void findPerson(Addressbooks * abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//5.修改联系人
void modifyPerson(Addressbooks * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;	
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//6.清空联系人
void cleanPerson(Addressbooks * abs)
{
	abs->m_Size = 0; //将联系人数量置为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//菜单显示界面
void showMenu()
{
	cout << "****************************" << endl;
	cout << "******  1.添加联系人  ******" << endl;
	cout << "******  2.显示联系人  ******" << endl;
	cout << "******  3.删除联系人  ******" << endl;
	cout << "******  4.查找联系人  ******" << endl;
	cout << "******  5.修改联系人  ******" << endl;
	cout << "******  6.清空联系人  ******" << endl;
	cout << "******  0.退出通讯录  ******" << endl;
	cout << "****************************" << endl;

}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量

	while (true)
	{
		showMenu(); //菜单调用
		
		cin >> select;
		switch (select)
		{
		case 1: //1.添加联系人
			addPerson(&abs);
			break;
		case 2: //2.显示联系人
			showPerson(&abs);
			break;
		case 3: //3.删除联系人
			deletePerson(&abs);
			break;
		case 4: //4.查找联系人
			findPerson(&abs);
			break;
		case 5: //5.修改联系人
			modifyPerson(&abs);
			break;
		case 6: //6.清空联系人
			cleanPerson(&abs);
			break;
		case 0: //7.退出通讯录
			cout << "欢迎下次使用" << endl;
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