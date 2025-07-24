#define FORWARD 1
#define REVERSE 2
extern volatile long encoderValue1, encoderValue2, encoderValue3, encoderValue4;
void motor_Init();
void moveMotor(int, int);
void Encoder1(); void Encoder2(); void Encoder3(); void Encoder4();
