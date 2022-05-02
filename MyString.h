#pragma once

class MyString
{
protected:
    int count;
    char* string;
public:
    MyString();
    MyString(const MyString& tempString);
    MyString (char* tempString, int tempCount); //конструктор создания строки (по умолчанию)
    ~MyString();
    int GetCount();
    void SetCount(int tempCount);
    MyString CopyFromIndex (MyString tempString, int startIndex, int tempCount);
    void FindString (const char* tempString);
    int FindChar (char tempChar);
    MyString& operator = (const MyString& tempString);
    MyString operator + (MyString tempString);
    bool operator == (MyString tempString);
    bool operator != (MyString tempString);
    bool operator < (MyString tempString);
    bool operator > (MyString tempString);
    bool operator <= (MyString tempString);
    bool operator >= (MyString tempString);
    friend std::ostream& operator << (std::ostream& out, const MyString& tempString);
    friend std::istream& operator >> (std::istream& in,  MyString& tempString);
    char operator [] (int i);
};


