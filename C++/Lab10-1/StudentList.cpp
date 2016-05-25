#include "StudentList.h"


StudentList::StudentList(void)
{
}


StudentList::~StudentList(void)
{
	Node *tmp, *n = m_head;
	while (n != NULL) {
		tmp = n;
		n = n->m_next;
		delete tmp;
	}
}

StudentList::Node::Node(Student *data)
	:m_next(NULL)
{
	m_data = data;
}

StudentList::Node::Node() : m_data(NULL), m_next(NULL) 
{
}

StudentList::Node::~Node(void)
{
	delete m_data;
}

void StudentList::appendEntry(Student *student){
	m_tail->m_next = new Node(student);
	m_tail = m_tail->m_next;
}

Student *StudentList::find(char *id){
	Node *ptr;
    for (ptr = m_head; ptr != 0; ptr = ptr->m_next)
        if (ptr->m_data->IDEquals(id))
            return ptr->m_data;
    return NULL;
}

bool StudentList::deleteEntry(char *id){
	Node *ptr1,*ptr2;
	if(m_head == NULL && m_tail == NULL){
		return false;
	}
	else if(m_head == m_tail){
		if (m_head->m_data->IDEquals(id)){
			delete m_head;
			m_head = m_tail = 0;
			return true;
		}
		return false;
	}
	else {
		if (m_head->m_data->IDEquals(id)){
			ptr1 = m_head;
			m_head = m_head->m_next;
			delete ptr1;
			return true;
		}
		for (ptr2 = m_head, ptr1 = m_head->m_next; ptr1 != 0; ptr2 = ptr1, ptr1 = ptr1->m_next)
			if (ptr1->m_data->IDEquals(id)){
				ptr2->m_next = ptr1->m_next;
				if (ptr1 == m_tail)
					m_tail = ptr2;
				delete ptr1;
				return true;
			}
		return false;
	}

}

