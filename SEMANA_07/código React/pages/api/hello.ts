// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import type { NextApiRequest, NextApiResponse } from "next";

interface Signal {
  id: number;
  macAddress: string;
  strength: number;
}

interface Localizacao {
  id: number;
  room: string;
  signals: Signal[];
}

let numero = 0;

export default function handler(
  req: NextApiRequest,
  res: NextApiResponse<Localizacao>
) {
  
  console.log(req.method);
  console.log();
  numero++;
  console.log(numero);
  res.status(200).send({ nome: "wahuida", idade: 12,signals: [{macAddress: "duaiwhd", strength: }] });
}
