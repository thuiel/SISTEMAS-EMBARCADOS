const int pin_botao1 = 2;			// pin_botao1 tem o valor da porta 2
const int pin_botao2 = 3;     // pin_botao1 tem o valor da porta 3
bool botao1 = false;				// Aceita valores de 0 ou 1 para botao1
bool botao2 = false;				// Aceita valores de 0 ou 1 para botao2

void setup() {
  pinMode(pin_botao1, INPUT_PULLUP);			// Define como uma entrada e adiciona um pull up interno no pino do botão1
  pinMode(pin_botao2, INPUT_PULLUP);			// Define como uma entrada e adiciona um pull up interno no pino do botão2
  pinMode(led_vermelho, OUTPUT);			// Define a porta do led vermelho como saída
  pinMode(led_verde, OUTPUT);			// Define a porta do led verde como saída
  pinMode(led_amarelo, OUTPUT);			// Define a porta do led amarelo como saída
}

void loop() {
  botao1 = digitalRead(pin_botao1);		// Lê o valor do pino em que o botão1 está ligado
  botao2 = digitalRead(pin_botao2);		// Lê o valor do pino em que o botão2 está ligado
  if(botao1 == LOW && botao2 == LOW) {				// Se o valor de botão1 e botao 2 for 0
  digitalWrite(led_vermelho, 1);				// Liga o botão vermelho
  }
  else{				// Se não
    digitalWrite(led_vermelho, 0);				// Desliga o botão vermelho
  }
  if(botao1 == LOW || botao2 == LOW){				// Se o botão1 apertado ou botão2 apertado
    digitalWrite(led_verde, 1);				// Liga o botão verde
  }
  else{
    digitalWrite(led_verde, 0);				// Desliga o botão verde
  }
  if(botao1 == LOW ^ botao2 == LOW){				// Se o botão1 e botão2 tiverem o mesmo valor( porta xor)
    digitalWrite(led_amarelo, 1);				// Liga o botão amarelo
  }
  else{
    digitalWrite(led_amarelo, 0);				// Desliga o botão amarelo
  }
}
