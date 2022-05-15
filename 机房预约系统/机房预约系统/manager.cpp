#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string userName, string passWord)
{
	this->m_userName = userName;
	this->m_passWord = passWord;
	this->initVector();
}

void Manager::openMenu()
{
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	cout << "1.����µ��˺�" << endl;
	cout << "2.��ʾ�����˺�" << endl;
	cout << "3.��ʾ������Ϣ" << endl;
	cout << "4.���������Ϣ" << endl;
	cout << "0.ע����¼��Ϣ" << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��  2.��ӽ�ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ������ظ�������������";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		if (checkRepeat(id, select)) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	if (select == 1) {
		vStu.push_back(Student(id,name,pwd));
	}
	else {
		vTea.push_back(Teacher(id, name, pwd));
	}
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();

}

void Manager::showPerson()
{
	cout << "��ѡ����Ҫ�鿴�����ݣ�" << endl;
	cout << "1.�鿴����ѧ�� 2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), [](Student& s1) {
			cout << "ѧ����ţ�" << s1.m_Id << "\tѧ��������" << s1.m_userName
				<< "\tѧ�����룺" << s1.m_passWord << endl;
			});
	}
	else {
		//�鿴��ʦ
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), [](Teacher& t1) {
			cout << "ְ����ţ�" << t1.m_empId<< "\tְ��������" << t1.m_userName
				<< "\tְ�����룺" << t1.m_passWord << endl;
			});
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (auto it : this->vCom) {
		cout << "�������Ϊ��" << it.m_comId << "\t�����������Ϊ��" << it.m_maxNum << endl;
	}
	system("pause");
	system("cls");

}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "�����ɣ�" << endl;
	system("pause");
	system("cls");

}

void Manager::initVector()
{
	this->vStu.clear();
	this->vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_userName && ifs >> s.m_passWord) {
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_userName && ifs >> t.m_passWord) {
		vTea.push_back(t);
	}
	ifs.close();
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_comId && ifs >> c.m_maxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) {
		for (auto it : this->vStu) {
			if (id == it.m_Id) {
				return true;
			}
		}
	}else{
		for (auto it : this->vTea) {
			if (id == it.m_empId) {
				return true;
			}
		}
	}
	return false;
}
