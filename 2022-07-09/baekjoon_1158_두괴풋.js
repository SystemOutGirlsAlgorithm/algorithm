const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ");
const N = input[0];
const K = input[1];

function createNode(value) {
  const node = {};

  node.value = value;
  node.next = null;

  return node;
}

function createCircleLinkedList() {
  const list = {};

  list.tail = null;
  list.size = 0;

  list.addToTail = function (num) {
    const newNode = createNode(num);

    if (!this.tail) {
      this.tail = newNode;
      this.tail.next = newNode;
      this.size++;

      return;
    }

    newNode.next = this.tail.next;
    this.tail.next = newNode;
    this.tail = newNode;
    this.size++;
  };

  list.remove = function (num) {
    let previousNode = this.tail;
    let targetNode = this.tail;

    for (let i = 0; i < num; i++) {
      previousNode = targetNode;
      targetNode = targetNode.next;
    }

    let targetNodeValue;
    targetNodeValue = targetNode.value;
    previousNode.next = targetNode.next;
    this.tail = targetNode;
    this.size--;

    return targetNodeValue;
  };

  return list;
}

const circleLinkedList = createCircleLinkedList();
let result = "";

for (let i = 1; i <= N; i++) {
  circleLinkedList.addToTail(i);
}

while (circleLinkedList.size > 0) {
  result += circleLinkedList.remove(K) + ", ";
}

console.log(`<${result.slice(0, -2)}>`);
