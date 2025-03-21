#include "employee.h"

using namespace std;

int employee::employee_count = 0;

// Ажилчин классын байгуулагч функц
employee::employee()
{
    emp_id = 0;
    set_emp_name(NULL);
    set_emp_role(NULL);
    emp_work_time = 0;
    emp_hourly_rate = 5000;
}

// Ажилчин классын анхдагч утгатай параметртэй байгуулагч функы
employee::employee(int id, char *name, char *role, float work_time, float hourly_rate)
{
    emp_id = id;
    set_emp_name(name);
    set_emp_role(role);
    emp_work_time = work_time;
    emp_hourly_rate = hourly_rate;

    employee_count++;
}

// Ажилчин классын устгагч функц
employee::~employee()
{
    delete[] emp_name;
    delete[] emp_role;
    employee_count--;
    cout << emp_id << " id-tai ajiltan ustav" << endl;
}

// Ажилчин классын хуулагч байгуулагч функц
void employee::copy(employee &e)
{
    if (emp_name != NULL)
    {
        delete[] emp_name;
    }
    if (emp_role != NULL)
    {
        delete[] emp_role;
    }

    emp_name = new char(strlen(e.emp_name) + 1);
    emp_role = new char(strlen(e.emp_role) + 1);
    strcpy(emp_name, e.emp_name);
    strcpy(emp_role, e.emp_role);

    emp_id = e.emp_id;
    emp_hourly_rate = e.emp_hourly_rate;
    emp_work_time = e.emp_work_time;
}

// Ажилчны мэдээллийг хэвлэх функц
void employee::printData()
{
    cout << get_emp_id() << " id-tai ajilchnii medeelel:" << endl;
    cout << "Tsalin: " << calcSalary() << endl;
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
int employee::get_employee_count() { return employee_count; };
int employee::get_emp_id() { return emp_id; };
char *employee::get_emp_name() { return emp_name; };
char *employee::get_emp_role() { return emp_role; };
float employee::get_emp_work_time() { return emp_work_time; };
float employee::get_emp_hourly_rate() { return emp_hourly_rate; };

// Set функцүүд
// void employee::set_emp_id();
void employee::set_emp_name(char *name)
{
    if (emp_name != NULL)
    {
        delete[] emp_name;
    }

    if (name==NULL)
    {
        emp_name=NULL;
    } else {
        emp_name = new char[strlen(name) + 1];
        strcpy(emp_name, name);
    }
    
};
void employee::set_emp_role(char *role)
{
    if (emp_role != NULL)
    {
        delete[] emp_role;
    }

    if (role==NULL) {
        emp_role=NULL;
    } else {
        emp_role = new char[strlen(role) + 1];
        strcpy(emp_role, role);    
    }
    };
// void employee::set_emp_work_time();
void employee::set_emp_hourly_rate(float rate)
{
    emp_hourly_rate = rate;
};




// employeeBusiness классын цалингаар эрэмбэлэх функцийн хэрэгжүүлэлт
void employeeBusiness::wage_sort(employee **workers)
{
    int count = employee::get_employee_count();

    // Хэрэв ганц юм уу ажилтан байхгүй бол буцна
    if (employee::get_employee_count() < 2)
    {
        return;
    }

    

    // Insertion sort ашиглаж эрэмбэлнэ
    for (int i = 1; i < count; i++)
    {
        employee *temp = new employee();
        temp->copy(*workers[i]);
        int j = i - 1;

        while (j >= 0 && temp->calcSalary() < workers[j]->calcSalary())
        {
            workers[j + 1]->copy(*workers[j]);
            j--;
        }
        workers[j + 1]->copy(*temp);
    }
}

void employeeBusiness::name_sort(employee **workers) {
    int count = employee::get_employee_count();
    // Хэрэв ганц юм уу ажилтан байхгүй бол буцна
    if (employee::get_employee_count() < 2)
    {
        return;
    }

    // Insertion sort ашиглаж эрэмбэлнэ
    for (int i = 1; i < count; i++)
    {
        employee *temp = new employee();
        temp->copy(*workers[i]);
        int j = i - 1;

        while (j >= 0 && strcmp(temp->get_emp_name(), workers[j]->get_emp_name())<0)
        {
            workers[j + 1]->copy(*workers[j]);
            j--;
        }
        workers[j + 1]->copy(*temp);
    }
}

bool employeeBusiness::has_id(employee** workers, int id) {
    int count = employee::get_employee_count();
    for (int i=0; i<count; i++) {
        if (workers[i]->get_emp_id()==id) {
            return true;
        }
    }

    return false;
}