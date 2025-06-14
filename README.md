# Edge-Computing-IoT---Sistema-F-sico-de-Monitoramento
# Sistema de Monitoramento de Enchentes com Edge Computing

## Descrição do Projeto

Este projeto utiliza a tecnologia de **Edge Computing** para monitoramento de enchentes em tempo real, com o objetivo de proporcionar alertas locais sobre a elevação do nível das águas e possíveis riscos de enchentes. A solução emprega sensores para medir a umidade, o nível da água e a distância da superfície do rio ou área monitorada. Quando valores críticos são atingidos, o sistema emite alertas visuais e sonoros, garantindo que moradores e autoridades sejam notificados de forma eficiente e local.

### Tecnologias Utilizadas

- **Edge Computing**: Processamento de dados local (no dispositivo) para gerar respostas rápidas sem a necessidade de enviar informações para a nuvem. Isso permite uma atuação quase imediata diante de situações de risco.
- **Arduino**: Controlador de hardware utilizado para a integração dos sensores e atuadores.
- **Sensores**:
  - **DHT22**: Sensor de umidade e temperatura, utilizado para medir a umidade do ambiente, simulando a detecção de chuvas.
  - **Sensor Ultrassônico**: Usado para medir a distância e, com isso, determinar o nível de água nas áreas monitoradas.
- **LEDs e Buzzer**: Indicadores visuais e sonoros para alertar sobre possíveis riscos de enchentes.

### Visão Geral da Solução

A solução desenvolvida monitora o nível da água e a umidade em tempo real, acionando alertas quando os parâmetros de segurança são ultrapassados. O sistema funciona da seguinte maneira:

1. O **sensor ultrassônico** mede a distância entre o sensor e a superfície da água, permitindo detectar mudanças no nível da água.
2. O **DHT22** mede a umidade do ar, que pode indicar o risco de chuvas intensas, complementando o monitoramento do nível da água.
3. Quando o nível da água ultrapassa um valor de segurança, o sistema ativa um **LED vermelho** e um **buzzer** como alertas visuais e sonoros. Caso o nível de segurança seja mantido, o sistema indica que está tudo seguro com um **LED verde**.

Este sistema permite que o monitoramento e o acionamento de alertas sejam realizados diretamente no local, sem a necessidade de processamento na nuvem, o que caracteriza a abordagem de **Edge Computing**. A comunicação local garante uma resposta mais ágil, essencial em situações de emergência.

### Funcionalidades

1. **Monitoramento em Tempo Real**: Medição constante da distância da superfície da água e da umidade do ar.
2. **Alertas Locais**: Acionamento de LEDs e buzzer quando os níveis de água ou umidade ultrapassam os limites predefinidos.
3. **Baixa Latência**: O processamento é feito localmente no dispositivo (Edge Computing), garantindo uma resposta imediata a mudanças nos dados monitorados.

### Diagrama do Sistema

A arquitetura do sistema é composta por três partes principais:

- **Sensores**: DHT22 (para umidade) e sensor ultrassônico (para nível da água).
- **Microcontrolador (Arduino)**: Processa os dados coletados pelos sensores e toma decisões com base em regras predefinidas.
- **Atuadores**: LEDs e buzzer, que são acionados conforme os dados dos sensores.

### Como Funciona

1. **Leitura do Sensor de Nível de Água**: O sensor ultrassônico mede a distância, que é convertida em centímetros para indicar o nível da água.
2. **Leitura do Sensor de Umidade**: O DHT22 mede a umidade relativa do ar, que pode ser usada para prever chuvas fortes.
3. **Lógica de Decisão**: Se a distância medida for inferior a 20 cm (indicando alto nível de água) ou a umidade for superior a 70% (indicando chuvas intensas), um alerta é gerado. Isso aciona o LED vermelho e o buzzer.
4. **Alertas**: Quando o sistema identifica um risco de enchente, ele envia um alerta local com um LED vermelho aceso e um buzzer sonoro. Caso as condições voltem à normalidade, o LED verde acende.

### Requisitos

- **Hardware**:
  - Arduino ou placa de desenvolvimento compatível.
  - Sensor de umidade DHT22.
  - Sensor ultrassônico HC-SR04.
  - LED vermelho e verde.
  - Buzzer.

- **Software**:
  - Arduino IDE para programação do microcontrolador.

### Instruções de Uso

1. **Montagem**:
   - Conecte o **sensor ultrassônico** ao Arduino conforme os pinos definidos (TRIG no pino 5 e ECHO no pino 6).
   - Conecte o **DHT22** ao pino digital 2 do Arduino.
   - Conecte os LEDs e o buzzer aos pinos definidos no código (LED vermelho no pino 13, LED verde no pino 11 e buzzer no pino 12).
   
2. **Simulação no Wokwi**:
   - Crie uma conta no Wokwi (ou use o link fornecido) e crie um novo projeto.
   - Importe o código fornecido e adicione os componentes no simulador.
   - Simule o funcionamento do sistema, observando como os alertas são acionados conforme as condições dos sensores.

3. **Execução**:
   - O sistema inicia o monitoramento assim que o Arduino é alimentado, medindo os parâmetros dos sensores a cada 10 segundos.
   - Caso o nível de água ou a umidade ultrapassem os limites de segurança, o sistema ativa os alertas.

### Link para o Projeto no Simulador

- [Acesse o projeto no Wokwi aqui](https://wokwi.com/projects/433023735753148417)

### Conclusão

Este projeto de **Edge Computing** é uma solução inovadora para o monitoramento de enchentes em áreas de risco. A implementação local garante um tempo de resposta imediato, fundamental para situações de emergência. Além disso, o uso de tecnologias acessíveis como o Arduino e sensores simples torna a solução escalável e adaptável a diversas situações.