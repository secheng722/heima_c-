#include "speechManager.h"
//���캯��
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
}
//��������
SpeechManager::~SpeechManager() {

}
//�˵�����
void SpeechManager::showMenu() {
	cout << "**************************************"<<endl;
	cout << "*************��ӭ�μ��ݽ�����***********"<<endl;
	cout << "************* 1.��ʼ�ݽ����� **********"<<endl;
	cout << "************* 2.�鿴�����¼ **********"<<endl;
	cout << "************* 3.��ձ�����¼ **********"<<endl;
	cout << "************* 4.�˳��������� **********"<<endl;
	cout << "**************************************"<<endl;
	cout << endl;
}
//�˳�ϵͳ
void SpeechManager::exitSystem() {
	cout << "   ��л����ʹ��  " << endl;
	system("pause");
	exit(0);
}
//��ʼ������
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->v_victory.clear();
	this->m_speaker.clear();
	this->m_index = 1;
	this->m_record.clear();
}
//����12��ѡ��
void SpeechManager::createSpeaker(){
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		//����ѡ�ֱ�Ų�����v1 
		this->v1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));

	}
}
//�������̿���
void SpeechManager::startSpeech() {
	//��һ��
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���
	this->showScore();
	
	//�ڶ���
	this->m_index++;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���
	this->showScore();
	
	//�����¼
	this->saveRecord();

	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "����������" << endl;
	cout << "========================================" << endl;
	system("pause");
}
//��ǩ
void SpeechManager::speechDraw() {
	cout << "�ڡ���" << this->m_index << "�����ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "======================" << endl;
	cout << "��ǩ���ݽ�˳�����£� " << endl;
	if (this->m_index == 1) {
		//��һ��
		random_shuffle(this->v1.begin(), this->v1.end());
		for (auto it:this->v1)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	else {
		//�ڶ���
		random_shuffle(this->v2.begin(), this->v2.end());
		for (auto it:this->v2)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	cout << "======================" << endl;
	system("pause");
}
//��ʼ����
void SpeechManager::speechContest() {
	cout << "�ڡ���" << this->m_index << "�����ֱ�����ʼ" << endl;
	cout << "======================" << endl;
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	vector<int>v_src;
	if (this->m_index == 1) {
		v_src = v1;
	}
	else {
		v_src = v2;
	}
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600)/10.0f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ�
		double avg = sum / (double)d.size();//ƽ����
		this->m_speaker[*it].m_score[this->m_index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		//ÿ6����ȡǰ����
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "������������£� " << endl;
			for (multimap<double, int, greater<double>>::iterator it
				= groupScore.begin(); it != groupScore.end(); it++) {
				cout << " ��ţ�" << it->second << " ������" << this->m_speaker[it->second].m_name
					<< " �ɼ���" << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it
				= groupScore.begin(); it != groupScore.end()&&count<3; it++,count++) {
				if (this->m_index == 1) {
					v2.push_back(it->second);
				}
				else {
					v_victory.push_back(it->second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "�ڡ���" << this->m_index << "�����ֱ������" << endl;
	cout << "===================================" << endl;
	cout << endl;
	system("pause");
}
//��ʾ�ɼ�
void SpeechManager::showScore() {
	cout << "�ڡ���" << this->m_index << "�����ֱ�������ѡ����Ϣ����" << endl;
	cout << "==========================================" << endl;
	vector<int>v;
	if (this->m_index == 1)
		v = v2;
	else
		v = v_victory;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->m_speaker[*it].m_name
			<< " �÷֣�" << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
	}
	cout << endl;
	system("pause");
}
//�����¼
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӷ�ʽios::app
	for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++) {
		ofs << *it << ","
			<< this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	this->fileIsEmpty = false;
	cout << "��¼�ѱ���" << endl;
	cout << "==========================" << endl;

}
//���ؼ�¼
void SpeechManager::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data) {
		//cout << data << endl;
		vector<string>v;//����ַ�����Ϣ
		int pos = -1;
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1){
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}
//չʾ��¼
void SpeechManager::showRecord()
{
	//for (map<int, vector<string>>::iterator it = this->m_record.begin(); it != this->m_record.end(); it++) {
	//	cout << it->first << "�ھ���ţ�" << it->second[0] << "�ھ��ɼ���" << it->second[1] << endl;
	//}
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ򲻴��ڸ��ļ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_record.size(); i++) {
			cout << "��" << i + 1 << "�����" << endl
				<< "�ھ���ţ�" << this->m_record[i][0] << " �÷֣�" << this->m_record[i][1] << endl
				<< "�Ǿ���ţ�" << this->m_record[i][2] << " �÷֣�" << this->m_record[i][3] << endl
				<< "������ţ�" << this->m_record[i][4] << " �÷֣�" << this->m_record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");

}
//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ�������" << endl;
	cout << "1.ȷ�� 2.����" << endl;
	int select = -1;
	cin >> select;
	if (select == 1) {
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
	system("pause");
}
