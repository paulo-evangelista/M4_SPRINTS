import Main from "./main";
import GameScreen from "./GameScreen";
import { useState } from "react";
import { Dispatch, SetStateAction } from "react";
// BluePlayer, YellowPlayer;

const EspIp: string = "http://192.168.66.194/";


export default function Home() {
  const [onGame, setOnGame] = useState(false);

  interface IProps {
    setOnGame: Dispatch<SetStateAction<boolean>>;
  }

  return (
    <div>
      {!onGame ? (
        <Main setOnGame={setOnGame} />
      ) : (
        <GameScreen setOnGame={setOnGame} />
      )}
    </div>
  );
}
