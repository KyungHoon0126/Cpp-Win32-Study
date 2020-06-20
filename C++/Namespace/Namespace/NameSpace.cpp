#include "header1.h"
#include "header2.h"

namespace header1 {
	int func()
	{
		foo(); // header1::foo()가 실행
	}
} // namespace header1

namespace header1 {
	int func() {
		foo(); // 알아서 header1::foo() 가 실행된다.
		header2::foo(); // header2::foo() 가 실행된다.
	}
} // namespace header1

int func() {
	header1::foo(); // header1 이란 이름 공간에 있는 foo 들 호출
}

using header1::foo;
int main() {
	foo(); // header1 에 있는 함수를 호출
}

using namespace header1;
int main() {
	foo(); // header1 에 있는 함수를 호출
	bar(); // header1 에 있는 함수를 호출
}

using namespace header1;
int main2() {
	header2::foo(); // header2 에 있는 함수를 호출
	foo(); // header1 에 있는 함수를 호출
}

#include <iostream>
using namespace std;
int main3() 
{
	cout << "Hello, World!" << endl;
	return 0;
}

namespace {

	// 이 함수는 이 파일 안에서만 사용 가능
	// static int OnlyInThisFile() 과 동일
	int OnlyInThisFile() {}

	// static int only_in_this_file 와 동일합니다.
	int only_in_this_file = 0;

}  // namespace를 벗어나면 main을 제외하고 사용 불가

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