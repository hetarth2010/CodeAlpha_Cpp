#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert grade into grade points
float getGradePoint(char grade) {
    switch (grade) {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 6.0;
        case 'D': return 4.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

int main() {
    int semesters;
    cout << "Enter number of semesters: ";
    cin >> semesters;

    float overallCredits = 0, overallGradePoints = 0;

    for (int s = 1; s <= semesters; s++) {
        int n;
        cout << "\nEnter number of courses in Semester " << s << ": ";
        cin >> n;

        float totalCredits = 0, totalGradePoints = 0;

        cout << "\n--- Enter Course Details ---\n";

        for (int i = 1; i <= n; i++) {
            char grade;
            float credits;

            cout << "\nCourse " << i << endl;
            cout << "Enter Grade (A, B, C, D, F): ";
            cin >> grade;
            cout << "Enter Credit Hours: ";
            cin >> credits;

            float gradePoint = getGradePoint(grade);

            totalCredits += credits;
            totalGradePoints += gradePoint * credits;

            cout << "Grade Point: " << gradePoint << endl;
        }

        float gpa = totalGradePoints / totalCredits;

        cout << fixed << setprecision(2);
        cout << "\nSemester " << s << " GPA: " << gpa << endl;

        overallCredits += totalCredits;
        overallGradePoints += totalGradePoints;
    }

    float cgpa = overallGradePoints / overallCredits;

    cout << "\n=============================";
    cout << "\nFinal Overall CGPA: " << cgpa << endl;
    cout << "=============================";

    return 0;
}