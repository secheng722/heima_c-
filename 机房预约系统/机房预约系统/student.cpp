#include "student.h"

Student::Student()
{
}

Student::Student(int id, string userName, string passWord)
{
	this->m_Id = id;
	this->m_userName = userName;
	this->m_passWord = passWord;
	ifstream ifs(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum) {
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::openMenu()
{
	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴����ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "0.ע���˺�" << endl;
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "��ѡ�����ڣ�" << endl;
	cout << "1.��һ��2.�ܶ���3.������4.���ģ�5.����" << endl;
	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "�����������������" << endl;
	}
	cout << "����������ԤԼʱ���" << endl;
	cout << "1.���磬2.����" << endl;
	while (true) {
		cin >> interval;
		if (interval == 1 || interval == 2)
			break;
		cout << "�����������������" << endl;
	}
	cout << "��ѡ�������" << endl;
	for (auto it : this->vCom) {
		cout << it.m_comId << "�Ż��� ����Ϊ" << it.m_maxNum << endl;
	}
	while (true) {
		cin >> room;
		auto it=std::find_if(vCom.begin(), vCom.end(), [&room](ComputerRoom& com) {
			if (room==com.m_comId) {
				return true;
			}
			return false;
			});
		if (it != vCom.end())
			break;
		cout << "�����������������" << endl;
	}
	cout << "ԤԼ�ɹ��� �����" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->m_Id << " "
		<< "stuName:"<<this->m_userName<<" "
		<< "roomId:" << room << " "
		<< "status:" << 1 <<endl;
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
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
	system("pause");
	system("cls");
}

void Student::showAllOrder()
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

void Student::calcelOrder()
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
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())
			&&(of.m_orderData[i]["status"]=="1"||of.m_orderData[i]["status"]=="2")) {
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
	cout << "������Ҫȡ���ļ�¼ 0:�˳�ȡ��" << endl;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				cout << "�˳��ɹ�" << endl;
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				cout << "ȡ���ɹ�" << endl;
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
