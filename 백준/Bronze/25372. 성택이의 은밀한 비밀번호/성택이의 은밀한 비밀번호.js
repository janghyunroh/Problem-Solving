const fs = require("fs");

const input = fs.readFileSync("/dev/stdin", "utf8").trim().split("\n");
const N = parseInt(input[0]);

for (let i = 1; i <= N; i++) {
    const password = input[i];
    if (password.length >= 6 && password.length <= 9) {
        console.log("yes");
    } else {
        console.log("no");
    }
}