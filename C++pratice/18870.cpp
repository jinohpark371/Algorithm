#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec1(n); //����
	vector<int> vec2(n); //���Ŀ�

	for (int i = 0; i < n; i++) {
		cin >> vec1[i];
		vec2[i] = vec1[i];
	}

	sort(vec2.begin(), vec2.end());

	//N^2�� �ð����⵵
	/*for (int i = vec1.size() - 1; i >0; i--) {
		if (vec1[i] == vec1[i - 1]) {
			vec1.erase(vec1.begin()+i); erase�� O(N) �ð� �ɸ�!
		} erase()�� ���� ������ ��� ���Ҹ� ������ �̵���Ű�� ������ �־��� ��� O(N^2) �� �ȴ�.
	}*/
	/*unipue�� ���� ���Ϳ� �ִ� �ߺ��� ��ҵ��� ������ �� �ְ� ���ο� �� ��ġ�� ��ȯ
	��� ���ʹ� ���ĵǾ�� �ϰ� �ߺ��� ���ŵ� ������ ��� ���� ��ġ�� �ݺ��ڸ� ��ȯ
	������ �����̳��� ũ�Ⱑ ������ �ʰ� ���� �ߺ��� ������ �ڷ� �о
	*/
	//�ð� ���⵵:  O(N)
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	//vec2.erase(���ο� ��, vec2.end())
	//erase()�� [���ο� ��, vec2.end()) ������ ���Ϳ��� ������ ������
	//�ڷ� �з��� �ߺ���ҵ��� ���Ϳ��� ���� (N)

	//�մ�� �ʿ� ���� �׳� ��°�� �߶󳻱⸸ �ϸ� ��

	for (int item : vec1) {
		int count = lower_bound(vec2.begin(), vec2.end(), item) - vec2.begin();
		cout << count << " ";
	}

	return 0;
}