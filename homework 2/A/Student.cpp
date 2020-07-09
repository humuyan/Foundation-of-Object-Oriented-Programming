#include "Student.h"
bool operator<(const Student &i, const Student &j) {
	if (i.totalScore != j.totalScore) {
		return (i.totalScore < j.totalScore);
	}
	if (i.chineseScore != j.chineseScore) {
		return (i.chineseScore < j.chineseScore);
	}
	if (i.mathScore != j.mathScore) {
		return (i.mathScore < j.mathScore);
	}
	return (i.englishScore < j.englishScore);
}
ostream &operator<<(ostream &out, const Student &x) {
	out << x.name << "-Total-" << x.totalScore << "-Chinese-" << x.chineseScore << "-Math-" << x.mathScore << "-English-" << x.englishScore;
	return out;
}
