import logo from './logo.svg';
import Caver from 'caver-js';
import './App.css';

const COUNT_CONTRACT_ADDRESS = '0xf461d87d54dc8549196F43831b549F240698901e';
const ACCESS_KEY_ID = 'KASKQEGA7NQRALPDX9D5RE2K';
const SECRET_ACCESS_KEY = 'E29Zp2QDITcEp33sDoNUaCQD8e1gMkmbVIlXRnx9';
const CHAIN_ID = '1001'; // main net -> 8217, test net -> 1001
const COUNT_ABI = '[ { "constant": false, "inputs": [ { "name": "_count", "type": "uint256" } ], "name": "setCount", "outputs": [], "payable": false, "stateMutability": "nonpayable", "type": "function" }, { "constant": true, "inputs": [], "name": "count", "outputs": [ { "name": "", "type": "uint256" } ], "payable": false, "stateMutability": "view", "type": "function" }, { "constant": true, "inputs": [], "name": "getBlockNumber", "outputs": [ { "name": "", "type": "uint256" } ], "payable": false, "stateMutability": "view", "type": "function" } ]';
// ABI(Application Binary Interface) 즉, 사용 설명서
const option = {
  headers: [
    {
      name: "Authorization",
      value: "Basic " + Buffer.from(ACCESS_KEY_ID + ":" + SECRET_ACCESS_KEY).toString("base64")
    },
    {
      name : "x-chain-id",
      value : CHAIN_ID
    }
  ]
}

const caver = new Caver(new Caver.providers.HttpProvider("https://node-api.klaytnapi.com/v1/klaytn", option));
const CountContract = new caver.contract(JSON.parse(COUNT_ABI), COUNT_CONTRACT_ADDRESS);

const readCount = async () => {
  const _count = await CountContract.methods.count().call();
  console.log(_count);
}

const getBalance = (address) => {
  return caver.rpc.klay.getBalance(address).then((response) => {
    const balance = caver.utils.convertFromPeb(caver.utils.hexToNumberString(response));
    console.log(`balance:${balance}`);
    return balance;
  })
}


function App() {
  readCount();
  getBalance('0x398627ff984396ae5e3f36df4dfd33d05dfb48c6');
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          hi <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
