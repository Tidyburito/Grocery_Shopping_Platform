#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

class UserDatabase{//linked list for user database using classes
    public:
    string userId;
    string pass;
    string name;
    int orders;
    int counter = 0;
    UserDatabase* next;
    UserDatabase* head = NULL;

    void insert(string user_Id, string Pass, string Name, int Orders){
        UserDatabase *current= head;
        UserDatabase *last;
        last = new UserDatabase;
        last->userId = user_Id;
        last->pass = Pass;
        last ->name = Name;
        last->orders = Orders;
        last->next = NULL;

        if (head == NULL){
            head = last;
        }
        else{
            while (current->next != NULL){
                current = current->next; 
            }
            current->next = last;    
        }    
    }
    
    bool checkUser(string User, string Pass){//Boolean function to check if user exists
        counter = 0;
        UserDatabase *current= head;
        while(current != NULL ){
            if(current ->userId == User && current->pass == Pass){
                return true;
            }
            else{
                counter++;//To check which node is the user found at
                current = current->next;
            }        
        }
        return false;
    }

    void modifyUser(string user_Id, string Name, int option){//Function to modify user details 
        UserDatabase *current = head;
        for(int i = 0; i < counter - 1; i++)
            current = current ->next;
        if(option == 1)    
            current ->userId = user_Id;
        else if(option == 2)
            current ->name = Name;

    }

    string getName(){
        UserDatabase *c = head;
        for(int i = 0; i < counter ; i++)
            c = c->next;
        return c->name;    
    }

    int getOrder(){
        UserDatabase *c = head;
        for(int i = 0; i < counter ; i++)
            c = c->next;
        return c->orders;    
    }

};

class Categories{//Linked list for inventory management using classes
    public:
    int serialNo;
    string name;
    int price;
    Categories* next;
    Categories* head = NULL;

    void insert(int SerialNo, string Name, int Price){
        Categories *current= head;
        Categories *last;
        last = new Categories;
        last->serialNo = SerialNo;
        last ->name = Name;
        last->price = Price;
        last->next = NULL;

        if (head == NULL){
            head = last;
        }
        else{
            while (current->next != NULL){
                current = current->next; 
            }
            current->next = last;    
        }    
    }

    void displayList(){// Function to display the list of categories
        Categories *current = head;
        while(current != NULL){
            cout<<current ->serialNo<<") "<<left<<setw(30)<<current ->name<<"Rs. "<<current ->price<<"\n";
            current = current->next;
        }
    }

    int CgetPrice(int j){//Function to traverse through the list to find the price of the selected item
        Categories *c = head;
        for(int i=1;i<j;i++)
            c = c->next;

        return c->price;
    }

    string CgetName(int j){//Function to traverse through the list to find the name of the selected item
        Categories *c = head;
        for(int i=1;i<j;i++)
            c=c->next;

        return c->name;
    }

};

void line(){// Function to print a normal line for aesthetic in terminal
    cout<<"\n";
    for(int i=0;i<93;i++)
        cout<<"-";

    cout<<"\n";
}

void sline(){ // Function to print an asterisk line for aesthetic in terminal
    cout<<"\n";
    for(int i=0;i<93;i++)
    cout<<"*";
    cout<<"\n";
}

class Cart{ //Linked list for the final bill using classes
        public:
        string name;
        int cost;
        int number;
        int id;
        Cart*next;
        Cart* head =NULL;

    int counter(){//Function to count total elements in the list
        int count = 0;
        if(head == NULL){
            count = 0;
            return count;
        }
        else{
            Cart* current;
            current = head;
            while(current != NULL){
                count++;
                current = current ->next;
            }
            return count;
    }
}  
      void insertItem(int SerialNo, string Name, int Price,int Number){
         Cart* item;
         item =new Cart;
         item->id=SerialNo;
         item->name=Name;
         item->cost=Price;
         item->number=Number;
         item->next=head;
         head=item;       
      }

      void deleteItem(int position){ //Function to delete desired item in the cart 
        int x = counter();
        if(head==NULL)
        cout<<"Linked list is Empty"<<endl;
        else if(x<position)
        cout<<"Invalid position"<<endl;
        else{
            if(position==1){
                Cart *current1;
                current1 = head;
                head = head->next;
                delete current1;
            }
            else{
                Cart *current=head;
                Cart *temp;
                Cart* d;
                for(int i=0;i<position-2;i++)
                current=current->next;
                d = current ->next;
                temp = d->next;
                delete d;
                current->next=temp;
            }   
        }     
    }

      void displayCart(){ // Function to display the cart with final amount 
            if(head == NULL){
               cout<<"Empty Cart"<<endl;  
            }
            else{
               int i = 1;
               int cost=0;
               Cart *current =  head ;
               cout<<left<<setw(10)<<"SerialNo"<<left<<setw(35)<<"Name"<<left<<setw(25)<<"Price"<<left<<setw(10)<<"Number of Products"<<endl;
               cout<<endl;
               while(current!=NULL){
                  cout<<left<<setw(10)<<i<<left<<setw(35)<<current->name<<left<<setw(25)<<current->cost<<left<<setw(10)<<current->number<<"\n\n";
                  cost=cost+(current->cost * current->number);
                  current=current->next;
                  i++;
               }
               line();
               cout<<"Final Cost:\t"<<cost;
               line();      
            }        
      }
};

int minDist(int distance[], bool visit[], int size){//Function to find minimum distance between nodes
    int minimum=INT_MAX,index;            
    for(int k=0;k<size;k++){
        if(visit[k]==false && distance[k]<=minimum){
            minimum=distance[k];
            index=k;
        }
    }

    return index;
}

void dijkstraAlgo(int graph[10][10],int src, int destination, int size){ //Dijkstra algorithm 
    int distance[size];                         
    bool visit[size];

    for(int k = 0; k<size; k++){
        distance[k] = INT_MAX;
        visit[k] = false;    
    }
    
    distance[src] = 0;               
    for(int c = 0; c < size; c++){
        int m=minDist(distance, visit, size); 
        visit[m]=true;       
        for(int k = 0; k<size; k++){ 
            if(!visit[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
  
    cout<<"Estimated delivery Time from GroceriaDeli:- "<<distance[destination]<<" min";
   
}


int main(){//Driver code
    // Variable declarations
    string id, pass, name;
    bool condition;
    int counter = 3, size = 6;
    char ch;

    UserDatabase u1;
    Categories fruits, vegetables, dairy, meats, snacks, bakery;
    Cart c1;

    //Predefined User declaration
    u1.insert("abc@gmail.com", "123", "ABC",8);
    u1.insert("xyz@gmail.com", "456", "XYZ",4);
    u1.insert("ijk@gmail.com", "789", "ijk",2);

    //Adj matrix for graph
    int graph[10][10]={
            {0, 18, 29, 13 , 9, 0},
            {12, 0, 26, 19 , 22, 15},
            {9, 18, 0, 23, 17, 24},
            {0, 15, 33, 0, 14, 24},
            {33, 26, 18, 26, 0, 19},
            {15, 27, 16, 23, 29, 0},
        };

    //Inventory declaration  
    fruits.insert(1, "Apple", 150);
    fruits.insert(2, "Banana", 60);
    fruits.insert(3, "Grape", 25);
    fruits.insert(4,"Peaches",100);
    fruits.insert(5,"Pineapple",65);
    fruits.insert(6,"Papaya",50);
    fruits.insert(7,"Dragon fruit",120);
    fruits.insert(8,"Orange",65);
    fruits.insert(9,"Mango",180);
    
    vegetables.insert(1, "Potatoes", 40);
    vegetables.insert(2,"Tomatoes",60);
    vegetables.insert(3,"Onion",50);
    vegetables.insert(4,"Spinach",30);
    vegetables.insert(5,"Bell Pepper",100);
    vegetables.insert(6,"Carrot",25);
    vegetables.insert(7,"Raddish",60);
    vegetables.insert(8,"Cucumber",40);
    vegetables.insert(9,"Cabbage",35);
    
    dairy.insert(1,"Milk",65);
    dairy.insert(2,"Cottage Cheese",120);
    dairy.insert(3,"Curd",80);
    dairy.insert(4,"Butter",75);
    dairy.insert(5,"Eggs",60);
    dairy.insert(6,"Cream Cheese",100);
    dairy.insert(7,"Sour Cream",110);
    dairy.insert(8,"Yogurt",90);
    dairy.insert(9,"Cheese",120);

    meats.insert(1,"Boneless Chicken Tenders", 500);
    meats.insert(2,"Chicken Livers", 350);
    meats.insert(3,"Boneless Chicken Breast", 600);
    meats.insert(4,"Grounded veal", 300);
    meats.insert(5,"Chicken Wings", 400);
    meats.insert(6,"Chicken thigh", 225);
    meats.insert(7,"Turkey Drumstick", 700);
    meats.insert(8,"Chicken Drumstick", 400);
    meats.insert(9,"Bacon", 250);

    snacks.insert(1, "Lays Chip Indian Masala", 20);
    snacks.insert(2, "Pringels Cream and Onions",100);
    snacks.insert(3, "Aloo Bhujia",50);
    snacks.insert(4, "Khata Mitha",50);
    snacks.insert(5, "Sev Bhujia",100);
    snacks.insert(6, "Mad Angles",20);
    snacks.insert(7, "Puffcorn",20);
    snacks.insert(8, "Doritos",50);
    snacks.insert(9, "Hide and Seek",30);

    bakery.insert(1,"French Baguette",200);
    bakery.insert(2,"Egg Twist Challah",350);
    bakery.insert(3,"Pumpkin Pie",500);
    bakery.insert(4,"Blueberry Muffins",200);
    bakery.insert(5,"Chocolate Chip Cookies",50);
    bakery.insert(6,"Crossiant",30);
    bakery.insert(7,"Bagel",50);
    bakery.insert(8,"Red Velvet Cupcake",50);
    bakery.insert(9,"Apple Pie",750);

    line();
    cout<<"\t\t\t\tWelcome to Groceria\n\t\t\tYour one step shop to all things grocery\n"; 
    line();
    cout<<"\t\t\t\tNew customer??? \n\t\t\t(enter y else press any key): ";
    cin>>ch;
    
    if( ch == 'y'){// if statement to check if the user is a new customer 
        line();
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter email id: ";
        cin>>id;
        cout<<"Enter password: ";
        cin>>pass;
        line();
        u1.insert(id, pass, name, 0);//creating a new user in the user database 
        cout<<"\t\t\t\t  Account created \n\t\t\t\tPlease login again :) \n";
    }
    line();
    retry:
    cout<<"Enter email id: ";
    cin>>id;
    cout<<"Enter password: ";
    cin>>pass;
    condition = u1.checkUser(id, pass);// Checks if the user exists in the database
    if(condition == false){//if the returned condition is false the application gives the user three retries to login 
        cout<<"Invalid ID/Pass";
        cout<<"\nYou have "<<counter<<" valid retries \n";
        counter--;
        if(counter >= 0)
            goto retry;
        else 
            return 0;
    }
    line();            
    name = u1.getName();
    cout<<"Welcome "<<name<<"\nWhat would you like to do today\n";
    menu:
    while(true){//While loop for the main menu 
         line();
         cout<<"\n1. Display account information \n2. Modify account information \n3. Order groceries \n4. Exit \n";
         line();
         char ch1, ch2;
         cin>>ch1; 
         switch (ch1){
               case '1':
                  int tOrders;
                  tOrders = u1.getOrder();
                  sline();
                  cout<<"Name: "<<name<<"\n";
                  cout<<"Email ID: "<<id<<"\t";
                  cout<<"Total number of orders: "<<tOrders<<"\n";
                  sline();
               break;

            case '2':
                  bool check;
                  cout<<"Please re-enter account password ";
                  cin>>pass;
                  check = u1.checkUser(id, pass);
                  if(check == true){
                     line();
                     int option;
                     cout<<"Select detail to modify: - \n1. Name \n2. Email ID \n";
                     cin>>option;
                     switch (option){
                     case 1:
                         cout<<"Enter new name: ";
                         cin>>name;
                         u1.modifyUser(name, id, option);
                         break;

                     case 2:
                        cout<<"Enter new email id: ";
                        cin>>id;
                        u1.modifyUser(name, id, option);
                        break;

                     default:
                         cout<<"Invalid option";
                         break;
                     }             
                     line();
                  }
                  else
                     cout<<"Invalid password!!! ";
                  break;

            case '3':
                while (true){
                     int x1;
                     int x;
                     sline();
                     cout<<"Select category: \n1. Fruits \n2. Vegetables  \n3. Dairy \n4. Meats \n5. Snacks  \n6. Bread & Bakery \n7. Show cart\n8. Proceed to checkout \n9. Back \n\n";
                     cin>>ch2;
                     sline();
                     switch (ch2){
                      case '1':
                        line();
                        cout<<"\t\tFruits Menu (per kilo) :- \n";
                        fruits.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart (Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{ 
                                cout<<"Enter kilo(s) of "<<fruits.CgetName(x1)<<" required: ";
                                cin>>x;  
                                c1.insertItem(x1,fruits.CgetName(x1),fruits.CgetPrice(x1),x);
                                cout<<"Item added!"<<endl;
                                break;
                            }
                            default:
                            cout<<"Wrong id"<<endl;
                        }
                        break;

                     case '2':
                        line();
                        cout<<"\t\tVegetables Menu (per kilo) :- \n";
                        vegetables.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart (Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{
                                
                                cout<<"Enter kilo(s) of "<<vegetables.CgetName(x1)<<" required: ";
                                cin>>x;
                                c1.insertItem(x1,vegetables.CgetName(x1),vegetables.CgetPrice(x1),x);
                                cout<<"Item added!"<<endl;
                                break;
                            }
                            default:
                            cout<<"Wrong id"<<endl;
                        }
                        break;

                     case '3':
                        line();
                        cout<<"\t\tDairy Menu :- \n";
                        dairy.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart(Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{  
                                cout<<"Enter quantity of "<<dairy.CgetName(x1)<<" required: ";
                                cin>>x; 
                                c1.insertItem(x1,dairy.CgetName(x1),dairy.CgetPrice(x1),x);
                                cout<<"Item added!"<<endl;
                                break; 
                            }
                            default:
                            cout<<"Wrong id"<<endl;
                        }
                        break;

                     case '4':
                        line();
                        cout<<"\t\tMeats Menu :- \n";
                        meats.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart(Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{     
                                cout<<"Enter quantity of "<<meats.CgetName(x1)<<" required: ";
                                cin>>x; 
                                c1.insertItem(x1,meats.CgetName(x1),meats.CgetPrice(x1),x);
                                cout<<"Item added!"<<endl;
                                break; 
                            }
                            default:
                            cout<<"Wrong id"<<endl;

                        }
                        break;

                     case '5':
                        line();
                        cout<<"\t\tSnacks Menu :- \n";
                        snacks.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart(Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{
                                cout<<"Enter quantity of "<<snacks.CgetName(x1)<<" required: ";
                                cin>>x;
                                c1.insertItem(x1,snacks.CgetName(x1),snacks.CgetPrice(x1),x);
                                cout<<"Item added!"<<endl;
                                break;  
                            }
                            default:
                            cout<<"Wrong id"<<endl;

                        }
                        break;

                     case '6':
                        line();
                        cout<<"\t\tBread & Bakery Menu :- \n";
                        bakery.displayList();
                        cout<<"\nPress 0 to go back or the id number to insertItem to cart(Enter number only!): ";
                        cin>>x1;
                        line();
                        switch(x1){
                            case 0:
                            break;
                            case 1 ... 9:{
                                 cout<<"Enter quantity of "<<bakery.CgetName(x1)<<" required: ";
                                 cin>>x;  
                                 c1.insertItem(x1,bakery.CgetName(x1),bakery.CgetPrice(x1),x);
                                 cout<<"Item added!"<<endl;
                                 break;
                            }
                            default:
                                 cout<<"Wrong id"<<endl;
                        }
                        break;

                     case '7':      //Displays the cart and gives option to delete items in the cart 
                        c1.displayCart();
                        char pop;
                        line();
                        cout<<"\t\t\t\tDelete any item?\n\t\t(enter y else press any key): ";
                        cin>>pop;
                        if(pop == 'y'){
                           int pos; 
                           cout<<"Enter serial number of item to be deleted: - ";
                           cin>>pos;
                           c1.deleteItem(pos);
                        } 
                        line();
                        break;

                     case '8': //Final Checkout with graph application for delivery 
                        c1.displayCart();
                        int destination;
                        line();
                        cout<<"\tSelect location for delivery: - \n1. Andheri \n2. Vile Parle \n3. Santacruz \n4. Bandra \n5. Malad \n";
                        cin>>destination;
                        line();
                        dijkstraAlgo(graph,0, destination, size);

                        goto exit;
                        break;

                     case '9':
                        goto menu;
                        break;

                    default:
                        cout<<"Invalid option!";
                        break;
                    }
                }
                break; 

            case '4': 
                  exit:
                  line();
                  cout<<"\tThank you for using Groceria!\n\t\tHave a nice day :) ";
                  line();
                  return 0;
                break;    
            
            default:
                  cout<<"Invalid option!";
                break;
        }
    }
    
}