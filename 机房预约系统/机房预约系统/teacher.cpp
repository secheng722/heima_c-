#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empId, string userName, string passWord)
{
	this->m_empId = empId;
	this->m_userName = userName;
	this->m_passWord = passWord;
}

void Teacher::openMenu()
{
	cout << "1.��������ԤԼ" << endl
		 << "2.�������ԤԼ" << endl
		 << "0.ע����ʦ��¼" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"]
			<< "\tʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
			<< "\tѧ�ţ�" <<of.m_orderData[i]["stuId"]
			<< "\t������" <<of.m_orderData[i]["stuName"]
			<< "\t�������Ϊ��" << of.m_orderData[i]["roomId"]
			<< "\tԤԼ״̬Ϊ��";
		string status;
		string* st = &of.m_orderData[i]["status"];
		if (*st == "1") {
			status = "�����";
		}
		else if (*st == "2") {
			status = "ԤԼ�ɹ�";
		}
		else if (*st == "-1") {
			status = "ԤԼʧ��";
		}
		else {
			status = "ԤԼȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");

}

void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 1;
	vector<int>v;
	for (int i = 0; i < of.m_size; i++) {
		if (of.m_orderData[i]["status"]=="1") {
			cout << index << ".";
			index++;
			v.push_back(i);
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"]
				<< " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< " �������Ϊ��" << of.m_orderData[i]["roomId"]
				<< " ԤԼ״̬Ϊ��";
			string status;
			string* st = &of.m_orderData[i]["status"];
			if (*st == "1") {
				status = "�����";
			}
			else if (*st == "2") {
				status = "ԤԼ�ɹ�";
			}
			else if (*st == "-1") {
				status = "ԤԼʧ��";
			}
			else {
				status = "ԤԼȡ��";
			}
			cout << status << endl;
		}
	}
	int select = 0;
	cout << "������Ҫ��˵ļ�¼ 0:�˳�ȡ��" << endl;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				cout << "�˳��ɹ�" << endl;
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "2";
				cout << "��˳ɹ�" << endl;
				break;
			}
		}
		else {
			cout << "�����Ŵ���" << endl;
		}
	}
	of.updateOrder();
	system("pause");
	system("cls");
}
