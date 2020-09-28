using namespace std;

struct student{
	long id;
	string firstname;
	string lastname;
	string major;
};

student * create_student_db(int);
void populate_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student **, int);
void swap(int &a, int &b);