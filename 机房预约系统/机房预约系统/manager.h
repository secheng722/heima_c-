#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include "student.h"
#include<vector>
#include "teacher.h"
#include<algorithm>
#include "computerRoom.h"
class Manager :public Identity {
public:
	Manager();

	Manager(string userName,string passWord);

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��Ϣ
	void cleanFile();
	//��ʼ������
	void initVector();
	//����ظ�
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//��������
	vector<ComputerRoom>vCom;

};
