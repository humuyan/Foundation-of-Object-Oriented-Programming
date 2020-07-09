#include "StudentCollection.h"
void StudentCollection::sortByScore() {
	sort(stuList.begin(), stuList.end());
	reverse(stuList.begin(), stuList.end());
}
istream &operator>>(istream &in, StudentCollection &x) {
	string line;
	in >> line;
	auto p = line.begin();
	string name, subject;
	for (; *p != '-'; ++p) {
		name += *p;
	}
	for (++p; *p != '-'; ++p) {
		subject += *p;
	}
	int score = 0;
	for (++p; p != line.end(); ++p) {
		score = score*10 + *p-'0';
	}
	if (x.h.find(name) == x.h.end()) {
		x.h[name] = x.stuList.size();
		x.stuList.push_back(Student(name));
	}
	auto &info = x.stuList[x.h[name]];
	info.totalScore += score;
	if (subject == "Chinese") {
		info.chineseScore = score;
	} else {
		if (subject == "Math") {
			info.mathScore = score;
		} else {
			info.englishScore = score;
		}
	}
	return in;
}
ostream &operator<<(ostream &out, const StudentCollection &sc) {
	for (auto stu: sc.stuList) {
		out << stu << endl;
	}
	return out;
}
Student StudentCollection::operator[](const string &name) {
	return stuList[h[name]];
}
