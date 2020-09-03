#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <map>
#include <forward_list>
#include <array>
#include <string>
using namespace std;

int mup(int cur, int n, int& up, int& down){
	if (cur == 1){
		cur = n;
		up = n - 3;
		down = n;
	}
	else{
		cur--;
	}

	if ((cur - up) == -1){
		up--;
		down--;
	}
	return cur;
}

int mdown(int cur, int n, int& up, int& down){
	if (cur == n){
		cur = 1;
		up = 1;
		down = 4;
	}
	else{
		cur++;
	}

	if ((cur - down) == 1){
		down++;
		up++;
	}
	return cur;
}

int main(){
	int n = 0;
	while (cin >> n){
		if (n <= 0) continue;
		char choice = ' ';
		int cur = 1;
		int up = 1;
		int down = 4;

		string str;
		cin>>str;
		
		for (int i = 0; i < str.size(); ++i){
			char choice = str[i];
			if (choice == 'U'){
				cur = mup(cur, n, up, down);
			}
			else if (choice == 'D'){
				cur = mdown(cur, n, up, down);
			}
		}

		for (int i = up; i <= down; i++){
			cout << i << " ";
		}
		cout << endl;
		cout << cur << endl;
	}
	system("pause");
	return 0;
}



//void washCard(vector<int>& first, vector<int>& second, vector<int>& ret){
//	int fidx = 0;
//	int sidx = 0;
//	int ridx = 0;
//	while (ridx<ret.size()){
//		ret[ridx++] = first[fidx++];
//		ret[ridx++] = second[sidx++];
//	}
//}
//
//
//int main(){
//	int T;
//	cin >> T;
//	while (T--){
//		int n = 0;
//		int k = 0;
//		cin >> n >> k;
//		vector<int> first;
//		vector<int>  second;
//		vector<int> ret;
//		ret.resize(2 * n);
//		first.resize(n);
//		second.resize(n);
//		for (int i = 0; i < n; i++){
//			cin >> first[i];
//		}
//		for (int i = 0; i<n; i++){
//			cin >> second[i];
//		}
//
//		while (k--){
//			washCard(first, second, ret);
//			int len = first.size();
//			for (int i = 0; i<len; ++i){
//				first[i] = ret[i];
//				second[i] = ret[i + len];
//			}
//		}
//		for (int i = 0; i < ret.size();++i){
//			if (i == (ret.size() - 1)){
//				cout << ret[i];
//				break;
//			}
//			cout << ret[i] << " ";
//		}
//	}
//	system("pause");
//	return 0;
//}
//class A{
//public:
//	A(int a,int b)
//		:_a(a)
//		, _b(b){}
//
//	A(int a)
//		:_a(a)
//		, _b(0){}
//private:
//	int _a;
//	int _b;
//};
//
//template<class T>
//class Vector{
//public:
//	// ��ʼ���б����ܵ��ã���Ҫ���ܹ��캯���Ĳ���������
//	Vector(int n)
//		:_array(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//
//	// ���أ�����ƥ��
//	// ʵ���˵�ǰ�����Ϳ��Խ����б��ʼ��
//	Vector(const initializer_list<T>& lst)
//		:_array(new T[lst.size()])
//		, _size(0)
//		, _capacity(lst.size())
//	{
//		for (auto& e : lst){
//			_array[_size++] = e;
//		}
//	}
//private:
//	T* _array;
//	size_t _size;
//	size_t _capacity;
//};
//void test1(){
//	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
//
//	// C++11��֧���������͵��б��ʼ��
//	int a = 1;	
//	int b = { 1 };
//	int c{ 1 };
//
//	float d = { 1.2f };
//	vector<int> array1{1, 2, 3, 4, 5};
//
//	vector<int> arr = { 31, 3, 4, 5, 80 };
//
//	map<int, int> m = { { 1, 2 }, { 3, 3 } };
//	for (auto e : array){
//		cout << e << " ";
//	}
//	cout << endl;
//	
//	// �Զ������ͣ�������������
//	A k = { 1, 22 }; //���ܸ�������ֵ������̫��
//	// C++11��Ҳ֧���Զ������͵��б��ʼ��
//
//	// ���ι��캯������ʽ����ת��
//	A a4 = 5;
//
//	/// �Զ������ͣ���ʼ�����Ԫ��-->������Ȼ֧���б��ʼ��
//	// �޷��ӳ�ʼ���б�ת��ΪVector
//	// ��Ҫ��ʽ�����������Ϊinitializer_list�Ĺ��캯��
//
//	// {}��������幹��һ������
//	Vector<int> vec = { 33, 32, 32, 21 };//������4��Ԫ��
//	// �κ����Ͷ�����ʵ���б��ʼ���Ĺ���
//
//	// ��������£�ÿһ��������һ������
//	Vector<int> vec2(10);//��һ����һ�������Ĺ��캯���������Ǵ���һ��Vector��������û��Ԫ�أ��յ�Vector
//	Vector<int> vec3{ 19 }; //���ٵ�������СΪ19
//}
//
//
//void tesst(){
//	forward_list<int> fi;
//	//array<int,int> ai;
//
//	map<string, string> m;
//	
//
//	// auto:����ʱ���ݳ�ʼ�����ʽ���������Ƶ�
//	auto it = m.begin();
//
//	// ֻ�����е�ʱ���֪��1+2�����ͣ���1+1������ȥ����a������
//	//auto(1 + 2) a;
//	// auto������ʱ����ʶ��
//
//	// decltype������ʱ����ʶ��
//	// Ҳ���Ը��ݺ����Ƴ�����ֵ����
//	decltype(1 + 2) b;
//}
//
//int fun(int a=1){ return a; }
//
//void fun1(){ cout << "fun1" << endl; }
//void test(){
//	 
//
//	// ���ݺ����ķ���ֵ�����Ƴ�b������
//	decltype(fun()) b;
//
//	// decltype:����в����б��Ƶ�����ֵ����
//	cout << "b:type��" << typeid(b).name() << endl;
//
//	// û��decltype�����û�в����б�ֻ�к�������ʱ���Ƶ�Ϊ�������͵Ľӿ�����
//	cout << typeid(decltype(fun1)).name() << endl;
//}
////���麯���������final�ͳ�Ϊʵ�ּ̳У����ܱ���д
//// override��ǿ����д����д�ᱨ�����������Զ���飬�����Ƿ���д
//
//// ����һ�����ܱ��̳е���
//class B final{
//
//};
//
//class C{
//public:
//	// default���ñ�������ʽ����һ��Ĭ�Ϻ���
//	// Ĭ�Ϲ��죬��������
//	C() = default;
//	C(){}
//	// delete����һ��������������ɾ�������������ٱ�ʹ��
//
//	// ������������Ϊdelete��������
//	C(const C& c) = delete;
//
//	C& operator=(const C& c) = delete;
//private:
//	int _c;
//};
//
//C::C(const C& c)
//	:_c(c._c)
//{
//	cout << "C(const C& c)" << endl;
//}
//
//void testDelete(){
//	C c;
//
//	// ��ʱ�Ŀ��������Ѿ������Ϊ��һ��delete����
//	//C copy(c);
//}
//
//int getA(int a){ return a; }
//
////��ֵ����
//void testLR(){
//	// ��ֵ
//
//	//�����
//	// ��ֵ���ȿ��Գ�����=�����ߣ����߿���ȡ��ַ��
//	int a = 10;
//	int b = a;
//	int* pa = &a;
//	int* pb = &b;
//
//	// ��ֵ��ֻ�ܳ����ڵȺŵ��ұߣ����߲�����ȡ��ַ
//	//10 = 20;//������
//	//int* p10 = &10;//������
//
//	//C++�У���ֵ
//	// ����ֵ����������ʱ�������Գ�Ϊ����ֵ
//	// ����ֵ���������ڼ�������
//	
//	// ��ֵ������ֵ
//	// ��ʱ����/��������:������ֵ���صı�����������Ĺ��캯�������ı���������ʱ����
//	//getA(a) = b;
//
//	//��������ʱ����
//
//	C();
//	C* pc = &C();//��ʱ�����в��Ǿ��ԵĲ���ȡ��ַ
//	// ������ֵ�Ķ�����ֵ
//}
//
//void testRef(){
//	int a = 10;
//
//	//��ֵ���ã����õ�ʵ��Ϊ��ֵ���ȿ���Ϊ��ֵҲ����Ϊ��ֵ
//	// ʵ��Ϊ��ֵ
//	int& ra = a;
//
//	// ʵ��Ϊ��ֵ���������������const
//	const int& ri = 10;
//
//
//	// ��ֵ���ú���ֵ���ö��Ǳ����ı�����Ϊ��������
//
//	//��ֵ���ã����õ�ʵ��ֻ������ֵ
//	// ��ֵ���ã�ʵ��Ϊ����
//	int&& lr = 10;//ֻ��������ֵ
//
//	// ��ֵ���ã�ʵ��Ϊ��ʱ����
//	int&& lr2 = getA(a);//��ֵ����
//	const int& r3 = getA(a);//��ֵ����
//	// ��ֵ���üȿ���������ֵҲ����������ֵ
//
//	//int&& rr4 = a;//��ֵ���ò�����������ֵ
//
//	C&& rc = C();//��ֵ����
//
//	const C& rc1 = C();
//
//
//	//D&& rd1 = D(10);
//	//// û���Ż�������+��������
//	//// �Ż�������
//	//D& rd2 = D(20);
//}
//class D{};
//// ��ʱ������г���
//void func3(D& d){}
//
//
//// ��ֵ�������õĵط����ڿ���
//class String{
//public:
//	String(char* str = "")
//		:_str(new char[strlen(str)+1])
//		, _size(strlen(str))
//		, _capacity(strlen(str))
//	{}
//
//	// ���
//	String(const String& str)
//		:_str(new char[strlen(str._str) + 1]){
//		strcpy(_str, str._str);
//		_size = _capacity = strlen(str._str);
//		cout << "String(const String&" << endl;
//	}
//	
//	// ֱ���ù���Ч������
//	// ��ֵ���õĿ������죺����Ҫ��������������һ��ǳ����
//	// �ȵ��ù��캯�����ٵ�����ֵ�������캯��
//
//	// �ƶ����죺���ǿ���������Դ���ƶ������Ӷ�
//	// ��߿���Ч��
//	// ����ƥ�佫��ֵ
//	String(String&& str) // �˴���str�����Ǿֲ���������Ϊ&&ֱ��ȡ��Դ
//		:_str(str._str)
//	{
//		str._str = nullptr;
//		_size = _capacity = str._size;
//		cout << "String(String&&)" << endl;
//	}
//
//	~String()
//	{
//		if (_str){
//			delete[] _str;
//			cout << "~String()" << endl;
//		}
//	}
//
//	String& operator=(const String& str){
//		if (this != &str){
//			delete[] _str;
//
//			_str = new char[strlen(str._str)+1];
//			strcpy(_str,str._str);
//			_size = _capacity = strlen(str._str);
//			cout << "" << endl;
//		}
//		return *this;
//	}
//
//	// �ƶ���ֵ
//	String& operator=(String&& str){
//		swap(_str, str._str);
//		_size = _capacity = str._size;
//		cout << "�ƶ���ֵ" << "String operator=(String&&)"<<endl;
//	}
//
//private:
//	char*  _str;
//	int _size;
//	int _capacity;
//};
//
//String getString(){
//	String str("123");
//	return str; // �����������Ͻ��������Ƕ������Ķ������м�ֵ
//}
//void testString(){
//	// ������������ڽ����Ż����������
//	// �ȵ����ƶ����죬�ٵ��������������������������ĵ��ò�û��������
//	// ֱ��ǳ�������������еľֲ����󻻹���
//	// ǳ�������ƶ����죬ֱ�ӻ�ȡ����ֵ(��ֵ������Դ
//	String ret = getString();
//
//	// ������������죬retΪ��ֵ
//	String copy(ret);
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//// ����ָ��