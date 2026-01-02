#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	//set은 중복 불가, 자동 정렬, 빠른 탐색/삽입/삭제 가능(O(log N))
	//벡터로 수행시 leave가 나올때 뒤에서 찾고 같은 이름 enter를 찾고
	//erase 여러 번 -> O(N²)
	//set은 존재하냐/없냐 문제에 최적
	set<string> people;

	cin >> n;

	while (n--) {
		string name, status;
		cin >> name >> status;

		//enter가 나올시만 저장
		if (status == "enter") {
			people.insert(name);
		}
		//leave가 나온 이름은 집합에서 삭제
		else {
			people.erase(name);
		}
	}

	//set은 오름차순 자동 정렬되어 있으므로 역순 출력
	for (auto it = people.rbegin(); it != people.rend(); it++) {
		cout << *it << '\n';
	}
}