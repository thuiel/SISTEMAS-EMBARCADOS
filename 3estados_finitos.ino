 const int ST1 = 2; // sensor se tem tampinha na esteira 
const int ST2 = 3; // sensor se tem tampinha na garrafa 
const int SP1 = 4; // sensor se a garrafa esta na possicao pra colocar tampinha 
const int Botao_start = 5; 
const int CR = 6; // motor que coloca as tampinha
const int FT = 7; // alarme falta tampinha na esteira
const int FC = 8; // alarme que falta tampinha na garrafa 
const int M1 = 9; // esteira das garrafa

unsigned int estado = 1;
int contagem = 0;

unsigned long timer = 0;
unsigned long segundos = 2000;

bool tampa_esteira = 0;
bool tampa_garrafa = 0;
bool posicao_garrafa = 0;
bool start = 0;

void setup() {

  pinMode(ST1, INPUT_PULLUP);
  pinMode(ST2, INPUT_PULLUP);
  pinMode(SP1, INPUT_PULLUP);
  pinMode(Botao_start, INPUT_PULLUP);
  pinMode(M1, OUTPUT);
  pinMode(CR, OUTPUT);
  pinMode(FT, OUTPUT);
  pinMode(FC, OUTPUT);
  Serial.begin(2400);

}

void loop() {
  Serial.print(estado);
  Serial.print("______");
  Serial.println(contagem);
  tampa_esteira = digitalRead(ST1);
  tampa_garrafa = !digitalRead(ST2);
  posicao_garrafa = !digitalRead(SP1);
  start = !digitalRead(Botao_start);
  //estado = 1;
  switch (estado){

    case 1:
      if(start){
        digitalWrite(FT, 0);
        digitalWrite(FC, 0);
      
        estado = 2;
      }
      break;

    case 2:
      if(!tampa_esteira){
        digitalWrite(FT, 1);
        estado = 1;
      }     
      else{
        digitalWrite(M1, 1);
        estado = 3;
      }
      break;
    
    case 3:
      if(posicao_garrafa){
        digitalWrite(M1, 0);
        digitalWrite(CR, 1);
        timer = millis();
        estado = 4;
      }
      break;

    case 4: 
      if((millis() - timer) >= segundos){
        digitalWrite(CR, 0);
        if(!tampa_garrafa){
          digitalWrite(FC, 1);
          estado = 1;
        }
        else {
          estado = 5;
        }
      }
      break;

    case 5: 
      contagem++;

      if(contagem >= 24 ){
        estado = 1;
        contagem = 0;
      }
      else  {
        estado = 2;
      }
      break;
  }
}