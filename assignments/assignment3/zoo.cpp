#include "zoo.h"

using namespace std;

Zoo::Zoo(){
    this->animals = new Animal *[4];
    for(int i = 0; i < 4; i++)
        animals[i] = new Animal[1];
    this->bank = 50000;
    this->month = 0;
    this->base_food_cost = 100;
    this->num_monkeys = 0;
    this->monkeys_cap = 1;
    this->num_sloths = 0;
    this->sloths_cap = 1;
    this->num_sea_otters = 0;
    this->sea_otters_cap = 1;
    this->num_moss_piglets = 0;
    this->moss_piglets_cap = 1;
    this->food = "";
}


Zoo::~Zoo(){
    for(int i = 0; i < 4; i++){
        delete[] this->animals[i];
        this->animals[i] = NULL;
    }
    delete[] this->animals;
    this->animals = NULL;
}


/*********************************************************************
** Function:         get_bank()
** Description:      gets the called zoo's bank
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the value of bank of the called zoo
*********************************************************************/
float Zoo::get_bank(){
    return this->bank;
}


/*********************************************************************
** Function:         get_adult_monkeys()
** Description:      gets the called zoo's adult monkeys
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of adult monkeys of the called zoo
*********************************************************************/
int Zoo::get_adult_monkeys(){
    int count = 0;
    for(int i = 0; i < this->num_monkeys; i++){
        if(this->animals[0][i].get_age() > 23){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_adult_sloths()
** Description:      gets the called zoo's adult sloths
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of adult sloths of the called zoo
*********************************************************************/
int Zoo::get_adult_sloths(){
    int count = 0;
    for(int i = 0; i < this->num_sloths; i++){
        if(this->animals[1][i].get_age() > 23){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_adult_sea_otters()
** Description:      gets the called zoo's adult sea_otters
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of adult sea_otters of the called zoo
*********************************************************************/
int Zoo::get_adult_sea_otters(){
    int count = 0;
    for(int i = 0; i < this->num_sea_otters; i++){
        if(this->animals[2][i].get_age() > 23){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_adult_moss_piglets()
** Description:      gets the called zoo's adult moss_piglets
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of adult moss_piglets of the called zoo
*********************************************************************/
int Zoo::get_adult_moss_piglets(){
    int count = 0;
    for(int i = 0; i < this->num_moss_piglets; i++){
        if(this->animals[3][i].get_age() > 23){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_baby_monkeys()
** Description:      gets the called zoo's baby monkeys
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of baby monkeys of the called zoo
*********************************************************************/
int Zoo::get_baby_monkeys(){
    int count = 0;
    for(int i = 0; i < this->num_monkeys; i++){
        if(this->animals[0][i].get_age() < 6){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_baby_sloths()
** Description:      gets the called zoo's baby sloths
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of baby sloths of the called zoo
*********************************************************************/
int Zoo::get_baby_sloths(){
    int count = 0;
    for(int i = 0; i < this->num_sloths; i++){
        if(this->animals[1][i].get_age() < 6){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_baby_sea_otters()
** Description:      gets the called zoo's baby sea_otters
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of baby sea_otters of the called zoo
*********************************************************************/
int Zoo::get_baby_sea_otters(){
    int count = 0;
    for(int i = 0; i < this->num_sea_otters; i++){
        if(this->animals[2][i].get_age() < 6){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         get_baby_moss_piglets()
** Description:      gets the called zoo's baby moss_piglets
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  returns the number of baby moss_piglets of the called zoo
*********************************************************************/
int Zoo::get_baby_moss_piglets(){
    int count = 0;
    for(int i = 0; i < this->num_moss_piglets; i++){
        if(this->animals[3][i].get_age() < 6){
            count++;
        }
    }
    return count;
}


/*********************************************************************
** Function:         display_zoo()
** Description:      displays the attributes for the day
** Parameters:       -
** Pre-Conditions:   called on an existing zoo
** Post-Conditions:  cout Bank value, Month, and all animals of the zoo
*********************************************************************/
void Zoo::display_zoo(){ 
    cout << fixed << setprecision(2) << "\n\nBank: $" << this->bank << endl;
    cout << "Month: " << this->month << endl;
    cout << "Your zoo contains:\n\tMonkey: " << num_monkeys << "\n\t\tAdult: " 
        << this->get_adult_monkeys() << "\n\t\tBaby: " << get_baby_monkeys()
        << "\n\tSloth: " << num_sloths << "\n\t\tAdult: " << this->get_adult_sloths() 
        << "\n\t\tBaby: " << get_baby_sloths() << "\n\tSea otter: " 
        << num_sea_otters << "\n\t\tAdult: " << this->get_adult_sea_otters() 
        << "\n\t\tBaby: " << get_baby_sea_otters() << "\n\tMoss piglet: " 
        << num_moss_piglets << "\n\t\tAdult: " << this->get_adult_moss_piglets() 
        << "\n\t\tBaby: " << get_baby_moss_piglets()
        << endl << endl;
}


/*********************************************************************
** Function:         add_monkey(string condition)
** Description:      adds a monkey (bought or given birth)
** Parameters:       string condition
** Pre-Conditions:   -
** Post-Conditions:  adds a bought or baby monkey to the zoo
*********************************************************************/
void Zoo::add_monkey(string condition){
    Monkey M_buy("buy"), M;
    if(condition == "buy" && bank < 15000){
    cout << "Insufficient funds to purchase further\n";
    return;
    }
    this->upsize(0, monkeys_cap, num_monkeys + 1);
    if(condition == "buy"){
        cout << "Bought a monkey\n";
        bank -= 15000;
        this->animals[0][this->num_monkeys] = M_buy;
    }
    else{
        cout << "Gave birth to a monkey\n";
        this->animals[0][this->num_monkeys] = M;
    }
    ++this->num_monkeys;
}


/*********************************************************************
** Function:         add_sloth(string condition)
** Description:      adds a sloth (bought or given birth)
** Parameters:       string condition
** Pre-Conditions:   -
** Post-Conditions:  adds a bought or baby sloth to the zoo
*********************************************************************/
void Zoo::add_sloth(string condition){
    int step;
    Sloth S_buy("buy"), S;
    step = condition == "buy" ? 1 : 5;
    if(condition == "buy" && bank < 2000){
        cout << "Insufficient funds to purchase further\n";
        return;
    }
    this->upsize(1, sloths_cap, num_sloths + step);
    for(int i = 0; i < step; ++i){
        if(condition == "buy"){
            cout << "Bought a sloth\n";
            bank -= 2000;
            this->animals[1][this->num_sloths] = S_buy;
        }
        else{
            cout << "Gave birth to a sloth\n";
            this->animals[1][this->num_sloths] = S;
        }
    ++this->num_sloths;
    }
}


/*********************************************************************
** Function:         add_sea_otter(string condition)
** Description:      adds a sea otter (bought or given birth)
** Parameters:       string condition
** Pre-Conditions:   -
** Post-Conditions:  adds a bought or baby sea otter to the zoo
*********************************************************************/
void Zoo::add_sea_otter(string condition){
    int step;
    Sea_otter S_buy("buy"), S;
    step = condition == "buy" ? 1 : 2;
    if(condition == "buy" && bank < 5000){
        cout << "Insufficient funds to purchase further\n";
        return;
    }
    this->upsize(2, sea_otters_cap, num_sea_otters + step);
    for(int i = 0; i < step; ++i){
        if(condition == "buy"){
            cout << "Bought a sea_otter\n";
            bank -= 5000;
            this->animals[2][this->num_sea_otters] = S_buy;
        }
        else{
            cout << "Gave birth to a sea_otter\n";
            this->animals[2][this->num_sea_otters] = S;
        }
    ++this->num_sea_otters;
    }
}


/*********************************************************************
** Function:         add_moss_piglets(string condition)
** Description:      adds a moss piglet (bought or given birth)
** Parameters:       string condition
** Pre-Conditions:   -
** Post-Conditions:  adds a bought or baby moss piglet to the zoo
*********************************************************************/
void Zoo::add_moss_piglets(string condition){
    int step;
    Moss_piglets M_buy("buy"), M;
    step = condition == "buy" ? 1 : 100;
    if(condition == "buy" && bank < 1000000){
        cout << "Insufficient funds to purchase further\n";
        return;
    }
    this->upsize(3, moss_piglets_cap, num_moss_piglets + step);
    for(int i = 0; i < step; ++i){
        if(condition == "buy"){
            cout << "Bought a moss_piglets\n";
            bank -= 1000000;
            this->animals[3][this->num_moss_piglets] = M_buy;
        }
        else{
            cout << "Gave birth to a moss_piglets\n";
            this->animals[3][this->num_moss_piglets] = M;
        }
        ++this->num_moss_piglets;
    }
}


/*********************************************************************
** Function:         upsize(int type, int &capacity, int needed_count)
** Description:      upsizes a species
** Parameters:       int type, int &capacity, int needed_count
** Pre-Conditions:   capacity has reached
** Post-Conditions:  increases capacity for specified species
*********************************************************************/
void Zoo::upsize(int type, int &capacity, int needed_count){
    while(needed_count > capacity){
        capacity *= 2;
        Animal *temp = new Animal[capacity];
        for(int i = 0; i < capacity/2; ++i){
            temp[i] = this->animals[type][i];
        }
        delete[] this->animals[type];
        this->animals[type] = temp;
        temp = NULL;
    }
}


/*********************************************************************
** Function:         purchase(int index, int amount)
** Description:      purchases the specified species once or twice
** Parameters:       int index, int amount
** Pre-Conditions:   -
** Post-Conditions:  adds 1 or 2 specified animal to the zoo
*********************************************************************/
void Zoo::purchase(int index, int amount){
    for(int i = 0; i < amount; ++i){
        if(index == 0){
            this->add_monkey("buy");
        }
        else if(index == 1){
            this->add_sloth("buy");
        }
        else if(index == 2){
            this->add_sea_otter("buy");
        }
        else if(index == 3){
            this->add_moss_piglets("buy");
        }
        else
            cout << "invalid animal to purchase\n";
    }
}


/*********************************************************************
** Function:         display_food_info(string& choice)
** Description:      couts all the information for food for the month
** Parameters:       string& choice
** Pre-Conditions:   -
** Post-Conditions:  changed choice to the user's food choice
*********************************************************************/
void Zoo::display_food_info(string& choice){
    do{
        cout << "\n\nThe following are the food costs for this month:\n"
            << "\tTotal monkey food cost: $" << 4 * this->base_food_cost * this->num_monkeys
            << "\n\tTotal sloth food cost: $" << 4 * this->base_food_cost * this->num_sloths
            << "\n\tTotal sea_otter food cost: $" << 4 * this->base_food_cost * this->num_sea_otters
            << "\n\tTotal moss_piglets food cost: $" << 4 * this->base_food_cost * this->num_moss_piglets
            << "\nYour food choces include:\n"
            << "1. Regular food \n"
            << "2. Cheap food = pay 50% of food cost : 150% chance of sickness\n"
            << "3. Premium food = pay 150% of food cost : 50% chance of sickness\n"
            << "Please enter your food choice(<enter> to select default food): ";
        getline(cin, choice);
        if(choice == ""){
            choice = "1";
        }
    }while(choice != "1" && choice != "2" && choice != "3");
}


/*********************************************************************
** Function:         food_choice()
** Description:      get the user to choose a kind of food to feed
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  a food is selected and cost is deducted
*********************************************************************/
void Zoo::food_choice(){
    float total = 4 * this->base_food_cost * this->num_monkeys + this->base_food_cost * this->num_sloths 
    + 2 * this->base_food_cost * this->num_sea_otters + 10 * this->base_food_cost * this->num_moss_piglets;
    string choice;
    this->display_food_info(choice);
    if(choice == "1"){
        this->food = "regular";
        bank -= total;
    }
    else if(choice == "2"){
        this->food = "cheap";
        bank -= total * 0.5;
    }
    else if(choice == "3"){
        this->food = "premium";
        bank -= total * 1.5;
    }
    else
        cout << "Invalid food choice\n";
}


/*********************************************************************
** Function:         buy_menu()
** Description:      displays the meny that asks user what animal to buy
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  buys the specified animal 1 or 2 times
*********************************************************************/
void Zoo::buy_menu(){
    string choice, amount;
    do{
        do{
            cout << "\n\nPlease select one species to purchase:\n1: Monkey - $15000\n"
                "2: Sloth - $2000\n3: Sea otter - $5000\n4: Moss piglets - $1000000\n"
                "Please enter your choice(Enter <enter> to skip purchase): ";
            getline(cin, choice);
        }while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "");
        if(choice == ""){
            return;
        }
        cout << "Please enter the amount you would like to purchases(1 or 2 in integers): ";
        getline(cin, amount);
    }while(amount != "1" && amount != "2");
    if(choice != ""){
        this->purchase(stoi(choice) - 1, stoi(amount));
    }
}


/*********************************************************************
** Function:         initiate()
** Description:      runs the steps needed to complete the first month
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  -
*********************************************************************/
void Zoo::initiate(){
    this->display_zoo();
    this->buy_menu();
    this->daily_increments();
}


/*********************************************************************
** Function:         sell(int index)
** Description:      sells the first index of the type of animal
** Parameters:       int index
** Pre-Conditions:   there should be an animal of the type being called
** Post-Conditions:  an specified animal will be removed from the zoo
*********************************************************************/
void Zoo::sell(int index){
    int count[] = {num_monkeys, num_sloths, num_sea_otters, num_moss_piglets};
    if(count[index] == 0){
        cout << "There are not enough selected animal to be sold\n";
        return;
    }
    bank += this->animals[index][0].get_selling_price();
    for(int i = 0; i < count[index] - 1; i++){
        this->animals[index][i] = this->animals[index][i + 1];
    }
    if(index == 0){
        --this->num_monkeys;
    }
    else if(index == 1){
        --this->num_sloths;
    }
    else if(index == 2){
        --this->num_sea_otters;
    }
    else if(index == 3){
        --this->num_moss_piglets;
    }
}


/*********************************************************************
** Function:         sell_menu()
** Description:      shows the user a sell animal menu
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  if user chooses to sell an animal -> sell it
*********************************************************************/
void Zoo::sell_menu(){
    string choice;
    do{
        cout << "\n\nPlease select one animal to sell:\n1: Monkey\n"
            "2: Sloth\n3: Sea otter\n4: Moss piglets\n"
            "Please enter your choice(Enter <enter> to skip selling): ";
        getline(cin, choice);
    }while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "");
    if(choice == ""){
        return;
    }
    this->sell(stoi(choice) - 1);
}


/*********************************************************************
** Function:         next_day()
** Description:      runs the necessary steps needed in the month
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  -
*********************************************************************/
void Zoo::next_day(){
    this->display_zoo();
    this->buy_menu();
    this->sell_menu();
    this->daily_increments();
}


/*********************************************************************
** Function:         revenue()
** Description:      calculates the revenue of the month
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  returns the revenue for the month
*********************************************************************/
float Zoo::revenue(){
    int count[] = {num_monkeys, num_sloths, num_sea_otters, num_moss_piglets};
    float total = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < count[i]; ++j){
            if(this->animals[i][j].get_age() < 7){
                total += this->animals[i][j].get_revenue() * 2;
            }
            else{
                total += this->animals[i][j].get_revenue();
            }
        }
    }
    return total;
}


/*********************************************************************
** Function:         sick(int type){
** Description:      performs what happens to a sickened animal
** Parameters:       int type
** Pre-Conditions:   there has to be an animal in the specified type
** Post-Conditions:  the sickened animal will be cured or sold
*********************************************************************/
void Zoo::sick(int type){ 
    int count[] = {num_monkeys, num_sloths, num_sea_otters, num_moss_piglets};
    int adult_animals[] = {this->get_adult_monkeys(), this->get_adult_sloths()
        , this->get_adult_sea_otters(), this->get_adult_moss_piglets()};
    float cure_price[] = {(float)15000 / 2, (float)2000 / 2, (float)5000 / 2, (float)1000000 / 2};
    if(rand()%count[type] > adult_animals[type]){
        cure_price[type] += 2;
    }
    bank -= cure_price[type];
    if(bank < 0){
        bank += cure_price[type];
        this->sell(type);
        cout << "The animal has been sold\n";
        return;
    }
    cout << "The sick animal has been cured\n";
}


/*********************************************************************
** Function:         sick_event()
** Description:      a randomly chosen animal will get sick
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  1 animal gets sick
*********************************************************************/
void Zoo::sick_event(){
    cout << "\nSick event started\n";
    if(num_monkeys + num_sloths + num_sea_otters + num_moss_piglets != 0){
        int chance = rand()%(num_monkeys + num_sloths + num_sea_otters + num_moss_piglets);
        if(chance < num_monkeys){
            cout << "A Monkey got sick" << endl;
            this->sick(0);
        }
        else if(chance < num_monkeys + num_sloths){
            cout << "A Sloth got sick" << endl;
            this->sick(1);
        }
        else if(chance < num_monkeys + num_sloths + num_sea_otters){
            cout << "A Sea otter got sick" << endl;
            this->sick(2);
        }
        else{
            cout << "A Moss piglet got sick" << endl;
            this->sick(3);
        }
    }
}


/*********************************************************************
** Function:         birth_event()
** Description:      a randomly chosen adult gives birth
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  an extra number of baby will be added to the zoo
*********************************************************************/
void Zoo::birth_event(){
    cout << "\nBirth event started\n";
    int adult_animals[] = {this->get_adult_monkeys(), this->get_adult_sloths()
        , this->get_adult_sea_otters(), this->get_adult_moss_piglets()};
    if(adult_animals[0] + adult_animals[1] + adult_animals[2] + adult_animals[3] == 0){
        cout << "No adult monkeys are available to give birth\n" << endl;
        return;
    }
    int randint = rand() % (adult_animals[0] + adult_animals[1] + adult_animals[2] + adult_animals[3]);
    if(randint < adult_animals[0]){
        this->add_monkey();
    }
    else if(randint < adult_animals[0] + adult_animals[1]){
        this->add_sloth();
    }
    else if(randint < adult_animals[0] + adult_animals[1] + adult_animals[2]){
        this->add_sea_otter();
    }
    else{
        this->add_moss_piglets();
    }


}


/*********************************************************************
** Function:         extra_revenue_event()
** Description:      all monkeys generate a random extra revenue
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  bank added with extra revenues
*********************************************************************/
void Zoo::extra_revenue_event(){
    cout << "\nA boom in zoo attendance occurs.\n";
    for(int i = 0; i < this->num_monkeys; i++){
        this->bank += (rand()%5 + 3)*100;
    }
}


/*********************************************************************
** Function:         events(int food_type)
** Description:      chooses event depending on food choice chances
** Parameters:       int food_type
** Pre-Conditions:   food choice has to be chosen
** Post-Conditions:  either sick_event birth_event extra_revenue_event
                        or no event
*********************************************************************/
void Zoo::events(int food_type){
    int limits[][3] = {{63, 126, 189}, {84, 140, 196}, {36, 108, 180}};
    int randint = rand() % 252;
    if(randint < limits[food_type][0]){
        this->sick_event();
    }
    else if(randint < limits[food_type][1]){
        this->birth_event();
    }
    else if(randint < limits[food_type][2]){
        this->extra_revenue_event();
    }
    else{
        cout << "\nThere are no events this month\n";
    }
}


/*********************************************************************
** Function:         daily_increments()
** Description:      perform daily increments of the zoo month
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  increments all necessary values of the month
*********************************************************************/
void Zoo::daily_increments(){
    int count[] = {num_monkeys, num_sloths, num_sea_otters, num_moss_piglets};
    ++this->month;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < count[i]; ++j){
            this->animals[i][j].increment_age();
        }
    }
    this->bank += this->revenue();
    this->food_choice();
    this->base_food_cost *= rand() % 51 / 100.0 + 0.75;
    if(food == "regular"){
        this->events(0);
    }
    else if(food == "cheap"){
        this->events(1);
    }
    else{
        this->events(2);
    }
}


/*********************************************************************
** Function:         rerun()
** Description:      asks if the user wants to continue the game
** Parameters:       -
** Pre-Conditions:   -
** Post-Conditions:  returns false if the user would not want to continue
*********************************************************************/
bool rerun(){
    string usr;
    cout << "\nPlease enter \"YES\" if you would like to end the game or hit <enter> to continue...";
    getline(cin, usr);
    if(usr == "YES"){
        return false;
    }
    return true;
}
