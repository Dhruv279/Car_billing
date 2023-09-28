#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <Windows.h>
#include <unistd.h>
struct User // Structure For Storing User Details
{
    char Name[20];
    long long int MobileNumber;
    char Email_Id[40];
    char Adress[70];
} cust;

struct Car // Structure For Storing Car Details
{
    int Brand;
    int Model;
    int code;
    int cost;
    int colour;
} car;

struct Modifiation // Structure For Storing Modification Details
{
    int choice;
    int sub_choice;
    char Wheels[20];
    int wheel_price;
    char Roof[20];
    int roof_price;
    char Lights[20];
    int light_price;
    char Spoiler[20];
    int spoiler_price;
    char Exhaust[20];
    int exhaust_price;
    char Car_Stereo[20];
    int car_stereo_price;
    // char Hydraulics[20];
    // int hydraulics_price;

} modifications;

struct Bill // Structure For Storing Bill Details
{
    int Mod_Total;
    int Tax;

    int Final_Amount;
    int Items[15];
} bill;

void display_car_list();              // Function That Will Display All The Available Cars
void choose_car_brand();              // Function To Select The Brand From Available Brands
void choose_car_model();              // Function To Select The Car Model From Available Models
void choose_car_colour();             // Function To Display And Choose The Available Car Colours
void fetch_selected_car();            // Function To Display The Selected Car Details
void display_modifications();         // Function To Display The Available Car Modifications
void display_sub_modification_menu(); // Function To Display The Available Car Modifications
void display_bill();
void get_Mod_Total();
void run();
int get_random_number(int upper, int lower);
int Car_cost(int n);
void clear_screen() // function to clear the screen in the
{
    system("@cls||clear");
}

int main()
{
    clear_screen();
    srand(time(0));

    strcpy(modifications.Wheels, "N/A         ");
    strcpy(modifications.Roof, "N/A         ");
    strcpy(modifications.Lights, "N/A         ");
    strcpy(modifications.Spoiler, "N/A         ");
    strcpy(modifications.Exhaust, "N/A         ");
    strcpy(modifications.Car_Stereo, "N/A         ");

    bill.Mod_Total = 0;

    run();

    return 0;
}
void run()
{
    int sml = 1, ch, c;
    char answer;
    printf("%c WELCOME TO OUR SHOP %c\n", sml, sml);
    printf("Would you buy a car ? (y/n)\n");
    scanf("%[^\n]%*c", &answer);
    if (tolower(answer) == 'y')
    {
        printf("Please enter below details:\n");
        printf("Enter your name: ");
        scanf("%[^\n]%*c", cust.Name);
        printf("Enter your MobileNumeber: ");
        scanf("%lli", &cust.MobileNumber);
        printf("Enter your Email_id: ");
        scanf("%s", cust.Email_Id);
        printf("Enter your Address: ");
        scanf(" %[^\n]%*c", cust.Adress);
    }
    else
    {
        printf("Thanks for visiting..");
        return 0;
    }
    clear_screen();
    display_car_list();

    choose_car_brand();
    clear_screen();
    choose_car_model();
    clear_screen();
    choose_car_colour();
    clear_screen();
    display_modifications();
    clear_screen();

    display_bill();
}
void display_car_list()
{
    printf("Here Are The Available Cars: \n");
    printf("1. Kia\n");
    printf("2. Hyundai\n");
    printf("3. Honda\n");
    printf("4. Mahindra\n");
    printf("5. Maruti Suzuki\n");
    printf("6. Mercedez\n");
    printf("7. Toyota\n");
}

void choose_car_brand()
{
    printf("\nWhich Brand Would You Like To Select: ");
    scanf("%d", &car.Brand);
    if (car.Brand < 1 && car.Brand > 7)
    {
        printf("\nDear Customer Please Enter A Valid Code.");
        choose_car_brand();
    }
}

void choose_car_model()
{
    switch (car.Brand)
    {
    case 1:
        printf("\nHere All The Kia Cars Available\n");
        printf("11. Kia Sonet    - Rs. 13.79 lakh\n");
        printf("12. Kia Seltos   - Rs. 18.65 lakh\n");
        printf("13. Kia Carnival - Rs. 35.49 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 11 && car.code > 13)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 2:
        printf("\nHere All The Hyundai Cars Available\n");
        printf("21. Hyundai Santro - Rs. 4.89 lakh\n");
        printf("22. Hyundai i10    - Rs. 5.39 lakh\n");
        printf("23. Hyundai i20    - Rs. 7.03 lakh\n");
        printf("24. Hyundai Verna  - Rs. 9.40 lakh\n");
        printf("25. Hyundai Creta  - Rs. 10.44 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 21 || car.code > 25)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 3:
        printf("\nHere All The Honda Cars Available\n");
        printf("31. Honda City  - Rs. 9.50 lakh\n");
        printf("32. Honda Amaze - Rs. 6.65 lakh\n");
        printf("33. Honda Jazz  - Rs. 8.11 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 31 || car.code > 33)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 4:
        printf("\nHere All The Mahindra Cars Available\n");
        printf("41. Mahindra Thar    - Rs. 13.53 lakh\n");
        printf("42. Mahindra XUV 300 - Rs. 8.41 lakh\n");
        printf("43. Mahindra XUV 500 - Rs. 9.31 lakh\n");
        printf("44. Mahindra XUV 700 - Rs. 13.18 lakh\n");
        printf("45. Mahindra Scropio - Rs. 11.99 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 41 || car.code > 45)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 5:
        printf("\nHere All The Maruti Suzuki Cars Available\n");
        printf("51. Maruti Suzuki Swift   - Rs. 5.91 lakh\n");
        printf("52. Maruti Suzuki Baleno  - Rs. 6.42 lakh\n");
        printf("53. Maruti Suzuki Ertiga  - Rs. 8.35 lakh\n");
        printf("54. Maruti Suzuki Brezza  - Rs. 7.99 lakh\n");
        printf("55. Maruti Suzuki S-Cross - Rs. 9.50 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 51 || car.code > 55)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 6:
        printf("\nHere All The Mercedez Cars Available\n");
        printf("61. Mercedez S-Class - Rs. 1.60 Crore\n");
        printf("62. Mercedez C-Class - Rs. 55.00 lakh\n");
        printf("63. Mercedez G-Class - Rs. 1.72 Crore\n");
        printf("64. Mercedez Benz    - Rs. 44.90 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 61 || car.code > 64)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;

    case 7:
        printf("\nHere All The Toyota Cars Available\n");
        printf("71. Toyota Camry        - Rs. 44.35 lakh\n");
        printf("72. Toyota Innova       - Rs. 17.86 lakh\n");
        printf("73. Toyota Fortuner     - Rs. 32.39 lakh\n");
        printf("74. Toyota Land Cruiser - Rs. 9.02 lakh\n");
        printf("\nPlease Select The Car Model You Would Like To Buy : ");
        scanf("%d", &car.code);
        if (car.code < 71 || car.code > 74)
        {
            printf("\nDear Customer Please Enter A Valid Code.");
            choose_car_model();
        }
        break;
    }
}

void choose_car_colour()
{
    {
        printf("\nThis Car Is Available In Following Colours: \n");
        printf("1. Black \n");
        printf("2. White \n");
        printf("3. Red \n");
        printf("4. Blue \n");
        printf("5. Dark Green \n");
        printf("6. Grey \n");
        printf("7. Yellow \n");

        printf("\nWhich Car Colour Would You Like To Opt For: ");
        scanf("%d", &car.colour);

        if (car.colour < 1 || car.colour > 7)
        {
            printf("Dear Customerm Please Select Valid And Available Colour");
            choose_car_colour();
        }
    }
}

const char *getCar(int n)
{
    switch (n)
    {
    case 11:
        return "Kia Sonet";
        break;
    case 12:
        return "Kia Seltos";
        break;
    case 13:
        return "Kia Carnival";
        break;
    case 21:
        return "Hyundai Santro";
        break;
    case 22:
        return "Hyundai i10";
        break;
    case 23:
        return "Hyundai i20";
        break;
    case 24:
        return "Hyundai Verna";
        break;
    case 25:
        return "Hyundai Creta";
        break;
    case 31:
        return "Honda City";
        break;
    case 32:
        return "Honda Amaze";
        break;
    case 33:
        return "Honda Jazz";
        break;
    case 41:
        return "Mahindra Thar";
        break;
    case 42:
        return "Mahindra XUV 300";
        break;
    case 43:
        return "Mahindra XUV 500";
        break;
    case 44:
        return "Mahindra XUV 700";
        break;
    case 45:
        return "Mahindra Scropio";
        break;
    case 51:
        return "Maruti Suzuki Swift";
        break;
    case 52:
        return "Maruti Suzuki Baleno";
        break;
    case 53:
        return "Maruti Suzuki Ertiga";
        break;
    case 54:
        return "Maruti Suzuki Brezza";
        break;
    case 55:
        return "Maruti Suzuki S-Cross";
        break;
    case 61:
        return "Mercedez S-Class";
        break;
    case 62:
        return "Mercedez C-Class";
        break;
    case 63:
        return " Mercedez G-Class";
        break;
    case 64:
        return "Mercedez Benz";
        break;
    case 71:
        return "Toyota Camry";
        break;
    case 72:
        return "Toyota Innova";
        break;
    case 73:
        return "Toyota Fortuner";
        break;
    case 74:
        return "Toyota Land Cruiser";
        break;
    default:
        return "Something Went Wrong!!";
        break;
    }
}

const char *getCarColour(int n)
{
    switch (n)
    {
    case 1:
        return "Black";
        break;
    case 2:
        return "White";
        break;
    case 3:
        return "Red";
        break;
    case 4:
        return "Blue";
        break;
    case 5:
        return "Dark Green";
        break;
    case 6:
        return "Grey";
        break;
    case 7:
        return "Yellow";
        break;
    default:
        return "Something Went Wrong!!";
        break;
    }
}

const char *getMMod(int n)
{
    switch (n)
    {
    case 11:
        return "Atomic";
        break;
    case 12:
        return "Off Road Wheel";
        break;
    case 13:
        return "Twist";
        break;
    case 14:
        return "Mega";
        break;
    case 21:
        return "Roof Scoop";
        break;
    case 31:
        return "Tail Light";
        break;
    case 32:
        return "Polo Light";
        break;
    case 33:
        return "Fog Light";
        break;
    case 34:
        return "White LED Light";
        break;
    case 41:
        return "Win";
        break;
    case 42:
        return "Alpha";
        break;
    case 51:
        return "Medium Exhaust";
        break;
    case 52:
        return "Twin Exhaust";
        break;
    case 61:
        return "Boost Bass";
        break;
    default:
        return ("Something Went Wrong!!");
        break;
    }
}

void fetch_selected_car()
{
    printf("\nDear Customers, You Have Opted To Buy");
    printf(" - %s(%s)", getCar(car.code), getCarColour(car.colour));
}

void display_modifications()
{
    printf("------------MODIFICATION LIST-----------\n\n");
    printf("1. Wheels\n");
    printf("2. Roof\n");
    printf("3. Lights\n");
    printf("4. Spoiler\n");
    printf("5. Side_Skirts(Exhaust)\n");
    printf("6. Car_Stereo(Sound System)\n");
    printf("\n");

    printf("What Would You Like To Modify? :");
    scanf("%d", &modifications.choice);
    if (modifications.choice < 1 || modifications.choice > 7)
    {
        printf("\nPlease Select A Valid Modification Choice.");
        display_modifications();
    }
    else
    {

        display_sub_modification_menu();
    }
}

void display_sub_modification_menu()
{
    switch (modifications.choice)
    {
    case 1:
    {
        printf("\nThese Are The Available Wheels Modification:\n");
        printf("\n11. Atomic         - Rs.2,000");
        printf("\n12. Off road wheel - Rs.4,000");
        printf("\n13. Twist          - Rs.3,000");
        printf("\n14. Mega           - Rs.2,500");
        printf("\nWhich Wheel Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 11 || modifications.sub_choice > 14)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Wheels, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.wheel_price = Mod_Cost(modifications.sub_choice);
            char che;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &che);
            if (toupper(che) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    case 2:
    {
        printf("\nThese Are The Available Roof Modification:\n");
        printf("\n21-Roof Scoop - Rs.4,000");
        printf("\nWhich Venrs Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 21 || modifications.sub_choice > 21)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Roof, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.roof_price = Mod_Cost(modifications.sub_choice);
            char ch;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &ch);
            if (toupper(ch) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    case 3:
    {
        printf("\nThese Are The Available Light Modification:\n");
        printf("\n31-Tail Light      - Rs.3,000");
        printf("\n32-Polo Light      - Rs.5,000");
        printf("\n33-Fog Light       - Rs.8,000");
        printf("\n34-White LED Light - Rs.12,000");
        printf("\nWhich Light Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 31 || modifications.sub_choice > 34)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Lights, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.light_price = Mod_Cost(modifications.sub_choice);
            char ch;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &ch);
            if (toupper(ch) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    case 4:
    {
        printf("\nThese Are The Available Spoiler Modification:\n");
        printf("\n41-Win   - Rs.12,000");
        printf("\n42-Alpha - Rs.10,000");
        printf("\nWhich Spoiler Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 41 || modifications.sub_choice > 42)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Spoiler, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.spoiler_price = Mod_Cost(modifications.sub_choice);
            char ch;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &ch);
            if (toupper(ch) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    case 5:
    {
        printf("\nThese Are The Available Side Skirts(Exhaust) Modification:\n");
        printf("\n51-Medium Exhaust - Rs.6,000");
        printf("\n52-Twin Exhaust   - Rs.8,000");
        printf("\nWhich Side Skirts(Exhaust) Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 51 || modifications.sub_choice > 52)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Exhaust, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.exhaust_price = Mod_Cost(modifications.sub_choice);
            char ch;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &ch);
            if (toupper(ch) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    case 6:
    {
        printf("\nThese Are The Available Car Stereo(Sound System) Modification:\n");
        printf("\n61-Boost Bass - Rs.15,000");
        printf("\nWhich Car Stereo(Sound System) Modification Do You Want To Implement? : ");
        scanf("%d", &modifications.sub_choice);

        if (modifications.sub_choice < 61 || modifications.sub_choice > 61)
        {
            printf("Please Select A Valid Modification Code.");
            display_sub_modification_menu();
        }
        else
        {
            strncpy(modifications.Car_Stereo, getMMod(modifications.sub_choice), strlen(getMMod(modifications.sub_choice)));
            modifications.car_stereo_price = Mod_Cost(modifications.sub_choice);

            char ch;
            printf("Do You Want To Add More Modifications(Y/N)?: ");
            scanf(" %c", &ch);
            if (toupper(ch) == 'Y')
            {
                display_modifications();
            }
        }
        break;
    }
    default:
    {
        break;
    }
    }
}
int Car_Cost(int n)
{
    switch (n)
    {
    case 11:
        return 1379000;
        break;
    case 12:
        return 1865000;
        break;
    case 13:
        return 3549000;
        break;
    case 21:
        return 489000;
        break;
    case 22:
        return 539000;
        break;
    case 23:
        return 703000;
        break;
    case 24:
        return 940000;
        break;
    case 25:
        return 1000000;
        break;
    case 31:
        return 950000;
        break;
    case 32:
        return 665000;
        break;
    case 33:
        return 811000;
        break;
    case 41:
        return 1353000;
        break;
    case 42:
        return 841000;
        break;
    case 43:
        return 931000;
        break;
    case 44:
        return 1318000;
        break;
    case 45:
        return 1199000;
        break;
    case 51:
        return 591000;
        break;
    case 52:
        return 642000;
        break;
    case 53:
        return 835000;
        break;
    case 54:
        return 799000;
        break;
    case 55:
        return 950000;
        break;
    case 61:
        return 16000000;
        break;
    case 62:
        return 5500000;
        break;
    case 63:
        return 17200000;
        break;
    case 64:
        return 4490000;
        break;
    case 71:
        return 4435000;
        break;
    case 72:
        return 1786000;
        break;
    case 73:
        return 3239000;
        break;
    case 74:
        return 902000;
        break;

    default:
        break;
    }
}
int Mod_Cost(int n)
{
    switch (n)
    {
    case 11:
        return 2000;
        break;
    case 12:
        return 4000;
        break;
    case 13:
        return 3000;
        break;
    case 14:
        return 2500;
        break;
    case 21:
        return 4000;
        break;
    case 31:
        return 3000;
        break;
    case 32:
        return 5000;
        break;
    case 33:
        return 8000;
        break;
    case 34:
        return 1200;
        break;
    case 41:
        return 12000;
        break;
    case 42:
        return 10000;
        break;
    case 51:
        return 6000;
        break;
    case 52:
        return 8000;
        break;
    case 61:
        return 15000;
        break;
    default:
        break;
    }
}
int get_random_number(int upper, int lower)
{
    return (rand() % (upper - lower + 1)) + lower;
}
void get_Mod_Total()
{
    bill.Mod_Total = modifications.wheel_price + modifications.roof_price + modifications.light_price + modifications.spoiler_price + modifications.exhaust_price + modifications.car_stereo_price;
}
void display_bill()
{
    int sml = 1, g, p;
    g = (bill.Mod_Total + Car_Cost(car.code)) * 28 / 100;
    p = (bill.Mod_Total + Car_Cost(car.code)) + g;
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    get_Mod_Total();
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\t\t\t\t\t\t\tPDEU CS CAR SHOP\n");
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("DATE: %d/%d/%d \n\n", stime.wDay, stime.wMonth, stime.wYear);
    printf("SHOP DETAILS :             \t\t\t\t\t            CUSTOMER DETAILS :\n\n");
    printf("PDEU CS CAR SHOP         \t\t\t\t\t            CUSTOMER_NAME: %s\n", cust.Name);
    printf("G-209 PANDIT DEENDAYAL   \t\t\t\t\t            MOBILE NO    : %lli\n", cust.MobileNumber);
    printf("ENERGY UNIVERSITY,         \t\t\t\t\t            E-MAIL       : %s\n", cust.Email_Id);
    printf("PDPU-ROAD, GANDHINAGAR.      \t\t\t\t\t            ADDRESS      : %s\n", cust.Adress);
    printf("MOBILE N0 : 8888888888            \n");
    printf("          : 9999999999            \n");
    printf("E-MAIL    : pdpeucar_2022@gmail.com\n\n\n");
    for (int i = 0; i <= 120; i++)
    {
        printf(":");
    }
    printf("\n\n");
    printf("CAR PURCHASED: \t\t\t\t SERIAL NUMBER: \t\t\t\t PRICE:\n");
    printf("\n\n");
    // printf("%s \t\t\t         GJ01-%c%c-%d%d%d%d\t\t\t\t\t%d\n\n",getCar(car.code),get_random_number(90,65),get_random_number(90,65),get_random_number(9,0),get_random_number(9,0),get_random_number(9,0),get_random_number(9,0),Car_Cost(car.code));
    printf("%s", getCar(car.code));
    for (int i = 0; i < 41 - strlen(getCar(car.code)); i++)
    {
        printf(" ");
    }
    printf("GJ18%c%c%d%d%d%d \t\t\t\t\t ", get_random_number(90, 65), get_random_number(90, 65), get_random_number(9, 0), get_random_number(9, 0), get_random_number(9, 0), get_random_number(9, 0));
    printf("Rs. %d\n\n", Car_Cost(car.code));

    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("MODIFICATION\n\n");
    printf("              \t\t\t\t                 \t\t\t\t PRICE:\n\n");
    printf("%s", modifications.Wheels);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n", modifications.wheel_price);
    printf("%s", modifications.Roof);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n", modifications.roof_price);
    printf("%s", modifications.Lights);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n", modifications.light_price);
    printf("%s", modifications.Spoiler);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n", modifications.spoiler_price);
    printf("%s", modifications.Exhaust);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n", modifications.exhaust_price);
    printf("%s", modifications.Car_Stereo);
    printf("\t\t\t\t\t\t\t\t\t\t Rs. %d\n\n\n", modifications.car_stereo_price);
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("   \t\t\t\t\t\t\t\t     MODIFICATION PRICE: Rs. %d\n\n", bill.Mod_Total);
    printf("   \t\t\t\t\t\t\t\t     TOTAL PRICE       : Rs. %d\n\n", bill.Mod_Total + Car_Cost(car.code));
    printf("   \t\t\t\t\t\t\t\t     28%% GST           : Rs. %d\n\n", g);
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("TOTAL PRICE(28%% GST TAX)                                                               : Rs. %d", p);
    printf("\n");
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t%c %c %c THANK YOU! VISIT AGAIN !! %c %c %c\n", sml, sml, sml, sml, sml, sml);
    for (int i = 0; i <= 120; i++)
    {
        printf("-");
    }
}