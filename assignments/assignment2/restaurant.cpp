#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "restaurant.h"

using namespace std;

/*********************************************************************
** Function:default constructor
** Description: initializes initial values
** Parameters: -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
//reads from files to correctly populate menu, employees, hours, etc.
Restaurant::Restaurant(){
    cout << "RESTAURANT DEFAULT CONSTRUCTOR CALLED\n";
    this->num_employee = 0;
    this->orders = NULL;
    this->employees = NULL;
    this->week = NULL;
    this->name = "";
    this->phone = "";
    this->address = "";
}
/*********************************************************************
** Function:deconstructor
** Description: deletes remaining memory
** Parameters: -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Restaurant::~Restaurant(){
    cout << "RESTAURANT DESTRUCTOR CALLED\n";
    delete[] this->orders;
    delete[] this->employees;
    delete[] this->week;
    this->employees = NULL;
    this->week = NULL;
}

/*********************************************************************
** Function:    copy constructor 
** Description: copies classes
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/ 
Restaurant::Restaurant(const Restaurant& old_obj){
    cout << "RESTAURANT COPY CONSTRUCTOR CALLED\n";
    this->orders = old_obj.orders;
    this->num_employee = old_obj.num_employee;
    this->menu = old_obj.menu;
    // this->employees = old_obj.employees;
    this->employees = old_obj.employees;
    // this->week = new week;
    this->week = old_obj.week;
    this->name = old_obj.name;
    this->phone = old_obj.phone;
    this->address = old_obj.address;
}

/*********************************************************************
** Function:    Assignment Operator Overload
** Description: assign a class to be another class
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: -
*********************************************************************/  
Restaurant& Restaurant::operator=(const Restaurant old_obj){
    cout << "RESTAURANT AOO CALLED\n";
    if(this != &old_obj){
        cout << "RESTAURANT AOO ASSIGNMENT CALLED";
        this->orders = old_obj.orders;
        this->num_employee = old_obj.num_employee;
        this->menu = old_obj.menu;
        // if(this->employees == NULL)
        //     this->employees = new employees;
        this->employees = old_obj.employees;
        // if(this->week == NULL)
        //     this->week = new week;
        this->week = old_obj.week;
        this->name = old_obj.name;
        this->phone = old_obj.phone;
        this->address = old_obj.address;
    }
}

/*********************************************************************
** Function:    store_pizza
** Description: stores pizzas for order
** Parameters:  Menu men, string c, string* selection, int& selection_size, int* num_ordered, string* piz_size
** Pre-Conditions:  
** Post-Conditions: get num_orders
*********************************************************************/ 
void Restaurant::store_pizza(Menu men, string c, string* selection, int& selection_size, int* num_ordered, string* piz_size){
    string sizes[] = {"Small", "Medium", "Large"};
    int quantity =  0;
    if(is_digits(c)){
        if(stoi(c) > 0 && stoi(c) < men.get_num_pizzas()*3){
            while(quantity < 1){
                cout << "How many "<< sizes[(stoi(c)-1)%3]
                    << " " << men.get_pizzas()[(stoi(c)-1)/3].get_name() << "(integer more than 0)? ";
                cin >> quantity;
                cin.ignore();
            }
            selection[selection_size] = men.get_pizzas()[(stoi(c)-1)/3].get_name();
            num_ordered[selection_size] = quantity;
            if((stoi(c)-1)%3 == 0)
                piz_size[selection_size] = " S";
            if((stoi(c)-1)%3 == 1)
                piz_size[selection_size] = " M";
            if((stoi(c)-1)%3 == 2)
                piz_size[selection_size] = " L";
            selection_size++;
        }
    }
}

/*********************************************************************
** Function:    get_num_orders
** Description: return num_orders
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: get num_orders
*********************************************************************/ 
void Restaurant::display_results(int& label, Menu men){
    string sizes[] = {"Small", "Medium", "Large"};
    for(int i = 0; i < men.get_num_pizzas(); i++){
        cout << "Men pizzas IS " << men.get_num_pizzas() << endl;
        for(int j = 0; j < 3; j++){
            cout << "(" << label++ << ")\t" << sizes[j] << " " << men.get_pizzas()[i].get_name() 
                << " - $";
                if(j == 0)
                    cout << men.get_pizzas()[i].get_small_cost() << endl;
                if(j == 1)
                    cout << men.get_pizzas()[i].get_medium_cost() << endl;
                if(j == 2)
                    cout << men.get_pizzas()[i].get_large_cost() << endl;
        }
    }
}

/*********************************************************************
** Function:    get_num_orders
** Description: return num_orders
** Parameters:  -
** Pre-Conditions:  -
** Post-Conditions: get num_orders
*********************************************************************/ 
void Restaurant::customer_order(Menu men){
    string *pizza_orders = new string[men.get_num_pizzas()*3], 
    *piz_size = new string[men.get_num_pizzas()*3];
    string choice = "-1";
    int label = 1, selection_size = 0, *num_ordered = new int[256];
    display_results(label, men);
    while(choice != "0" && choice != ""){
        cout << "Please select an option from the list above. \nYou may also enter 0 to cancel this order "
            "or press enter (blank line) to proceed to checkout.\nYour selection: ";
        getline(cin, choice);
        this->store_pizza(men, choice, pizza_orders, selection_size, num_ordered, piz_size);
    }
    if(choice == "0"){
        delete[] num_ordered; num_ordered = NULL;
        delete[] piz_size; piz_size = NULL;
        delete[] pizza_orders; pizza_orders = NULL;
        return;
    }
    place_order(pizza_orders, selection_size, num_ordered, piz_size);
    delete[] pizza_orders; pizza_orders = NULL;
    delete[] piz_size; piz_size = NULL;
    delete[] num_ordered; num_ordered = NULL;
}


void Restaurant::customer_menu(){
    string usr;
    while(true){
        cout << "What would you like to do?\n 1. View Menu\n 2. Search by Cost\n 3. Search by Ingredients"
            "\n 4. Place Order\n 5. View Hours\n 6. View Address\n 7. View Phone\n 8. Log out\nSelection: ";
        getline(cin, usr);
        cout << endl;
        if(usr == "1")
            this->view_menu();
        if(usr == "2");
        if(usr == "3")
            this->search_by_ingredients();
        if(usr == "4")
            customer_order(this->menu);
        if(usr == "5")
            this->view_hours();
        if(usr == "6")
            this->view_address();
        if(usr == "7")
            this->view_phone();
        if(usr == "8")
            return;
    }
}


bool Restaurant::employee_selection(){
    string usr;
    while(true){
        cout << "What would you like to do?\n 1. Change hours\n 2. View orders\n 3. Remove order"
            "\n 4. Add Item to Menu\n 5. Remove Item from Menu\n 6. View Menu\n 7. View Hours\n"
            " 8. View Address\n 9. View Phone\n 10. Log out\nSelection:";
        getline(cin, usr);
        cout << endl;
        if(usr == "1")
            this->change_hours();
        if(usr == "2")
            this->view_orders();
        if(usr == "3")
            this->remove_orders();
        if(usr == "4")
            this->add_to_menu();
        if(usr == "5")
            this->remove_from_menu ();
        if(usr == "6")
            this->view_menu();
        if(usr == "7")
            this->view_hours();
        if(usr == "8")
            this->view_address();
        if(usr == "9")
            this->view_phone();
        if(usr == "10")
            return false;
    }
}


void Restaurant::Employee_menu(){
    string id, password;
    do{
        cout << "Please enter your ID number: ";
        getline(cin, id);
        cout << "Please enter your password: ";
        getline(cin, password);
    }while(!login(id, password));
    cout << "Welcome "<< this->employees[this->employee_logedin].first_name << " " 
        << this->employees[this->employee_logedin].last_name << "!\n";
    this->employee_selection();
}


void Restaurant::main_menu(){
    string choice = "abc";
    this->load_data();
    while(choice != "Q"){
        cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";
        getline(cin, choice);
        if(choice == "C")
            this->customer_menu();
        if(choice == "E")
            this->Employee_menu();
    }
    cout << "Bye!\n";
}


string Restaurant::get_name(){
    return this->name;
}


void Restaurant::set_name(string name){
    this->name = name;
}


void Restaurant::set_phone(string phone){
    this->phone = phone;
}


void Restaurant::set_address(string address){
    this->address = address;
}


void Restaurant::load_pizza(ifstream &fin){
    cout << "Menu.txt OPENED\n";
    if(fin.is_open()){
        this->menu.populate_pizzas(fin);
    }
    else{
        cout << "unable to open menu.txt file\n";
        exit(1);
    }
}


void Restaurant::load_employee(ifstream& fin){
    int capacity= 1;
    this->employees = new employee[1];
    string str;
    while(fin >> str){
        if(fin.eof())
            break;
        if(this->num_employee == capacity)
            this->resize_employee(capacity);
        this->employees[this->num_employee].id = stoi(str);
        fin >> this->employees[this->num_employee].password;
        fin >> this->employees[this->num_employee].first_name;
        fin >> this->employees[this->num_employee].last_name;
        ++this->num_employee;
    }
    fin.close();
}


void Restaurant::load_orders(ifstream& fin){
    if(fin.is_open()){
        cout << "OPENED ORDERS.TXT" << endl;
        string temp;
        fin >> temp;
        while(true){ 
            cout << "READING FROM ORDER.TXT" << endl;
            if(fin.eof()){
                break;
            }
            cout << "ORDER.TXT NOT AT EOF" << endl;
            this->upsize_Orders();
            cout << "ORDER UPSIZED!!!!!!!!!!!!!!" << endl;
            this->orders[this->orders->get_num_orders()-1].set_from_file(fin, temp);
        }
        fin.close();
    }
    else{
        cout << "unable to open orders.txt file\n";
        exit(1);
    }
}


void Restaurant::load_data(){
    ifstream fin;
    fin.open("menu.txt");
    this->load_pizza(fin);
    fin.open("restaurant_info.txt");
    this->load_restaurant(fin);
    fin.open("employee.txt");
    this->load_employee(fin);
    fin.open("orders.txt");
    this->load_orders(fin);
}


bool Restaurant::login(string id, string password){
    if(!is_digits(id)){
        cout << "Incorrect ID or password. Please try again.\n";
        return false;
    }
    for(int i = 0; i < this->num_employee; i++){
        if(this->employees[i].id == stoi(id)){
            if(this->employees[i].password == password){
                this->employee_logedin = i;
                return true;
            }
        }
    }
    cout << "Incorrect ID or password. Please try again.\n";
    return false;
}


void Restaurant::view_menu(){
    cout << "VIEW MENU" << endl;
    for(int i = 0; i < this->menu.get_num_pizzas(); ++i){
        cout << i + 1 << ": ";
        this->menu.display_pizzas(i);
    }
}


void Restaurant::view_hours(){
    // TESTIGNGGGGG
    // cout << "STRING IS: " << this->week[0].open_hour << endl;
    for(int i = 0; i < 7; ++i){
        if(this->week[i].open_hour != ""){
            cout << this->week[i].day << " ";
            cout << this->week[i].open_hour << " ";
            cout << this->week[i].close_hour << endl;
        }
    }
}


void Restaurant::view_address(){
    cout << this->address << endl;
}


void Restaurant::view_phone(){
    cout << this->phone << endl;
}


void Restaurant::search_menu_by_price(){
    string temp;
    Menu searched;
    int budget, n_orders;
    cout << "What is your maximum budget (in dollars)? ";
    cin >> budget;
    searched = this->menu.search_pizza_by_cost(budget);
    cout << "Here are the pizzas that match your criteria. Ineligible sizes are"
        "marked as N/A:" << endl;
    searched.display_pizzas();
    cout << endl << "Would you like to place an order off this search result (Yes/No)? ";
    cin >> temp;
    if(temp == "Yes"){
        // this->add_to_orders(searched.display_results(n_orders), n_orders);
    }
}


bool Restaurant::include_ingredients_from_usr(string* including, int &num_including){
    string temp;
    string again = "Yes";
    while(again == "Yes"){
        cout << "What item would you like to include? ";
        getline(cin, temp);
        including[num_including++] = temp;
        cout << "Do you want to include another item (Yes/No)? ";
        getline(cin, again);
    }
    cout << "Would you like to reduce your search by excluding some ingredients(Yes/No)? ";
    getline(cin,temp);
    if(temp == "Yes")
        return true;
    return false;
}


bool Restaurant::exclude_ingredients_from_usr(string* excluding, int &num_excluding){
    string temp;
    string again = "Yes";
    while(again == "Yes"){
        cout << "What item would you like to exclude? ";
        getline(cin, temp);
        excluding[num_excluding++] = temp;
        cout << "Do you want to exclude another item (Yes/No)? ";
        getline(cin, again);
    }
    cout << "Would you like to reduce your search by including some ingredients(Yes/No)? ";
    getline(cin,temp);
    if(temp == "Yes")
        return true;
    return false;
}


void Restaurant::evaluate_include_exclude_ingredients(string* including, int& num_including
    , string* excluding, int& num_excluding){
    bool contain;
    Menu temp = this->menu;
    for(int i = 0; i < num_excluding; i++){
        for(int p = temp.get_num_pizzas(); p >= 0; p--){
            for(int j = 0; j < temp.get_pizzas()[p].get_num_ingredients(); j++){
                if(excluding[i] == temp.get_pizzas()[p].get_ingredients()[j]){
                    temp.remove_from_menu(p);
                }
            }
        }
    }
    for(int i = 0; i < num_including; i++){
        for(int p = temp.get_num_pizzas(); p >= 0; p--){
            contain = false;
            for(int j = 0; j < temp.get_pizzas()[p].get_num_ingredients(); j++){
                if(including[i] == temp.get_pizzas()[p].get_ingredients()[j]){
                    cout << including[i] << " = " << temp.get_pizzas()[p].get_ingredients()[j] << endl;
                    contain = true;
                    break;
                }
            }
            if(!contain)
                temp.remove_from_menu(p);
        }
    }
    customer_order(temp);
}

void Restaurant::search_by_ingredients(){
    string usr;
    string *including = new string[100], *excluding = new string[100];
    int num_including = 0, num_excluding = 0;
    cout << "Would you like to search for ingredients you want include (I) or exclude (E)? ";
    getline(cin, usr);
    if(usr == "I"){
        if(this->include_ingredients_from_usr(including, num_including))
            this->exclude_ingredients_from_usr(excluding, num_excluding);
    }
    else if(usr == "E"){
        if(this->exclude_ingredients_from_usr(excluding, num_excluding))
            this->include_ingredients_from_usr(including, num_including);
    }
    else{
        cout << "Sorry invalid input." << endl;
    }
    this->evaluate_include_exclude_ingredients(including, num_including, excluding, num_excluding);
    delete[] including; including = NULL;
    delete[] excluding; excluding = NULL;
}



// Only one of the following two prototypes should be used:
// selection is a dynamically allocated array of Pizza objects that are being ordered
// selection_size indicates the number of Pizza objects in the array
// num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
void Restaurant::place_order(string* selection, int selection_size, int* num_ordered, string* piz_size){
    string temp;
    this->upsize_Orders();
    for(int i = 0; i < selection_size; ++i){
        this->orders[this->orders->get_num_orders()-1].upsize_pizzas();
        this->orders[this->orders->get_num_orders()-1].set_pizza_name(selection[i], i);
        this->orders[this->orders->get_num_orders()-1].set_quantity(num_ordered[i], i);
        this->orders[this->orders->get_num_orders()-1].set_size(piz_size[i] ,i);
    }
    cout << "Please provide the following information:\nCustomer name: ";
    cin >> temp;
    this->orders[this->orders->get_num_orders()-1].set_customer_name(temp);
    cout << "Credit card number: ";
    cin >> temp;
    this->orders[this->orders->get_num_orders()-1].set_customer_CC(temp);
    cout << "Phone number: ";
    cin >> temp;
    this->orders[this->orders->get_num_orders()-1].set_customer_phone(temp);
    cout << "Thank you! Your order number is " << this->orders->get_num_orders() << ".\n";
}


// you may also choose to use this prototype:
//void place_order(Pizza* selection);

void Restaurant::change_hours(){
    string day, open, close;
    this->view_hours();
    cout << "Which day would you like to change(type exactly as shown)? ";
    getline(cin, day);
    for(int i = 0; i < 7; i++){
        if(this->week[i].day == day){
            cout << "Enter the new opening hours: ";
            getline(cin, open);
            this->week[i].open_hour = open;
            cout << "Enter the new closing hours: ";
            getline(cin, close);
            this->week[i].close_hour = close;
            return;
        }
    }
    cout << "could not find the day\n.";
}


void Restaurant::add_to_menu_ingredients(){
    string temp;
    int num_ingred = -1;
    while(num_ingred < 1){
        std::cout << "Enter the num_ingredients for the pizza(numbers only): ";
        cin >> num_ingred;
    }
    cin.ignore();
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].allocate_ingredients(num_ingred);
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_num_ingred(num_ingred);
    for(int i = 0; i < num_ingred; ++i){
        cout << "Enter ingredient " << i+1 << ": ";
        getline(cin, temp);
        this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_ingredients(temp, i);
    }
}



void Restaurant::add_to_menu(){
    string temp;
    int cost;
    this->menu.set_num_pizzas(this->menu.get_num_pizzas() + 1);
    cout << "NUM PIZZA ISSSSSSSSS " << this->menu.get_num_pizzas() << endl;
    cout << "Enter the name for the pizza: ";
    getline(cin, temp);
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_name(temp);
    cout << "Enter the small_cost for the pizza(numbers only): ";
    cin >> cost;
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_small_cost(cost);
    cout << "Enter the medium_cost for the pizza(numbers only): ";
    cin >> cost;
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_medium_cost(cost);
    cout << "Enter the large_cost for the pizza(numbers only): ";
    cin >> cost;
    this->menu.get_pizzas()[this->menu.get_num_pizzas()-1].set_large_cost(cost);
    cin.ignore();
    this->add_to_menu_ingredients();
}


void Restaurant::remove_from_menu(){
    this->view_menu();
    int temp;
    cout << "Which pizza would you like to remove? ";
    cin >> temp;
    cin.ignore();
    --temp;
    this->menu.remove_from_menu(temp);
}


void Restaurant::upsize_Orders(){
    Order* temp = new Order[this->orders->get_num_orders() + 1];
    for(int i = 0; i < this->orders->get_num_orders(); ++i){
        temp[i] = this->orders[i];
    }
    delete[] this->orders;
    this->orders = temp;
    temp = NULL;
    this->orders->set_num_orders(this->orders->get_num_orders() + 1);
}


void Restaurant::add_to_orders(Order* order_to_add, int num_orders){
    cout << "ADD TO ORDERS CALLED" << endl;
    for(int i = 0; i < num_orders; ++i){
        cout << "LOOP WITHIN ADD TO ORDERS" << endl;
        this->upsize_Orders();
        this->orders[this->orders->get_num_orders()-1] = order_to_add[i];
    }
}


void Restaurant::view_orders(){
    for(int i = 0; i < this->orders->get_num_orders(); ++i){
        cout << "order_num = " << i+1 << endl;
        this->orders[i].display_orders();
        cout << endl;
    }
}


void Restaurant::remove_orders(){
    int i;
    this->view_orders();
    cout << "Which order would you want to remove? ";
    cin >> i;
    cin.ignore();
    i--;
    if(i < 0 || i >= this->orders->get_num_orders()){
        cout << "Unable to remove order out of range" << endl;
        return;
    }

    // delete[] this->order[]
    // cout << "REMOVING ORDERS\n";
    for(;i < this->orders->get_num_orders()-1; i++)
        this->orders[i] = this->orders[i+1];
    this->orders->set_num_orders(this->orders->get_num_orders()-1);

}

void Restaurant::populate_week(ifstream& fin){
    string str;
    hours * temp = new hours[7];
    string days[] = 
    {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for(int i = 0; i < 7; ++i)
        temp[i].day = days[i];
    while(fin >> str){
        if(fin.eof()){
            break;
        }
        for(int i = 0; i < 7; ++i){
            if(str == temp[i].day){
                fin >> temp[i].open_hour;
                fin >> temp[i].close_hour;
                break;
            }
        }
    }
    this->week = temp;
}


void Restaurant::load_restaurant(ifstream& fin){
    cout << "restaurant_info.txt OPENED\n";
    string temp;
    if(fin.is_open()){
        getline(fin, temp);
        this->name = temp;
        getline(fin, temp);
        this->phone = temp;
        getline(fin, temp);
        this->address = temp;
        this->populate_week(fin);
    }
    else{
        cout << "unable to open restaurant_info.txt file\n";
        exit(1);
    }
    fin.close();
}


void Restaurant::display_employee(){
    for(int i = 0; i < this->num_employee;i++){
        cout << "ID: " << this->employees[i].id << endl;
        cout << "password: " << this->employees[i].password << endl;
        cout << "first_name: " << this->employees[i].first_name << endl;
        cout << "last_name: " << this->employees[i].last_name << endl;
    }
}


void upsize_string(string* str, int& cap){
    string *temp = new string[cap++];
    for(int i = 0; i < cap-1; i++){
        temp[i] = str[i];
    }
    delete[] str;
    str = temp;
    temp = NULL;
}


void Restaurant::resize_employee(int& capacity){
    employee *temp = new employee[++capacity];
    for(int i = 0; i < capacity-1; i++){
        temp[i].id = this->employees[i].id;
        temp[i].password = this->employees[i].password;
        temp[i].first_name = this->employees[i].first_name;
        temp[i].last_name = this->employees[i].last_name;
    }
    delete[] this->employees;
    this->employees = temp;
    temp = NULL;
}
