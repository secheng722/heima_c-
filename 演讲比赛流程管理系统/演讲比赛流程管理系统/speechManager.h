#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
//�ݽ�����������
class SpeechManager {
public:
	//���캯��
	SpeechManager();
	//��������
	~SpeechManager();
	//�˵�����
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ������
	void initSpeech();	
	//��������ѡ��
	void createSpeaker();
	//��ʼ����
	void startSpeech();
	//��ǩ
	void speechDraw();
	//��ʼ����
	void speechContest();
	//��ʾ�������
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//չʾ��¼
	void showRecord();
	//��ռ�¼
	void clearRecord();

	//��������¼
	map<int, vector<string>> m_record;
	//�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//����ѡ�ֵ�һ�� ����12��
	vector<int> v1;
	//����ѡ�ֵڶ��� ����6��
	vector<int> v2;
	//����ѡ�ֻ�ʤ 3��
	vector<int> v_victory;
	//���ھ����ź�ѡ�ֵ�����
	map<int, Speaker> m_speaker;
	//��ű�������
	int m_index;
};
