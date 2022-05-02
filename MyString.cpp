#include <iostream>
#include "MyString.h"
#include <string.h>
//конструктор инцииализации
MyString::MyString()
{
    count = 0;
    string = nullptr;
}
//конструктор копирования
MyString::MyString(const MyString& tempString)
{
    count = tempString.count;
    string = new char[count + 1];
    for (int i=0; i < count; i++)
    {
        string[i]=tempString.string[i];
    }
}
//конструктор по умолчанию
MyString::MyString (char* tempString, int tempCount)
{
    count= tempCount;
    string = new char [ count + 1 ];
    for (int i=0; i < count; i++)
    {
        string[i]=tempString[i];
    }
}
//деструктор - чистим память
MyString::~MyString()
{
    delete[] string;
}
//получаем длину строки
int MyString::GetCount()
{
    return count;
}
//задаем длину строки
void MyString::SetCount(int tempCount)
{
    count = tempCount;
}
//перегрузка оператора присваивания
MyString& MyString::operator = (const MyString& tempString)
{
    if (string != nullptr)
    {
        delete [] string;
        string = nullptr;
    }
    count = tempString.count;
    string = new char [count + 1];
    for (int i=0; i < count; i++)
    {
        string[i] = tempString.string[i];
    }
    return *this; //вернет стринг
}
//копирование начиная с какого-то символа
MyString MyString::CopyFromIndex(MyString tempString, int startIndex, int tempCount)
{
  if (startIndex < 0)
  {
    tempCount = count + startIndex;
    startIndex = 0;
  }
  if (startIndex >= count)
  {
    tempCount = 0;
  }
  if (startIndex + tempCount < count)
  {
    count = tempCount;
    string = new char[count + 1];
    for (int i = 0; i < count; i++)
    {
      string[i] = tempString.string[startIndex + i];
    }
  }
  return *this;
}
//
void MyString::FindString (const char* tempString)
{
    int temp = strlen(tempString);
    bool f;
    bool f1 = false;
    for (int i = 0; i <= count - temp; i++)
    {
      f = true;

      if (string[i] == tempString[0])
      {
        for (int j = 1; j < temp; j++)
        {
          if (string[i + j] == tempString[j])
          {
            f = true;
          }
          else
          {
            f = false;
            break;
          }
        }

        if (f == true)
        {
          std::cout<< i << " ";
          f1 = true;
        }
      }
    }
    if (f1 == false)
      std::cout << "No result";
}

int MyString::FindChar (char tempChar)
{
  for (int i = 0; i < count; i++)
  {
    if (string[i] == tempChar)
    {
      return i;
    }
  }
  return -1;
}
//перегрузка оператора сложения
MyString MyString::operator + (MyString tempString)
{
  char* result = new char[count + tempString.count + 1];

  for (int i = 0; i < count; i++)
  {
    result[i] = string[i];
  }

  for (int i = 0; i < tempString.count; i++)
  {
    result[count + i] = tempString.string[i];
  }

  MyString resultString(result, count + tempString.count);
  return resultString;
}
//перегрузка оператора ==
bool MyString::operator == (MyString tempString)
{
  if (count == tempString.count)
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] == tempString.string[i])
      {

      }
      else
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool MyString::operator != (MyString tempString)
{
  if (count != tempString.count)
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] != tempString.string[i])
      {

      }
      else
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool MyString::operator < (MyString tempString)
{
  if (count < tempString.count)
  {
    return true;
  }
  else if (count > tempString.count)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] < tempString.string[i])
      {
        return true;
      }
      else if (string[i] > tempString.string[i])
        {
          return false;
        }
    }
  }
  return false;
}

bool MyString::operator > (MyString tempString)
{
  if (count > tempString.count)
  {
    return true;
  }
  else if (count < tempString.count)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] > tempString.string[i])
      {
        return true;
      }
      else if (string[i] < tempString.string[i])
        {
          return false;
        }
    }
  }
  return false;
}

bool MyString::operator <= (MyString tempString)
{
  if (count <= tempString.count)
  {
    return true;
  }
  else if (count > tempString.count)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] <= tempString.string[i])
      {
        return true;
      }
      else if (string[i] > tempString.string[i])
        {
          return false;
        }
    }
  }
  return false;
}

bool MyString::operator >= (MyString tempString)
{
  if (count >= tempString.count)
  {
    return true;
  }
  else if (count < tempString.count)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      if (string[i] >= tempString.string[i])
      {
        return true;
      }
      else if (string[i] < tempString.string[i])
        {
          return false;
        }
    }
  }
  return false;
}

std::ostream& operator << (std::ostream& out, const MyString& tempString)
{
    for ( int i =0; i < tempString.count; i++)
    {
        out << tempString.string[i];
    }
    return out;
}

std::istream& operator >> (std::istream& in,  MyString& tempString)
{
    std::string temp;
    in >> temp;
    tempString.count = int (temp.length());
    tempString.string = new char [tempString.count + 1];
    for (int i=0; i < tempString.count; i++){
        tempString.string[i] =temp [i];
    }
    return in;
}

char MyString::operator [] (int i)
{
  if ((i >= 0) && (i < count))
  {
    return string[i];
  }
  else
  {
    throw ("Error! Incorrect index!");
  }
}
