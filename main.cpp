#include "employee.h"

using namespace std;

int main()
{
    // 100 ширхэг ажилчин объектын хүснэгт үүсгэнэ
    employee **workers = new employee *[100];
    // Сонголтын утгыг хадгална
    int choice, i = 0;

    // Программаас гарах сонголтыг хийтэл ажиллана
    while (1)
    {
        // Программын хийж болох сонголтыг гаргаад утгыг гараас авна
        cout << "1. Ajiltan oruulah, 2. Tsalingaar erembeleh, 3. Nereer erembeleh, 4. Hevleh, 9. Exit" << endl;
        cout << "Songoltiig oruul: ";
        cin >> choice;

        // Ажилтны мэдээллийг гараас авна
        if (choice == 1)
        {
            int id;
            string name;
            string role;
            float work_time;
            float hourly_rate;

            // Гараас авсан id-ний утгыг шалгана
            while (1)
            {
                // Гараас id-ний утгыг авна
                cout << "Ajilchnii id: ";
                cin >> id;

                // Гараас авсан утга тоо эсэхийг шалгана
                if (cin.fail())
                {
                    // Cin объектын алдааны флагийг цэвэрлэнэ
                    cin.clear();
                    // Буфер доторх алдаатай утгыг цэвэрлэнэ
                    cin.ignore();
                    cout << "Too oruulna uu!" << endl;
                }
                // Тухайн id-тай объект байгаа эсэхийг шалгана
                else if (employeeBusiness::has_id(workers, id) == false)
                {
                    break;
                }
                else
                {
                    cout << "Ajilchnii id davhtsaj bolohgui!" << endl;
                }
            }

            // Нэр, албан тушаал утгуудыг гараас авна
            cout << "Ajilchnii ner: ";
            cin >> name;
            cout << "Alban tushaal: ";
            cin >> role;

            // Гараас авсан нэр, албан тушаалыг string-ээс char хүснэгт рүү хувиргана
            char *nameChar = new char[name.length() + 1];
            strcpy(nameChar, name.c_str());
            char *roleChar = new char[role.length() + 1];
            strcpy(roleChar, role.c_str());

            // Ажилласан цагийн утга, цагийн орлогыг гараас авна
            cout << "Ajillasan tsag: ";
            cin >> work_time;
            cout << "Tsagiin orlogo: ";
            cin >> hourly_rate;

            // Шинэ ажилтны объектын санах ойг динамикаар нөөцөлнө
            workers[i++] = new employee(id, nameChar, roleChar, work_time, hourly_rate);

            // Санах ойг чөлөөлнө
            delete nameChar;
            delete roleChar;

            // Амжилттай болсныг мэдээлнэ
            cout << "Successful" << endl
                 << endl;
        }
        else if (choice == 2)
        {
            // Цалингаар эрэмбэлэх функц руу ажилтны мэдээлэлтэй объектын хүснэгт, тоог дамжуулж өгнө
            employeeBusiness::wage_sort(workers);
        }
        else if (choice == 3)
        {
            // Нэрээр эрэмбэлэх функц руу ажилтны мэдээлэлтэй объектын хүснэгт, тоог дамжуулж өгнө
            employeeBusiness::name_sort(workers);
        }
        else if (choice == 4)
        {
            // Ажилтны мэдээлэл байхгүй бол мэдээлнэ
            if (employee::get_employee_count() == 0)
            {
                cout << "No employee data" << endl;
            }

            // Ажилтны мэдээлэл байвал хэвлэнэ
            for (int n = 0; n < employee::get_employee_count(); n++)
            {
                cout << endl;
                workers[n]->printData();
            }
        }
        else if (choice == 9)
        {
            // Программаас гарахдаа бүх нөөцөлсөн санах ойг чөлөөлнө
            for (int m = 0; m < i; m++)
            {
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