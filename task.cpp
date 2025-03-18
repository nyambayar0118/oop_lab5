#include <iostream>
#include <string.h>
#include "employee.h"

using namespace std;

// Ажилчин классын байгуулагч функц
employee::employee()
{
    emp_id = 0;
    strcpy(emp_name, "na");
    strcpy(emp_role, "Worker");
    emp_work_time = 0;
    emp_hourly_rate = 5000;
}

// Ажилчин классын анхдагч утгатай параметртэй байгуулагч функы
employee::employee(int id = 0, char *name = NULL, char *role = NULL, float work_time = 0, float hourly_rate = 5000)
{
    emp_id = id;
    strcpy(emp_name, name);
    strcpy(emp_role, role);
    emp_work_time = work_time;
    emp_hourly_rate = hourly_rate;
}

// Ажилчин классын устгагч функц
employee::~employee()
{
        cout << emp_id << " id-tai ajiltan ustav" << endl;
}

// Ажилчны мэдээллийг хэвлэх функц
void employee::printData()
{
    cout << get_emp_id() << " id-tai ajilchnii medeelel:" << endl;
    cout << "Ner: " << get_emp_name() << endl;
    cout << "Alban tushaal: " << get_emp_role() << endl;
    cout << "Ajillasan tsag: " << get_emp_work_time() << endl;
    cout << "Tsagiin orlogo: " << get_emp_hourly_rate() << endl
         << endl;
}

// Ажилчны цалинг тооцох функц
float employee::calcSalary()
{
    float salary = emp_hourly_rate * emp_work_time;

    if (strcmp("Zahiral", emp_role) == 0 || strcmp("zahiral", emp_role) == 0)
    {
        salary += calcBossSalary();
    }

    return (salary);
}

// Хэрэв захирал бол цалинг 1.5 дахин дүн нэмж тооцох функц
float employee::calcBossSalary()
{
    return (emp_hourly_rate * emp_work_time * 1.5);
}

// Ажилтны ажилласан цаг нэмэх функц
bool employee::addWorkTime(float hour)
{
    bool ret_value;
    if (hour < 0 || hour > 24)
    {
        ret_value = 0;
        cout << "Failed" << endl;
    }
    else
    {
        ret_value = 1;
        emp_work_time += hour;
        cout << "Successful" << endl;
    }

    return ret_value;
}

// Get функцүүд
int employee::get_emp_id() { return emp_id; };
char *employee::get_emp_name() { return emp_name; };
char *employee::get_emp_role() { return emp_role; };
float employee::get_emp_work_time() { return emp_work_time; };
float employee::get_emp_hourly_rate() { return emp_hourly_rate; };

// Set функцүүд
// void employee::set_emp_id();
void employee::set_emp_name(char *name)
{
    strcpy(emp_name, name);
};
void employee::set_emp_role(char *role)
{
    strcpy(emp_role, role);
};
// void employee::set_emp_work_time();
void employee::set_emp_hourly_rate(float rate)
{
    emp_hourly_rate = rate;
};


// employeeBusiness классын эрэмбэлэх функцийн хэрэгжүүлэлт
void employeeBusiness::sort(employee **workers,int count)
{
    // Хэрэв ганц юм уу ажилтан байхгүй бол буцна
    if (count<2) {
        return;
    }

    // Insertion sort ашиглаж эрэмбэлнэ
    for (int i=1; i<count; i++) {
        employee *temp=workers[i];
        int j=i-1;

        while (j>=0 && temp->calcSalary() < workers[j]->calcSalary()) {
            workers[j+1]=workers[j];
            j--;
        }
        workers[j+1]=temp;
    }
}

int main()
{
    // 100 ширхэг ажилчин объектын хүснэгт үүсгэнэ
    employee **workers = new employee *[100];
    // Оруулсан ажилтны тоог хадгална
    int i = 0;
    // Сонголтын утгыг хадгална
    int choice;

    // Программаас гарах сонголтыг хийтэл ажиллана
    while (1)
    {
        // Программын хийж болох сонголтыг гаргаад утгыг гараас авна
        cout << "1. Ajiltan oruulah, 2. Tsalingaar erembeleh, 3. Hevleh, 9. Exit" << endl;
        cout << "Songoltiig oruul: ";
        cin >> choice;

        // Ажилтны мэдээллийг гараас авна
        if (choice == 1)
        {
            char name[20];
            char role[10];
            float work_time;
            float hourly_rate;

            cout << "Ajilchnii ner: ";
            cin >> name;
            cout << "Alban tushaal: ";
            cin >> role;
            cout << "Ajillasan tsag: ";
            cin >> work_time;
            cout << "Tsagiin orlogo: ";
            cin >> hourly_rate;

            // Шинэ ажилтны объектын санах ойг динамикаар нөөцөлнө
            workers[i] = new employee(i + 1, name, role, work_time, hourly_rate);
            i++;

            // Амжилттай болсныг мэдээлнэ
            cout << "Successful" << endl
                 << endl;
        }
        else if (choice == 2)
        {
            // Ажилтан объект дээр ажиллах бизнес классын объект байгуулна
            employeeBusiness sorter;
            // Ажилтны мэдээлэлтэй объектын хүснэгт, тоог дамжуулж өгнө
            sorter.sort(workers,i);
        }
        else if (choice == 3)
        {
            // Ажилтны мэдээлэл байхгүй бол мэдээлнэ
            if (i == 0)
            {
                cout << "No employee data" << endl;
            }

            // Ажилтны мэдээлэл байвал хэвлэнэ
            for (int n = 0; n < i; n++)
            {
                cout << endl;
                // Ажилтны мэдээлэл алдаатай буюу 0 id-тай бол хэвлэхгүй
                if (workers[n]->get_emp_id() != 0)
                {
                    cout << workers[n]->calcSalary() << endl;
                    workers[n]->printData();
                }
            }
        }
        else if (choice == 9)
        {
            // Программаас гарахдаа бүх нөөцөлсөн санах ойг чөлөөлнө
            for (int m=0; m<i; m++) {
                delete workers[m];
            }
            delete[] workers;
            break;
        }
        else
        {
            // Буруу сонголт оруулсныг мэдэгдэнэ
            cout << "Invalid choice" << endl;
        }
    }
}