#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>

class OrderFile {
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//ԤԼ����
	int m_size;
	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>>m_orderData;
};

