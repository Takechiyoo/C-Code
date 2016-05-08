#include<iostream>

using namespace std;

class Course
{
public:
    string course_name;
    double course_grade;
    Course(string name, double grade)
    {
        course_name = name;
        course_grade = grade;
    }
};

class Student
{
private:
    string ID;
    string name;
    Course *courses[5];
    double sum;
public:
    Student(string id, string n)
    {
        ID = id;
        name = n;
        sum = 0.0;
    }
    void get_courses()
    {
        string course_name[5];
        double grade[5];
        cout << "Please input the course name and course grade:" << endl;
        for(int i = 0; i < 5; i++)
        {
            cin >> course_name[i] >> grade[i];
            courses[i] = new Course(course_name[i], grade[i]);
        }
        /*
        for(int i = 0; i < 5; i++)
        {
            string course_name;
            double grade;
            cout << "Please input the " << i+1 << " course name and course grade:" << endl;
            cin >> course_name >> grade;
            courses[i] = new Course(course_name, grade);
        }
        */
    }
    double avearge()
    {
        sum = 0;
        get_sum();
        return sum / 5;
    }
    double get_sum()
    {
        for(int i = 0; i < 5; i++)
            sum += courses[i]->course_grade;
        return sum;
    }
    string get_id()
    {
        return ID;
    }
    string get_name()
    {
        return name;
    }
};

void less_average(Student **s)
{
    cout << "Average less 70:" << endl;
    for(int i = 0; i < 5; i++)
    {
        if(s[i]->avearge() < 70)
            cout << s[i]->get_id() << " " << s[i]->get_name() << endl;
    }
}

void sort_students(Student **s)
{
    Student *temp;
    for(int j = 0; j < 5; j++)
        for(int i = 0; i < 5-1-j; i++)
        {
            if(s[i]->get_sum() < s[i+1]->get_sum())
            {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    cout << "Sorted students info:" <<endl;
    for(int i = 0; i < 5; i++)
        cout << s[i]->get_id() << " " << s[i] ->get_name() << endl;
}

int main()
{

    Student *students[5];
    for(int i = 0; i < 5; i++)
    {
        string id, name;
        cout << "Please input " << i+1 <<" student's ID and name:" << endl;
        cin >> id >> name;
        students[i] = new Student(id, name);
        students[i]->get_courses();
    }
    less_average(students);
    sort_students(students);
	return 0;

}



