import styled from "styled-components";

export const Container = styled.div`
  width: 100vw;
  height: 100%;
  background: #f0f0f0;
  color: #000000;
  font-size: 3rem;
  text-align: center;
  justify-content: center;
  & > p {
    margin: 0;
  }
`;
export const GameContainer = styled.div`
  width: 100vw;
  height: 100%;
  color: #000000;
  font-size: 3rem;
  text-align: center;
  justify-content: center;
`;
export const PlayersDiv = styled.div`
  width: 40%;
  height: 300px;
  display: flex;
  justify-content: space-between;
  margin: 100px auto 10px auto;
  /* background: #bfbfbf; */
`;
export const BluePlayer = styled.div`
  width: 40%;
  height: 100%;
  border-radius: 20px;
  background: #0044ff;
  color: #ffffff;
  & > h3 {
    font-size: 0.9em;
    margin: 5px 0 0 0;
  }
  & > h1 {
    margin: 0 0 0 0;
  }
  & > p {
    margin: 0;
    font-size: 2rem;
    padding: 5px;
  }
`;
export const YellowPlayer = styled.div`
  width: 40%;
  height: 100%;
  align-self: flex-end;
  border-radius: 20px;
  background: #ffcf00;
  & > h3 {
    font-size: 0.9em;
    margin: 5px 0 0 0;
  }
  & > h1 {
    margin: 0 0 0 0;
  }
  & > p {
    margin: 0;
    font-size: 2rem;
    padding: 5px;
  }
`;

export const Button = styled.button`
  width: 20%;
  height: 100px;
  border-radius: 8px;
  font-size: 2rem;
  border: none;
  margin-top: 10px;
  background-color: #0044ff;
  transition: all 0.2s;
  :hover {
    background: #0044aa;
  }
`;
export const StartButton = styled.button`
  width: 30%;
  height: 150px;
  border-radius: 8px;
  font-size: 4rem;
  border: none;
  margin-top: 20px;
  margin-bottom: 80px;
  background-color: green;
  transition: all 0.2s;
  :hover {
    background: #006006;
    scale: 1.2;
  }
`;
export const RedDot = styled.div`
  width: 7%;
  margin: 0 auto 40px auto;
  height: 200px;
  border-radius: 50%;
  background-color: red;
`;
export const GreenDot = styled.div`
  width: 9%;
  margin: 0 auto 40px auto;
  height: 250px;
  border-radius: 50%;
  background-color: green;
`;

export const BlueBall = styled.div`
  position: absolute;
  left: 10%;
  top: 40%;
  width: 400px;
  height: 400px;
  border-radius: 50%;
  color: #ffffff;
  background-color: #0044ff;
  font-size: 4.5rem;
  margin: 0 auto;
  `;
export const YellowBall = styled.div`
  position: absolute;
  left: 75%;
  top: 40%;
  font-size: 4.5rem;
  color: #000000;
  width: 400px;
  height: 400px;
  border-radius: 50%;
  background-color: yellow;
  margin: 0 auto;
  `;
