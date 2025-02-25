class Queue {
  constructor() {
    this.queue = [];
  }

  push(ele) {
    this.queue.push(ele);
  }

  pop() {
    return this.queue.unshift();
  }

  top() {
    return this.queue[0];
  }

  reverse() {
    this.queue.reverse();
  }

  answer() {
    let string = "";
    this.queue.reverse();
    for (const ele of this.queue) string += ele;
    return string;
  }
}

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [str1, str2] = input;

const dp = Array.from({ length: str1.length + 1 }, () => Array.from({ length: str2.length + 1 }, () => 0));

for (let i = 1; i < str1.length + 1; i++) {
  for (let j = 1; j < str2.length + 1; j++) {
    if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}

let row = str1.length;
let col = str2.length;
const q = new Queue();
while (row > 0 && col > 0) {
  if (str1[row - 1] === str2[col - 1]) {
    q.push(str1[row - 1]);
    row--;
    col--;
  } else {
    if (dp[row - 1][col] > dp[row][col - 1]) row--;
    else col--;
  }
}

console.log(dp[str1.length][str2.length]);
if (dp[str1.length][str2.length]) {
  console.log(q.answer());
}
