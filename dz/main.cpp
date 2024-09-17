//
//  main.cpp
//  dz
//
//  Created by paul blazhko on 17.09.2024.
//

#include <iostream>
using namespace std;
class IOutput
{
public:
    virtual void Show() const = 0;
    virtual void Show(const string& info) const = 0;
};

class IMath
{
public:
    virtual int Max() const = 0;
    virtual int Min() const = 0;
    virtual float Avg() const = 0;
    virtual bool Search(int valueToSearch) const = 0;
};

class ISort
{
public:
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array: public IOutput, public IMath, public ISort
{
private:
    int* data;
    int size;
public:
    Array(int arr[], int size2)
    {
        size = size2;
        data = new int[size];
        for(int i = 0; i < size; i++)
        {
            data[i] = arr[i];
        }
    }
    ~Array()
    {
        delete[] data;
    }
    void Show() const
    {
        cout << "Числа из массива: ";
        for(int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void Show(const string& info) const
    {
        cout << info;
        for(int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int Max() const
    {
        int max = data[0];
        for(int i = 1; i < size; i++)
        {
            if(data[i] > max)
                max = data[i];
        }
        return max;
    }
    int Min() const
    {
        int min = data[0];
        for(int i = 1; i < size; i++)
        {
            if(data[i] < min)
                min = data[i];
        }
        return min;
    }
    float Avg() const
    {
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += data[i];
        }
        return static_cast<float>(sum) / size;
    }
    bool Search(int valueToSearch) const
    {
        for(int i = 0; i < size; i++)
        {
            if(data[i] == valueToSearch)
                return true;
        }
        return false;
    }
    void SortAsc()
    {
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(data[i] > data[j])
                {
                    swap(data[i], data[j]);
                }
            }
        }
    }
    void SortDesc()
    {
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(data[i] < data[j])
                {
                    swap(data[i], data[j]);
                }
            }
        }
    }
    void SortByParam(bool isAsc)
    {
        if(isAsc)
        {
            SortAsc();
        }
        else
        {
            SortDesc();
        }
    }
};

int main()
{
    int arr[] = {21, 2, 5, 7, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    Array ar(arr, size);
    ar.Show();
    ar.Show("Inf: ");
    cout << "Максимум: " << ar.Max() << endl;
    cout << "Минимум: " << ar.Min() << endl;
    cout << "Среднее арифметическое: " << ar.Avg() << endl;
    int valueToSearch = 7;
    if (ar.Search(valueToSearch))
        cout << "Число " << valueToSearch << " найдено" << endl;
    else
        cout << "Число " << valueToSearch << " не найдено" << endl;
    ar.SortAsc();
    ar.Show("по возрастанию: ");
    ar.SortDesc();
    ar.Show("по убыванию: ");
    ar.SortByParam(true);
    ar.Show("по возрастанию SortByParam: ");
    ar.SortByParam(false);
    ar.Show("по убыванию SortByParam: ");
}
