
#include "Functions.h"
#include "Student.h"
#include "stdio.h"
#include "cstring"

int main() {
	Student student1;
	char name1[]={"abdd"};
	student1.SetName(name1);
	student1.SetEnglishGrade(3.5f);
	student1.SetHistoryGrade(5.4f);
	student1.SetMathGrade(7.8f);
	student1.SetMathGrade(11.5f);
	printf("%s %f %f %f %f \n",student1.GetName(),student1.GetEnglishGrade(), student1.GetHistoryGrade(),student1.GetMathGrade(),student1.GetAverageGrade());
	Student student2;
	char name2[] = { "abdaf" };
	student2.SetName(name2);
	student2.SetEnglishGrade(4.5f);
	student2.SetHistoryGrade(5.0f);
	student2.SetMathGrade(10.0f);
	printf("%s %f %f %f %f \n", student2.GetName(), student2.GetEnglishGrade(), student2.GetHistoryGrade(), student2.GetMathGrade(), student2.GetAverageGrade());
	printf("%d %d %d %d %d", compareName(student1, student2), compareEngGrade(student1, student2), compareHistoryGrade(student1, student2), compareMathGrade(student1, student2), compareAvgGrade(student1, student2));
}