#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include "computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include<algorithm>
#include"orderFile.h"
class Student :public Identity {
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string userName, string passWord);

	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void calcelOrder();


	//ѧ��ѧ��
	int m_Id;
	//��������
	vector<ComputerRoom>vCom;
};
