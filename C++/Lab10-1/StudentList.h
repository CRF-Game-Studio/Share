#pragma once
#include "Student.h"

class StudentList
{	
public:
	StudentList(void);
	~StudentList(void);
	void appendEntry(Student *);
    bool deleteEntry(char *);
    Student *find(char *);
	
private:
	class Node
    {
    public:
       Node(Student *);
	   Node(void);
       ~Node();
	   friend class StudentList;
    private:
        Student *m_data;
        Node *m_next;
    };
    Node *m_head, *m_tail;
};

