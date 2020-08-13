#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class vectorTest {
	
public:
	vector<int> mv0;
	vector<int> mv1;
	vector<int> mv2;
	vector<int> mv3;
	vector<int> mv4;
	vector<int> mv5;
	vector<vector<int>> mv6 = { {1,2},{5,1},{4,3} };
	set<int> st;
	map<int,int> mp;
	vectorTest() {
		//assign�����������أ�
		mv0.assign(10, 0);//10��0
		mv2.assign(mv0.begin(),mv0.end());//��һ�����Ŀ�ʼ������
		mv3.assign({ 1,2,3 });//һ����ʼ���б�δָ������

		//����lambda���ʽ������ʾ����
		sort(mv6.begin(), mv6.end(), [](vector<int>& nums1, vector<int>& nums2)->bool { return nums1[0] > nums2[0]; });

		//��1��λ��ɾ��
		mv6.erase(mv6.begin() + 1);

		//��1��λ�ò���
		mv6.insert(mv6.begin() + 1, vector<int>{4, 4});

		//resize���������������������
		//���´�СС�ھɴ�С��Ԫ��ֵ���䣬�����������ڶ����βε�ֵ
		mv1.resize(10);
		mv1.resize(5, 2);//�������2,���´�СС�ھɴ�С��Ԫ��ֵ���䣬ֻ�ı��С

		//��������iter
		mv4 = { 1,2,3,4,5,6,7,8,9,10 };
		for (auto iter = mv4.begin(); iter != mv4.end(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//C++11������cbegin()��cend()��crbegin()��crend()����ԭ���ϼ�const
		for (auto iter = mv4.cbegin(); iter != mv4.cend(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//��ת���
		for (auto iter = mv4.rbegin(); iter != mv4.rend(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//�ڶ��ַ�ʽ
		for (auto iter = mv4.end()-1; iter >= mv4.begin(); iter--) {
			cout << *iter << " ";
			if (iter == mv4.begin()) break;
		}
		cout << endl;

	}

	void mapTest() {
		for (auto mv : mv6) {
			if (mp.find(mv[0]) != mp.end()) continue;//����
			mp[mv[0]] = mv[1];//����map
		}
		mp.erase(mv6[1][0]);//ɾ��key=mv6[1][0]��ֵ�����򱨴�

		//������
		int key = 1;
		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			if (iter->first == key) {
				iter->second = 3;
			}
		}
	}
	void setTest() {
		for (auto mv : mv6) {
			if (st.find(mv[0]) != st.end()) continue;//����
			st.insert(mv[0]);//����set
		}
		st.erase(mv6[1][0]);//ɾ��key=mv6[1][0]��ֵ�����򱨴�

		//������
		int key = 1;
		for (auto iter = st.begin(); iter != st.end(); iter++) {
			if (*iter == key) {
				st.erase(key);
				st.insert(3);
			}
		}
	}
	void out(vector<int>& nums) {
		for (int n : nums) {
			cout << n << " ";
		}
		cout << endl;
	}

};

//int main() {
//	vectorTest vt;
//	//vt.out(vt.mv1);
//	system("pause");
//	return 0;
//}