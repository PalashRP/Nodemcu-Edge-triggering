const int  buttonPin1 = D5;// the pin that the pushbutton is attached to, takes "." as an input
const int  buttonPin2 = D6;// the pin that the pushbutton is attached to, takes "-" as an input
const int  buttonPin3 = D7;// the pin that the pushbutton is attached to, takes " " as an input
const int  buttonPin4 = D8;// the pin that the pushbutton is attached to, prints the current status of array

int i, k;
int count1 = 0;//counter for array 1 which will store the pushButtonCounter values for that D5 pin(suppose you are pressing buttons randomly, this "pushButtonCounter" will count the of numbers
int count2 = 0;//counter for array 2 which will store the pushButtonCounter values for that D6 pin .. of button presses, and if you want to keep track of the relative positions of each charater i.e. (".","-"," ")
int count3 = 0;//counter for array 3 which will store the pushButtonCounter values for that D7 pin ..with respective to the "pushButtonCounter" these array will individually store the position
//at which these were triggered. for example String= "." "-" "-" "." " " "-" "." "-" "." " " "-" "-" " " "." "-"
                                                    //1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
                                                    //then array1 will store 1, 4, 7, 9, 14
                                                    //then array1 will store 2, 3, 6, 8, 11, 12, 15
                                                    //then array1 will store 5, 10, 13   
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState1 = 0;// current state of the button1
int buttonState2 = 0;// current state of the button2
int buttonState3 = 0;// current state of the button3
int buttonState4 = 0;// current state of the button3

int lastButtonState1 = 0;// previous state of the button
int lastButtonState2 = 0;// previous state of the button
int lastButtonState3 = 0;// previous state of the button
int lastButtonState4 = 0;// previous state of the button
int array1[20];// declaring array1 and size
int array2[20];// declaring array2 and size
int array3[20];// declaring array3 and size
int array4[60];// declaring array4 and size

void setup() {
  pinMode(buttonPin1, INPUT);//pinfunctions
  pinMode(buttonPin2, INPUT);//pinfunctions
  pinMode(buttonPin3, INPUT);//pinfunctions
  pinMode(buttonPin4, INPUT);//pinfunctions
  Serial.begin(9600);
  Serial.println("Setup done");// debugging purpose

}

void loop() {


  buttonState1 = digitalRead(buttonPin1);//reading the state of button1
  buttonState2 = digitalRead(buttonPin2);//reading the state of button2
  buttonState3 = digitalRead(buttonPin3);//reading the state of button3
  Serial.println("Initiation Done");//debugging purpose


  //..................................................................................
  if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on_1");// debugging purpose
      array1[count1] = buttonPushCounter;// storing value of the buttonPushCounter when button1 was pressed
      count1++;//incrementing count1
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off_1");//// debugging purpose
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
   lastButtonState1 = buttonState1; //changing the states
  //................................................................................

  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on_2");// debugging purpose
      array1[count2] = buttonPushCounter;// storing value of the buttonPushCounter when button2 was pressed
      count2++;//incrementing count2
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off_2");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  lastButtonState2 = buttonState2; //changing the states
  //..............................................................................
  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on_3");
      array1[count3] = buttonPushCounter;
      count3++;
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off_3");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  lastButtonState3 = buttonState3; //changing the states

  //...............................................................................
  //this button is used for printing the current status of array(printing the charater buttons pushed till now in the sequence they were pushed)
  if (buttonState4 != lastButtonState4) {
    // if the state has changed, perform the printing 
    if (buttonState4 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      for (i = 0; i < buttonPushCounter; i++)
    {
      Serial.print(array4[i]);

    } // Delay a little bit to avoid bouncing
    delay(50);
  }
  lastButtonState4 = buttonState4; //changing the states

 //...............................................................................
  
  
  
// the program written below will increment a variable k 20 times because size of the smaller arrays are 20; it will also use i variable which will be equal to the number of buttonPushCounter
//now all these three arrays will contain buttonPushCounter values when their pin was at high state, it is explained above with example. now when reassembling the complete string by merging
//all the charactes in the series in which they were pushed, this array is designed to reconstruct that complete array.
   
  for (i = 1; i < buttonPushCounter + 1; i++)
  {
    Serial.println("Filling array4");

    for (k = 0; k < 20; k++)
    {
      if (array1[k] == i)
      {
        array4[i] = 1;
        Serial.println("up array1");
      }


      if (array2[k] == i)
      {
        array4[i] = 2;
        Serial.println("up array2");
      }

      if (array3[k] == i)
      {
        array4[i] = 3;
        Serial.println("up array3");
      }

    }

  }
  
}
