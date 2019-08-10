#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

void display(int &number)
{
	++number;
	cout << number << " ";
}

void test0()
{
	vector<int> numbers{ 1,2,3,4,5 };

	//std::for_each(numbers.begin(), numbers.end(), display);

	//lambda����ʽ ==> ��������
	std::for_each(numbers.begin(), numbers.end(), [](int number){
		//cout << numbers.size() << endl;
		cout << number << " ";
		});
	cout << endl;

	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void test1()
{
	vector<int> numbers{ 7,1,2,6,8,9,3,4,5 };
	//�������������в���ʱ��Ҫ���õ���std::find/std::count
	//��ʱ�临�Ӷ�ΪO(N)
	auto it = std::find(numbers.begin(), numbers.end(), 3);
	cout << "*it = " << *it << endl;

	//Ϊ����߲����ٶȣ������������ٽ��в���
	//
	//sortĬ������°�����������
	std::greater<int> gt;
	std::sort(numbers.begin(), numbers.end(), gt);
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//��ʱʹ��lower_bound��ʱ�临�Ӷ�O(logN)
	auto it2 = std::lower_bound(numbers.begin(), numbers.end(), 3, gt);
	cout << "*it2 = " << *it2 << endl;
}

int main()
{
	//test0();
	test1();
	return 0;
}