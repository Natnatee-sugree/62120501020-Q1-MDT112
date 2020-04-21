int light ;
int count = 1;
int Faster = 100;
void setup(){
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
for (int light = 3; light <= 13; light++) 
    {
    
    pinMode(light, OUTPUT);
    }
    
    tone(8,200,500);
    delay (250);
    tone(8,400,100);
    delay(100);

    }
void loop()
{
    for (int light = 3; light <= 13; light++) 
    { 
        if (light == 8) 
        {
        digitalWrite(light,0); 
        continue;
        }
    
        digitalWrite(light,1);
        delay(Faster);
        digitalWrite(light,0);
    
        if ( digitalRead(2) == 0 )
        {                     
            count = count*2;
            Faster = Faster / 2;
            delay(800);
            Serial.println("I'm the Flash X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            
        }
} 
    for (int light = 13; light >= 3; light--) 
    { 
        if (light == 8) 
        {
        digitalWrite(light,0);
        continue;
        }
    
        digitalWrite(light,1);
        delay(Faster);
        digitalWrite(light,0);
        if ( digitalRead(2) == 0 )
        {                     
            count = count*2;
            Faster = Faster / 2;
            delay(800);
            Serial.println("I'm the Flash X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            
        }

    }
}

