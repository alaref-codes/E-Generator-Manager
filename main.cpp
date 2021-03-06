// This program is made by ('Alaref Abushaala') and ('Mohamed algaramanly') and it made for generator follow up
#include <iostream>
#include <windows.h>
#include <ctime>
#include <mmsystem.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void gotoxy(int x,int y)
    {
        COORD coord;
        coord.X=x;
        coord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    void state()
    {
      gotoxy(35,8);
      SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
      cout<<"2 - End";
      SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    void state1()
    {
      gotoxy(35,6);
      SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
      cout<<"1 - Start";
      SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
void Invalid()
{

        gotoxy(50,8);
        cout<<"Invalid input";
        PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
        Sleep(500);
        gotoxy(50,8);
        cout<<"                     " <<endl;
        cin.clear();
        cin.ignore (100, '\n') ;
}
void window()
{
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for(int i = 0 ; i<9 ; i++)
    {
        gotoxy(30,i);
        cout <<"|";
    }
    for(int i = 1 ; i<30 ; i++)
    {
        gotoxy(i,8);
        cout<<"_";
    }

}

void menu()
{
    gotoxy(50,3);
     SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
     cout<<"Generator";
      for (int i=40 ; i<70 ; i++)
     {
         gotoxy(i,2);
         cout<<"%";
     }
       for (int i=40 ; i<70 ; i++)
     {
         gotoxy(i,4);
         cout<<"%";
     }
     gotoxy(35,6);
     cout<<"1 - Start";
     gotoxy(35,8);
     cout<<"2 - End";
     gotoxy(35,10);
     cout<<"3 - Maintenance";
     gotoxy(35,12);
     cout<<"4 - Generator Specifications";
     gotoxy(35,14);
     cout<<"5 - Reports";
     gotoxy(35,16);
     cout<<"6 - Close the program ";
     gotoxy(59,18);
     cout<<"|";
     gotoxy(60,17);
     cout<<"_";
     gotoxy(61,18);
     cout<<"|";
     gotoxy(60,18);
     cout<<"_";
     gotoxy(60,18);
}
void frame()
{
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  for (int i=1 ; i<30 ; i++)
     {
         gotoxy(1,i);
         cout<<"|";
     }
      for (int i=1 ; i<30 ; i++)
     {
         gotoxy(111,i);
         cout<<"|";
     }
     for (int i=0 ; i<111 ; i++)
     {
         gotoxy(i,0);
         cout<<"~";
     }
     for (int i=2 ; i<111 ; i++)
     {
         gotoxy(i,29);
         cout<<"~";
     }
}
struct Date
{
    int day;
    string month;
    int year;
};

struct generator
{
    string name,model,country,voltage;
    float capacity;
    float fuelconsum;
    float oilconsum,frequency,powerFactor;
    string fueltype;
    int primePower,standbyPower,RPM;
    Date date;
};
generator gene ={"Perkins" , "WPS2505" , "Germany", "400/250" , 200 , 10.0 , 0.3 , 50 , 0.8
                           ,"gasoline"  , 250 , 270  , 1500};
struct consum
{
    int rec_no;
    float hour;
    float minute;
    float consumed;
}consumption;


int main()
{
    ofstream olamed;
    ifstream ilamed;
    ofstream saveTime;
    ifstream saveTime0;
    ofstream ofuel;
    ifstream ifuel;
    ofstream ooil;
    ifstream ioil;
    ofstream ohange;
    ifstream ihange;
    float rightfuel,rightfuel2,starthour,startminute,shuthour,shutminute,addedFuel, times,ffuel;
    char input,input1,input2;
    int stateOfG;
    char partName[80] ;
    int remainHour, remainMinute;
    time_t now;
    struct tm nowLocal;
    now = time(NULL) ;
    nowLocal = *localtime(&now);
    int day,month,year;

    gene.date.day = 20;
    gene.date.month = "jan";
    gene.date.year = 2014;

        saveTime0.open("saveTime.text");
        saveTime0>>stateOfG;
        saveTime0.close();
        cout <<stateOfG ;
        Sleep(1000);
        if (stateOfG == 1)
        {
            saveTime0.open("saveTime.text");
            saveTime0>>stateOfG>>starthour>>startminute;
            saveTime0.close();


             ifuel.open("fuel.txt");
             ifuel>>rightfuel;
             ifuel.close();

             rightfuel2 = rightfuel ;

             shuthour = nowLocal.tm_hour;
             shutminute = nowLocal.tm_min;

          if (shuthour >= starthour )
                consumption.hour = shuthour - starthour;
            else
                consumption.hour =24 - (starthour - shuthour);

            if (startminute > shutminute)
            {
                consumption.minute = 60 -(startminute - shutminute);
                consumption.hour -- ;
            }
            else if(shutminute >= startminute)
            {
                 consumption.minute = shutminute - startminute;
            }

          if((starthour == shuthour) && (startminute > shutminute))
            {
               consumption.hour = 23;
               consumption.minute = startminute - shutminute;
            }

           ffuel=gene.fuelconsum * (consumption.hour + (consumption.minute/60));
           rightfuel2 = rightfuel - ffuel ;
           times = rightfuel2 / gene.fuelconsum;
           remainHour = times;
           remainMinute = (times - remainHour)*60;


             if (rightfuel2 < 1)
        {
            rightfuel2 = 0.0 ;

            shuthour = remainHour + starthour;

            shutminute = remainMinute + startminute ;
            if(shuthour > 23)
             shuthour = 24 - (remainHour + starthour) ;


            if(shutminute > 59)
            {
            shutminute = 60 - (remainMinute + startminute) ;
                shuthour++;
            }

                if (shuthour >= starthour )
                consumption.hour = shuthour - starthour;
            else
                consumption.hour =24 - (starthour - shuthour);
            if (startminute > shutminute)
            {
                consumption.minute = 60 -(startminute - shutminute);
                consumption.hour -- ;
            }
            else if(shutminute >= startminute)
            {
                 consumption.minute = shutminute - startminute ;
            }
            if((starthour == shuthour) && (startminute > shutminute))
           {
               consumption.hour = 23;
               consumption.minute = startminute - shutminute;
            }


         times = rightfuel2 / gene.fuelconsum;
         remainHour = times;
         remainMinute = (remainHour - times) *60;
           olamed.open("follow.txt",ios::app);

          consumption.consumed = gene.fuelconsum * (consumption.hour + (consumption.minute/60));


         if (consumption.consumed > 200 )
         {
                consumption.consumed = 200;
         }
         if (consumption.consumed < 0 )
         {
                consumption.consumed = 0;
         }

          olamed <<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900 <<"    ";
          olamed<<starthour <<" "<<startminute<<" "<< shuthour<<" "<<shutminute;
          olamed<<"   "<<  consumption.consumed;

          olamed.close();

            stateOfG = 0;
            saveTime.open("savetime.text" ,ios::trunc);
            saveTime << "0";
            saveTime.close();
            ofuel.open("fuel.txt" ,ios::trunc);
            ofuel << 0 ;
            ofuel.close();
        }

        }

    while(true)
    {
        saveTime0.open("saveTime.text");
        saveTime0>>stateOfG>>starthour>>startminute;
        saveTime0.close();

        ifuel.open("fuel.txt");
        ifuel>>rightfuel;
        ifuel.close();

 if(stateOfG == 0)
    {

         times = rightfuel / gene.fuelconsum;
         remainHour = times;
         remainMinute = (times - remainHour)*60;

     if (rightfuel > 15)
     {
     system("CLS");
     window();
     gotoxy(3,2);
     cout<<"state : ";
     cout<<"turned off";
     gotoxy(3,4);
     cout<<"Fuel : "<<rightfuel<<" Liter"<<endl;
     gotoxy(3,6);
     cout<<"Endurance : "<<remainHour<< " : " <<remainMinute ;
     frame();
     menu(); // 28
     state();
     gotoxy(60,18);
     cin >> input ;
     }else    // right fuel < 15
     {
     system("CLS");
     gotoxy(3,2);
     cout<<"status";
     window();
     gotoxy(3,2);
     cout<<"state : "<<"turned off";
     gotoxy(3,4);
     cout<<"Fuel : "<<rightfuel<<" Liter"<<endl;
     gotoxy(3,6);
     cout<<"Endurance : "<<remainHour<< " : " <<remainMinute ;
     frame();
     menu(); //28
     state();
     gotoxy(60,14);
     for (int i = 0 ; i<5 ; i++)
     {
     Sleep(350);
     gotoxy(10,4);
     cout<<rightfuel;
     Sleep(350);
     gotoxy(10,4);
     cout<<"         ";
     }
     gotoxy(10,4);
     cout<<rightfuel<<" Liter";
     gotoxy(60,18);
     cin >> input ;
     }
    }
    else
        if (stateOfG == 1) // turned on !!!
    {
        if(rightfuel2> 15)
        {
     system("CLS");
       window();
     gotoxy(3,2);
     cout<<"state : ";
     cout<<"turned on   "<<starthour <<" : "<< startminute;
     gotoxy(3,4);
     cout<<"Fuel : "<<rightfuel2<<" Liter"<<endl;
     gotoxy(3,6);
     cout<<"Endurance : "<<remainHour<< " : " <<remainMinute ;
    frame();
     menu(); //28
     state1();

     gotoxy(60,14);
     cin >> input ;
        }else
        if (rightfuel2 <= 15)
        {
     system("CLS");
         window();
     gotoxy(3,2);
     cout<<"state : "<<"turned on"<<remainHour<< " : " <<remainMinute ;
     gotoxy(3,4);
     cout<<"Fuel : "<<rightfuel2<<" Liter"<<endl;
     gotoxy(3,6);
     cout<<"Endurance : "<<remainHour<< " : " <<remainMinute ;
     frame();
     menu(); //28
     state1();
     gotoxy(60,18);
     for (int i = 0 ; i<5 ; i++)
     {
      Sleep(350);
      gotoxy(10,4);
     cout<<rightfuel2;
     Sleep(350);
     gotoxy(10,4);
     cout<<"             ";
     }
     gotoxy(10,4);
     cout<<rightfuel2<<" Liter";

     gotoxy(60,18);
     cin >> input ;
        }
    }
        while (true)
        {
            if( (input == '1')  || (input == '2') || (input == '3') || (input == '4') || (input == '5') || (input == '6') || (input == '7') )
               break ;
            else
            {
                gotoxy(43 , 19);
                cout<<"Please choose a number from the list";
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                Sleep(500);
                gotoxy(60 , 12);
                cout<<" ";
                gotoxy(60 , 18);
                cin >> input ;
            }
        }
     if (input == '1')  //  to start
     {
            if (stateOfG==1)
            {
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                gotoxy(20 , 18);
                cout<<" The generator is already working! \n";
                gotoxy(20 , 19);
                system("pause");
            }
            else
                if (rightfuel < 1 )
                {
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                gotoxy(20 , 18);
                cout<<" There is not enough fuel !! \n";
                gotoxy(20,19);
                system("pause");
                }
            else
            {
              system("CLS");
              frame();
              gotoxy(50,2);
              cout <<"Starting the generator ";
              gotoxy(40,4);
              cout<<"Please Enter the time of the start  (Hour / minute) : ";
              gotoxy(40,6);
              cout<<"time in the 24 hour system : " ;
        while (! (cin>>starthour) || (starthour>23) || (starthour<0))
        {
        Invalid(); // line 19
        gotoxy(69,6);
        cout<<"             ";
        gotoxy(69,6);
        }
        gotoxy(71,6);
        cout<<" : ";
        gotoxy(74,6);
       while (! (cin>>startminute) || (startminute>59)  || (startminute<0))
        {
         Invalid();  // line19
         gotoxy(74,6);
         cout<<"             ";
         gotoxy(74,6);
        }
        stateOfG = 1;
        saveTime.open("saveTime.text",ios::trunc);
        saveTime<<stateOfG<<endl<<starthour<<endl<<startminute;
        saveTime.close();

        rightfuel2 = rightfuel;

        cout<<rightfuel<<"     "<<rightfuel2;
        Sleep(1500);


        gotoxy(40,9);
        cout<<"The generator is now starting ";
        PlaySound(TEXT("car+start3"),NULL,SND_SYNC);
        gotoxy(20,11);
        cout<<"press [ Y ] to return to the main menu or press [ E ] to close the program : ";
        gotoxy(98,11);
        cin>>input ;
           while(1)
            {
                if(input=='y' || input == 'Y')
                {
                    break;
                }
                else if(input=='e' || input == 'E')
                {
                    return 0;
                }
                else
                {
                    gotoxy(45,13);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(45,13);
                    cout<<"                                                                            ";
                    gotoxy(98,11);
                    cout<<"             ";
                    gotoxy(98,11);
                    cin>>input;
                }
            }
            }

     }
     else
     if (input == '2') // to shut
     {
         if (stateOfG==0){
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                gotoxy(20 , 18);
                cout<<" The generator is not even working ! \n";
                gotoxy(20 , 19);
                system("pause");

      }
            else {
         system("CLS");
         frame();
         gotoxy(50,2);
        cout <<"Shutting the generator ";
        gotoxy(40,4);
        cout<<"Please Enter the time of the Shutting  (Hour / minute) : ";
        gotoxy(40,6);
        cout<<"time in the 24-hour system : " ;
        while (! (cin>>shuthour) || (shuthour>23) || (shuthour<0))
        {
         Invalid();
         gotoxy(69,6);
         cout<<"             ";
         gotoxy(69,6);
        }
        gotoxy(71,6);
        cout<<" : ";
        gotoxy(74,6);
       while (! (cin>>shutminute) || (shutminute>59)  || (shutminute<0))
        {
         Invalid();
         gotoxy(74,6);
         cout<<"             ";
         gotoxy(74,6);
        }
      if (shuthour >= starthour )
                consumption.hour = shuthour - starthour;
            else
                consumption.hour =24 - (starthour - shuthour);
            if (startminute > shutminute)
            {
                consumption.minute = 60 -(startminute - shutminute);
                consumption.hour -- ;
            }
            else if(shutminute >= startminute)
            {
                 consumption.minute = shutminute - startminute ;
            }
            if((starthour == shuthour) && (startminute > shutminute))
           {
               consumption.hour = 23;
               consumption.minute = startminute - shutminute;
            }
          consumption.consumed = gene.fuelconsum * (consumption.hour + (consumption.minute/60));

          if (consumption.consumed > 200 )
                consumption.consumed = 200;

         if (consumption.consumed < 0 )
                consumption.consumed = 0;

          consumption.consumed = gene.fuelconsum * (consumption.hour + (consumption.minute/60));
          olamed.open("follow.txt" , ios::app);

          olamed <<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900 <<"    ";
          olamed<<starthour <<" "<<startminute<<" "<< shuthour<<" "<<shutminute;
          olamed<<"   "<<  consumption.consumed <<endl;
          olamed.close();


        gotoxy(30,10);
        cout<<"Total work time is  : "<<consumption.hour <<" : "<<consumption.minute;
        gotoxy(30,12);
        cout<<"fuel consumed is : "<<consumption.consumed<<" Liter ";


        rightfuel = rightfuel - consumption.consumed;
        if (rightfuel < 0)
        {
            rightfuel = 0.0 ;
        }

        saveTime.open("saveTime.text",ios::trunc);
        saveTime<<"0";   //stageOfG = 0
        saveTime.close();

        ofuel.open("fuel.txt" , ios::trunc);
        ofuel<<rightfuel;
        ofuel.close();

        gotoxy(20,14);
        cout<<"press [ Y ] to return to the main menu or press [ E ] to close the program : ";
        gotoxy(98,14);
        cin>>input;
           while(1)
            {
                if(input=='y' || input == 'Y')
                {
                    break;
                }
                else if(input=='e' || input == 'E')
                {
                    return 0;
                }
                else
                {
                    gotoxy(35,16);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(35,16);
                    cout<<"                                                                            ";
                    gotoxy(98,14);
                    cout<<"             ";
                    gotoxy(98,14);
                    cin>>input;
                }
            }
            }

     }
    else
      if(input == '3') // maintenance
     {
        while(true)
        {
        system("CLS");
        frame();
        gotoxy(35,3);
        cout<<"1 - Add fuel ";
        gotoxy(35,5);
        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout<<"2 - change the oil ";
        SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        gotoxy(35,7);
        cout<<"3 - change any thing";
        gotoxy(35,9);
        cout<<"4 - return to the menu";
        cin>>input1;
        while(true)
        {
            if(input == '1' ||  input == '2'  || input == '3' || input == '4')
                break;
            else
                {
                gotoxy(43 , 14);
                cout<<"Please choose a number from the list";
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                Sleep(500);
                gotoxy(60 , 12);
                cout<<" ";
                gotoxy(60 , 12);
                cin>>input1;
                }
        }
        if(input1 == '1')
        {
            system("CLS");
            frame();
            gotoxy(45,3);
            cout<<"Adding fuel";
            gotoxy(25,5);
            cout<<"(Maximum = 200 liter) : ";
            gotoxy(50,5);
            while (! (cin>>addedFuel) || (addedFuel>200) )
                {
                    Invalid(); // line 19
                    gotoxy(47,5);
                    cout<<"           ";
                    gotoxy(47,5);
                }
            rightfuel = rightfuel + addedFuel ;
            if (rightfuel > 200 )
            {
                gotoxy(45,7);
                cout<<"TANK IS FULL!";
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                Sleep(200);
                 gotoxy(45,7);
                cout<<"                         ";
                gotoxy(105,5);
                cout<<"      ";
                cin.clear();
                cin.ignore (100, '\n') ;
            }
            else
        {
            ofuel.open("fuel.txt" , ios::trunc);
            ofuel<<rightfuel;
            ofuel.close();
            gotoxy(15,7);
            cout<<addedFuel<<"  Liter of fuel has been added!";
            gotoxy(15,9);
            cout<<"press [ Y ] to return to the main menu or press [ E ] to close the program : ";
            gotoxy(98,11);
            cin>>input1 ;
            while(1)
            {
                if(input1=='y' || input1 == 'Y')
                {
                    break;
                }
                else if(input1=='e' || input1 == 'E')
                {
                    return 0;
                }
                else
                {
                    gotoxy(45,13);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(45,13);
                    cout<<"                                                                            ";
                    gotoxy(98,11);
                    cout<<"             ";
                    gotoxy(98,11);
                    cin>>input1;
                }
        }
        }
        }
        else
        if( input1 == '2')
        {
            system("CLS");
             cout<<"Please enter how many liter you want to add : ";
        }
        else
        if(input1 == '3')
        {
            system("CLS");
            frame();
            gotoxy(45,3);
            cout<<"Placement";
            gotoxy(35,5);
            cout<<"1 - Updates history";
            gotoxy(35,7);
            cout<<"2 - Modification ";
            cin>>input2;
              while (true)
        {
            if( (input2 == '1')  || (input2 == '2')  )
               break ;
            else
            {
                gotoxy(43 , 14);
                cout<<"Please choose a number from the list";
                PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                Sleep(500);
                gotoxy(60 , 12);
                cout<<" ";
                gotoxy(60 , 14);
                cin >> input2 ;
            }
        }
        if(input2 == '1' )
        {
            system("CLS");
            frame();
                for(int i = 2 ; i<28 ; i++)
                {
                    gotoxy(13,i);
                    cout<<"|";
                }
                 for(int i = 2 ; i<28 ; i++)
                {
                    gotoxy(41,i);
                    cout<<"|";
                }
                    for(int i = 2 ; i<40 ; i++)
                {
                    gotoxy(i,4);
                    cout<<"_";
                }
                    for(int i = 2 ; i<40 ; i++)
                {
                    gotoxy(i,1);
                    cout<<"_";
                }
                gotoxy(50,3);
                cout<<"Update history";
                gotoxy(45,5);
                cout<<" 0 = Delete History & go back to previous menu ";
                gotoxy(45,6);
                cout<<" Y = Back to previous menu";
                gotoxy(45,7);
                cout<<" E = Close the program";
                 gotoxy(6,3);
                cout<<"Date";
                gotoxy(16,3);
                cout<<"Part name";

            int x=6;
            string part;
             ihange.open("change.txt");
            while((ihange>>day>>month>>year) && (getline(ihange,part)) )
            {
                gotoxy(3,x);
                cout<<day<<"/"<<month<<"/"<<year;
                gotoxy(15,x);
                cout<<part;
                x++; x++;
            }
            ihange.close();
                cin>>input2;
           while(1)
            {
                if(input2 == '0')
                {
                    ohange.open("change.txt", ios::trunc);
                    ohange.close();
                    break ;

                }
                else
                if(input2=='y'||input2=='Y')
                {
                    break;

                }
                else if(input2=='e'||input2=='E')
                    return 0;
                else
                {
                    cout<<"error! please choose either Y or E";
                    cin>>input;
                }
            }

        }
        else
        if(input2 == '2')
        {
        system("CLS");
         frame();
        gotoxy(35,3);
        cout<<"Modification";
        gotoxy(25,6);
        cin.ignore(80,'\n');
        cout<<"Name of part : ";
        gotoxy(40,6);
        cin.getline(partName,100) ;

        ohange.open("change.txt", ios::app);
        ohange<<nowLocal.tm_mday <<"   "<<nowLocal.tm_mon+1<<"  "<<nowLocal.tm_year+1900<<"  "<< partName <<endl;
        ohange.close();
        gotoxy(15,8);
        cout<<"The "<<partName<< " has been changed successfully !";
        gotoxy(15,10);
            cout<<" [ Y ] = return to the main menu";
            gotoxy(15,11);
            cout<<" [ E ] = close the program  ";
            gotoxy(60,11);
            cin>>input2 ;
            while(1)
            {
                if(input2=='y' || input2 == 'Y')
                {
                    break;
                }
                else if(input2=='e' || input2 == 'E')
                {
                    return 0;
                }
                else
                {
                    gotoxy(45,13);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(45,13);
                    cout<<"                                                                            ";
                    gotoxy(98,11);
                    cout<<"             ";
                    gotoxy(98,11);
                    cin>>input1;
                }
        }
        }

        }
        else
        if(input1 == '4')
        {
            break;
        }
        }
     }
     else
      if(input == '4') // the generator
     {
         system("CLS");
            gotoxy(45,1);
            cout <<" The generator ";
            gotoxy(35,3);
            cout<<"name  :        "<<gene.name;
            gotoxy(35,5);
            cout << "Model :        "<<gene.model;
            gotoxy(35,7);
            cout<<"country :      "<<gene.country;
            gotoxy(35,9);
            cout<<"capacity :     "<<gene.capacity<<" Liter";
            gotoxy(35,11);
            cout<<"Prime power :  "<<gene.primePower<<" KVA";
            gotoxy(35,13);
            cout<<"Frequency :    "<<gene.frequency<<" HZ";
            gotoxy(35,15);
            cout<<"Power factor : "<<gene.powerFactor;
            gotoxy(35,17);
            cout<<"RPM :          "<<gene.RPM<<" Per minute";
            gotoxy(35,19);
            cout<<"oil burn rate:"<<gene.oilconsum;
            gotoxy(35,21);
            cout<<"fuel type :    "<<gene.fueltype;
            gotoxy(35,23);
            cout<<"fuel consume rate:"<<gene.fuelconsum<<"Liter per hour";
            gotoxy(35,25);
            cout<<"operation date:"<<gene.date.day<<" / "<<gene.date.month<<" / "<<gene.date.year;
            gotoxy(20,27);
            cout<<"press [ Y ] to return to the main menu or press [ E ] to close the program : ";
            gotoxy(98,27);
            cin>>input;
            while(1)
            {
                if(input=='y' || input == 'Y')
                    break;
                else if (input=='e' || input == 'E')
                    return 0;
                else
                {
                    gotoxy(35,24);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(35,24);
                    cout<<"                                                                            ";
                    gotoxy(98,22);
                    cout<<"             ";
                    gotoxy(98,22);
                    cin>>input;
                }
             }
     }
    else
      if(input == '5')
      {
          system("CLS");
          int Shour , Ehour , Sminute , Eminute,x=6,OP=1;
          float  fuelConsumed;
          frame();
          for(int i = 2 ; i<65 ; i++)
          {
              gotoxy(i,1);
              cout<<"_";
          }
          for(int i = 2 ; i<65 ; i++)
          {
              gotoxy(i,4);
              cout<<"_";
          }

            for(int i = 1 ; i<29 ; i++)
          {
              gotoxy(65,i);
              cout<<"|";
          }
           for(int i = 1 ; i<29 ; i++)
          {
              gotoxy(7,i);
              cout<<"|";
          }
           for(int i = 1 ; i<29 ; i++)
          {
              gotoxy(18,i);
              cout<<"|";
          }

           for(int i = 1 ; i<29 ; i++)
          {
              gotoxy(30,i);
              cout<<"|";
          }
           for(int i = 1 ; i<29 ; i++)
          {
              gotoxy(45,i);
              cout<<"|";
          }
          gotoxy(78,3);
          cout<<"Reports";
          gotoxy(67,5);
          cout<<" 0 = Delete History & go back to main menu ";
          gotoxy(67,6);
          cout<<" Y = Back to main menu";
          gotoxy(67,7);
          cout<<" E = Close the program";
          gotoxy(5,3);
          cout<<"OP";
          gotoxy(12,3);
          cout<<"Date";
          gotoxy(20,3);
          cout<<"Start hour";
          gotoxy(34,3);
          cout<<"Shut minute";
          gotoxy(49,3);
          cout<<"Fuel consumed";

            ilamed.open("follow.txt");
            ilamed>>day;
            while(!ilamed.eof())
           {
            ilamed >> day >> month >> year >> Shour >> Sminute >> Ehour  >> Eminute >> fuelConsumed ;
           gotoxy(4,x);
           cout << OP;
           gotoxy(9,x);
           cout<<day<<"/"<<month<<"/"<<year;
           gotoxy(19,x);
           cout<<Shour<<" : "<<Sminute;
           gotoxy(32,x);
           cout<<Ehour<<" : "<<Eminute;
           gotoxy(46,x);
           cout<<fuelConsumed<<" Liter";

            x++;x++;
            OP++;
           }

            ilamed.close();
            gotoxy(98,14);
            cin>>input1;
            while(1)
            {
                if(input1 == '0')
                {
                    olamed.open("follow.txt" , ios::trunc);
                    olamed.close();
                    break;
                }
                if(input1=='y' || input1 == 'Y')
                {
                    break;
                }
                else if(input1=='e' || input1 == 'E')
                {
                    return 0;
                }
                else
                {
                    gotoxy(35,16);
                    cout<<"error! please choose either [ Y ] or [ E ]  ";
                    PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
                    Sleep(500);
                    gotoxy(35,16);
                    cout<<"                                                                            ";
                    gotoxy(98,14);
                    cout<<"             ";
                    gotoxy(98,14);
                    cin>>input;
                }
            }
          }
     else
      if(input == '6')
      {
         return 0;
     }
    }
}

