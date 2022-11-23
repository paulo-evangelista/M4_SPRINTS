import { useEffect } from "react";
import {
  Container,
  PlayersDiv,
  BluePlayer,
  YellowPlayer,
  Button,
  StartButton,
} from "./components";
import { Dispatch, SetStateAction } from "react";


// BluePlayer, YellowPlayer;

const EspIp: string = "http://192.168.66.194/";

const testAPI = async () => {
  fetch(EspIp + "reset");
};



interface IProps {
  setOnGame: Dispatch<SetStateAction<boolean>>;
}

export default function Main({ setOnGame }: IProps) {


  return (
    <Container>
      <h1>Bem-vindo!</h1>
      <h2>Quem tem a reação mais rápida?</h2>
      <p>
        Assim que a luz verde aparecer, seja o primeiro jogador a reagir e
        ganhar um ponto!
      </p>
      <p>Quando a luz verde aparecer...</p>
      <PlayersDiv>
        <BluePlayer>
          <h3>Jogador Azul</h3>
          <p>Você deve apertar a tecla:</p>
          <h1>A</h1>
        </BluePlayer>
        <YellowPlayer>
          <h3>Jogador Amarelo</h3>
          <p>Você deve apertar a tecla:</p>
          <h1>L</h1>
        </YellowPlayer>
      </PlayersDiv>
      <h2>Prontos?</h2>
      <p>Antes de qualquer coisa, vamos testar a conexão com o ESP32:</p>
      <Button onClick={testAPI}>Testar conexão</Button>
      <br />
      <StartButton onClick={() => setOnGame(true)}>JOGAR!</StartButton>
    </Container>
  );
}
