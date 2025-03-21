#ifndef employee_h
#define employee_h

#include <iostream>
#include <string.h>
#include <stdlib.h>

// Ажилчин классыг толгой файлд загварчлав
class employee
{
    // Ажилчны дугаар, нэр, албан тушаал, ажилласан цаг, цагт олдог орлогын дүнг хадгална
private:
    // Үүссэн ажилтан объектын тоог хадгална
    static int employee_count;

    int emp_id;
    char *emp_name;
    char *emp_role;
    float emp_work_time;
    float emp_hourly_rate;

    // Байгуулагч функцүүд
public:
    // Анхдагч байгуулагч
    employee();
    // Параметртэй байгуулагч
    employee(int, char[], char[], float, float);
    // Устгагч функцүүд
    ~employee();

    // Хуулагч байгуулагч
    void copy(employee &e);

public:
    // Объектын бүх гишүүнийг хэвлэнэ
    void printData();
    // Ажилтны цалинг бодно
    float calcSalary();

private:
    // Захирлын цалинг бодно
    float calcBossSalary();

    // Тухайн өдөрт ажилласан цагийг нэмэгдүүлнэ
public:
    bool addWorkTime(float);

    // Get, set функцүүд
public:
    // Ажилтан объектын тоог авна
    static int get_employee_count();

    int get_emp_id();
    char *get_emp_name();
    char *get_emp_role();
    float get_emp_work_time();
    float get_emp_hourly_rate();

    // void set_emp_id();
    void set_emp_name(char *name);
    void set_emp_role(char *role);
    // void set_emp_work_time();
    // void set_emp_hourly_rate(float);
};

// Ажилчин класс дээр үйлдэл хийх бизнес класс
class employeeBusiness
{
    // Бизнес классын хийх үйлдлүүд
public:
    // Ажилчдын мэдээллийг цалингаар нь эрэмбэлнэ
    static void wage_sort(employee**);
    // Ажилчдын мэдээллийг нэрээр нь эрэмбэлнэ
    static void name_sort(employee**);
    // Ажилчдын мэдээллээс тухайн id-тай ажилтан байгаа эсэхийг шалгана
    static bool has_id(employee**,int);
};

#endif