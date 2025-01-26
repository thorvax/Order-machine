#include <iostream>
#include <fstream>
#include <string>
#include <vector>

    
    
// I put this here to make the vector accesible to all of the program    
std::vector<int> trash;
std::vector<int> ordersArr; // this only stores the orders number like an ID
std::vector<int> ordersArrTemp;
int sumTotal;
std::vector<int> ordersArrID = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<std::string> ordersArrName = {"Burger", "Pizza", "Doughnut", "Taco", "Fried Chicken" ,
                                        "Lemonade" , "Iced Tea", "Coke", "Sprite" , "Dr.Pepper"};
std::vector<int> ordersArrPrices = {30, 120, 15, 47, 35, 15, 10, 17, 13, 24};    
std::string username;
std::vector<std::string> userNameArr;


// "Foods:\n1. Burger \n2. Pizza \n3. Doughnut \n4.Taco \n5.Fried Chicken" << 
//                 "\n\nDrinks: \n6.Lemonade \n7. Iced Tea \n8.Coke \n9. Sprite 10.\n10.Dr.Pepper"
void orderConfirmedtoFile(int &a){
    if(a == 1){
            std::string userFileNameCreator = username + ".txt";
            std::fstream ordersFileSave;
            ordersFileSave.open(userFileNameCreator, std::ios::out);
    
            if(ordersFileSave.is_open()){
                for(int i = 0; i < ordersArr.size(); i++){
                        ordersFileSave << i+1
                                       << "."
                                       << ordersArrName[trash[i]-1]
                                       << "\n";
                }
                ordersFileSave  <<"_____________________________\n"
                                <<"Total Price: "
                                << sumTotal;

            } else{ std::cout << "File cannot be opened"; }

            ordersFileSave.close();

        }

void reviewOrdersNameList (int &a){

    

    // while (ordersArr.size() != ordersArrTemp.size())
    // {
    //     int ii=0;
    //     ordersArrTemp.push_back(ordersArr[ii]);
    //     ii++;
    // }
    
    std::cout << "\033[2J\033[H";
    if(ordersArr.empty()){
        std::cout << "\033[2J\033[H"
                  << "Your cart is empty!\n" 
                  << "Press any key to continue...";
                  system("pause>0");
    } else {
                                            
        int sumTotal;
        std::cout << "\033[2J\033[H";
        std::cout << "Your orders are as follows: \n";

        for ( int i = 0; i < ordersArr.size(); i++){
        std::cout << i+1 
                  << "." 
                  << ordersArrName[ordersArr[i]-1]
                  << "                            "
                  << ordersArrPrices[ordersArr[i]-1]
                  << "\n";
                  sumTotal += ordersArrPrices[ordersArr[i]-1];
        }
        std::cout <<"_____________________________"
                  << "\nTotal: " << sumTotal << "\n";

        std::cout <<"Enter 1 to confirm and 0 to go back...\n";
        short a;

        std::cin >> a ;
        ordersFileSave.close(a);

        }

        
    }

}

int main(){
    std::string order;
    std::vector<int> trash;
    short a = 1;

 
    // std::fstream myFile;
    // myFile.open("foods.txt", std::ios::out);//write into the file

    // if(myFile.is_open()){
    //     myFile << "HEllo\n";
    //     myFile << "THis is the second line\n";
    // }
    // if (!myFile.is_open()){
    //     std::cout << "File is corrupted/missing!" << std::endl;
    // }

    std::cout << "Hello user, Please enter your full name below \n>-- ";
    
    getline(std::cin, username);
    userNameArr.push_back(username);
    
    while (true)
    {
        int opOrder; //Users select numbers if they want to order or delete some order.
        
        int orderChoices;
        //welcome users and lets them input their orders
        std::cout << "\033[2J\033[H  Hello, " << username << std::endl;
        std::cout << "1. Order more \n" 
                  << "2. Review Order \n" 
                  << "3. Delete an order \n";

        std::cin >> opOrder;

        switch (opOrder)
        {
        case 1:
            while (true)
            { 
                std::cout << "\033[2J\033[H" 
                          <<"todays menu is                  SRP\n" 
                          << "Foods:\n"
                          << "1. Burger                  30 \n"
                          << "2. Pizza                  120 \n"
                          << "3. Doughnut                  15\n" 
                          << "4.Taco                  47 \n"
                          << "5.Fried Chicken                  35\n"
                          << "\n"
                          << "Drinks: \n"
                          << "6.Lemonade                  15 \n"
                          << "7. Iced Tea                  10 \n"
                          << "8.Coke                  17\n" 
                          << "9. Sprite                  13 \n"
                          << "10.Dr. Pepper                  24\n"
                          << "\n"
                          << "Enter 0 to exit\n";

                std::cin >> orderChoices;
                if(orderChoices >0 && orderChoices <= ordersArrID.size() ){
                    ordersArr.push_back(orderChoices);
                    std::cout << "\033[2J\033[H" 
                              <<ordersArrName[orderChoices-1] 
                              << " Has been added to your order. \n"
                              << "\n\n\n\n\n\nPress any key to continue...";
                              system("pause > 0");
                
                } 
                else if (orderChoices == 0){
                    break;
                } else { std::cout << "\033[2J\033[H Invalid Order\n"
                                   << "\n\n\n\n\n\nPress any key to continue...";
                        system("pause>0");
                }
                trash.push_back(orderChoices);
                trash.pop_back();
            }
            
            break;
        case 2:
            reviewOrdersNameList();
            break;
        case 3:
            
            break;
        
        
        default:
            break;
        }
        
        
    }



    system("pause>0");
    return 0;
}
void start(){
   
    
    
    







}
