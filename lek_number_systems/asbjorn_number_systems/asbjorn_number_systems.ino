void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
}

void printByteH(int16_t c)
{
  int n;
  Serial.print("0x");
  n = (0xF000  & c) >> 12;
  Serial.print(n, HEX);
  n = (0x0F00  & c) >> 8;
  Serial.print(n, HEX);
  n = (0x00F0  & c) >> 4;
  Serial.print(n, HEX);
  n = (0x000F  & c);
  Serial.print(n, HEX);
  }

void printByteB(int16_t c)
{
  for (int i = 15; 0 <= i; i--) {
    if (c & (1 << i))
      Serial.print("1");
    else
      Serial.print("0");
  }
}
int16_t signedByte = 10000;
void loop()
{
  Serial.print(signedByte, DEC); Serial.print("  ");
  Serial.print((char)(signedByte >> 8));Serial.print((char)signedByte); Serial.print("  ");
  printByteB(signedByte); Serial.print("  ");
  printByteH(signedByte); Serial.print("  ");
  signedByte++;
  Serial.println("");
}
