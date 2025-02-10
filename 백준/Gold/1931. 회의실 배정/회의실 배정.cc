#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct class_ {
	int startTime;
	int endTime;

	class_(int startTime_, int endTime_) :
		startTime(startTime_), endTime(endTime_) {}
	
};

struct cmp {
	bool operator()(class_ a, class_ b) {
		if(a.endTime == b.endTime) return a.startTime > b.startTime;
		return a.endTime > b.endTime;
	}
};

int N;
priority_queue<class_, vector<class_>, cmp> pq;
vector<class_> v;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int a, b;
	for(int i = 0; i < N; i++) {
		cin >> a >> b;
		pq.push(class_(a, b));
	}

	int lastEndedTime = 0;
	while (!pq.empty()) {

		class_ tmp = pq.top();
		pq.pop();
		if (tmp.startTime >= lastEndedTime) {
			lastEndedTime = tmp.endTime;
			v.push_back(tmp);
		}
	}

	cout << v.size() << "\n";

	return 0;

	
}