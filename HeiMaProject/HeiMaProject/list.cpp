#include<list>
#include <iostream>
using namespace std;
class Person {
public :
	Person(string name, int age,int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_height = height;
	}
	string m_name;
	int m_age;
	int m_height;
};
bool comparePerson(Person& p1, Person& p2) {
	if (p1.m_age == p2.m_age) {
		return p1.m_height < p2.m_height;
	}
	else {
		return p1.m_age < p2.m_age;
	}
}
void testList() {
	list<Person> L;
	Person p1("����", 19,166);
	Person p2("��˹", 22,178);
	Person p3("����", 22,189);
	Person p4("����", 22,160);
	Person p5("����", 26,144);
	Person p6("��˼", 66,199);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << " ������ " << it->m_name << " ���䣺" << it->m_age <<" ��ߣ� "<<it->m_height<< endl;
	}
	L.sort(comparePerson);
	cout << "========================= " << endl;
	cout << "�����" << endl;
	
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << " ������ " << it->m_name << " ���䣺" << it->m_age <<" ��ߣ� "<<it->m_height<< endl;
	}


}
