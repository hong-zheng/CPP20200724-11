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
//	// 初始化列表并不能调用，需要不受构造函数的参数的限制
//	Vector(int n)
//		:_array(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//
//	// 重载：相似匹配
//	// 实现了当前函数就可以进行列表初始化
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
//	// C++11：支持内置类型的列表初始化
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
//	// 自定义类型：创建单个对象
//	A k = { 1, 22 }; //不能给出三个值，这样太多
//	// C++11：也支持自定义类型的列表初始化
//
//	// 单参构造函数的隐式类型转换
//	A a4 = 5;
//
//	/// 自定义类型：初始化多个元素-->不是天然支持列表初始化
//	// 无法从初始化列表转换为Vector
//	// 需要显式定义参数类型为initializer_list的构造函数
//
//	// {}：这个整体构成一个参数
//	Vector<int> vec = { 33, 32, 32, 21 };//里面有4个元素
//	// 任何类型都可以实现列表初始化的工作
//
//	// 这种情况下：每一个都构成一个参数
//	Vector<int> vec2(10);//第一个有一个参数的构造函数，这里是创建一个Vector对象，里面没有元素，空的Vector
//	Vector<int> vec3{ 19 }; //开辟的容器大小为19
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
//	// auto:编译时根据初始化表达式进行类型推导
//	auto it = m.begin();
//
//	// 只有运行的时候才知道1+2的类型，用1+1的类型去定义a的类型
//	//auto(1 + 2) a;
//	// auto：编译时类型识别
//
//	// decltype：运行时类型识别
//	// 也可以根据函数推出返回值类型
//	decltype(1 + 2) b;
//}
//
//int fun(int a=1){ return a; }
//
//void fun1(){ cout << "fun1" << endl; }
//void test(){
//	 
//
//	// 根据函数的返回值类型推出b的类型
//	decltype(fun()) b;
//
//	// decltype:如果有参数列表，推导返回值类型
//	cout << "b:type：" << typeid(b).name() << endl;
//
//	// 没有decltype：如果没有参数列表，只有函数名的时候，推导为函数类型的接口类型
//	cout << typeid(decltype(fun1)).name() << endl;
//}
////给虚函数后面添加final就成为实现继承，不能被重写
//// override：强制重写，不写会报错，编译器会自动检查，自身是否被重写
//
//// 定义一个不能被继承的类
//class B final{
//
//};
//
//class C{
//public:
//	// default：让编译器显式生成一个默认函数
//	// 默认构造，拷贝构造
//	C() = default;
//	C(){}
//	// delete：把一个函数声明成已删除函数，不能再被使用
//
//	// 拷贝构造声明为delete：防拷贝
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
//	// 此时的拷贝构造已经定义成为了一个delete函数
//	//C copy(c);
//}
//
//int getA(int a){ return a; }
//
////右值引用
//void testLR(){
//	// 左值
//
//	//简单理解
//	// 左值：既可以出现在=的两边，或者可以取地址的
//	int a = 10;
//	int b = a;
//	int* pa = &a;
//	int* pb = &b;
//
//	// 右值：只能出现在等号的右边，或者不可以取地址
//	//10 = 20;//不可行
//	//int* p10 = &10;//不可行
//
//	//C++中：右值
//	// 纯右值：常量，临时变量可以称为纯右值
//	// 将亡值：声明周期即将结束
//	
//	// 右值：将亡值
//	// 临时变量/匿名变量:函数以值返回的变量，调用类的构造函数创建的变量（即临时对象）
//	//getA(a) = b;
//
//	//匿名，临时变量
//
//	C();
//	C* pc = &C();//临时变量中不是绝对的不能取地址
//	// 不是右值的都是左值
//}
//
//void testRef(){
//	int a = 10;
//
//	//左值引用：引用的实体为左值，既可以为左值也可以为右值
//	// 实体为左值
//	int& ra = a;
//
//	// 实体为右值（常量），必须加const
//	const int& ri = 10;
//
//
//	// 左值引用和右值引用都是变量的别名，为变量本身
//
//	//右值引用：引用的实体只能是右值
//	// 右值引用，实体为常量
//	int&& lr = 10;//只能引用右值
//
//	// 右值引用：实体为临时变量
//	int&& lr2 = getA(a);//右值引用
//	const int& r3 = getA(a);//左值引用
//	// 左值引用既可以引用右值也可以引用左值
//
//	//int&& rr4 = a;//右值引用并不能引用左值
//
//	C&& rc = C();//右值引用
//
//	const C& rc1 = C();
//
//
//	//D&& rd1 = D(10);
//	//// 没有优化：构造+拷贝构造
//	//// 优化：构造
//	//D& rd2 = D(20);
//}
//class D{};
//// 临时对象具有常性
//void func3(D& d){}
//
//
//// 右值引用有用的地方在于拷贝
//class String{
//public:
//	String(char* str = "")
//		:_str(new char[strlen(str)+1])
//		, _size(strlen(str))
//		, _capacity(strlen(str))
//	{}
//
//	// 深拷贝
//	String(const String& str)
//		:_str(new char[strlen(str._str) + 1]){
//		strcpy(_str, str._str);
//		_size = _capacity = strlen(str._str);
//		cout << "String(const String&" << endl;
//	}
//	
//	// 直接拿过来效率增加
//	// 右值引用的拷贝构造：不需要做深拷贝，本身就是一个浅拷贝
//	// 先调用构造函数，再调用右值拷贝构造函数
//
//	// 移动构造：不是拷贝，是资源的移动或者掠夺
//	// 提高拷贝效率
//	// 可以匹配将亡值
//	String(String&& str) // 此处的str并不是局部对象，声明为&&直接取资源
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
//	// 移动赋值
//	String& operator=(String&& str){
//		swap(_str, str._str);
//		_size = _capacity = str._size;
//		cout << "移动赋值" << "String operator=(String&&)"<<endl;
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
//	return str; // 生命周期马上结束，但是对其他的对象还是有价值
//}
//void testString(){
//	// 对象的生命周期结束才会调析构函数
//	// 先调用移动构造，再调用析构函数，但是析构函数的调用并没有起到作用
//	// 直接浅拷贝，将函数中的局部对象换过来
//	// 浅拷贝：移动构造，直接获取将亡值(右值）的资源
//	String ret = getString();
//
//	// 深拷贝：拷贝构造，ret为左值
//	String copy(ret);
//}
//int main(){
//	test();
//	system("pause");
//	return 0;
//}
//// 智能指针