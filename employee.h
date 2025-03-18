#ifndef employee_h
#define employee_h

// Ажилчин классыг толгой файлд загварчлав
class employee
{
    // Ажилчны дугаар, нэр, албан тушаал, ажилласан цаг, цагт олдог орлогын дүнг хадгална
private:
    int emp_id;
    char emp_name[20];
    char emp_role[10];
    float emp_work_time;
    float emp_hourly_rate;

    // Байгуулагч функцүүд
public:
    employee();
    employee(int, char[], char[], float, float);
    // Устгагч функцүүд
    ~employee();

    // Өгөгдлийг хэвлэх, цалин бодох, захирлын цалин бодох функцүүд
public:
    void printData();
    float calcSalary();

private:
    float calcBossSalary();

    // Тухайн өдөрт ажилласан цагийг нэмэгдүүлнэ
public:
    bool addWorkTime(float);

    // Get, set функцүүд
public:
    int get_emp_id();
    char *get_emp_name();
    char *get_emp_role();
    float get_emp_work_time();
    float get_emp_hourly_rate();

    // void set_emp_id();
    void set_emp_name(char[]);
    void set_emp_role(char[]);
    // void set_emp_work_time();
    void set_emp_hourly_rate(float);
};

// Ажилчин класс дээр үйлдэл хийх бизнес класс
class employeeBusiness
{
    // Ажилчдын мэдээллийг цалингаар нь эрэмбэлнэ
public:
    void sort(employee**,int);
};

#endif