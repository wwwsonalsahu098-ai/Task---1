#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course{
    string name;
    string grade;
    double credits;
};

double gradeToPoint(string g){
    if(g=="A+") return 4.0;
    if(g=="A") return 4.0;
    if(g=="B+") return 3.5;
    if(g=="B") return 3.0;
    if(g=="C") return 2.0;
    if(g=="D") return 1.0;
    return 0.0;
}

int main(){
    int n;
    cout<<"===== CGPA CALCULATOR =====\n";
    cout<<"Enter number of courses: ";
    cin>>n;

    vector<Course> courses(n);
    double totalCredits=0,totalPoints=0;

    for(int i=0;i<n;i++){
        cout<<"\nCourse "<<i+1<<" Name: ";
        cin>>courses[i].name;
        cout<<"Grade (A+,A,B+,B,C,D,F): ";
        cin>>courses[i].grade;
        cout<<"Credit Hours: ";
        cin>>courses[i].credits;

        totalCredits += courses[i].credits;
        totalPoints += gradeToPoint(courses[i].grade)*courses[i].credits;
    }

    cout<<"\n----- COURSE REPORT -----\n";
    for(auto &c:courses){
        cout<<c.name<<" | "<<c.grade<<" | Credits: "<<c.credits<<"\n";
    }

    cout<<fixed<<setprecision(2);
    cout<<"\nTotal Credits: "<<totalCredits;
    cout<<"\nCGPA: "<<totalPoints/totalCredits<<endl;
    return 0;
}
