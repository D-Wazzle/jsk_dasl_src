#include <ros.h>
#include <std_msgs/Float64.h>

int pot1 = 0;
int pot2 = 5;
int led1 = 13;
int led2 = 2;
int val1 = 0;
int val2 = 0;

ros::NodeHandle  nh;
std_msgs::Float64 pot1_msg;
ros::Publisher pot1_pub("pot1_val", &pot1_msg);
std_msgs::Float64 pot2_msg;
ros::Publisher pot2_pub("pot2_val", &pot2_msg);

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(57600); // 9600
  
  nh.initNode();
  nh.advertise(pot1_pub);
  nh.advertise(pot2_pub);
}

void loop()
{
  val1 = analogRead(pot1);
  val2 = analogRead(pot2);

  pot1_msg.data = (double) val1;
  pot2_msg.data = (double) val2;
  pot1_pub.publish( &pot1_msg );
  pot2_pub.publish( &pot2_msg );
  
  nh.spinOnce();

  if(val1 < 100){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }  
  if(val2 < 100){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }

  delay(1); // 1000
}
