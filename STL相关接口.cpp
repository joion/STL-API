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
		//assign函数三种重载：
		mv0.assign(10, 0);//10个0
		mv2.assign(mv0.begin(),mv0.end());//另一容器的开始到结束
		mv3.assign({ 1,2,3 });//一个初始化列表，未指定类型

		//按照lambda表达式函数所示排序
		sort(mv6.begin(), mv6.end(), [](vector<int>& nums1, vector<int>& nums2)->bool { return nums1[0] > nums2[0]; });

		//在1号位置删除
		mv6.erase(mv6.begin() + 1);

		//在1号位置插入
		mv6.insert(mv6.begin() + 1, vector<int>{4, 4});

		//resize函数用来重新填充向量，
		//若新大小小于旧大小，元素值不变，否则多余的填充第二个形参的值
		mv1.resize(10);
		mv1.resize(5, 2);//重新填充2,但新大小小于旧大小，元素值不变，只改变大小

		//迭代器：iter
		mv4 = { 1,2,3,4,5,6,7,8,9,10 };
		for (auto iter = mv4.begin(); iter != mv4.end(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//C++11新增的cbegin()、cend()、crbegin()、crend()，即原版上加const
		for (auto iter = mv4.cbegin(); iter != mv4.cend(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//翻转输出
		for (auto iter = mv4.rbegin(); iter != mv4.rend(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
		//第二种方式
		for (auto iter = mv4.end()-1; iter >= mv4.begin(); iter--) {
			cout << *iter << " ";
			if (iter == mv4.begin()) break;
		}
		cout << endl;

	}

	void mapTest() {
		for (auto mv : mv6) {
			if (mp.find(mv[0]) != mp.end()) continue;//查找
			mp[mv[0]] = mv[1];//插入map
		}
		mp.erase(mv6[1][0]);//删除key=mv6[1][0]的值，否则报错。

		//遍历：
		int key = 1;
		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			if (iter->first == key) {
				iter->second = 3;
			}
		}
	}
	void setTest() {
		for (auto mv : mv6) {
			if (st.find(mv[0]) != st.end()) continue;//查找
			st.insert(mv[0]);//插入set
		}
		st.erase(mv6[1][0]);//删除key=mv6[1][0]的值，否则报错。

		//遍历：
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