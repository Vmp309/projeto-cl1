// pinos que serão a entrada do registrador de deslocamento (binário):

int q0 = 13; // menos significativo
int q1 = 12;
int q2 = 11;
int q3 = 10; // mais significativo
int botao = 22;
int pulso = 23;
int altera = 24;

int linhas[]  = {2, 3, 4, 5}; // pinos das linhas
int colunas[] = {6, 7, 8, 9}; // pinos das colunas
char teclas[4][4] = {{'1','2','3','A'}, //matriz de teclas
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};

void setup()
{
  pinMode(pulso, OUTPUT);
  pinMode(botao, INPUT);
  
  for (int nL = 0; nL <= 3; nL++) {
     pinMode(linhas[nL], OUTPUT); // seta as colunas como saída e joga o nível alto
     digitalWrite(linhas[nL], HIGH);
  }

  for (int nC = 0; nC <= 3; nC++) {
     pinMode(colunas[nC], INPUT_PULLUP); // seta as colunas como entrada 
  } 
   
  Serial.begin(9600); // inicia a comunicação serial
  Serial.println("Aguardando acionamento das teclas");
  Serial.println();
}
 
void loop()
{
    for (int nL = 0; nL <= 3; nL++)
    {
      digitalWrite(linhas[nL], LOW); // joga as linhas em nível baixo
      
      for (int nC = 0; nC <= 3; nC++) {
        /* quando uma tecla for pressionada, a respectiva tecla[L][C] terá seu contato 
        fechado e ficará em nível lógico baixo */
      
        if (digitalRead(colunas[nC]) == LOW)
        {
          Serial.print("Tecla: ");
          Serial.println(teclas[nL][nC]);
          if(teclas[nL][nC] == teclas[0][0])
          { // UM
              digitalWrite(q0, HIGH); // escreve os valores nos pinos de saída em binário
              digitalWrite(q1, LOW);
              digitalWrite(q2, LOW);
              digitalWrite(q3, LOW);
              digitalWrite(pulso, HIGH);
              delay(20);
              digitalWrite(pulso, LOW);
              delay(20);
              Serial.println("0001");
           } else if(teclas[nL][nC] == teclas[0][1])
           { // DOIS
              digitalWrite(q0, LOW);
              digitalWrite(q1, HIGH);
              digitalWrite(q2, LOW);
              digitalWrite(q3, LOW);
              digitalWrite(pulso, HIGH);
              delay(20);
              digitalWrite(pulso, LOW);
              delay(20);
              Serial.println("0010");
            } else if(teclas[nL][nC] == teclas[0][2])
            { // TRES
              digitalWrite(q0, HIGH);
              digitalWrite(q1, HIGH);
              digitalWrite(q2, LOW);
              digitalWrite(q3, LOW);
              digitalWrite(pulso, HIGH);
              delay(20);
              digitalWrite(pulso, LOW);
              delay(20);
              Serial.println("0011");
             } else if(teclas[nL][nC] == teclas[1][0])
             { // QUATRO
               digitalWrite(q0, LOW);
               digitalWrite(q1, LOW);
               digitalWrite(q2, HIGH);
               digitalWrite(q3, LOW);
               digitalWrite(pulso, HIGH);
               delay(20);
               digitalWrite(pulso, LOW);
               delay(20);
               Serial.println("0100");
             } else if(teclas[nL][nC] == teclas[1][1])
             { // CINCO
               digitalWrite(q0, HIGH);
               digitalWrite(q1, LOW);
               digitalWrite(q2, HIGH);
               digitalWrite(q3, LOW);
               digitalWrite(pulso, HIGH);
               delay(20);
               digitalWrite(pulso, LOW);
               delay(20);
               Serial.println("0101");
              } else if(teclas[nL][nC] == teclas[1][2])
              { // SEIS
               digitalWrite(q0, LOW);
               digitalWrite(q1, HIGH);
               digitalWrite(q2, HIGH);
               digitalWrite(q3, LOW);
               digitalWrite(pulso, HIGH);
               delay(20);
               digitalWrite(pulso, LOW);
               delay(20);
               Serial.println("0110");
              } else if(teclas[nL][nC] == teclas[2][0])
              { // SETE
                digitalWrite(q0, HIGH);
                digitalWrite(q1, HIGH);
                digitalWrite(q2, HIGH);
                digitalWrite(q3, LOW);
                digitalWrite(pulso, HIGH);
                delay(20);
                digitalWrite(pulso, LOW);
                delay(20);
                Serial.println("0111");
              } else if(teclas[nL][nC] == teclas[2][1])
              { // OITO
                digitalWrite(q0, LOW);
                digitalWrite(q1, LOW);
                digitalWrite(q2, LOW);
                digitalWrite(q3, HIGH);
                digitalWrite(pulso, HIGH);
                delay(20);
                digitalWrite(pulso, LOW);
                delay(20);
                Serial.println("1000");
              } else if(teclas[nL][nC] == teclas[2][2])
              { // NOVE
                digitalWrite(q0, HIGH);
                digitalWrite(q1, LOW);
                digitalWrite(q2, LOW);
                digitalWrite(q3, HIGH);
                digitalWrite(pulso, HIGH);
                delay(20);
                digitalWrite(pulso, LOW);
                delay(20);
                Serial.println("1001");
              } else if(teclas[nL][nC] == teclas[3][1])
              { // ZERO
                digitalWrite(q0, LOW);
                digitalWrite(q1, LOW);
                digitalWrite(q2, LOW);
                digitalWrite(q3, LOW);
                digitalWrite(pulso, HIGH);
                delay(20);
                digitalWrite(pulso, LOW);
                delay(20);
                Serial.println("0000");
              }else if(teclas[nL][nC] == teclas[0][3])
            { // ALTERA (A)
              digitalWrite(altera, HIGH);
              Serial.println("Altera");
             }
              
          while(digitalRead(colunas[nC]) == LOW){}
        }
      }

      digitalWrite(linhas[nL], HIGH);
    }
}
 
