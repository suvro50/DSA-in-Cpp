
#include<iostream>
#include<string>
using namespace std;

struct student {
    string name;
    double cgpa;
    string Date_of_birth;

    student() {}
    student(string name, double cgpa, string Date_of_birth) {
        this->name = name;
        this->cgpa = cgpa;
        this->Date_of_birth = Date_of_birth;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "cgpa: " << cgpa << endl;
        cout << "Date of Birth: " << Date_of_birth << endl;
    }

    // Simple function to convert date (DD/MM/YYYY) to comparable format (YYYYMMDD)
    string convert_date_for_compare(const string &date) const {
        string day = date.substr(0, 2);    // First 2 characters (day)
        string month = date.substr(3, 2);  // Characters 3-4 (month) 
        string year = date.substr(6, 4);   // Last 4 characters (year)
        
        return year + month + day;  // Return as YYYYMMDD for proper comparison
    }
};

void swapd(student &a, student &b) {
    student temp = a;
    a = b;
    b = temp;
}

void Bubble_sort(student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swp = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].cgpa < s[j + 1].cgpa) {
                swapd(s[j], s[j + 1]);
                swp = true;
            }
            else if (s[j].cgpa == s[j + 1].cgpa) {
                string date1 = s[j].convert_date_for_compare(s[j].Date_of_birth);
                string date2 = s[j + 1].convert_date_for_compare(s[j + 1].Date_of_birth);
                if (date1 > date2) {  // Older students (smaller date values) should come first
                    swapd(s[j], s[j + 1]);
                    swp = true;
                }
            }
        }
        if (!swp) break;
    }
}

// Search student by their CGPA
int Binary_search(student s[], int n, double key) {
    int start = 0;
    int end = n - 1;
    int result=-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (s[mid].cgpa == key) {
            result=mid; // Store potential result
            end = mid - 1; // Continue searching left for first occurrence
        }
        else if (key > s[mid].cgpa) {
            end = mid - 1; // Since array is sorted in descending order
        }
        else {
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    int n;
    string name;
    double cgpa;
    string date;

    cout << "Enter number of student: ";
    cin >> n;

    student s[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter info for student num " << i + 1 << endl;
        
        cout << "Enter name: ";
        cin>>name;

        cout << "Enter cgpa: ";
        cin >> cgpa;

        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> date;

        s[i] = student(name, cgpa, date);
    }

    Bubble_sort(s, n);

    cout << endl << "After sorting: " << endl;

    for (int i = 0; i < n; i++) {
        s[i].print();
        cout << endl;
    }

    double key;
    cout << "Enter cgpa for searching student: " << endl;
    cin >> key;

    int result = Binary_search(s, n, key);

    if (result != -1) {
        for (int i = result; i < n && s[i].cgpa == key; i++) {
            s[i].print();
            cout << endl;
        }
    }else cout << "No student found" << endl; // Fixed typo


    return 0;
}
