#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Skill {
public:
    int skillID;
    string skillName;
    string description;
   
    Skill(int id, const string& name, const string& desc)
    {
        skillID = id;
        skillName = name;
        description = desc;
    }
   
    void showSkillDetails()
    {
        cout << "Skill ID: " << skillID << endl <<  "Skill Name: " << skillName << endl <<"Description: " << description << endl;
    }
   
    void updateSkillDescription(const string& newDescription)
    {
        description = newDescription;
    }
};



class Sport {
public:
    int sportID;
    string name;
    string description;
    Skill* requiredSkills[10];
    int skillCount;
   
    Sport(int id, const string& n, const string& desc)
    {
        sportID = id;
        name = n;
        description = desc;
        skillCount = 0;
    }
   
    void addSkill(Skill* s)
    {
        if (skillCount < 10)
        {
            requiredSkills[skillCount++] = s;
        }
    }
   
    void removeSkill(int skillID)
    {
        for (int i = 0; i < skillCount; i++)
        {
            if (requiredSkills[i]->skillID == skillID)
            {
                for (int j = i; j < skillCount - 1; j++)
                {
                    requiredSkills[j] = requiredSkills[j + 1];
                }
                skillCount--;
                break;
            }
        }
    }
};



class Mentor;


class Student {
public:
    int studentID;
    string name;
    int age;
    Sport* sportsInterests[5];
    int sportCount;
    Mentor* mentorAssigned;
   
    Student(int id, const string& n, int a)
    {
        studentID = id;
        name = n;
        age = a;
        sportCount = 0;
        mentorAssigned = NULL;
    }
   
    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(Sport* s)
    {
        if (sportCount < 5)
        {
            sportsInterests[sportCount++] = s;
        }
    }
};



class Mentor {
public:
    int mentorID;
    string name;
    Sport* sportsExpertise[5];
    int sportExpCount;
    int maxLearners;
    Student* assignedLearners[5];
    int learnerCount;
   
    Mentor(int id, const string& n, int maxL)
    {
        mentorID = id;
        name = n;
        maxLearners = maxL;
        learnerCount = 0;
        sportExpCount = 0;
    }
   
    void assignLearner(Student* s)
    {
        if (learnerCount < maxLearners)
        {
            assignedLearners[learnerCount++] = s;
            s->mentorAssigned = this;
        }
        else
        {
            cout << "Mentor is already teaching " << maxLearners << " students" << endl;
        }
    }
   
    void removeLearner(Student* s)
    {
        for (int i = 0; i < learnerCount; i++)
        {
            if (assignedLearners[i] == s)
            {
                for (int j = i; j < learnerCount - 1; j++)
                {
                    assignedLearners[j] = assignedLearners[j + 1];
                }
                learnerCount--;
                s->mentorAssigned = NULL;
                break;
            }
        }
    }
   
    void viewLearners()
    {
        cout << "Mentor: " << name << "\nAssigned Learners:" << endl;
        for (int i = 0; i < learnerCount; i++)
        {
            cout << assignedLearners[i]->name << endl;
        }
    }
   
    void provideGuidance()
    {
        cout << name << " is providing guidance to learners." << endl;
    }
};



void Student::registerForMentorship(Mentor* m)
{
    if (m->learnerCount < m->maxLearners)
    {
        m->assignLearner(this);
    }
    else
    {
        cout << "Mentor is already teaching " << m->maxLearners << " students" << endl;
    }
}



void Student::viewMentorDetails()
{
    if (mentorAssigned)
    {
        cout << "Mentor Assigned: " << mentorAssigned->name << endl;
    }
    else
    {
        cout << "No mentor assigned yet." << endl;
    }
}





int main()
{
    Mentor m1(1, "Ali", 3);
    Student s1(101, "Saad", 20);
    Student s2(102, "Anas", 22);
    Student s3(103, "Hasan", 21);
    Student s4(104, "Nafees", 19);
   
    s1.registerForMentorship(&m1);
    s2.registerForMentorship(&m1);
    s3.registerForMentorship(&m1);
    s4.registerForMentorship(&m1);
   
    m1.viewLearners();
   
    s1.viewMentorDetails();
    m1.removeLearner(&s1);
   
    m1.viewLearners();
   
    return 0;
}
