#include "Student.h"
#include "cstring"

void Student::SetName(char* newName) {
    int c = 0;
    this->name[strlen(newName)] = 0;
    for (int i = 0; i < strlen(newName); i++) {
        this->name[i] = newName[i];
    }
    this->nameLength = strlen(newName);
}

char* Student::GetName() {
    return this->name;
}

void Student::SetMathGrade(float grade) {
    if (grade < 0.0f || grade > 10.0f) return;
    this->mathGrade = grade;
}

float Student::GetMathGrade() {
    return this->mathGrade;
}

void Student::SetEnglishGrade(float grade) {
    if (grade < 0 || grade>10) return;
    this->englishGrade = grade;
}

float Student::GetEnglishGrade() {
    return this->englishGrade;
}

void Student::SetHistoryGrade(float grade) {
    if (grade < 0 || grade>10) return;
    this->historyGrade = grade;
}

float Student::GetHistoryGrade() {
    return this->historyGrade;
}

float Student::GetAverageGrade() {
    return (this->historyGrade + this->mathGrade + this->englishGrade) / 3;
}

int Student::GetNameLength() {
    return this->nameLength;
}