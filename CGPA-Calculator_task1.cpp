#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Course{
    string name;
    double creditsHours;
    double score;
};

double scoreToPoints(double score){
    if (score >= 85) return 4.0;
    else if(score >= 80) return 3.7;
    else if(score >= 75) return 3.3;
    else if(score >= 70) return 3.0;
    else if(score >= 65) return 2.7;
    else if(score >= 61) return 2.3;
    else if(score >= 58) return 2.0;
    else if(score >= 55) return 1.7;
    else if(score >= 50) return 1.0;
    else return 0.0;
}

string scoreToGrade(double score){
    if(score >= 85) return "A";
    else if(score >= 80) return "A-";
    else if(score >= 75) return "B+";
    else if(score >= 70) return "B";
    else if(score >= 65) return "B-";
    else if(score >= 61) return "C+";
    else if(score >= 58) return "C";
    else if(score >= 55) return "C-";
    else if(score >= 50) return "D";
    else return "F";
}

double calculateGPA(vector<Course> courses, int numCourses){
    double totalPoints =0.0;
    double totalCredits = 0.0;

    for(int i = 0; i < numCourses; i++){
        totalPoints += scoreToPoints(courses[i].score) * courses[i].creditsHours;
        totalCredits += courses[i].creditsHours;
    }
    
    return totalPoints / totalCredits;

}

int main(){
    int semesters;
    cout << "Enter the number of semesters: ";
    cin >> semesters;

    double totalCredits = 0.0;
    double totalWeightedGPA = 0.0;
    
    for( int i = 1; i <= semesters; i++){
        cout << endl << "Semester " << i << " " << endl;

        int numCourses;
        cout << "Enter the number of courses per semester: ";
        cin >> numCourses;
        cin.ignore(); 

        vector<Course> courses(numCourses);

        double semCredits = 0.0;
        for(int j = 0; j < numCourses; j++){
            cout << "Enter Course Name: ";
            getline(cin, courses[j].name);

            cout << "Enter Score: ";
            cin >> courses[j].score;

            cout << "Enter Credit Hours: ";
            cin >> courses[j].creditsHours; 
            cin.ignore(); 

            semCredits += courses[j].creditsHours;
        }

        cout << endl << "Course  Score  Grade   CR      PTS" << endl << endl;
        for(int j = 0; j < numCourses; j++){
            cout << courses[j].name << "    |  "  << courses[j].score << "  |  " << scoreToGrade(courses[j].score) << "  |  " << courses[j].creditsHours << " cr  |  " << scoreToPoints(courses[j].score) << " pts   " << endl;
        }

        double sgpa = calculateGPA(courses, numCourses);
        cout << "Semester GPA: " << fixed << setprecision(2) << sgpa << endl;
        
        totalWeightedGPA += sgpa * semCredits;
        totalCredits += semCredits;
    }
    
    double cgpa = totalWeightedGPA / totalCredits;
    cout << endl << "CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}