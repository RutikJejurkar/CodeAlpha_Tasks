# include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of coureses : ";
    cin>>n;

    float credit [10], gradePoint [10];
    float totalCredits = 0, totalGradePoints = 0;


    for(int i=0; i<n; i++)
    {
        char grade;
        cout << "\nEnter grade for course " <<i+1<<"(A/B/C/D/F): ";
        cin>>grade;

        cout<<"Enter credit hours: ";
        cin >> credit[i];

        if(grade == 'A' || grade == 'a')
            gradePoint[i] = 10;

        else if(grade == 'B' || grade == 'b')
            gradePoint[i] = 9;

        else if(grade == 'C' || grade == 'c')
            gradePoint[i] = 8;

        else if(grade == 'D' || grade == 'd')
            gradePoint[i] = 7;

        else
            gradePoint[i] = 0;

        totalCredits += credit[i];
        totalGradePoints +=gradePoint[i] * credit[i];
    }


    float cgpa = totalGradePoints / totalCredits;

    cout << "----* RESULT *----"<<endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "CGPA: "<< cgpa;

    return 0;
}