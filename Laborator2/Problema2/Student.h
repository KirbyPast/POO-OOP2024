#pragma once
class Student
{
private:
    char name[100];
    int nameLength;
    float mathGrade;
    float englishGrade;
    float historyGrade;
public:
    void SetName(char* newName);
    char* GetName();
    void SetMathGrade(float grade);
    float GetMathGrade();
    void SetEnglishGrade(float grade);
    float GetEnglishGrade();
    void SetHistoryGrade(float grade);
    float GetHistoryGrade();
    float GetAverageGrade();
    int GetNameLength();
};

