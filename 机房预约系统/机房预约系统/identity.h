#pragma once
#include<iostream>
using namespace std;
//��ݳ������
class Identity {
public:
	//�����˵�
	virtual void openMenu()=0;

	//�û���
	string m_userName;
	//����
	string m_passWord;
};
