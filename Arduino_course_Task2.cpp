
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
String N1;
String n;
//char KEY ;
//int flage = 0 ; 
int NUM = 0;
char oper = 0;
String S;
int i =0 ;
int j = 0; 
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte cols = 4;
const byte rows = 4;
char keys[rows][cols] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '*' },
  { 'C', '0', '#', '/' },
};
byte colspins[cols] = { A0, A1, A2, A3 };

byte rowspins[rows] = { 13, 12, 11, 10 };

Keypad kpd = Keypad(makeKeymap(keys), rowspins, colspins, rows, cols);

void setup()

{
  Serial.begin(9600);
  kpd.setDebounceTime(50);

  for (int i = 0; i < 8; i++) {

    pinMode(i, OUTPUT);
  }
  Wire.begin();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
}
bool OPeratorCHk(char c) {
  //bool CHK =
  return c == '*' || c == '/' || c == '-' || c == '+';
}
void loop() {

  char key = kpd.getKey();
 


  if (key) {
    if (S.length() == 0 && OPeratorCHk(key) ) {
      Serial.println("LOOP1");

    }

    else if (OPeratorCHk(S.charAt(S.length() - 1)) && OPeratorCHk(key)) {
      Serial.println("LOOP2");



    } else if (key!='#') {

     



      S += key;
      lcd.print(key);
       if (OPeratorCHk(key)) 
       { oper = key;
                  Serial.println("TRR");
      N1="";
       }
        if (!OPeratorCHk(key)) {
        N1 += key;

      }

      if(key >= '0' && key <= '9' && !OPeratorCHk(key) ) 
{ Serial.println("I1 " + N1+" I2 " + NUM+" JJJ "+j);
      
        if (oper == '+') {
        if (j == 0)
                   NUM =n.toInt();

        NUM+=N1.toInt();
          j=1;
          Serial.println("I1 " + N1+" I2 +" + NUM+" JJJ "+j);
       
      }
    else  if (oper == '-') {
        if (j == 0)
                    NUM =n.toInt();

        NUM -= N1.toInt();
        j=1;
      }
      else if (oper == '*') {
        if (j == 0)
                    NUM =n.toInt();

        j=1;
        NUM *= N1.toInt();
      }
      else if (oper == '/') {
        
        if (j == 0){
         
          NUM =n.toInt();
        }
        j=1;
        NUM /= N1.toInt();
      }

        else 
        {
n += key ; 
          Serial.println("FUCK "+n);
        }
}



     
  
 

      

    }
  
  else if (key == '#') {
        Serial.println("J1 " + N1+" J2 " + NUM);
     lcd.clear();
    lcd.setCursor(0, 0);      
     lcd.print(" ");

    S += '=';
         lcd.setCursor(0, 0);      

    lcd.print(S);
    lcd.print(NUM);
             lcd.setCursor(7, 1);      
    lcd.print("Final Answer");

    Serial.println(NUM);
    delay(1000);

    NUM = 0;
    N1 = "";
    S = "";
    oper = 0;
    i = 0;
    j=0;
    key = 0;
    n="";

    
    //flage =0;
   while (1)
  {
 key = kpd.getKey();
if ( key )
{
 
 lcd.setCursor(0, 0); 
  lcd.clear();

return;
} 
    //else if ( key=='#')
    //{
//return ;
    //}
  }
  }

   if (key =='C')
  {
         Serial.println("CCCCCC");

    NUM = 0;
    N1 = "";
    S = "";
    oper = 0;
    i = 0;
    j=0;
    key = 0;
    n="";

    
    //flage =0;
    lcd.setCursor(0, 0);
     lcd.clear();
return ;

  }
}
}