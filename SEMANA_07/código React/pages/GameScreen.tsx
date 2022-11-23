import {
  StartButton,
  Button,
  GameContainer,
  RedDot,
  GreenDot,
  BlueBall,
  YellowBall,
} from "./components";
import {
  Dispatch,
  SetStateAction,
  useState,
  useEffect,
  useCallback,
} from "react";

const EspIp: string = "http://192.168.66.194/";
let randomTime: number = 0;

let buttonOn = false;

interface IProps {
  setOnGame: Dispatch<SetStateAction<boolean>>;
}

const GameScreen: React.FC<IProps> = ({ setOnGame }) => {
  const [lightCount, setLightCount] = useState(0);

  const keyPressed = ({ key }: any) => {
    if (key === "a" && buttonOn) {
      setLightCount(0);
      fetch(EspIp + "blueWon");
      console.log("yellow wins");
      buttonOn = false;
    } else if (key === "l" && buttonOn) {
      fetch(EspIp + "yellowWon");
      setLightCount(0);
      console.log("blue wins");
      buttonOn = false;
    }
  };

  useEffect(() => {
    document.addEventListener("keydown", keyPressed);
    return () => {
      document.removeEventListener("keyup", keyPressed);
    };
  }, []);

  const startGame = () => {
    setLightCount(1);

    setTimeout(() => {
      setLightCount(2);

      setTimeout(() => {
        setLightCount(3);
        randomTime = Math.random() * 6;

        setTimeout(() => {
          setLightCount(4);
          buttonOn = true;
        }, randomTime * 1000);
      }, 2000);
    }, 2000);
  };

  const resetCounter = () => {
    fetch(EspIp + "reset");
  };

  return (
    <GameContainer>
      <StartButton onClick={startGame}>COMEÇAR!</StartButton>
      <Button onClick={() => setOnGame(false)}>Voltar</Button>
      <Button onClick={resetCounter}>Resetar contador</Button>
      <BlueBall><h1>A</h1></BlueBall>
      <YellowBall><h1>L</h1></YellowBall>
      {lightCount > 0 && <RedDot />}
      {lightCount > 1 && <RedDot />}
      {lightCount > 2 && <RedDot />}
      {lightCount > 3 && <GreenDot />}
    </GameContainer>
  );
};

export default GameScreen;
