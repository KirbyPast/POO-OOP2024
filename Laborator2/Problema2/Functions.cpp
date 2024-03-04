#include "Functions.h"
int compareName(Student student1, Student student2) {
	int st1Len = student1.GetNameLength(), st2Len = student2.GetNameLength();
	for (int i = 0; i < st1Len && i <st2Len; i++) {
		if (student1.GetName()[i] > student2.GetName()[i]) return 1;
		else if (student1.GetName()[i] < student2.GetName()[i]) return -1;
	}
	if (st1Len == st2Len) return 0;
	else if (st1Len == st2Len) return 1;
	else if (st1Len == st2Len) return -1;
	
}

int compareEngGrade(Student student1, Student student2) {
	if (student1.GetEnglishGrade() > student2.GetEnglishGrade()) return 1;
	else if (student1.GetEnglishGrade() < student2.GetEnglishGrade()) return -1;
	else return 0;
}

int compareMathGrade(Student student1, Student student2) {
	if (student1.GetMathGrade() > student2.GetMathGrade()) return 1;
	else if (student1.GetMathGrade() < student2.GetMathGrade()) return -1;
	else return 0;
}

int compareHistoryGrade(Student student1, Student student2) {
	if (student1.GetHistoryGrade() > student2.GetHistoryGrade()) return 1;
	else if (student1.GetHistoryGrade() < student2.GetHistoryGrade()) return -1;
	else return 0;
}

int compareAvgGrade(Student student1, Student student2) {
	if (student1.GetAverageGrade() > student2.GetAverageGrade()) return 1;
	else if (student1.GetAverageGrade() < student2.GetAverageGrade()) return -1;
	else return 0;
}
