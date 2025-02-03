#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// ==================== کلاس‌ها ====================
class Student {
public:
    string firstName;
    string lastName;
    string fatherName;
    string birthDate;
    string nationalCode;
    string fieldOfStudy;
    vector<string> registeredCourses;

    void saveToFile() {
        ofstream file("student_data.txt");
        file << firstName << "\n"
             << lastName << "\n"
             << fatherName << "\n"
             << birthDate << "\n"
             << nationalCode << "\n"
             << fieldOfStudy << "\n";
        file << registeredCourses.size() << "\n";
        for (auto& course : registeredCourses) {
            file << course << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file("student_data.txt");
        if (file) {
            getline(file, firstName);
            getline(file, lastName);
            getline(file, fatherName);
            getline(file, birthDate);
            getline(file, nationalCode);
            getline(file, fieldOfStudy);
            
            int courseCount;
            file >> courseCount;
            file.ignore();
            registeredCourses.clear();
            for (int i = 0; i < courseCount; i++) {
                string course;
                getline(file, course);
                registeredCourses.push_back(course);
            }
            file.close();
        }
    }

    void displayProfile() {
        system("cls");
        cout << "=== Student Profile ===" << endl
             << "First Name: " << firstName << endl
             << "Last Name: " << lastName << endl
             << "Father's Name: " << fatherName << endl
             << "Birth Date: " << birthDate << endl
             << "National Code: " << nationalCode << endl
             << "Field of Study: " << fieldOfStudy << endl
             << "Registered Courses: " << registeredCourses.size() << endl;
    }
};

// ==================== توابع کمکی ====================
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore();
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "!ورودی نامعتبر - لطفا عدد وارد کنید" << endl;
    }
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// ==================== سیستم آموزشی ====================
class CourseManager {
public:
    vector<string> availableCourses = {
        "Physics 1 (3 units)",
        "Calculus (4 units)",
        "Programming (3 units)",
        "Literature (2 units)",
        "English (2 units)"
    };

    void showCourses(Student& student) {
        system("cls");
        cout << "=== Available Courses ===" << endl;
        for (int i = 0; i < availableCourses.size(); i++) {
            cout << i+1 << ". " << availableCourses[i] << endl;
        }
        
        int choice = getIntInput("\nEnter course number to register (0 to cancel): ");
        if (choice > 0 && choice <= availableCourses.size()) {
            student.registeredCourses.push_back(availableCourses[choice-1]);
            cout << "!ثبت نام با موفقیت انجام شد" << endl;
        }
        cin.ignore();
    }
};

// ==================== سیستم مالی ====================
class FinanceManager {
public:
    vector<pair<string, double>> payments = {
        {"Tuition Fee", 5000000},
        {"Dormitory Fee", 2000000},
        {"Library Fee", 500000}
    };

    void showPayments() {
        system("cls");
        cout << "=== Financial Status ===" << endl
             << left << setw(25) << "Item" << setw(15) << "Amount" << endl
             << "---------------------------------" << endl;
        
        for (auto& [item, amount] : payments) {
            cout << setw(25) << item 
                 << setw(15) << fixed << setprecision(0) << amount 
                 << " IRR" << endl;
        }
        cout << "\n";
    }
};

// ==================== سیستم منوها ====================
void showMainMenu(Student& student) {
    CourseManager courseManager;
    FinanceManager financeManager;

    while (true) {
        system("cls");
        cout << "=== سیستم مدیریت دانشجویی ===" << endl
             << "1. ثبت نام دروس" << endl
             << "2. مشاهده نمرات" << endl
             << "3. وضعیت مالی" << endl
             << "4. پروفایل دانشجویی" << endl
             << "5. خروج و ذخیره اطلاعات" << endl;

        int choice = getIntInput(":گزینه مورد نظر را انتخاب کنید ");
        
        switch (choice) {
            case 1:
                courseManager.showCourses(student);
                break;
            case 3:
                financeManager.showPayments();
                break;
            case 4:
                student.displayProfile();
                break;
            case 5:
                student.saveToFile();
                cout << "!اطلاعات با موفقیت ذخیره شد" << endl;
                exit(0);
            default:
                cout << "!گزینه نامعتبر" << endl;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
    }
}

// ==================== تابع اصلی ====================
int main() {
    Student student;
    
    // بارگذاری اطلاعات ذخیره شده
    try {
        student.loadFromFile();
        cout << "!اطلاعات قبلی با موفقیت بارگذاری شد" << endl;
    } catch (...) {
        cout << "!هیچ اطلاعات ذخیره شده ای یافت نشد" << endl;
    }

    // ورود اطلاعات اولیه
    if (student.firstName.empty()) {
        system("cls");
        cout << "=== ثبت اطلاعات اولیه ===" << endl;
        student.firstName = getStringInput("نام: ");
        student.lastName = getStringInput("نام خانوادگی: ");
        student.fatherName = getStringInput("نام پدر: ");
        student.birthDate = getStringInput("تاریخ تولد (1402/05/15): ");
        student.nationalCode = getStringInput("کد ملی: ");
        student.fieldOfStudy = getStringInput("رشته تحصیلی: ");
    }

    showMainMenu(student);
    return 0;
}