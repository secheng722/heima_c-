#pragma once
#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include<vector>
using namespace std;
class Teacher :public Identity {
public:
	//�޲ι���
	Teacher();
	//�вι���
	Teacher(int empId, string userName, string passWord);

	//��ʾ�˵�
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//�������ԤԼ
	void validOrder();

	//��ʦ���
	int m_empId;
};
