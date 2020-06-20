#include "header1.h"
#include "header2.h"

namespace header1 {
	int func()
	{
		foo(); // header1::foo()�� ����
	}
} // namespace header1

namespace header1 {
	int func() {
		foo(); // �˾Ƽ� header1::foo() �� ����ȴ�.
		header2::foo(); // header2::foo() �� ����ȴ�.
	}
} // namespace header1

int func() {
	header1::foo(); // header1 �̶� �̸� ������ �ִ� foo �� ȣ��
}

using header1::foo;
int main() {
	foo(); // header1 �� �ִ� �Լ��� ȣ��
}

using namespace header1;
int main() {
	foo(); // header1 �� �ִ� �Լ��� ȣ��
	bar(); // header1 �� �ִ� �Լ��� ȣ��
}

using namespace header1;
int main2() {
	header2::foo(); // header2 �� �ִ� �Լ��� ȣ��
	foo(); // header1 �� �ִ� �Լ��� ȣ��
}

#include <iostream>
using namespace std;
int main3() 
{
	cout << "Hello, World!" << endl;
	return 0;
}

namespace {

	// �� �Լ��� �� ���� �ȿ����� ��� ����
	// static int OnlyInThisFile() �� ����
	int OnlyInThisFile() {}

	// static int only_in_this_file �� �����մϴ�.
	int only_in_this_file = 0;

}  // namespace�� ����� main�� �����ϰ� ��� �Ұ�

int main() {
	OnlyInThisFile();
	only_in_this_file = 3;
}

int main()
{
	std::cout << "Hi" << std::endl
			  << "My Name is"
			  << "KyungHoon" << std::endl;
}