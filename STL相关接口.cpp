#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class STLTest {
	
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
	string s1 = "abaaba";
	string s2 = "str2";
	string s3 = "str3";
	STLTest(){}
	//输入输出解耦合，加快一点速度
	void cincout() {
		static const auto __ = []() {
			ios::sync_with_stdio(false);
			cin.tie(nullptr);
			return nullptr;
		}();
	}
	void vectorTest() {
		//（1）assign函数三种重载：
		mv0.assign(10, 0);//10个0
		mv2.assign(mv0.begin(),mv0.end());//另一容器的开始到结束
		mv3.assign({ 1,2,3 });//一个初始化列表，未指定类型
		//（2）resize函数用来重新填充向量，
		//若新大小小于旧大小，元素值不变，否则多余的填充第二个形参的值
		mv1.resize(10);
		mv1.resize(5, 2);//重新填充2,但新大小小于旧大小，元素值不变，只改变大小

		//按照lambda表达式函数所示排序
		sort(mv6.begin(), mv6.end(), [](vector<int>& nums1, vector<int>& nums2)->bool { return nums1[0] > nums2[0]; });

		//在1号位置删除
		mv6.erase(mv6.begin() + 1);

		//在1号位置插入
		mv6.insert(mv6.begin() + 1, vector<int>{4, 4});

		//两个vector合并在一起：
		vector<int> v1, v2, v3;
		v1 = { 1,2,3 };
		v2 = { 4,5,6 };
		v3.insert(v3.end(), v1.begin(), v1.end());
		v3.insert(v3.end(), v2.begin(), v2.end());

		//迭代器：iter
		mv4 = { 1,2,3,4,5,6,7,8,9,10 };
		auto iter = mv4.begin();
		advance(iter, 2);//将iter向前移动2
		advance(iter, -1);//将iter向后移动1
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
		//vector<int>::reverse_iterator iter;注意需要用reverse_iterator
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


		//不知道一行多少元素的输入
		vector<int> nums;
		int num;
		while (cin >> num) {
			nums.push_back(num);
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	struct cmp {
		bool operator()(const string& a,const string& b) const{
			int an = a.size();
			int bn = b.size();
			int i = 0, j = 0;
			while (i < an&&j < bn) {
				if (a[i] == b[j]) {
					i++;
					j++;
				}
				else if (a[i] > b[j]) {
					return false;
				}
				else if (a[i] < b[j]) {
					return true;
				}
			}
			if (an > bn) {
				return false;
			}
			else {
				return true;
			}
		}
	};
	void mapTest() {
		for (auto mv : mv6) {
			if (mp.find(mv[0]) != mp.end()) continue;//查找
			mp[mv[0]] = mv[1];//插入map
		}
		mp.erase(mv6[1][0]);//删除key=mv6[1][0]的值，否则报错。

		auto iter = mp.begin();
		advance(iter, 2);//将iter向前移动2
		advance(iter, -1);//将iter向后移动1

		map<string, int, cmp> mpp;//改变map的key值排序方法

		multimap<int, int> nkmap;//重复的key值，根据val值升序排序

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
	void stringTest() {
		int a = 12345;
		string str = to_string(a);
		a = stoi(str);
		int b = s2.at(3) - '0';
		s1 = s1 + 'x';
		s1.insert(s1.begin(), 'h');
		s1.append("hahaha");//在尾部添加
		s1.clear();
		s1 = "1234";
		s1.substr(1, 2);////获得字符串s1中从第1位开始的长度为2的字符串，结果为"23"

		//不知道输入多少行字符串，以输入一个空行来结束：
		vector<string> sv;
		while (1) {
			string s;
			cin >> s;
			if (getchar() == '\n') {
				if (getchar() == '\n') break;
			}
			sv.push_back(s);
		}
		
	}
	void pqueueTest() {
		priority_queue<int, vector<int>, greater<int>> smallQueue;//greater<int>代表堆顶最小，依次增大的，小顶堆
		priority_queue<int, vector<int>, less<int>> bigQueue;//less<int>代表堆顶最大，依次减小，大顶堆
		vector<int> nums = { 1,2,3,4,6,8,10,20,50,100 };

		for (int i = 0; i < nums.size(); i++) {
			smallQueue.push(nums[i]);
			bigQueue.push(nums[i]);
		}

		smallQueue.top();//1
		bigQueue.top();//100
	}
	void out(vector<int>& nums) {
		for (int n : nums) {
			cout << n << " ";
		}
		cout << endl;
	}

};

//int main() {
//	STLTest stl;
//	stl.pqueueTest();
//	system("pause");
//	return 0;
//}
